#!/usr/bin/env python3

import sys
import time
import math
import os
import pathlib
import inspect
import types
from ctypes import *

import IceRayPy

from IceRayPy import core
from IceRayPy import utility

import library_room


def doRendering(P_config): # P_folder, P_dll, P_eye, P_view
    print( __name__ +"::"+sys._getframe().f_code.co_name + "(" + str( sys._getframe().f_lineno ) + "): "  )
    folder = P_config['folder']

    name = "hello1"
    filen_name = folder + "/" + name + '_'+ "{:04d}".format(P_config['index']) + '.ppm'

    print( filen_name, flush = True  )

    my_file = pathlib.Path(filen_name)
    if my_file.is_file():
        return

    geometry = core.geometry.simple.Sphere( P_config['dll'] )
    light_the = core.light.Point( P_config['dll'] )

    light_enclose = core.light.transform.Translate( P_config['dll'], light_the, IceRayPy.type.math.coord.Scalar3D( 0, 0, 2 ) )
    light_blocked = core.light.Obstruct( P_config['dll'], light_enclose, geometry );
    light_final = light_blocked

    P_config['light'] = light_enclose

    pigment = utility.material.illumination.Alp( P_config['dll'], P_config )
    medium = core.material.medium.Transparent( P_config['dll'] )

    object = IceRayPy.core.object.Wrapper( P_config['dll'] )
    object.geometrySet( geometry )
    object.pigment( pigment )
    object.medium( medium )

    camera= IceRayPy.core.camera.transform.Affine( P_config['dll'] )
    camera.child( core.camera.flat.Perspective( P_config['dll'] ) )
    camera_up   = IceRayPy.type.math.coord.load3D( P_config['dll'], 0, 0, 1 )
    camera.toWorldSet( IceRayPy.type.math.affine.lookAt( P_config['dll'], P_config['camera']['eye'], P_config['camera']['view'], camera_up ) )

    room_object = library_room.cornel_close( P_config['dll'], P_config['room'], light_final, geometry )

    rtss = IceRayPy.core.geometry.rtss.Object( P_config['dll'] )

    list = IceRayPy.core.geometry.rtss.List( P_config['dll'] )

    rtss.rtss( list )
    rtss.push( IceRayPy.core.geometry.Pretender( P_config['dll'], room_object.cast2Geometry(),    room_object ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_config['dll'], object.cast2Geometry(), object ) )
    print( __name__ +"::"+sys._getframe().f_code.co_name + "(" + str( sys._getframe().f_lineno ) + "): "  )

    scene = IceRayPy.core.object.Wrapper( P_config['dll'] )
    scene.geometrySet( rtss )

    picture = IceRayPy.type.graph.Picture(P_config['dll'])
    picture.size( P_config['picture']['width'], P_config['picture']['height'] )

    manager = IceRayPy.utility.render.Manager( P_config['dll'] )
    manager.camera(camera )
    manager.object( scene )

    start = time.time()
    manager.start( picture )
    delta = time.time() - start

    print( "Time:" + str( delta ) )

    crop  = IceRayPy.type.graph.Picture( P_config['dll'])

    A = IceRayPy.type.math.coord.Size2D( P_config['window']['A']['x'], P_config['window']['A']['y'] )
    B = IceRayPy.type.math.coord.Size2D( P_config['window']['B']['x'], P_config['window']['B']['y'] )

    IceRayPy.type.graph.Crop( crop, picture, A, B )

    crop.storePNM( filen_name )

    P_config['dll'].IceRayC_Utility_Random_Table_Next()


start = 0;
if( 1 < len( sys.argv ) ):
    start = int( sys.argv[1] )

step = 1
if( 2 < len( sys.argv ) ):
    step  = int( sys.argv[2] )

config={}
config['folder'] = '_out'
config['index'] = 0

config['picture'] = {}
config['picture']['width']  = int( 256 * 1 )
config['picture']['height'] = int( 256 * 1 )

config['camera'] = {}
config['camera']['eye'] = IceRayPy. type.math.coord.Scalar3D(  0, 4, 0.5 )
config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )

config['window'] = {}
config['window']['A'] = {}
config['window']['B'] = {}
config['window']['A']['x'] = 0
config['window']['A']['y'] = int( config['picture']['height'] * 0.834 * 0 )
config['window']['B']['x'] = int( config['picture']['width'] )
config['window']['B']['y'] = int( config['picture']['height'] * 0.836 / 0.836 )

config['room'] = {}

config['dll'] = IceRayPy.system.LoadCDLL( IceRayPy.system.SearchCDLL() )

radiusX = 5;
radiusY = 3;

for index in range( start, 360, step ):

    config['index'] = index
    t = index/360.0
    alpha = t * ( 2 * 3.1415926 )

    height =     ( math.cos( 2* alpha ) + 1 )/2 ;

    height = 3 * ( math.cos(    alpha ) + 1 )/2 *  height;

    x =   radiusX * math.cos( alpha );
    y = ( radiusY*( math.cos( alpha ) +1)/2 + 1 ) * math.sin( alpha );
    config['camera']['eye']  = IceRayPy.type.math.coord.Scalar3D( x*0.8, y*0.8, height*0.8 );
    config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )

    print( "Index:" + str(index) + "[" + os.getcwd() + "]", flush = True  )
    doRendering( config )
    break
