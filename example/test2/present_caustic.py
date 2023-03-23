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
I_picture[ 'width']  = int( 800 )
I_picture['height']  = int( 600 )
I_picture['aspect']  = I_picture['width'] / I_picture['height']

if( 1 < len( sys.argv ) ):
    I_picture[ 'width'] = int( sys.argv[1] )
    I_picture['height'] = int( I_picture['width'] / I_picture['aspect'] )

I_picture['prefix'] = ''
I_picture['folder'] = './_out'
I_picture['extension'] = 'pnm'

I_picture['index'] = 0
I_picture['time'] = 0
I_picture['watermark'] = "%index"

I_picture['window'] = {}
I_picture['window']['A'] = {}
I_picture['window']['A']['x'] = 0
I_picture['window']['A']['y'] = 0
I_picture['window']['B'] = {}
I_picture['window']['B']['x'] = I_picture['width']
I_picture['window']['B']['y'] = I_picture['height']

I_scene = {}
I_scene['room']       = 'P-radiosity'  #  'C-close'
I_scene['camera']     = 'F-persp'
I_scene['geometry']   = 'Q-sphere'
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'T-B-refract-schlick'
I_scene['light']      = 'dark'
I_scene['decoration'] = 'radiosity'


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
I_config['room']['radiosity']={}
I_config['room']['radiosity']['sample' ]  = 1
I_config['room']['radiosity']['angle'  ]   = math.radians( 90 )
I_config['room']['radiosity']['albedo' ]   = IceRayPy.type.color.RGB( 0.99, 0.99, 0.99 )
I_config['room']['radiosity']['blossom']   = 'sobol'
I_config['room']['radiosity']['correction'] = "trim"
I_config['decoration']   = { }
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

I_config['composer']={}
I_config['composer']['ray-trace']={}
I_config['composer']['ray-trace']['depth'] = 12
I_config['composer']['ray-trace']['trash'] = 1.0/10000.0
I_config['composer']['ray-trace']['next'] = 17000

index = 0;
for object in [  'Q-sphere' ]:  # 'V-Vacuum',
    I_scene['geometry']   = object
    for blossom in [ 'congruent', 'vdc', 'random', 'triangle', 'grid', 'hexagon'  ]: # 
        I_picture['index'] = index
        I_picture['prefix'] = str(index)+ '_' + blossom + "_"
        I_config['room']['radiosity']['patch' ]  = math.radians( 5 )
        I_config['room']['radiosity']['jitter-type' ]   = "none"
        I_config['room']['radiosity']['jitter-angle' ]   = 0.25*I_config['room']['radiosity']['patch']
        I_config['room']['radiosity']['angle'  ]  = math.radians( 90 )
        I_config['room']['radiosity']['sample'] = int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
        I_config['room']['radiosity']['blossom']  = blossom
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
        index = index + 1


#index = 0;
#for index in range( 0, 30 ): # 'triangle', 'grid', 'hexagon', 'vdc', 'random'
#    I_scene['geometry']   = 'V-Vacuum'
#    I_picture['index'] = index
#    I_picture['prefix'] = str(index)+ '_' + 'congruent' + "_"
#    I_config['room']['radiosity']['patch' ]  = math.radians( 5 )
#    I_config['room']['radiosity']['jitter-type' ]   = "random"
#    I_config['room']['radiosity']['jitter-angle' ]  = index/100.0*I_config['room']['radiosity']['patch']
#    I_config['room']['radiosity']['angle'  ]  = math.radians( 45 )
#    I_config['room']['radiosity']['sample'] = 10 # int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
#    I_config['room']['radiosity']['blossom']  = 'congruent'
#    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
#    index = index + 1

