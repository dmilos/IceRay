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
I_scene['geometry']   = 'Q-sphere'
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'I-ALP'
I_scene['light']      = 'chand-nine'
I_scene['decoration'] = 'plate'


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
#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )

pigment_list =[
   'T-0-reflect-One'               ,
   'T-0-reflect-mirror'            ,
   'T-1-reflect-schlick'           ,
   'T-2-reflect-blossom-Grid'      ,
   'T-3-reflect-blossom-Hexagon'   ,
   'T-4-reflect-blossom-trg'       ,
  #'T-5-reflect-blossom-LD'        ,
  #'T-5-reflect-blossom-Pinwheel'  ,
  #'T-5-reflect-blossom-penrose'   ,
   'T-6-reflect-blossom-Rand'      ,
   'T-7-reflect-blossom-sobol'     ,
   'T-8-reflect-blossom-VDC'       ,
   'T-8-reflect-blossom-congruent' ,
   'T-9-refract-fresnel'           ,
   'T-A-refract-Snell'             ,
   'T-B-refract-schlick'
]

I_config['pigment']['count']  = 1

for item in pigment_list :
    I_scene['pigment']= item
    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

geometry_list =[
    'F-box',
    'S-torus'
]

pigment_list =[
    'T-0-reflect-mirror',
    'T-B-refract-schlick'
]

I_config['pigment']['specular']  = IceRayPy.type.color.RGB( 1, 0.1, 0.01 ) 

for geometry_name in geometry_list :
    I_scene['geometry']= geometry_name
    for pigment_name in pigment_list :
        I_scene['pigment']= pigment_name
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )


import os
def prepare_readme():
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_F-box_trans_T-0-reflect-mirror_chand-nine_0000.pnm'                , I_picture['folder']+'/'+'mirror-box.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_F-box_trans_T-B-refract-schlick_chand-nine_0000.pnm'               , I_picture['folder']+'/'+'refract-schlick-box.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-0-reflect-mirror_chand-nine_0000.pnm'             , I_picture['folder']+'/'+'mirror-sphere.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-2-reflect-blossom-Grid_chand-nine_0000.pnm'       , I_picture['folder']+'/'+'blossom-grid.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-3-reflect-blossom-Hexagon_chand-nine_0000.pnm'    , I_picture['folder']+'/'+'blossom-hex.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-4-reflect-blossom-trg_chand-nine_0000.pnm'        , I_picture['folder']+'/'+'blossom-trg.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-6-reflect-blossom-Rand_chand-nine_0000.pnm'       , I_picture['folder']+'/'+'blossom-rand.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-7-reflect-blossom-sobol_chand-nine_0000.pnm'      , I_picture['folder']+'/'+'blossom-sobol.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-8-reflect-blossom-VDC_chand-nine_0000.pnm'        , I_picture['folder']+'/'+'blossom-vdc.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-8-reflect-blossom-congruent_chand-nine_0000.pnm'  , I_picture['folder']+'/'+'blossom-congruent.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-9-refract-fresnel_chand-nine_0000.pnm'            , I_picture['folder']+'/'+'refract-fresnel.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-A-refract-Snell_chand-nine_0000.pnm'              , I_picture['folder']+'/'+'refract-snell.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-B-refract-schlick_chand-nine_0000.pnm'            , I_picture['folder']+'/'+'refract-schlick-sphere.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_S-torus_trans_T-0-reflect-mirror_chand-nine_0000.pnm'              , I_picture['folder']+'/'+'mirror-torus.pnm' )
    os.rename( I_picture['folder']+'/'+'C-close_F-persp_S-torus_trans_T-B-refract-schlick_chand-nine_0000.pnm'             , I_picture['folder']+'/'+'refract-schlick-torus.pnm' )
   #os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-0-reflect-One_chand-nine_0000.pnm'                , I_picture['folder']+'/'+'-delete.pnm' )
   #os.rename( I_picture['folder']+'/'+'C-close_F-persp_Q-sphere_trans_T-1-reflect-schlick_chand-nine_0000.pnm'            , I_picture['folder']+'/'+'-delete.pnm' )