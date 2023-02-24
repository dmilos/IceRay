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

    P_picture['temp']['name'] = I_room['name'] +"_"+ I_camera['name'] +'_'+ I_geometry['name'] +"_"+ I_medium['name']  +"_"+ I_pigment['name']+"_" + I_light['name']
    P_picture['temp']['file'] = P_picture['folder'] + "/" + P_picture['temp']['name'] + '_'+ "{:04d}".format( P_picture['frame']['index'] ) + '.' + P_picture['extension']

    print( P_picture['file'], flush = True  )

    my_file = pathlib.Path( P_picture['temp']['file'] )
    if my_file.is_file():
        return

    I_geometry['the'] = P_inventory['geometry'][ I_geometry['name'] ]( P_dll )
    I_light['the']    = P_inventory['light'   ][ I_light   ['name'] ]( P_dll )
    I_pigment['the']  = P_inventory['pigment' ][ I_pigment ['name'] ]( P_dll, P_config['pigment'] )
    I_medium['the']   = P_inventory['medium'  ][ I_medium  ['name'] ]( P_dll )
    I_camera['the']   = P_inventory['camera'  ][ I_camera  ['name'] ]( P_dll, P_config['camera'] )


    I_light['enclose'] = light_enclose = IceRayPy.core.light.transform.Translate( P_dll, I_light['the'], IceRayPy.type.math.coord.Scalar3D( 0, 0, 2 ) )
    I_light['blocked'] = IceRayPy.core.light.Obstruct( P_dll, I_light['enclose'], I_geometry['the'] );
    I_light['final']   = I_light['blocked']

    P_config['composer']['light']            = I_light['enclose']
    P_config['composer']['geometry']         = I_geometry['the']
    P_config['composer']['pigment']['light'] = I_light['enclose']

    object = composer.object( P_dll, I_geometry['the'], I_pigment['the'], I_medium['the'] )

    I_camera['final'] = composer.camera( P_dll, I_camera['the'], P_config['camera'] )

    I_room['the'] = P_inventory['room'][ I_room['name'] ]( P_dll, P_config['room'], I_light['final'], I_geometry['the'] )

    I_decoration['the'] = P_inventory['decoration'][ I_decoration['name'] ](  P_dll, {   }, I_light['final'], object )
    scene = composer.arange( P_dll, object, I_room['the'], I_decoration['the'] )

    P_picture['temp']['object'] = IceRayPy.type.graph.Picture( P_dll )
    P_picture['temp']['object'].size( P_picture['width'], P_picture['height'] )

    manager = composer.manager( P_config['composer'], I_camera['final'], scene )
    start = time.time()
    manager.start( P_picture['temp']['object'] )
    delta = time.time() - start
    print( "Time:" + str( delta ), flush = True )

    P_picture['temp']['crop']  = IceRayPy.type.graph.Picture( P_dll )

    A = IceRayPy.type.math.coord.Size2D( P_picture['window']['A']['x'], P_picture['window']['A']['y'] )
    B = IceRayPy.type.math.coord.Size2D( P_picture['window']['B']['x'], P_picture['window']['B']['y'] )

    IceRayPy.type.graph.Crop( P_dll, P_picture['temp']['crop'], P_picture['temp']['object'], A, B )

    P_picture['temp']['crop'].storePNM( P_picture['temp']['file'] )

    P_dll.IceRayC_Utility_Random_Table_Next()

