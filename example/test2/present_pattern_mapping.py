#!/usr/bin/env python3

import time
import math
import os
import sys
import IceRayPy

import render

running_in_visual_studio = "VisualStudioVersion" in os.environ

dll_path = IceRayPy.system.SearchCDLL( P_preferDebug = running_in_visual_studio )

if 0 != len( dll_path ):
    I_dll = IceRayPy.system.LoadCDLL( dll_path )
else:
    print("Can not find DLL")
    time.sleep(200)
    exit()


I_picture ={}
I_picture[ 'width']  = int( 1920 )
I_picture['height']  = int( 1080 )
I_picture['aspect']  = I_picture['width'] / I_picture['height']

if( 1 < len( sys.argv ) ):
    I_picture[ 'width'] = int( sys.argv[1] )
    I_picture['height'] = int( I_picture['width'] / I_picture['aspect'] )

try:
    os.mkdir( "_out" )
except OSError as e:
    pass
I_picture['folder'] = './_out'
I_picture['extension'] = 'pnm'

I_picture['index'] = 0
I_picture['time'] = 0

I_picture['window'] = {}
I_picture['window']['A'] = {}
I_picture['window']['A']['x'] = 0
I_picture['window']['A']['y'] = 0
I_picture['window']['B'] = {}
I_picture['window']['B']['x'] = I_picture['width']
I_picture['window']['B']['y'] = I_picture['height']

I_scene = {}
I_scene['room']       = 'C-close'
I_scene['camera']     = 'F-persp'
I_scene['geometry']   = 'vacuum'
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'I-ALP'
I_scene['light']      = 'point'
I_scene['decoration'] = 'plate'


import library_room
import library_camera
import library_light
import library_pigment
import library_medium
import library_geometry
import library_decoration
import library_path


I_inventory= {}
I_inventory['room']       = library_room.list
I_inventory['camera']     = library_camera.list
I_inventory['geometry']   = library_geometry.list
I_inventory['medium']     = library_medium.list
I_inventory['pigment']    = library_pigment.list
I_inventory['light']      = library_light.list
I_inventory['decoration'] = library_decoration.list

I_config  = {}
I_config['pigment']  = {}
I_config['camera']  = {}
I_config['room']   = {}
I_config['light']   = {}
I_config['light']['sample']   = 1
I_config['decoration']   = {}
I_config['geometry']   = {}

g = 1.22074408460575947536 #(math.sqrt(5)+1)/2

g = (math.sqrt(5)+1)/2
p = 1.324717957244746025960908854
c = 1.22074408460575947536
I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( +c*p*g, +p*g , +g )
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
#I_config['camera']['hfov']   = math.radians( 30 )
#I_config['camera']['vfov']   = math.radians( 30 )
I_config['camera']['width']   =0.666


geometry_list = [ 'S-torus' ]
pigment_list =[ 'M-o-Cartesian2Torus'  ] #!< 'M-o-Cartesian2Torus', 'M-o-Torus2Cartesian'
for index in range( 0, 360, 1 ):
    I_config['camera'][ 'eye' ] = library_path.looker( index/360.0 )
    I_picture['prefix'] = "%04i"%(index)
    for geometry_item in geometry_list :
        I_scene['geometry']= geometry_item
        for pigment_item in pigment_list :
            I_scene['pigment']= pigment_item
            render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

geometry_list = [ 'Q-cylinder']
pigment_list =[ 'M-o-Cartesian2WoodZ' ]
for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )


geometry_list = [
     'F-box'           ,
     'Q-sphere'        ,
     'Q-cylinder'   
 ]
pigment_list =[
      'M-o-Cartesian2WoodX'        ,
      'M-o-Cartesian2WoodY'        ,
      'M-o-Cartesian2WoodZ'        ,
      'M-o-Cylindric2Spherical'    ,
      'M-o-Spherical2Cartesian'    ,
      'M-o-Spherical2Cylindric'   
]
for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )


pigment_list =[ 'M-o-Cartesian2WoodX', 'M-o-Cartesian2WoodY', 'M-o-Cartesian2WoodZ' ]
for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )


geometry_list = [ 'Q-sphere' ]
pigment_list =[ 'M-o-Cartesian2Fisheye', 'M-o-Cartesian2Tablecloth']
for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

geometry_list = [ 'F-box'  ]
pigment_list =[ 'M-o-Cartesian2Package', 'M-o-Spherical2Cartesian', 'M-o-Cylindric2Cartesian', 'M-o-Euclid2Max', 'M-o-Max2Euclid', 'M-o-Cartesian2Cylindric'  ]
for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )


import os
def prepare_readme():
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-sphere_trans_M-o-homography_point_0000.pnm' ,   I_picture['folder']+'/'+   'transform-sphere-hg.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-sphere_trans_M-o-ID_point_0000.pnm' ,           I_picture['folder']+'/'+   'transform-sphere-id.pnm'   )

    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cartesian2Cylindric_point_0000.pnm' ,     I_picture['folder']+'/'+   'transform-cartesian2cylindric.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cartesian2Package_point_0000.pnm' ,       I_picture['folder']+'/'+   'transform-cartesian2package.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cylindric2Cartesian_point_0000.pnm' ,     I_picture['folder']+'/'+   'transform-cylindric2cartesian.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cylindric2Spherical_point_0000.pnm' ,     I_picture['folder']+'/'+   'transform-cylindric2spherical.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Euclid2Max_point_0000.pnm' ,              I_picture['folder']+'/'+   'transform-euclid2max.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Max2Euclid_point_0000.pnm' ,              I_picture['folder']+'/'+   'transform-max2euclid.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Spherical2Cartesian_point_0000.pnm' ,     I_picture['folder']+'/'+   'transform-spherical2cartesian.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Spherical2Cylindric_point_0000.pnm' ,     I_picture['folder']+'/'+   'transform-spherical2cylindric.pnm'   )

    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-sphere_trans_M-o-Cartesian2Fisheye_point_0000.pnm' ,    I_picture['folder']+'/'+   'transform-cartesian2fisheye.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-sphere_trans_M-o-Cartesian2Tablecloth_point_0000.pnm' , I_picture['folder']+'/'+   'transform-cartesian2tablecloth.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-sphere_trans_M-o-Cartesian2WoodX_point_0000.pnm' ,      I_picture['folder']+'/'+   'transform-cartesian2woodx.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-sphere_trans_M-o-Cartesian2WoodY_point_0000.pnm' ,      I_picture['folder']+'/'+   'transform-cartesian2woody.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-cylinder_trans_M-o-Cartesian2WoodZ_point_0000.pnm' ,    I_picture['folder']+'/'+   'transform-cartesian2woodz.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_S-torus_trans_M-o-Cartesian2Torus_point_0000.pnm' ,       I_picture['folder']+'/'+   'transform-cartesian2torus.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_M-o-Cartesian2Spherical_point_0000.pnm' ,   I_picture['folder']+'/'+   'transform-cartesian2spherical.pnm'   )

    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cartesian2WoodX_point_0000.pnm' ,       I_picture['folder']+'/'+   'transform-wood-x.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cartesian2WoodY_point_0000.pnm' ,       I_picture['folder']+'/'+   'transform-wood-y.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cartesian2WoodZ_point_0000.pnm' ,       I_picture['folder']+'/'+   'transform-wood-z.pnm'   )
prepare_readme()
