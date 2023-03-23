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
I_config['decoration']   = {}
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

geometry_list = [
     'Q-sphere'           ,
     'Q-sphereu'          ,
     'Q-cylinder'         ,
     'Q-cylinderu'        ,
     'Q-util-cylinder'    ,
     'Q-cone'             ,
     'Q-util-cone'        ,
     'Q-ellipsoid'        ,
     'Q-paraboloid'       ,
     'Q-util-paraboloid'  ,
     'Q-Q-defailt'        ,
     'Q-Q-sphere'         ,
     'Q-Q-cylinder'       ,
     'Q-Q-para'           ,
     'Q-Q-saddle'         ,
     'Q-Q-nuke'           ,
     'Q-Q-cone'           ,
     'Q-saddle'           ,
     'Q-hyper-nuke'       ,
     'Q-hyper-sphere'     ,
     'Q-hyper-cone'       ,
     'Q-hyper-cylinder'   ,
     'Q-hyper-negative'
 ]

for item in geometry_list :
    I_scene['geometry']= item
    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

import os
def prepare_readme():
    os.rename( I_picture['folder']+'/'+    'TODO.pnm'       , I_picture['folder']+'/'+'sphere.pnm' )
    os.rename( I_picture['folder']+'/'+    'TODO.pnm'       , I_picture['folder']+'/'+'cylinder.pnm' )
    os.rename( I_picture['folder']+'/'+    'TODO.pnm'       , I_picture['folder']+'/'+'cone.pnm' )
    os.rename( I_picture['folder']+'/'+    'TODO.pnm'       , I_picture['folder']+'/'+'ellipsoid.pnm' )
    os.rename( I_picture['folder']+'/'+    'TODO.pnm'       , I_picture['folder']+'/'+'hyper-nuke.pnm' )
    os.rename( I_picture['folder']+'/'+    'TODO.pnm'       , I_picture['folder']+'/'+'hyper-negative.pnm' )
    os.rename( I_picture['folder']+'/'+    'TODO.pnm'       , I_picture['folder']+'/'+'paraboloid.pnm' )
    os.rename( I_picture['folder']+'/'+    'TODO.pnm'       , I_picture['folder']+'/'+'saddle.pnm' )
