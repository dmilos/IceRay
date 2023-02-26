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
I_picture[ 'width']  = 2*800
I_picture['height']  = 2*600
I_picture['aspect']  = I_picture['width'] / I_picture['height']

if( 1 < len( sys.argv ) ):
    I_picture[ 'width'] = int( sys.argv[1]  )
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
I_scene['geometry']   = 'Q-sphere'
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
I_config['decoration'] = {}
I_config['light']   = {}
I_config['light']['sample']   = 1

I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( 1, 3, 2 )
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

for geometry_name in geometry_list :
    I_scene['geometry']= geometry_name
    for pigment_name in pigment_list :
        I_scene['pigment']= pigment_name
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
