#!/usr/bin/env python3

import time
import math
import os
import sys
import IceRayPy

import render

dll_path = IceRayPy.system.SearchCDLL( P_preferDebug = False )

if 0 != len( dll_path ):
    I_dll = IceRayPy.system.LoadCDLL( dll_path )
else:
    print("Can not find DLL")
    time.sleep(200)
    exit()
    
start = 0;
if( 1 < len( sys.argv ) ):
    start = int( sys.argv[1] )

end = 10;
if( 2 < len( sys.argv ) ):
    end = int( sys.argv[2] )

I_picture ={}
I_picture[ 'width']  = int( 4/3*1000*3  )
I_picture['height']  = int(     1000*3  )
I_picture['aspect']  = I_picture['width'] / I_picture['height']

#if( 1 < len( sys.argv ) ):
#    I_picture[ 'width'] = int( sys.argv[1] )
#    I_picture['height'] = int( I_picture['width'] / I_picture['aspect'] )

I_picture['prefix'] = ''
try:
    os.mkdir( "_out" )
except OSError as e:
    pass
I_picture['folder'] = './_out'
I_picture['extension'] = 'pnm'
I_picture['overwrite'] = False

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

#I_picture['window']['A']['x'] = int(0.35*I_picture['width'])
#I_picture['window']['B']['x'] = int(0.80*I_picture['width'])
#I_picture['window']['A']['y'] = int(0.55*I_picture['height'])
#I_picture['window']['B']['y'] = int(0.75*I_picture['height'])

I_scene = {}
I_scene['room']       = 'P-radiosity'  #  'C-close'
I_scene['camera']     = 'F-persp'
I_scene['geometry']   = 'Q-sphere'
I_scene['medium']     = 'trans'
I_scene['pigment']    =  'T-B-refract-schlick'
I_scene['light']      = 'dark' #'point'
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
I_config['room']['radiosity']['sample' ]  = 16
I_config['room']['radiosity']['angle'  ]   = math.radians( 90 )
I_config['room']['radiosity']['albedo' ]   = IceRayPy.type.color.RGB( 0.99, 0.99, 0.99 )
I_config['room']['radiosity']['blossom']   = 'sobol'
I_config['room']['radiosity']['correction'] = {}
I_config['room']['radiosity']['correction']['rays'] = "trim"
I_config['room']['radiosity']['correction']['leader' ]  = False
I_config['room']['radiosity']['correction']['cone' ]  = False
I_config['room']['level']  = -1
 
I_config['light']   = {}
I_config['light']['sample']   = 1
I_config['decoration']   = {}
I_config['decoration']['size']   = IceRayPy.type.math.coord.Scalar3D(  1.5, 1.5, 0.01 )
I_config['decoration']['center'] = IceRayPy.type.math.coord.Scalar3D( 1, 1, 1 )
I_config['decoration']['color'] = IceRayPy.type.color.RGB(  50/10.0, 50/10.0,  50/10.0 )
I_config['decoration']['pigment'] = 'hexagon'
I_config['geometry']   = {}

g = 1.22074408460575947536 #(math.sqrt(5)+1)/2

g = (math.sqrt(5)+1)/2
p = 1.324717957244746025960908854
c = 1.22074408460575947536
I_config['camera'][ 'eye'] = IceRayPy.type.math.coord.Scalar3D( -c*p*g,+ 1.5* p*g ,  +g )
I_config['camera'][  'up'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0.99999 )
I_config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )

I_config['composer']={}
I_config['composer']['ray-trace']={}
I_config['composer']['ray-trace']['depth'] = 12
I_config['composer']['ray-trace']['trash'] = 1.0/10000.0
I_config['composer']['ray-trace']['next'] = 17000
I_config['composer']['hot'] = {}
I_config['composer']['hot']['x'] = 50
I_config['composer']['hot']['y'] = 360

for index in (  1, 2, 5, 10, 20,50,100, 200, 500, 1000, 2000 ): #1, 2, 5, 10, 20,50,100, 200, 500, 1000, 2000  
    for jitter in [ 'none' ]:  # , 'vdc', 'triangle', 'sobol', 'random', 'sunflower', 'congruent', 'grid', 'hexagon' 
        for object in [ 'Q-sphere'  ]:  #'Q-sphere' 'V-vacuum', 'Q-sphere', 'Q-util-cylinder', 
            I_scene['geometry']   = object
            for blossom in [ 'vdc'  ]: # , 'kmeans', 'triangle', 'sunflower', 'grid', 'hexagon', 'congruent', 'sobol', 'random'  
                I_picture['index'] = index
                I_picture['prefix'] = "%04i"%(index) + '_sph_' + blossom + "_"
                I_config['room']['radiosity']['type']  = blossom
                I_config['room']['radiosity']['patch']  = math.radians( 90 )/index #<! Used also for sample number calculation
                I_config['room']['radiosity']['jitter'] = {}
                I_config['room']['radiosity']['jitter']['type' ]   = jitter # 'none', 'random', 'sobol', 'vdc', 'congruent'
                I_config['room']['radiosity']['jitter']['angle' ]   = 0.5 * I_config['room']['radiosity']['patch']
                I_config['room']['radiosity']['correction'] = {}
                I_config['room']['radiosity']['correction']['leader' ] = False
                I_config['room']['radiosity']['correction']['cone' ] = False
                I_config['room']['radiosity']['correction']['rays' ] = 'trim' # 'none', 'claim', 'trim'
                I_config['room']['radiosity']['angle'  ] = math.radians( 135 )
                I_config['room']['radiosity']['sample'] = index +0* int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
                I_config['room']['radiosity']['reflect']  = 'diffusive' # 'diffusive', 'one', 'schlick'
                I_config['room']['radiosity']['albedo']  = IceRayPy.type.color.RGB( 1.0, 1.0, 1.0 )
                I_config['room']['radiosity']['coefficient']  = 1/3
                render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
