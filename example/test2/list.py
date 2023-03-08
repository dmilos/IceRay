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
import obseravtion
import signal
import faulthandler

import library_room
import library_camera
import library_light
import library_pigment
import library_medium
import library_geometry
import library_decoration


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
 #'C-hfieldT30x30',
  #'C-hfieldI'
  #'S-sphere'
  #'F-piped' 
  #'S-torus',
   #  'T-affine'    ,
   #  'T-hgraphy'
    'T-hgraphy'
  #'S-util-torus'
 ]

pigment_inventory =  library_pigment.list
pigment_list =[
      'I-ALP'           ,
      #'I-ambient'       ,
      #'I-AsDiffuse'     ,
      #'I-AsSpecular'    ,
      #'I-Beckmann'      ,
      #'I-Blinn'         ,
      #'I-gaussian'      ,
      #'I-HsLambert'     ,
      #'I-HsPhong'       ,
      #'I-Lambert'       ,
      #'I-ONf29'         ,
      #'I-ONf30'         ,
      #'I-ONYFP'         ,
      #'I-ONYFQ'         ,
      #'I-ONJvO'         ,
      #'I-Phong'         ,
      #'I-WardApprox'    ,
      #'I-WardIsotropic' ,
      #'I-WardReal'      ,
      #'T-B-refract-schlick' 
]

room_inventory = library_room.list
room_list = [
   #'C-radiosity',
   'C-close',
   #'R-M-box',
   #'R-M-sphere',
   #'R-plane',
   #'disc',
   #'plane',
   #'plate',
   #'vacuum',
 ]

decoration_inventory = library_decoration.list
decoration_item = 'plate'

path_inventory= obseravtion.list

path_item = 'looker'


#### radiosity {{{
#camera_list     = { 'F-persp'  }
#light_list      = { 'dark'  }
#medium_list     = { 'trans'      }
#geometry_list   = { 'S-sphere'  }
##geometry_list   = { 'S-torus'          : utility.geometry.simple.Torus }
##geometry_list   = { 'U-cylinder'      : utility.geometry.simple.Cylinder }
##geometry_list   = { 'V-vacuum'              : core.geometry.volumetric.Vacuum }
#geometry_list   = {
#     'T-lensCS'      : library.geometry.lens.concave.Symetric,
#     'T-lensCP'      : library.geometry.lens.concave.Plano,
#     'T-lensVS'      : library.geometry.lens.convex.Symetric,
#     'T-lensVP'      : library.geometry.lens.convex.Plano
#  }
#pigment_list    = { 'M-o-Cartesian2Fisheye' : utility.material.operation.mapping.Cartesian2Fisheye }
#pigment_list    = { 'T-reflect-one'         : utility.material.transmission.reflect.One }
#pigment_list    = { 'P-hexagon'             : utility.material.pattern.Hexagon }
#pigment_list    = { 'P-hexagon'          : utility.material.pattern.Hexagon }
#pigment_list    = {
#                   #'T-8-refract-snell'       : utility.material.transmission.refract.Snell,
#                   #'T-A-refract-fresnel'     : utility.material.transmission.refract.Fresnel,
#                   'T-9-refract-schlick'     : utility.material.transmission.refract.Schlick
#                  }
##room_list       = { 'C-close'               : room.cornel_close }
##room_list       = { 'plane'                 : room.plane }
#room_list       = { 'R-plane'               : room.radiosity_plane }
##room_list       = { 'C-radiosity'           : room.cornell_radiosity }
#decoration_item = 'radiosity'
#### }}}

def doRendering(P_config):
    folder = P_config['folder']

    for key_room in room_list:
       for key_camera in camera_list:
           for key_geometry in geometry_list:
            for key_medium in medium_list:
                for key_pigment in pigment_list:
                   for key_light in light_list:
                       extension =  'pnm'
                       name = key_room +"_"+ key_camera +'_'+ key_geometry +"_"+ key_medium +"_"+ key_pigment+"_" + key_light
                       filen_name = folder + "/" + name + '_'+ "{:04d}".format( P_config['frame']['index'] ) + '.' + extension
                       print( filen_name, flush = True  )

                       my_file = pathlib.Path( filen_name )
                       if my_file.is_file():
                           continue

                       geometry = geometry_inventory[ key_geometry ]( P_config['dll'] )#, P_config

                       light_the = light_inventory[ key_light ]( P_config['dll'] )

                       light_enclose = IceRayPy.core.light.transform.Translate( P_config['dll'], light_the, IceRayPy.type.math.coord.Scalar3D( 0, 0, 2 ) )
                       light_blocked = IceRayPy.core.light.Obstruct( P_config['dll'], light_enclose, geometry );
                       light_final = light_blocked

                       P_config['light'] = light_enclose
                       P_config['geometry'] = geometry
                       P_config['pigment']['light'] = light_enclose

                       pigment = pigment_inventory[key_pigment]( P_config['dll'], P_config['pigment'] )
                       medium = medium_inventory[key_medium]( P_config['dll'] )
                       object = composer.object( P_config['dll'], geometry, pigment, medium )

                       camera = composer.camera( P_config['dll'], camera_inventory[ key_camera ]( P_config['dll'], P_config['camera'] ), P_config['camera'] )

                       room = room_inventory[ key_room ]( P_config['dll'], P_config['room'], light_final, geometry )

                       scene = composer.arange( P_config['dll'], object, room, decoration_inventory[ decoration_item ](  P_config['dll'], {   }, light_final, object ) )

                       GI_save_image_image = IceRayPy.type.graph.Picture( P_config['dll'] )
                       GI_save_image_image.size( P_config['picture']['width'], P_config['picture']['height'] )

                       manager = composer.manager( P_config['dll'], P_config, camera, scene )
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

                       #break
                   #break
               #break
           #break
       #break


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
config['pigment']['ior'] = 2.41
config['pigment']['albedo'] = IceRayPy.type.color.RGB( 1, 1, 1 )

config['ray-trace']={}
config['ray-trace']['depth'] = 32
config['ray-trace']['trash'] = 1.0/10000.0
config['ray-trace']['next'] = 17000

config['room'] = {}
config['room']['radiosity'] = {}
config['room']['radiosity']['blossom'] = 'congruent'
config['room']['radiosity']['patch']  = math.radians( 4 )
config['room']['radiosity']['angle']  = math.radians( 89 )
config['room']['radiosity']['sample'] = int( (1 - math.cos(config['room']['radiosity']['angle']) ) / ( 1 - math.cos( config['room']['radiosity']['patch'] ) ) + 1 )
config['room']['radiosity']['jitter-angle'] = math.radians( 4 )
config['room']['radiosity']['jitter-type'] = 'none' #'random''sobol''vdc''none', 'congruent'

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

#config['room']['pigment'] = utility.material.pattern.Checker( config['dll'], {} )
#config['room']['pigment'] = utility.material.pattern.Image( config['dll'], { 'scale': 0.3 }, os.getcwd()+"/default_256.pnm" )
#config['room']['pigment'] = utility.material.pattern.Image( config['dll'], { 'scale': 0.3 }, os.getcwd()+"/../../datag4738.pnm" )

dilatation  = config['observer']['dilatation'];

#output = os.popen('wmic process get description, processid').read()
# Displaying the output
## import subprocess
##
## print(subprocess)
##
## # traverse the software list
## Data = subprocess.check_output(['wmic', 'process', 'list', 'brief'])
## a = str(Data)
## print(a)
##
##exit(0)

#I_picture   = IceRayPy.type.graph.Picture( config['dll'] )
#I_picture.size( 1024, 1024 )
#IceRayPy.type.graph.Default( I_picture )
#I_picture.storePNG( "default_1024.png" )

path_item = 'looker' # 'looker', 'fixed', 'circle' 'presentation'

config['pigment']['sigma'] = IceRayPy.type.color.RGB( 1, 1, 1 )
config['pigment']['rho']   = IceRayPy.type.color.RGB( 3.1415926, 3.1415926, 3.1415926 )

gold = (math.sqrt(5)-1)/2

#for counter in range( 0, 500 ):
#    index = int( 360 * ( gold * counter ) ) % 360

#for step in [ int(360/3), int(360/4), int(360/5), int(360/6), int(360/24), int(360/8), int(360/9), int(360/10), int(360/12), int(360/15), int(360/18), 1 ] :
for index in range( start, 360 * int( dilatation ), step ):

    config['frame']['index'] = index
    t = index / 360.0 / dilatation
    config['frame']['time'] = t

    [x,y,height] = path_inventory[path_item]( t, config['camera']['path'] ) #!< MAIN
    #[x,y,height] = path_inventory[path_item]( 135 / 360.0 / dilatation, config['camera']['path'] )#!< debug

    config['camera'][ 'eye'] = IceRayPy.type.math.coord.Scalar3D( x, y, height ) #!< MAIN
    config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 ) #!< MAIN

    #config['camera']['eye']  = IceRayPy.type.math.coord.Scalar3D(  0, -3, 3 ) #!< debug
    #config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D(  0,  0, 0 ) #!< debug

    print( "Hot: ", config['hot'], flush = True  )
    print( "Index:" + str(index) + "[" + os.getcwd() + "]", flush = True  )

    #config['camera']['eye']  = IceRayPy.type.math.coord.Scalar3D( 0, -3,   2 );

    #config['room']['radiosity']['angle'] = math.radians( 85 )
    #config['room']['radiosity']['jitter-angle'] = math.fmod( config['room']['radiosity']['jitter-angle'] + math.radians( index*0.1 ), 5 )
    #config['pigment']['ior'] = config['pigment']['ior'] + index*0.01;
    #config['room']['radiosity']['sample'] = config['room']['radiosity']['sample'] + index
    #config['pigment']['ior'] = 1.0 + 0.01*index;
    #config['pigment']['ior'] = config['pigment']['ior'] + 0.01;
    #config['room']['radiosity']['angle'] = math.radians( index )
    #config['room']['radiosity']['sample'] = 3 #int( (1 - math.cos(config['room']['radiosity']['angle']) ) / ( 1 - math.cos( config['room']['radiosity']['patch'] ) ) + 1 )
    #config['pigment']['rho'] = IceRayPy.type.color.RGB( 3.1415926, 3.1415926, 3.1415926 )
    #config['pigment']['sigma'] = IceRayPy.type.color.RGB( 10*t, 10*t, 10*t )
    #try:
    doRendering( config )
    #except:
    #    print("aaaaaaa", flush = True )


    print( 'garbage collector: get_threshold() ' + str( gc.get_threshold() ), flush = True  )
    print( 'garbage collector: get_count()     ' + str( gc.get_count()     ), flush = True  )
    print( 'garbage collector: collect()       ' + str( gc.collect()       ), flush = True  )
    print( 'garbage collector: get_count()    )' + str( gc.get_count()     ), flush = True  )
    print( 'garbage collector: get_threshold() ' + str( gc.get_threshold() ), flush = True  )


#time.sleep( 20 )

