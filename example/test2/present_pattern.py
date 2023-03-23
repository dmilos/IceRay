#!/usr/bin/env python3

import time
import math
import os
import sys
import IceRayPy

import IceRayPy

import render

dll_path = IceRayPy.system.SearchCDLL()

if 0 != len( dll_path ):
    I_dll = IceRayPy.system.LoadCDLL( dll_path )
else:
    print("Can not find DLL")
    time.sleep(200)
    exit()


I_picture ={}
I_picture[ 'width']  = 800
I_picture['height']  = 600
I_picture['aspect']  = I_picture['width'] / I_picture['height']

if( 1 < len( sys.argv ) ):
    I_picture[ 'width'] = int( sys.argv[1] )
    I_picture['height'] = int( I_picture['width'] / I_picture['aspect'] )

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
I_scene['decoration'] = 'vacuum'


import library_room
import library_camera
import library_light
import library_pigment
import library_medium
import library_geometry
import library_decoration


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
I_config['decoration']   = {}
I_config['light']   = {}
I_config['light']['sample']   = 1

g = 1.22074408460575947536 #(math.sqrt(5)+1)/2

g = (math.sqrt(5)+1)/2
p = 1.324717957244746025960908854
c = 1.22074408460575947536
I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( +c*p*g, +p*g , +g )
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )

geometry_list = [
     'F-box'           ,
     'Q-sphere'        ,
 ]

pigment_list =[

      'P-image'            ,

      'P-level'            ,
      'P-gradientBW' ,

      'M-o-ID'                     ,
      'M-o-translate'              ,
      'M-o-affine'                 ,
      'M-o-homography'             ,

      'M-o-Cartesian2WoodX'        ,
      'M-o-Cartesian2WoodY'        ,
      'M-o-Cylindric2Spherical'    ,

      'M-o-Spherical2Cartesian'    ,
      'M-o-Spherical2Cylindric'    ,
]

geometry_list = [ 'F-plane' ] #debug
pigment_list =[ 'P-noise-congruent3d' ]
for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )



for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )


geometry_list = [ 'S-torus' ]
pigment_list =[ 'M-o-Cartesian2Torus' ]
for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )


geometry_list = [ 'Q-sphere'        , ]
pigment_list =[ 'M-o-Cartesian2Fisheye',   'M-o-Cartesian2Tablecloth', 'M-o-Euclid2Max', 'M-o-Max2Euclid']
for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

geometry_list = [ 'Q-cylinder' , ]
pigment_list =[ 'M-o-Cartesian2WoodZ' ]
for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

geometry_list = [ 'F-plane' ]
pigment_list =[ 'P-onion','P-checker' , 'P-hexagon', 'P-noise-vdc' , 'P-noise-cells', 'P-noise-crackle'    , 'P-noise-perlin'     ,'P-noise-random', 'P-noise-congruent1d', 'P-noise-congruent3d', 'P-noise-value', 'M-o-Cartesian2Spherical' ]
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
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cartesian2Cylindric_point_0000.pnm' ,     I_picture['folder']+'/'+   'transform-Cartesian2Cylindric.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cartesian2Package_point_0000.pnm' ,       I_picture['folder']+'/'+   'transform-Cartesian2Package.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cylindric2Cartesian_point_0000.pnm' ,     I_picture['folder']+'/'+   'transform-Cylindric2Cartesian_point.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Cylindric2Spherical_point_0000.pnm' ,     I_picture['folder']+'/'+   'transform-Cylindric2Spherical.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Euclid2Max_point_0000.pnm' ,              I_picture['folder']+'/'+   'transform-Euclid2Max.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Max2Euclid_point_0000.pnm' ,              I_picture['folder']+'/'+   'transform-Max2Euclid.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Spherical2Cartesian_point_0000.pnm' ,     I_picture['folder']+'/'+   'transform-Spherical2Cartesian.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_M-o-Spherical2Cylindric_point_0000.pnm' ,     I_picture['folder']+'/'+   'transform-Spherical2Cylindric.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-sphere_trans_M-o-Cartesian2Fisheye_point_0000.pnm' ,    I_picture['folder']+'/'+   'transform-Cartesian2Fisheye.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-sphere_trans_M-o-Cartesian2Tablecloth_point_0000.pnm' , I_picture['folder']+'/'+   'transform-Cartesian2Tablecloth.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-sphere_trans_M-o-Cartesian2WoodX_point_0000.pnm' ,      I_picture['folder']+'/'+   'transform-Cartesian2WoodX.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-sphere_trans_M-o-Cartesian2WoodY_point_0000.pnm' ,      I_picture['folder']+'/'+   'transform-Cartesian2WoodY.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_Q-cylinder_trans_M-o-Cartesian2WoodZ_point_0000.pnm' ,    I_picture['folder']+'/'+   'transform-Cartesian2WoodZ.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_S-torus_trans_M-o-Cartesian2Torus_point_0000.pnm' ,       I_picture['folder']+'/'+   'transform-Cartesian2Torus.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_M-o-Cartesian2Spherical_point_0000.pnm' ,   I_picture['folder']+'/'+   'transform-Cartesian2Spherical.pnm'   )

    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-box_trans_P-gradientBW_point_0000.pnm' ,        I_picture['folder']+'/'+   'function-gradient.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-checker_point_0000.pnm' ,         I_picture['folder']+'/'+   'function-checker.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-hexagon_point_0000.pnm' ,         I_picture['folder']+'/'+   'function-hexagon.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-onion_point_0000.pnm' ,           I_picture['folder']+'/'+   'function-onion.pnm'   )

    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-noise-cells_point_0000.pnm' ,     I_picture['folder']+'/'+   'noise-cells.pnm'   )

    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-noise-congruent1d_point_0000.pnm' , I_picture['folder']+'/'+   'noise-congruent1d.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-noise-congruent3d_point_0000.pnm' , I_picture['folder']+'/'+   'noise-congruent3d.pnm'   )

    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-noise-crackle_point_0000.pnm' ,   I_picture['folder']+'/'+   'noise-crackle.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-noise-perlin_point_0000.pnm' ,    I_picture['folder']+'/'+   'noise-perlin.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-noise-random_point_0000.pnm' ,    I_picture['folder']+'/'+   'noise-random.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-noise-value_point_0000.pnm' ,     I_picture['folder']+'/'+   'noise-value.pnm'   )
    os.rename( I_picture['folder']+'/'+ 'C-close_F-persp_F-plane_trans_P-noise-vdc_point_0000.pnm' ,       I_picture['folder']+'/'+   'noise-vdc.pnm'   )

# prepare_readme()
