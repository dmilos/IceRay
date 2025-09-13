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
try:
    os.mkdir( "_out" )
except OSError as e:
    pass
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
I_scene['geometry']   = 'Q-sphere' #'V-Vacuum'
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'P-hexagon' #'T-B-refract-schlick'
I_scene['light']      = 'point'
I_scene['decoration'] = 'vacuum' # 'radiosity'


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
I_config['room']['radiosity']['sample' ]  = 256
I_config['room']['radiosity']['angle'  ]   = math.radians( 90 )
I_config['room']['radiosity']['albedo' ]   = IceRayPy.type.color.RGB( 0.99, 0.99, 0.99 )
I_config['room']['radiosity']['blossom']   = 'sobol'
I_config['room']['radiosity']['correction'] = "trim"
I_config['light']   = {}
I_config['light']['sample']   = 1
I_config['decoration']   = {}

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


for blossom in [ 'hexagon', 'grid', 'triangle' ]:
    I_picture['prefix'] = '0-' +blossom + "_"
    I_config['room']['radiosity']['patch' ]  = math.radians( 10 )  #<! Used for sample number calculation
    I_config['room']['radiosity']['jitter-type'  ]   = "congruent"
    I_config['room']['radiosity']['jitter-angle' ]   = I_config['room']['radiosity']['patch']
    I_config['room']['radiosity']['angle'  ]  = math.radians( 90 )
    I_config['room']['radiosity']['sample'] = int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
    I_config['room']['radiosity']['blossom']  = blossom
    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

for blossom in [ 'random', 'sobol',  'vdc' ]:
    I_picture['prefix'] = '1-' + blossom + "_"
    I_config['room']['radiosity']['patch' ]  = math.radians( 10 )  #<! Used for sample number calculation
    I_config['room']['radiosity']['jitter-type'  ]   = "none"
    I_config['room']['radiosity']['angle'  ]  = math.radians( 90 )
    I_config['room']['radiosity']['sample'] = int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
    I_config['room']['radiosity']['blossom']  = blossom
    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

for blossom in [ 'congruent' ]:
    I_picture['prefix'] = '2-' + blossom + "_"
    I_config['room']['radiosity']['patch' ]  = math.radians( 10 )  #<! Used for sample number calculation
    I_config['room']['radiosity']['jitter-type'  ]   = "none"
    I_config['room']['radiosity']['angle'  ]  = math.radians( 90 )
    I_config['room']['radiosity']['sample'] = int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
    I_config['room']['radiosity']['blossom']  = blossom
    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

#for index in range( 1, 360 ):
#    I_picture['index'] = index
#
#    t = index / 360.0
#    I_picture['time'] = t
#    I_picture['index'] = index
#
#    [x,y,height] = library_path.list['looker']( t, {} ) #!< MAIN
#
#    I_config['camera'][ 'eye'] = IceRayPy.type.math.coord.Scalar3D( x, y, height ) #!< MAIN
#    I_config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 ) #!< MAIN
#
#    I_scene['pigment']    = 'P-hexagon'
#    I_picture['prefix'] = '1-' + 'vdc' + "_"
#    I_config['room']['radiosity']['patch' ]  = math.radians( 8 )
#    I_config['room']['radiosity']['jitter-type'  ]   = "none"
#    I_config['room']['radiosity']['angle'  ]  = math.radians( 90 )
#    I_config['room']['radiosity']['sample'] = index # int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
#    I_config['room']['radiosity']['blossom']  = 'vdc'
#    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

