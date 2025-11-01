#!/usr/bin/env python3

import time
import math
import os
import sys
import IceRayPy

import IceRayPy

import render

dll_path = IceRayPy.system.SearchCDLL( P_preferDebug = False )

if 0 != len( dll_path ):
    I_dll = IceRayPy.system.LoadCDLL( dll_path )
else:
    print("Can not find DLL")
    time.sleep(200)
    exit()


I_picture ={}
I_picture[ 'width']  = int( 1920*.25 )
I_picture['height']  = int( 1080*.25 )
I_picture['aspect']  = I_picture['width'] / I_picture['height']
I_picture['watermark'] = ""

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
I_picture['window']['B'] = {}
I_picture['window']['A']['x'] = int( 0.10 * I_picture['width'] )
I_picture['window']['B']['x'] = int( 0.90 * I_picture['width'] )
I_picture['window']['A']['y'] = int( 0.43 * I_picture['height'] )
I_picture['window']['B']['y'] = int( 0.47 * I_picture['height'] )

I_picture['model']={}
I_picture['model']['name'] = "./_out/sample/384x010.pnm"
I_picture['model']['name'] = "c:/work/code/cpp/prj/github/iceray/work/example/test2/_out/sample/384x010.pnm"
I_picture['model']['object'] = IceRayPy.type.graph.Picture( I_dll )
I_picture['model']['object'].load( I_picture['model']['name'] );

I_scene = {}
I_scene['room']       = 'C-close'
I_scene['camera']     = 'F-persp'
I_scene['geometry']   = 'vacuum'
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
I_config['geometry'] ={}
I_config['geometry']['expression']='sin(sqrt(x*x+y*y))'
I_config['geometry']['density']= 0.99

I_config['composer']={}
I_config['composer']['hot'] = {}
I_config['composer']['hot']['x'] = 400
I_config['composer']['hot']['y'] = 400
I_config['composer']['manager'] = {}
I_config['composer']['manager']['pixel'] = {}
I_config['composer']['manager']['pixel']['type'] = 'grid' # 'center', 'grid', 'random', 'sobol'
I_config['composer']['manager']['pixel']['size'] = 2
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
     #'V-vacuum',
     'V-Mist',
     #'V-Smoke',
 ]

I_config['camera']['eye']   = IceRayPy.type.math.coord.Scalar3D( p*g * math.cos( math.radians(90)), p*g* math.sin( math.radians(90)) , +g )

array_len = 44
chunck_len = 3

best_minimum = 100;
seed = 0;
for index in range(1,362885,1): #(0,)  1, 2, 5, 10, 20,50, 100, 200, 500, 1000,
    print("-----------------------------")
    I_picture['prefix'] = "%04i"%(index)
    I_config['geometry']['density']= 0.25
    I_config['geometry']['seed']= seed
    #I_config['composer']['manager']['pixel']['size'] = index
    for item in geometry_list :
        I_scene['geometry']= item
        I_picture['watermark'] = "" #"index" + " : " +str(index) 
        
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
        
        current_minimum = IceRayPy.type.graph.Compare( I_picture['temp']['crop'], I_picture['model']['object'] )
        if( 1000000 < seed ):
            seed -= 1000000
        if( 0 == ( index % 50) ):
            seed = seed + 1;
            seed += 1000000
            continue;
        if( 100 < seed ):
            seed = seed - 100;
        if( current_minimum < best_minimum ):
            seed += 1000000
            print( "OLD best_minimum: " +  str(best_minimum), flush=True )
            best_minimum  = current_minimum;   
            seed = seed + 1;
            print( "NEW best_minimum: " +  str(best_minimum), flush=True )
            I_picture['temp']['crop'].storePNM( "goodone.pnm")

        print(  "I: "+str(index)+ " S: " + str(seed )+ " - best_minimum: " +  str(best_minimum), flush=True  )
