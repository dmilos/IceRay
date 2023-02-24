#!/usr/bin/env python3

import sys
import time
import math
import os
import platform
import threading
import traceback
import pathlib
import inspect
import types
import gc
from ctypes import *

import IceRayPy


import composer
import decoration
import obseravtion
import signal
import faulthandler

import library_room
import library_camera
import library_light
import library_pigment
import library_medium
import library_geometry


gc.enable()
faulthandler.enable()

camera_inventory = library_camera.list

camera_list = [ 'F-persp' ]

light_inventory = library_light.list
light_list = [ 'point' ]

medium_inventory = library_medium.list
medium_list = ['trans']

geometry_inventory =  library_geometry.list
geometry_list = [
  'F-piped'
 ]

pigment_inventory =  library_pigment.list
pigment_list =[
     'T-0-reflect-One'               ,
     'T-0-reflect-mirror'            ,
     'T-1-reflect-schlick'           ,
     'T-2-reflect-blossom-Grid'      ,
     'T-3-reflect-blossom-Hexagon'   ,
     'T-4-reflect-blossom-trg'       ,
     #'T-5-reflect-blossom-Pinwheel' ,
     #'T-5-reflect-blossom-penrose'  ,
     'T-6-reflect-blossom-Rand'      ,
     'T-7-reflect-blossom-VDC'       ,
     'T-8-refract-fresnel'           ,
     'T-9-refract-Snell'             ,
     'T-A-refract-schlick'           ,
]

room_inventory = library_room.list
room_list = [
   'C-close'
 ]

decoration_inventory = decoration.list
decoration_item = 'vacuum'

path_inventory = obseravtion.list

def doRendering(P_config):
    folder = P_config['folder']

    for key_room in room_list:
       for key_camera in camera_list:
           for key_geometry in geometry_list:
            for key_medium in medium_list:
                for key_pigment in pigment_list:
                   for key_light in light_list:
                       name = key_room +"_"+ key_camera +'_'+ key_geometry +"_"+ key_medium +"_"+ key_pigment+"_" + key_light
                       filen_name = folder + "/" + name + '_'+ "{:04d}".format( P_config['frame']['index'] ) + '.png'
                       print( filen_name, flush = True  )

                       my_file = pathlib.Path( filen_name )
                       if my_file.is_file():
                           continue

                       geometry = geometry_inventory[ key_geometry ]( P_config['dll'] )#, P_config

                       light_the = light_inventory[ key_light ]( P_config['dll'] )

                       light_enclose = IceRayPy.core.light.transform.Translate( P_config['dll'], light_the, IceRayPy.type.math.coord.Scalar3D( 0, 0, 2 ) )
                       light_blocked = IceRayPy.core.light.Obstruct( P_config['dll'], light_enclose, geometry );
                       light_final = light_blocked
                       P_config['light']            = light_enclose
                       P_config['geometry']         = geometry
                       P_config['pigment']['light'] = light_enclose

                       pigment = pigment_inventory[key_pigment]( P_config['dll'], P_config['pigment'] )
                       medium = medium_inventory[key_medium]( P_config['dll'] )
                       object = composer.object( P_config['dll'], geometry, pigment, medium )

                       camera = composer.camera( P_config['dll'], camera_inventory[ key_camera ]( P_config['dll'], P_config['camera'] ), P_config['camera'] )

                       room = room_inventory[ key_room ]( P_config['dll'], P_config['room'], light_final, geometry )

                       scene = composer.arange( P_config['dll'], object, room, decoration_inventory[ decoration_item ](  P_config['dll'], {   }, light_final, object ) )

                       GI_save_image_image = IceRayPy.type.graph.Picture( P_config['dll'] )
                       GI_save_image_image.size( P_config['picture']['width'], P_config['picture']['height'] )

                       manager = composer.manager( P_config, camera, scene )
                       start = time.time()
                       manager.start( GI_save_image_image )
                       delta = time.time() - start
                       print( "Time:" + str( delta ), flush = True )

                       crop  = IceRayPy.type.graph.Picture( P_config['dll'] )

                       A = IceRayPy.type.math.coord.Size2D( P_config['window']['A']['x'], P_config['window']['A']['y'] )
                       B = IceRayPy.type.math.coord.Size2D( P_config['window']['B']['x'], P_config['window']['B']['y'] )

                       IceRayPy.type.graph.Crop( P_config['dll'], crop, GI_save_image_image, A, B )

                       crop.storePNM( filen_name )

                       P_config['dll'].IceRayC_Utility_Random_Table_Next()

                       #end
                   #end
               #end
           #end
       #end


config={}
config['picture'] = {}

start = 0;
if( 1 < len( sys.argv ) ):
    start = int( sys.argv[1] )

step = 1
if( 2 < len( sys.argv ) ):
    step = int( sys.argv[2] )

config['picture']['width']   = int( 1200 )
config['picture']['height']  = int( 900 )
if( 3 < len( sys.argv ) ):
    config['picture'][ 'width'] = int( sys.argv[3] )
    config['picture']['height'] = int( int( sys.argv[3] ) * 0.66666667 )

config['folder'] = './_out'

#config['pixel']['type'] = 'basic'
config['window'] = {}
config['window'] = {}
config['window']['A'] = {}
config['window']['B'] = {}
config['window']['A']['x'] = int( config['picture']['width']  * 0.0 )
config['window']['A']['y'] = int( config['picture']['height'] * 0.666 )
config['window']['B']['x'] = config['window']['A']['x']  + int( config['picture']['width']  * 0.333 )
config['window']['B']['y'] = config['window']['A']['y']  + int( config['picture']['height'] * 0.333 )
config['window']['A']['x'] = 0
config['window']['A']['y'] = 0
config['window']['B']['x'] = config['picture']['width']
config['window']['B']['y'] = config['picture']['height']

config['camera'] = {}
config['camera']['angle-horizontal']  = 1
config['camera']['angle-vertical']    = 1 # 0.66666666666666666666666666666667 #config['picture']['height'] / config['picture']['width']

config['camera']['height']  = config['picture']['height'] / config['picture']['width']
config['camera'][ 'width']  = 1
config['camera']['aspect']  = config['picture']['width'] / config['picture']['height']

config['camera']['eye']  = IceRayPy.type.math.coord.Scalar3D( 0, -3, 0 )
config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0,  0, 0 )
config['camera']['sample'] = 32
config['camera']['path'] = {}
config['camera']['path']['radius'] = 1.75
config['camera']['path']['height'] = 0.9

config['pigment'] = {}
config['pigment']['ior'] = 1.0
config['pigment']['albedo'] = IceRayPy.type.color.RGB( 1, 1, 1 )

config['ray-trace']={}
config['ray-trace']['depth'] = 32
config['ray-trace']['trash'] = 1.0/10000.0
config['ray-trace']['next'] = 17000

config['room'] = {}
config['room']['radiosity'] = {}
config['room']['radiosity']['blossom'] = 'sobol'
config['room']['radiosity']['patch']  = math.radians( 4 )
config['room']['radiosity']['angle']  = math.radians( 89 )
config['room']['radiosity']['sample'] = int( (1 - math.cos(config['room']['radiosity']['angle']) ) / ( 1 - math.cos( config['room']['radiosity']['patch'] ) ) + 1 )
config['room']['radiosity']['jitter-angle'] = math.radians( 4 )
config['room']['radiosity']['jitter-type'] = 'none' #'random''sobol''vdc''none'

config['room']['radiosity']['correction-leader'] = True
config['room']['radiosity']['correction-cone']   = False
config['room']['radiosity']['correction-trim']   = False
config['room']['radiosity']['correction-claim']  = False

config['observer'] = {}
config['observer']['radius'] = 4
config['observer']['dilatation'] = 1
config['observer']['type'] = 1
config['observer']['radius-lo'] = 2
config['observer']['radius-hi'] = 3
config['frame'] = {}
config['frame']['index'] = 0
config['frame']['time'] = 0


config['hot'] = {}
config['hot']['x'] = 300 #int( (0.5) * config['picture']['width']  )
config['hot']['y'] = 500 #int( (0.5) * config['picture']['height'] )

print( "config:" + str( config ), flush = True  )
print( "OS:" + os.getcwd(), flush = True  )
print( "Platform:" + platform.system(), flush = True  )

dll_path = IceRayPy.system.SearchCDLL()

if 0 != len( dll_path ):
    config['dll'] = IceRayPy.system.LoadCDLL( dll_path )
else:
    print("Can not find DLL")
    time.sleep(200)


path_item = 'presentation'

config['pigment']['sigma'] = IceRayPy.type.color.RGB( 1, 1, 1 )
config['pigment']['rho']   = IceRayPy.type.color.RGB( 3.1415926, 3.1415926, 3.1415926 )

index = 0;
config['frame']['index'] = index
dilatation  = config['observer']['dilatation'];
t = index / 360.0 / dilatation
config['frame']['time'] = t

[x,y,height] = path_inventory[path_item]( t, config['camera']['path'] ) #!< MAIN

config['camera'][ 'eye'] = IceRayPy.type.math.coord.Scalar3D( x, y, height ) #!< MAIN
config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 ) #!< MAIN

print( "Hot: ", config['hot'], flush = True  )
print( "Index:" + str(index) + "[" + os.getcwd() + "]", flush = True  )

doRendering( config )

print( 'garbage collector: get_threshold() ' + str( gc.get_threshold() ), flush = True  )
print( 'garbage collector: get_count()     ' + str( gc.get_count()     ), flush = True  )
print( 'garbage collector: collect()       ' + str( gc.collect()       ), flush = True  )
print( 'garbage collector: get_count()    )' + str( gc.get_count()     ), flush = True  )
print( 'garbage collector: get_threshold() ' + str( gc.get_threshold() ), flush = True  )


#time.sleep( 20 )