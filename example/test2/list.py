import sys
import sys
import math
import os
import pathlib
from ctypes import *

import IceRayPy

from IceRayPy import core
from IceRayPy import utility

import composer
import room


camera_list = {
      'flat-Perspective'          : core.camera.flat.Perspective,
      #'flat-orthogonal'           : core.camera.flat.Orthogonal,
      #'flat-Super'                : core.camera.flat.Super,
      #'sphere-horizontal'         : core.camera.sphere.Horizontal,
      #'sphere-vertical'           : core.camera.sphere.Vertical,
      #'sphere-fisheye'            : core.camera.sphere.Fisheye,
      #'cylinder-vertical'         : core.camera.cylinder.Vertical,
      #'cylinder-horizontal'       : core.camera.cylinder.Horizontal,
      #'invert-cylinder-vertical'  : core.camera.transform.Invert,
     }

light_list = {
       #'dark'       : light.dark.unit.make,
       #'point'      : core.light.Point ,
       #'reflector'  : core.light.Reflector ,
       #'sunPoint'   : utility.light.sun.general.point,
       #'sunSpot'    : utility.light.sun.spot,
       #'sunArea'    : utility.light.sun.general.area,
       #'sunLine'    : utility.light.sun.general.line,
       #'sunCircle'  : utility.light.sun.general.circle,
       #'sunDisc'    : utility.light.sun.general.disc,
       #'line'       : core.light.Line,
       #'spline'     : core.light.Spline ,
       'circle'     : core.light.Circle ,
       #'area'       : core.light.Area ,
       #'disc'       : core.light.Disc,
       #'confine'       : core.light.Confine,
       #'sphere'     : util.light.sphere.unit.make,
       #'chandelier-H'  : util.light.chandelier.unit.hexa,
       #'chandelier-T'  : util.light.chandelier.unit.tetra,
       #'chandelier-O'  : util.light.chandelier.unit.octa
    }

medium_list = {
      'constant'      : core.material.medium.Constant,
      #'exponential'   : core.material.medium.Exponential,
      #'constant'      : core.material.medium.Linear,
      #'quadratic'     : core.material.medium.Quadratic,
    }

geometry_list = {
      #'simple-usphere'    : core.geometry.simple.USphere,
      #'simple-box'           : core.geometry.simple.Box,
      #'simple-Cone'           : core.geometry.simple.Cone,
      #'simple-Cylinder'           : core.geometry.simple.Cylinder,
      #'simple-Disc'           : core.geometry.simple.Disc,
      #'simple-Ellipsoid'           : core.geometry.simple.Ellipsoid,
      #'simple-Hyperboloid'           : core.geometry.simple.Hyperboloid,
      #'simple-Paraboloid'           : core.geometry.simple.Paraboloid,
      #'simple-Plane'           : core.geometry.simple.Plane,
      #'simple-Quadric'           : core.geometry.simple.Quadric,
      #'simple-Torus'           : core.geometry.simple.Torus,
      #'simple-Triangle'           : core.geometry.simple.Triangle,
      #'simple-Saddle'           : core.geometry.simple.Saddle,
      #'simple-ucylinder'    : core.geometry.simple.UCylinder,
      'simple-USphere'    : core.geometry.simple.USphere,
      #'complex-Intersect'    : core.geometry.complex.Intersect,
      #'complex-Enclose'    : core.geometry.complex.Enclose,
      #'transform-Identity'    : core.geometry.transform.Identity,
      #'transform-Translate'   : core.geometry.transform.Translate,
      #'transform-Affine'     : core.geometry.transform.Affine,
      #'volumetric-Vacuum'     : core.geometry.volumetric.Vacuum,
      #'volumetric-Mist'     : core.geometry.volumetric.Mist,
      #'volumetric-Smoke'     : core.geometry.volumetric.Smoke
     }

pigment_list = {
      #'default'                 : core.material.pigment.Constant,
      #'surface'                 : core.material.pigment.Surface,
      #'pattern-image'           : utility.material.pattern.Image,
       #'pattern-checker'         : utility.material.pattern.Checker,
       #'pattern-hexagon'         : utility.material.pattern.Hexagon,
       #'illumination-ambient'    : utility.material.illumination.Ambient,
       'illumination-lambert'    : utility.material.illumination.Lambert,
       #'illumination-phong'      : utility.material.illumination.Phong,
       #'illumination-ALP'        : utility.material.illumination.Alp,
       #'mapping-ID'         : utility.material.operation.mapping.Identity,
       #'mapping-Cartesian2Cylindric'        : utility.material.operation.mapping.Cartesian2Cylindric,
       #'mapping-Cartesian2Package'        : utility.material.operation.mapping.Cartesian2Package,
       #'mapping-Cartesian2Spherical'        : utility.material.operation.mapping.Cartesian2Spherical,
       #'mapping-Cartesian2Torus'        : utility.material.operation.mapping.Cartesian2Torus,
       #'mapping-Cartesian2Tablecloth'        : utility.material.operation.mapping.Cartesian2Tablecloth,
       #'mapping-Cartesian2WoodX'        : utility.material.operation.mapping.Cartesian2WoodX,
       #'mapping-Cartesian2WoodY'        : utility.material.operation.mapping.Cartesian2WoodY,
       #'mapping-Cartesian2WoodZ'        : utility.material.operation.mapping.Cartesian2WoodZ,
       #'mapping-Cylindric2Cartesian'        : utility.material.operation.mapping.Cylindric2Cartesian,
       #'mapping-Cylindric2Spherical'        : utility.material.operation.mapping.Cylindric2Spherical,
       #'mapping-Spherical2Cartesian'        : utility.material.operation.mapping.Spherical2Cartesian,
       #'mapping-Spherical2Cylindric'        : utility.material.operation.mapping.Spherical2Cylindric,
       #'mapping-Euclid2Max'        : utility.material.operation.mapping.Euclid2Max,
       #'mapping-Max2Euclid'        : utility.material.operation.mapping.Max2Euclid,
       #'mapping-Cartesian2Fisheye'        : utility.material.operation.mapping.Cartesian2Fisheye
    }

room_list = {
      #'vacuum'    : room.vacuum,
      'plane'     : room.plane,
      #'cornel'    : room.cornel
    }


def doRendering(P_config):
    folder = P_config['folder']

    for key_room, data_room in room_list.items():
       for key_camera, data_camera in camera_list.items():
           for key_geometry, data_geometry in geometry_list.items():
               for key_pigment, data_pigment in pigment_list.items():
                   for key_light, data_light in light_list.items():
                       name = key_room +"-"+ key_camera +'-'+ key_geometry +"-"+ key_pigment+"-" + key_light
                       filen_name = folder + "\\" + name + '_'+ "{:04d}".format(P_config['index']) + '.ppm'

                       my_file = pathlib.Path(filen_name)
                       if my_file.is_file():
                           print ( filen_name )
                           continue

                       geometry = data_geometry( P_config['dll'] )

                       light_the = data_light( P_config['dll'] )

                       light_enclose = core.light.transform.Translate( P_config['dll'], light_the, IceRayPy.type.math.coord.Scalar3D( 0, 0, 2 ) )
                       light_blocked = core.light.Obstruct( P_config['dll'], light_enclose, geometry );
                       light_final = light_blocked

                       pigment = data_pigment( P_config['dll'], light_enclose, geometry )
                       medium = medium_list['constant']( P_config['dll'] )
                       object = composer.object( P_config['dll'], geometry, pigment, medium )

                       camera = composer.camera( P_config['dll'], data_camera( P_config['dll'] ), P_config['camera']['eye'], P_config['camera']['view'] )

                       room = data_room( P_config['dll'], P_config['room'], light_final, geometry )

                       scene = composer.arange( P_config['dll'], object, room )

                       picture = IceRayPy.type.graph.Picture(P_config['dll'])
                       picture.size( P_config['picture']['width'], P_config['picture']['height'] )

                       manager = composer.manager( P_config, camera, scene )

                       manager.start( picture )

                       crop  = IceRayPy.type.graph.Picture( P_config['dll'])

                       A = IceRayPy.type.math.coord.Size2D( P_config['window']['A']['x'], P_config['window']['A']['y'] )
                       B = IceRayPy.type.math.coord.Size2D( P_config['window']['B']['x'], P_config['window']['B']['y'] )

                       IceRayPy.type.graph.Crop( P_config['dll'], crop, picture, A, B )

                       crop.storePNM( filen_name )

                       P_config['dll'].IceRayC_Utility_Random_Table_Next()

                       #break
                   #break
               #break
           #break

start = 0;
if( 1 < len( sys.argv ) ):
    start = int( sys.argv[1] )

step = 1
if( 2 < len( sys.argv ) ):
    step  = int( sys.argv[2] )

config={}
config['folder'] = '_out'
config['dll'] = cdll.LoadLibrary(r"z:\work\code\cpp\prj\github\IceRay\work\bin\IceRayCDLL-x86-Release\IceRayCDLL-1.0.0.0-dynamic.dll")
config['index'] = 0

config['picture'] = {}
config['picture']['width']  = int( 900 )
config['picture']['height'] = int( 900 )

config['camera'] = {}
config['camera']['width']  = 1
config['camera']['height'] = config['picture']['height'] / config['picture']['width']

config['camera']['eye'] = IceRayPy.type.math.coord.Scalar3D(  0, 4, 0.5 )
config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )

config['ray-trace']={}
config['ray-trace']['depth'] = 12
config['ray-trace']['trash'] = 0.001
config['hot'] = {}
config['hot']['x'] = 256
config['hot']['y'] = 221

config['window'] = {}
config['window'] = {}
config['window']['A'] = {}
config['window']['B'] = {}
config['window']['A']['x'] = 0
config['window']['A']['y'] = int( config['picture']['height'] * 0.834 * 0 )
config['window']['B']['x'] = int( config['picture']['width'] )
config['window']['B']['y'] = int( config['picture']['height'] * 0.836 / 0.836 )

config['room'] = {}

for index in range( start, 360, step ):

    config['index'] = index
    t = index/360.0
    alpha = t * ( 2 * 3.1415926 ) * 0

    height =     ( math.cos( 2* alpha ) + 1 )/2 ;
    height = 3 * ( math.cos(    alpha ) + 1 )/2 *  height;

    x = 2 * math.cos( alpha );
    y = ( 3*( math.cos( alpha ) +1)/2 + 1 ) * math.sin( alpha );
    config['camera']['eye'] = IceRayPy.type.math.coord.Scalar3D( x*0.8, y*0.8, height*0.8 );
    config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )

    print( "Index:" + str(index) + "[" + os.getcwd() + "]" )
    doRendering( config )

