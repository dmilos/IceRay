#!/usr/bin/env python3

import time
import math
import os
import sys

import IceRayPy
import render

os.system('color')

running_in_visual_studio = "VisualStudioVersion" in os.environ
dll_path = IceRayPy.system.SearchCDLL( P_preferDebug = running_in_visual_studio )
if 0 != len( dll_path ):
    I_dll = IceRayPy.system.LoadCDLL( dll_path )
else:
    print("Can not find DLL")
    time.sleep(200)
    exit()


I_picture ={}
I_picture[ 'width']  = int( 1920/2 )
I_picture['height']  = int( 1080/2 )
I_picture['aspect']  = I_picture['width'] / I_picture['height']
I_picture['watermark'] = ""
I_picture['overwrite'] = True

I_begin = 0
if( 1 < len( sys.argv ) ):
    I_begin = int( sys.argv[1] )
    #I_picture[ 'width'] = int( sys.argv[1] )
    #I_picture['height'] = int( I_picture['width'] / I_picture['aspect'] )

try:
    os.mkdir( "_out" )
except OSError as e:
    pass
I_picture['folder'] = './_out'
I_picture['extension'] = 'png'

I_picture['index'] = 0
I_picture['time'] = 0

I_picture['window'] = {}
I_picture['window']['A'] = {}

I_picture['window']['A']['x'] = 0
I_picture['window']['A']['y'] = 0
I_picture['window']['B'] = {}
I_picture['window']['B']['x'] = I_picture['width']
I_picture['window']['B']['y'] = I_picture['height']

#I_picture['model']={}
#I_picture['model']['name'] = "./_out/sample/384x010.pnm"
#I_picture['model']['object'] = IceRayPy.type.graph.Picture( I_dll )
#I_picture['model']['object'].load( I_picture['model']['name'] );

I_scene = {}
I_scene['room']       = 'C-close'
I_scene['camera']     = 'F-persp'
I_scene['geometry']   = 'vacuum'
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'P-RgbCube'
I_scene['light']      = 'chand-nine'
I_scene['decoration'] = 'vacuum'


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
I_config['pigment']  = {  'lo' : IceRayPy.type.math.coord.Scalar3D( -1.0, -1.0, -1.0 ), 'hi' : IceRayPy.type.math.coord.Scalar3D( +1.0, +1.0, +1.0 ) }
I_config['camera']  = {}
I_config['room']   = {}
I_config['light']   = {}
I_config['light']['sample']   = 1
I_config['decoration']   = {}
I_config['geometry'] ={}
I_config['geometry']['expression']= 'abs( cos(x*5)*cos(y*5)*cos(z*5) )'
I_config['geometry']['expression']='(sin(20*(x*x+y*y+z*z))+1)/2'
I_config['geometry']['density']= 0.1

I_config['composer']={}
I_config['composer']['hot'] = {}
I_config['composer']['hot']['x'] = 400
I_config['composer']['hot']['y'] = 400
I_config['composer']['manager'] = {}
I_config['composer']['manager']['pixel'] = {}
I_config['composer']['manager']['pixel']['type'] = 'grid' # 'center', 'grid', 'random', 'sobol'
I_config['composer']['manager']['pixel']['size'] = 9
g = 1.22074408460575947536 #(math.sqrt(5)+1)/2

g = (math.sqrt(5)+1)/2  #1.6180339887498948482045868343656
p = 1.324717957244746025960908854
c = 1.22074408460575947536

I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( +c*p*g, +p*g , +g )
radius = 1 + 0*math.sqrt(  ( c*p*g* c*p*g ) + (p*g*p*g) );
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
I_config['camera']['sample'] = 1

print( "Magic number:" + str( c*p*g) )

#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )

geometry_list = [
      #'V-vacuum',
      #'V-Mist',
      'V-Smoke',
      #'F-box'  ,

 ]

for index in range( I_begin, 360, 1 ):
    I_config['camera'][ 'eye'] = library_path.looker( index/360.0 )
    I_picture['prefix'] = "%04i"%(index)
    I_picture['index'] = index
    for item in geometry_list :
        I_scene['geometry']= item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

def prepare_readme():
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_V-Mist_trans_P-gradientBW_chand-nine_0000.pnm',      I_picture['folder']+'/'+'volumetric_mist.pnm'   )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_V-Smoke_trans_P-gradientBW_chand-nine_0000.pnm',     I_picture['folder']+'/'+'volumetric_smoke.pnm'  )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_V-vacuum_trans_P-gradientBW_chand-nine_0000.pnm',    I_picture['folder']+'/'+'volumetric_vacuum.pnm' )

#prepare_readme()
