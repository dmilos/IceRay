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

import composer
import room

camera_list = {
       'flat-perspective'          : core.camera.flat.Perspective,
      #'flat-orthogonal'           : core.camera.flat.Orthogonal,
      #'flat-super'                : core.camera.flat.Super,
      #'sphere-horizontal'         : core.camera.sphere.Horizontal,
      #'sphere-vertical'           : core.camera.sphere.Vertical,
      #'sphere-fisheye'            : core.camera.sphere.Fisheye,
      #'cylinder-vertical'         : core.camera.cylinder.Vertical,
      #'cylinder-horizontal'       : core.camera.cylinder.Horizontal,
      #'invert-cylinder-vertical'   : utility.camera.invert.CylinderVertical,
      #'dof-perspective'  : core.camera.dof.Focus,
     }

light_list = {
         'dark'       : core.light.Dark, # No light at all
        #'point'      : core.light.Point ,
        #'reflector'  : core.light.Reflector ,
        #'line'       : core.light.Line,
        #'spline'     : core.light.Spline ,
        #'circle'     : core.light.Circle ,
        #'area'       : core.light.Area ,
        #'disc'       : core.light.Disc,
        #'confine'    : core.light.Confine,
        #'t-id'         : core.light.transform.Identity,     # TODO NYI
        #'t-translate'  : core.light.transform.Translate,    # TODO NYI
        #'t-affine'     : core.light.transform.Affine,       # TODO NYI
        #'t-homography' : core.light.transform.Homography,   # TODO NYI

        #'sun-Point'   : utility.light.sun.Point,
        #'sun-Area'    : utility.light.sun.Area,
        #'sun-Line'    : utility.light.sun.Line,
        #'sun-Circle'  : utility.light.sun.Circle,
        #'sun-Disc'    : utility.light.sun.Disc,
        # #'sphere'     : utility.light.sphere.unit.make,    # TODO NYI
        # #'chandelier-H'  : utility.light.chandelier.Hexa,  # TODO NYI
        # #'chandelier-T'  : utility.light.chandelier.Tetra, # TODO NYI
        # #'chandelier-O'  : utility.light.chandelier.Octa   # TODO NYI
    }

light_radiosity_list = {
      #'vacuumacuum'    : core.geometry.volumetric.Vacuum,
       'box'   : utility.light.radiosity.Box,
    }


medium_list = {
       'transparent'   : core.material.medium.Transparent,
       #'solid'         : core.material.medium.Solid,
       #'constant'      : core.material.medium.Constant,
       #'exponential'   : core.material.medium.Exponential,
       #'linear'        : core.material.medium.Linear,
       #'quadratic'     : core.material.medium.Quadratic,
    }

geometry_list = {
      'simple-usphere'       : core.geometry.simple.USphere,
      #'simple-sphere'       : core.geometry.simple.Sphere,
      #'simple-box'           : core.geometry.simple.Box,
      #'simple-Cone'          : core.geometry.simple.Cone,
      #'simple-Cylinder'      : core.geometry.simple.Cylinder,
      #'simple-Disc'          : core.geometry.simple.Disc,
      #'simple-Ellipsoid'     : core.geometry.simple.Ellipsoid,
      #'simple-Hyperboloid'   : core.geometry.simple.Hyperboloid,
      #'simple-Paraboloid'    : core.geometry.simple.Paraboloid,
      #'simple-Plane'         : core.geometry.simple.Plane,
      #'simple-Quadric'       : core.geometry.simple.Quadric,
      #'simple-Torus'         : core.geometry.simple.Torus,
      #'simple-Triangle'      : core.geometry.simple.Triangle,
      #'simple-Saddle'        : core.geometry.simple.Saddle,
      #'simple-ucylinder'     : core.geometry.simple.UCylinder,
      #'hyper-nuke'           : utility.geometry.simple.hyperboloid.Nuke,
      #'hyper-sphere'         : utility.geometry.simple.hyperboloid.Sphere,
      #'hyper-cone'           : utility.geometry.simple.hyperboloid.Cone,
      #'hyper-cylinder'       : utility.geometry.simple.hyperboloid.Cylinder,
      #'hyper-negative'       : utility.geometry.simple.hyperboloid.Negative,
      #
      #'complex-Intersect'    : core.geometry.complex.Intersect,
      #'complex-Enclose'      : core.geometry.complex.Enclose,
      #
      #'transform-identity'   : core.geometry.transform.Identity,
      #'transform-translate'  : core.geometry.transform.Translate,
      #'transform-affine'     : core.geometry.transform.Affine,
      #'transform-homography' : core.geometry.transform.Homography,
      #
      #'volumetric-Vacuum'    : core.geometry.volumetric.Vacuum,
      #'volumetric-Mist'      : core.geometry.volumetric.Mist,
      #'volumetric-Smoke'     : core.geometry.volumetric.Smoke
     }

pigment_list = {
     #'constant'                 : utility.material.pattern.Constant,
     #'surface'                 : core.material.pigment.Surface,  # TODO NYI

     #'pattern-noise-cells'      : utility.material.pattern.noise.Cells,
     #'pattern-noise-crackle'    : utility.material.pattern.noise.Crackle,
     #'pattern-noise-perlin'     : utility.material.pattern.noise.Perlin,
     #'pattern-noise-random'     : utility.material.pattern.noise.Random,
     #'pattern-noise-value'      : utility.material.pattern.noise.Value,
     #'pattern-noise-vdc'        : utility.material.pattern.noise.VDC,
     #'pattern-image'            : utility.material.pattern.Image,
     #'pattern-checker'          : utility.material.pattern.Checker,
     #'pattern-hexagon'          : utility.material.pattern.Hexagon,
     #'pattern-onion'            : utility.material.pattern.Onion, #TODO check
     #'pattern-level'            : utility.material.pattern.Level, #TODO check

     #'illum-ALP'           : utility.material.illumination.Alp, # OK
     #'illum-ambient'       : utility.material.illumination.Ambient, # OK
     #'illum-AsDiffuse'     : utility.material.illumination.AsDiffuse,  # TODO
     #'illum-AsSpecular'    : utility.material.illumination.AsSpecular, # TODO
     #'illum-Beckmann'      : utility.material.illumination.Beckmann, # TODO problem on terminator
     #'illum-Blinn'         : utility.material.illumination.Blinn,    # TODO problem on terminator
     #'illum-Gaussian'      : utility.material.illumination.Gaussian, # TODO problem on terminator
     #'illum-HsLambert'     : utility.material.illumination.HsLambert, # TODO
     #'illum-HsPhong'       : utility.material.illumination.HsPhong,   # TODO problem on terminator
     #'illum-Lambert'       : utility.material.illumination.Lambert, #OK
     #'illum-OnF29'         : utility.material.illumination.OnF29,  # TODO
     #'illum-OnP44'         : utility.material.illumination.OnP44,  # TODO
     #'illum-OnYF'          : utility.material.illumination.OnYF,   # TODO
     #'illum-Phong'         : utility.material.illumination.Phong, #OK
     #'illum-WardApprox'    : utility.material.illumination.WardApprox,    # TODO
     #'illum-WardIsotropic' : utility.material.illumination.WardIsotropic, # TODO
     #'illum-WardReal'      : utility.material.illumination.WardReal,      # TODO

     #'mapping-o-ID'                     : utility.material.operation.mapping.Identity3D,
     #'mapping-o-translate'              : utility.material.operation.mapping.Translate3D,
     #'mapping-o-affine'                 : utility.material.operation.mapping.Affine3D,
     #'mapping-o-homography'             : utility.material.operation.mapping.Homography3D,

     #'mapping-o-Cartesian2Cylindric'    : utility.material.operation.mapping.Cartesian2Cylindric,  #TODO check
     #'mapping-o-Cartesian2Package'      : utility.material.operation.mapping.Cartesian2Package,    #TODO check
     #'mapping-o-Cartesian2Spherical'    : utility.material.operation.mapping.Cartesian2Spherical,  #TODO check
     #'mapping-o-Cartesian2Torus'        : utility.material.operation.mapping.Cartesian2Torus,      #TODO check
     #'mapping-o-Cartesian2Tablecloth'   : utility.material.operation.mapping.Cartesian2Tablecloth, #TODO check
     #'mapping-o-Cartesian2WoodX'        : utility.material.operation.mapping.Cartesian2WoodX,      #TODO check
     #'mapping-o-Cartesian2WoodY'        : utility.material.operation.mapping.Cartesian2WoodY,      #TODO check
     #'mapping-o-Cartesian2WoodZ'        : utility.material.operation.mapping.Cartesian2WoodZ,      #TODO check
     #'mapping-o-Cylindric2Cartesian'    : utility.material.operation.mapping.Cylindric2Cartesian,  #TODO check
     #'mapping-o-Cylindric2Spherical'    : utility.material.operation.mapping.Cylindric2Spherical,  #TODO check
     #'mapping-o-Spherical2Cartesian'    : utility.material.operation.mapping.Spherical2Cartesian,  #TODO check
     #'mapping-o-Spherical2Cylindric'    : utility.material.operation.mapping.Spherical2Cylindric,  #TODO check
     #'mapping-o-Euclid2Max'             : utility.material.operation.mapping.Euclid2Max,           #TODO check
     #'mapping-o-Max2Euclid'             : utility.material.operation.mapping.Max2Euclid,           #TODO check
     #'mapping-o-Cartesian2Fisheye'      : utility.material.operation.mapping.Cartesian2Fisheye,    #TODO check

     #'transmission-reflect-One'              : utility.material.transmission.reflect.One,      #OK
     #'transmission-reflect-Schlick'          : utility.material.transmission.reflect.Schlick,  #OK
     #'transmission-reflect-blossom-Hexagon'  : utility.material.transmission.blossom.Hexagon,  #OK
     #'transmission-reflect-blossom-Grid'     : utility.material.transmission.blossom.Grid,     #TODO
     #'transmission-reflect-blossom-Rand'     : utility.material.transmission.blossom.Random,   #OK
     #'transmission-reflect-blossom-VDC'      : utility.material.transmission.blossom.VDC,      #OK
      'transmission-refract-Arbitrary'        : utility.material.transmission.refract.Arbitrary,#TODO check
     #'transmission-refract-Fresnel'          : utility.material.transmission.refract.Fresnel,  #TODO
     #'transmission-refract-Snell'            : utility.material.transmission.refract.Snell,    #OK
     #'transmission-refract-Schlick'          : utility.material.transmission.refract.Schlick,  #OK
}

room_list = {
      #'vacuum'    : room.vacuum,
      #'plane'     : room.plane,
      #'plate'     : room.plate,
      #'cornell'   : room.cornell,
       'cornell_radiosity'   : room.cornell_radiosity,
      #'cornel'    : room.cornel_open,
      #'cornel'    : room.cornel_close
    }


def doRendering(P_config):
    folder = P_config['folder']

    for key_room, data_room in room_list.items():
       for key_camera, data_camera in camera_list.items():
           for key_geometry, data_geometry in geometry_list.items():
            for key_medium, data_medium in medium_list.items():
                for key_pigment, data_pigment in pigment_list.items():
                   for key_light, data_light in light_list.items():
                       name = key_room +"-"+ key_camera +'-'+ key_geometry +"-"+ key_medium +"-"+ key_pigment+"-" + key_light
                       filen_name = folder + "\\" + name + '_'+ "{:04d}".format(P_config['index']) + '.ppm'
                       print( filen_name, flush = True  )

                       my_file = pathlib.Path(filen_name)
                       if my_file.is_file():
                           continue

                       geometry = data_geometry( P_config['dll'] )

                       light_the = data_light( P_config['dll'] )

                       light_enclose = core.light.transform.Translate( P_config['dll'], light_the, IceRayPy.type.math.coord.Scalar3D( 0, 0, 2 ) )
                       light_blocked = core.light.Obstruct( P_config['dll'], light_enclose, geometry );
                       light_final = light_blocked

                       P_config['light'] = light_enclose
                       P_config['geometry'] = geometry

                       pigment = data_pigment( P_config['dll'], P_config )
                       medium = data_medium( P_config['dll'] )
                       object = composer.object( P_config['dll'], geometry, pigment, medium )

                       camera = composer.camera( P_config['dll'], data_camera( P_config['dll'] ), P_config['camera']['eye'], P_config['camera']['view'] )

                       room = data_room( P_config['dll'], P_config['room'], light_final, geometry )

                       scene = composer.arange( P_config['dll'], object, room, light_radiosity_list['box']( P_config['dll'] ) )

                       picture = IceRayPy.type.graph.Picture(P_config['dll'])
                       picture.size( P_config['picture']['width'], P_config['picture']['height'] )

                       manager = composer.manager( P_config, camera, scene )
                       start = time.time()
                       manager.start( picture )
                       delta = time.time() - start
                       print( "Time:" + str( delta ), flush = True )

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
#config['dll'] = cdll.LoadLibrary(r"z:\work\code\cpp\prj\github\IceRay\work\bin\IceRayCDLL-x86-Debug\IceRayCDLL-1.0.0.0-dynamic.dll")
config['index'] = 0

config['picture'] = {}
config['picture']['width']  = int( 256 * 2 )
config['picture']['height'] = int( 256 * 2 )

config['camera'] = {}
config['camera']['width']  = 1
config['camera']['height'] = config['picture']['height'] / config['picture']['width']

config['camera']['eye'] = IceRayPy. type.math.coord.Scalar3D(  0, 4, 0.5 )
config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )

config['ray-trace']={}
config['ray-trace']['depth'] = 4
config['ray-trace']['trash'] = 1.0/10000.0
config['ray-trace']['next'] = 17000
config['hot'] = {}
config['hot']['x'] = 256
config['hot']['y'] = 256

config['window'] = {}
config['window'] = {}
config['window']['A'] = {}
config['window']['B'] = {}
config['window']['A']['x'] = 0
config['window']['A']['y'] = int( config['picture']['height'] * 0.834 * 0 )
config['window']['B']['x'] = int( config['picture']['width'] )
config['window']['B']['y'] = int( config['picture']['height'] * 0.836 / 0.836 )

config['room'] = {}

radiusX = 5;
radiusY = 3;

for index in range( start, 360, step ):

    config['index'] = index
    t = 60/360.0 #t = index/360.0
    alpha = t * ( 2 * 3.1415926 )

    height =     ( math.cos( 2* alpha ) + 1 )/2 ;
    
    height = 3 * ( math.cos(    alpha ) + 1 )/2 *  height;

    x =   radiusX * math.cos( alpha );
    y = ( radiusY*( math.cos( alpha ) +1)/2 + 1 ) * math.sin( alpha );
    config['camera']['eye']  = IceRayPy.type.math.coord.Scalar3D( x*0.8, y*0.8, height*0.8 );
    config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )

    print( "Index:" + str(index) + "[" + os.getcwd() + "]" )
    doRendering( config )
