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

try:
    os.mkdir( "_out" )
except OSError as e:
    pass
I_picture['folder'] = './_out'
I_picture['extension'] = 'pnm'

I_picture['index'] = 0
I_picture['time']  = 0

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
I_scene['geometry']   = 'Q-sphere'
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'I-ALP'
I_scene['light']      = 'chand-nine'
I_scene['decoration'] = 'grid'


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
I_config['room']   = {}
I_config['camera']  = {}
I_config['pigment']  = {}
I_config['light']   = {}
I_config['light']['sample']   = 1
I_config['decoration']   = {}

g = 1.22074408460575947536 #(math.sqrt(5)+1)/2

g = (math.sqrt(5)+1)/2  #1.6180339887498948482045868343656
p = 1.324717957244746025960908854
c = 1.22074408460575947536
I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( +c*p*g, +p*g , +g )
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
I_config['camera']['sample'] = 1
#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )

camera_list = [
    'F-persp'        ,
    'F-orth'         ,
    'F-super'        ,
    'S-horizontal'   ,
    'S-vertical'     ,
    'S-fisheye'      ,
    'C-vertical'     ,
    'C-horizontal'   ,
    'P-C-vertical'   ,
    'DOF-persp'       ,
    'DOF-cone'       ,
    'DOF-cylinder'
]

for item in camera_list :
    I_scene['camera']= item
    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

camera_list = [  'I-C-vertical' ]

I_config['camera'][ 'eye'] = IceRayPy.type.math.coord.Scalar3D(  0, 0, 0 )
I_config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( -3, 0, 0 )
for item in camera_list :
    I_scene['camera']= item
    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

import os
def prepare_readme():
    os.rename( I_picture['folder']+'/'+    'C-close_C-horizontal_Q-sphere_trans_I-ALP_chand-nine_0000.pnm'       , I_picture['folder']+'/'+'camera-cylinder-horizontal.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_C-vertical_Q-sphere_trans_I-ALP_chand-nine_0000.pnm'         , I_picture['folder']+'/'+'camera-cylinder-vertical.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_DOF-cone_Q-sphere_trans_I-ALP_chand-nine_0000.pnm'           , I_picture['folder']+'/'+'camera-dof-cone.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_DOF-cylinder_Q-sphere_trans_I-ALP_chand-nine_0000.pnm'       , I_picture['folder']+'/'+'camera-dof-cylinder.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_DOF-persp_Q-sphere_trans_I-ALP_chand-nine_0000.pnm'          , I_picture['folder']+'/'+'camera-dof-persp.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_F-orth_Q-sphere_trans_I-ALP_chand-nine_0000.pnm'             , I_picture['folder']+'/'+'camera-flat-orthogonal.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_Q-sphere_trans_I-ALP_chand-nine_0000.pnm'            , I_picture['folder']+'/'+'camera-flat-perspective.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_S-fisheye_Q-sphere_trans_I-ALP_chand-nine_0000.pnm'          , I_picture['folder']+'/'+'camera-sphere-fisheye.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_S-horizontal_Q-sphere_trans_I-ALP_chand-nine_0000.pnm'       , I_picture['folder']+'/'+'camera-sphere-horizontal.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_S-vertical_Q-sphere_trans_I-ALP_chand-nine_0000.pnm'         , I_picture['folder']+'/'+'camera-sphere-vertical.pnm' )


##debug  ************************************
#for index in range( 0, 360, 6 ):
#    t = index / 360.0
#    I_picture['index'] = index
#    I_picture['time'] = t
#
#    [x,y,height] = library_path.list['looker']( t, {} ) #!< MAIN
#    I_config['camera'][ 'eye'] = IceRayPy.type.math.coord.Scalar3D( 3, 0, 0 ) #!< MAIN
#    I_config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 ) #!< MAIN
#
#    I_scene['camera']= 'S-fisheye'
#    #I_config['camera']['width'] = index / 100
#    #I_config['camera']['theta']  = index / 100
#    #I_config['camera']['radius']
#    #I_config['camera']['phi'] = index / 100.0
#    I_config['camera']['vertical'] = index / 100.0
#    #I_config['camera']['vertical'] = index / 100.0
#    #I_config['camera']['height'] = 4
#    #I_config['camera']['radius']
#    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )