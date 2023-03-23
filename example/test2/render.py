#!/usr/bin/env python3

import sys
import time
import math
import os

import pathlib

import IceRayPy

import composer

def doIt( P_dll, P_picture, P_scene, P_inventory, P_config ):

    I_light = {}
    I_camera = {}
    I_geometry = {}
    I_pigment = {}
    I_medium = {}
    I_decoration = {}
    I_room = {}

    I_room      ['name'] = P_scene['room']
    I_camera    ['name'] = P_scene['camera']
    I_geometry  ['name'] = P_scene['geometry']
    I_medium    ['name'] = P_scene['medium']
    I_pigment   ['name'] = P_scene['pigment']
    I_light     ['name'] = P_scene['light']
    I_decoration['name'] = P_scene['decoration']

    I_prefix = ''
    if( 'prefix' in P_picture ):
        I_prefix = P_picture['prefix']
    P_picture['temp'] = {}
    P_picture['temp']['name'] = I_room['name'] +"_"+ I_camera['name'] +'_'+ I_geometry['name'] +"_"+ I_medium['name']  +"_"+ I_pigment['name']+"_" + I_light['name']
    P_picture['temp']['file'] =  P_picture['folder'] + "/" + I_prefix + P_picture['temp']['name'] + '_'+ "{:04d}".format( P_picture['index'] ) + '.' + P_picture['extension']

    print( P_picture['temp']['file'], flush = True  )

    my_file = pathlib.Path( P_picture['temp']['file'] )
    if my_file.is_file():
        return

    I_geometry['the'] = P_inventory['geometry'][ I_geometry['name'] ]( P_dll )
    I_light['the']    = P_inventory['light'   ][ I_light   ['name'] ]( P_dll, P_config['light'] )
    I_medium['the']   = P_inventory['medium'  ][ I_medium  ['name'] ]( P_dll )
    I_camera['the']   = P_inventory['camera'  ][ I_camera  ['name'] ]( P_dll, P_config['camera'] )

    I_light['enclose'] = light_enclose = IceRayPy.core.light.transform.Translate( P_dll, I_light['the'], IceRayPy.type.math.coord.Scalar3D( 0, 0, 2 ) )
    I_light['blocked'] = IceRayPy.core.light.Obstruct( P_dll, I_light['enclose'], I_geometry['the'] );
    I_light['final']   = I_light['blocked']

    if( 'composer' not in P_config ):
        P_config['composer'] = {}
    P_config['composer']['light']            = I_light['enclose']
    P_config['composer']['geometry']         = I_geometry['the']

    if( 'pigment' not in P_config['composer'] ):
        P_config['composer']['pigment'] = {}

    P_config['composer']['pigment']['light'] = I_light['enclose']

    P_config['pigment']['light'] = I_light['final']
    I_pigment['the']  = P_inventory['pigment' ][ I_pigment ['name'] ]( P_dll, P_config['pigment'] )

    object = composer.object( P_dll, I_geometry['the'], I_pigment['the'], I_medium['the'] )

    I_camera['final'] = composer.camera( P_dll, I_camera['the'], P_config['camera'] )

    I_room['the'] = P_inventory['room'][ I_room['name'] ]( P_dll, P_config['room'], I_light['final'], I_geometry['the'] )

    I_decoration['the'] = P_inventory['decoration'][ I_decoration['name'] ](  P_dll, P_config['decoration'], I_light['final'], object )
    scene = composer.arange( P_dll, object, I_room['the'], I_decoration['the'] )

    P_picture['temp']['object'] = IceRayPy.type.graph.Picture( P_dll )
    P_picture['temp']['object'].size( P_picture['width'], P_picture['height'] )

    manager = composer.manager( P_dll, P_config['composer'], I_camera['final'], scene )
    print( "picture:" + str(P_picture), flush = True )
    print( "config:"  + str(P_config),  flush = True )
    print( "scene:"   + str(P_scene),   flush = True )
    start = time.time()
    manager.start( P_picture['temp']['object'] )
    delta = time.time() - start
    print( "Time:" + str( delta ), flush = True )

    P_picture['temp']['crop']  = IceRayPy.type.graph.Picture( P_dll )

    A = IceRayPy.type.math.coord.Size2D( P_picture['window']['A']['x'], P_picture['window']['A']['y'] )
    B = IceRayPy.type.math.coord.Size2D( P_picture['window']['B']['x'], P_picture['window']['B']['y'] )

    IceRayPy.type.graph.Crop( P_picture['temp']['crop'], P_picture['temp']['object'], A, B )
    #if( 'watermark' in P_picture ):
    #IceRayPy.type.graph.Print( P_picture['temp']['crop'], Size2D(0,0), P_picture['watermark'] )

    #P_picture['temp']['crop'].store( P_picture['temp']['file'] )

    if( 'pnm' == P_picture['extension'] ):
        P_picture['temp']['crop'].storePNM( P_picture['temp']['file'] )
    if( 'png' == P_picture['extension'] ):
        P_picture['temp']['crop'].storePNG( P_picture['temp']['file'] )
    if( 'jpeg' == P_picture['extension'] ):
        P_picture['temp']['crop'].storeJPEG( P_picture['temp']['file'] )

    P_dll.IceRayC_Utility_Random_Table_Next()



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

I_picture['folder'] = './_out'
I_picture['extension'] = 'png'

I_picture['index'] = 0
I_picture['time'] = 123.123


I_picture['window'] = {}
I_picture['window']['A'] = {}
I_picture['window']['A']['x'] = 0
I_picture['window']['A']['y'] = 0
I_picture['window']['B'] = {}
I_picture['window']['B']['x'] = I_picture['width']
I_picture['window']['B']['y'] = I_picture['height']

I_scene = {}
I_scene['room']       = 'C-close'
I_scene['camera']     =  'F-persp'
I_scene['geometry']   = 'F-box'
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'I-ALP'
I_scene['light']      = 'point'
I_scene['decoration'] = 'vacuum'


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

I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( 1, 2, 3 )
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )

if __name__ == "__main__":
    doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
