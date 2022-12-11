#!/usr/bin/env python3

import sys
import time
import math
import os
import platform
import pathlib
import inspect
import types
import gc
from ctypes import *

import IceRayPy

from IceRayPy import core
from IceRayPy import utility
from IceRayPy import library


import composer
import room
import decoration



camera_list = {
       'F-persp'        : core.camera.flat.Perspective,
       #'F-orth'         : core.camera.flat.Orthogonal,
       #'F-super'        : core.camera.flat.Super,
       #'S-horizontal'   : core.camera.sphere.Horizontal,
       #'S-vertical'     : core.camera.sphere.Vertical,
       #'S-fisheye'      : core.camera.sphere.Fisheye,
       #'C-vertical'     : core.camera.cylinder.Vertical,
       #'C-horizontal'   : core.camera.cylinder.Horizontal,
       #'I-C-vertical'   : utility.camera.invert.CylinderVertical,
       #'P-C-vertical'   : utility.camera.pin.PinCylinderVertical,
       #'DOF-persp'      : core.camera.dof.Focus,
       #'DOF-cone'        : core.camera.dof.Cone,
       #'DOF-cylinder'    : core.camera.dof.Cylinder,
     }

light_list = {
        #'dark'       : core.light.Dark, # No light at all
        'point'      : core.light.Point,
        #'reflector'  : core.light.Reflector,
        #'line'       : core.light.Line,
        #'spline'     : core.light.Spline,
        #'circle'     : core.light.Circle,
        #'area'       : core.light.Area,
        #'disc'       : core.light.Disc,
        #'confine'    : core.light.Confine, # TODO it is dark
        #'t-id'         : core.light.transform.Identity,     # TODO NYI
        #'t-translate'  : core.light.transform.Translate,    # TODO NYI
        #'t-affine'     : core.light.transform.Affine,       # TODO NYI
        #'t-homography' : core.light.transform.Homography,   # TODO NYI

        #'sun-Point'   : utility.light.sun.Point, # TODO it is dark
        #'sun-Area'    : utility.light.sun.Area,
        #'sun-Line'    : utility.light.sun.Line,
        #'sun-Circle'  : utility.light.sun.Circle,
        #'sun-Disc'    : utility.light.sun.Disc
        #'sphere'     : utility.light.sphere.unit.make,    # TODO NYI
        #'chandelier-H'  : utility.light.chandelier.Hexa   # TODO NYI
        #'chandelier-T'  : utility.light.chandelier.Tetra, # TODO NYI
        #'chandelier-O'  : utility.light.chandelier.Octa   # TODO NYI
    }

medium_list = {
       'trans'      : core.material.medium.Transparent,
       #'solid'     : core.material.medium.Solid,
       #'const'     : core.material.medium.Constant,
       #'exp'       : core.material.medium.Exponential,
       #'linear'    : core.material.medium.Linear,
       #'quadratic' : core.material.medium.Quadratic,
    }

geometry_list = {
     'simple-sphere'        : core.geometry.simple.Sphere,
     #'simple-usphere'       : core.geometry.simple.USphere,
     #'simple-cylinder'      : core.geometry.simple.Cylinder,
     #'simple-box'           : core.geometry.simple.Box,
     #'simple-plane'         : core.geometry.simple.Plane,
     #'simple-torus'         : core.geometry.simple.Torus,
     #'simple-cone'          : core.geometry.simple.Cone,
     #'simple-disc'          : core.geometry.simple.Disc,
     #'simple-udisc'         : core.geometry.simple.UDisc,
     #'simple-ellipsoid'     : core.geometry.simple.Ellipsoid,
     #'simple-hyperboloid'   : core.geometry.simple.Hyperboloid,
     #'simple-paraboloid'    : core.geometry.simple.Paraboloid,
     #'simple-quadric'       : core.geometry.simple.Quadric,
     #'simple-triangle'      : core.geometry.simple.Triangle,
     #'simple-utriangle'     : core.geometry.simple.UTriangle,
     #'simple-saddle'        : core.geometry.simple.Saddle,
     #'simple-ucylinder'     : core.geometry.simple.UCylinder,
     #
     #'hyper-nuke'           : utility.geometry.simple.hyperboloid.Nuke,
     #'hyper-sphere'         : utility.geometry.simple.hyperboloid.Sphere,
     #'hyper-cone'           : utility.geometry.simple.hyperboloid.Cone,
     #'hyper-cylinder'       : utility.geometry.simple.hyperboloid.Cylinder,
     #'hyper-negative'       : utility.geometry.simple.hyperboloid.Negative,
     #
     #'complex-Intersect'    : core.geometry.complex.Intersect, #NYI
     #'complex-Enclose'      : core.geometry.complex.Enclose, #NYI
     #
     #'transform-identity'   : core.geometry.transform.Identity,
     #'transform-translate'  : core.geometry.transform.Translate,
     #'transform-affine'     : core.geometry.transform.Affine,
     #'transform-hgraphy'    : core.geometry.transform.Homography,
     #'transform-mblur'      : library.geometry.MotionBlur,
     #
     #'volumetric-Vacuum'    : core.geometry.volumetric.Vacuum,
     #'volumetric-Mist'      : core.geometry.volumetric.Mist,
     #'volumetric-Smoke'     : core.geometry.volumetric.Smoke,
     #'library-1m'           : library.geometry.OneM
     ##'library-intersect'     : library.geometry.Intersect NYI
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

     #'illum-ALP'           : utility.material.illumination.Alp,       # OK OK
     #'illum-ambient'       : utility.material.illumination.Ambient,   # OK OK TODO align with ALP
     #'illum-AsDiffuse'     : utility.material.illumination.AsDiffuse, # OK OK TODO align with ALP
     #'illum-AsSpecular'    : utility.material.illumination.AsSpecular,# OK OK TODO align with ALP
     #'illum-Beckmann'      : utility.material.illumination.Beckmann,  # OK Check again  TODO problem on terminator
     #'illum-Blinn'         : utility.material.illumination.Blinn,     # OK OK TODO fix color TODO problem on terminator
     #'illum-Gaussian'      : utility.material.illumination.Gaussian,  # OK OK TODO problem on terminator
     #'illum-HsLambert'     : utility.material.illumination.HsLambert, # OK OK TODO align with Alp
     #'illum-HsPhong'       : utility.material.illumination.HsPhong,   # OK OK TODO align with Alp
     #'illum-Lambert'       : utility.material.illumination.Lambert,   #OK OK  TODO align with ALP
     #'illum-ONf29'         : utility.material.illumination.ON_f29,       # TODO in progress
     #'illum-ONf30'         : utility.material.illumination.ON_f30,       # TODO in progress
     #'illum-ONYFP'         : utility.material.illumination.ON_Fujii_Proposed,     # OK OK TODO align with Alp
     #'illum-ONYFQ'         : utility.material.illumination.ON_Fujii_Qualitative,  # OK OK TODO align with ALP
     #'illum-ON-JvO'        : utility.material.illumination.ON_Ouwerkerk,  # OK OK TODO align with ???
     #'illum-Phong'         : utility.material.illumination.Phong,         # OK OK TODO align with ALP
     #'illum-WardApprox'    : utility.material.illumination.WardApprox,    # OK OK TODO align with ALP
     #'illum-WardIsotropic' : utility.material.illumination.WardIsotropic, # OK OK TODO align with ALP
     #'illum-WardReal'      : utility.material.illumination.WardReal,      # OK OK TODO align with ALP

     #'mapping-o-ID'                     : utility.material.operation.mapping.Identity3D,
     #'mapping-o-translate'              : utility.material.operation.mapping.Translate3D,
     #'mapping-o-affine'                 : utility.material.operation.mapping.Affine3D,
     #'mapping-o-homography'             : utility.material.operation.mapping.Homography3D,

     #'mapping-o-Cartesian2Cylindric'    : utility.material.operation.mapping.Cartesian2Cylindric,  #TODO check
     ##'mapping-o-Cartesian2Package'      : utility.material.operation.mapping.Cartesian2Package,    #TODO check
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

      #'T-0-reflect-One'               : utility.material.transmission.reflect.One,      #OK
      #'T-1-reflect-Schlick'           : utility.material.transmission.reflect.Schlick,  #OK
      #'T-2-reflect-blossom-Grid'      : utility.material.transmission.blossom.Grid,     #TODO edge bug
      'T-3-reflect-blossom-Hexagon'   : utility.material.transmission.blossom.Hexagon,  #CHECK
      #'T-4-reflect-blossom-trg'       : utility.material.transmission.blossom.Triangle, #OK
      ##'T-5-reflect-blossom-Pinwheel'  : utility.material.transmission.blossom.Pinwheel, #TODO
      #'T-6-reflect-blossom-Rand'      : utility.material.transmission.blossom.Random,   #OK
      #'T-7-reflect-blossom-VDC'       : utility.material.transmission.blossom.VDC,      #OK
      #'T-8-refract-Fresnel'           : utility.material.transmission.refract.Fresnel,  #OK
      #'T-9-refract-Snell'             : utility.material.transmission.refract.Snell,    #OK
      #'T-A-refract-Schlick'           : utility.material.transmission.refract.Schlick,  #OK
}

room_list = {
      #'vacuum'    : room.vacuum,
      #'plane'     : room.plane,
      #'plate'     : room.plate,
     #'R-M-box'    : room.mirror_box,
     # 'R-M-sphere' : room.mirror_sphere,
      #'CRNL'      : room.cornell,
      #'cornel-0pen'    : room.cornel_open,
      'cornel-close'    : room.cornel_close
    }

decoration_list = {
      'vacuum'    : decoration.vacuum,
      'ptrs'      : decoration.pointers,
    }
decoration_item = 'ptrs'

def doRendering(P_config):
    folder = P_config['folder']

    for key_room, data_room in room_list.items():
       for key_camera, data_camera in camera_list.items():
           for key_geometry, data_geometry in geometry_list.items():
            for key_medium, data_medium in medium_list.items():
                for key_pigment, data_pigment in pigment_list.items():
                   for key_light, data_light in light_list.items():
                       name = key_room +"-"+ key_camera +'-'+ key_geometry +"-"+ key_medium +"-"+ key_pigment+"-" + key_light
                       filen_name = folder + "/" + name + '_'+ "{:04d}".format(P_config['index']) + '.ppm'
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

                       camera = composer.camera( P_config['dll'], data_camera( P_config['dll'], P_config['camera'] ), P_config['camera'] )

                       room = data_room( P_config['dll'], P_config['room'], light_final, geometry )

                       scene = composer.arange( P_config['dll'], object, room, decoration_list[ decoration_item ](  P_config['dll'], {   }, light_final, object ) )

                       picture = IceRayPy.type.graph.Picture(P_config['dll'])
                       picture.size( P_config['picture']['width'], P_config['picture']['height'] )

                       manager = composer.manager( P_config, camera, scene )
                       start = time.time()
                       manager.start( picture )
                       delta = time.time() - start
                       print( "Time:" + str( delta ) )

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
       #break

start = 0;
if( 1 < len( sys.argv ) ):
    start = int( sys.argv[1] )

step = 1
if( 2 < len( sys.argv ) ):
    step = int( sys.argv[2] )

config={}
config['folder'] = '_out'

config['index'] = 0

config['picture'] = {}
config['picture']['width']  = int( 800 * 1 )
config['picture']['height'] = int( 800 * 1 )
#config['pixel']['type'] = 'basic'

config['camera'] = {}
config['camera']['angle-horizontal']  = 1
config['camera']['angle-vertical']    = 1 # 0.66666666666666666666666666666667 #config['picture']['height'] / config['picture']['width']
config['camera']['height']  = 1 * 0.8
config['camera']['width']   = 1 * 0.8 # 0.66666666666666666666666666666667 #config['picture']['height'] / config['picture']['width']
config['camera']['aspect']    = 1 # config['picture']['width'] / config['picture']['height']

config['camera']['eye']  = IceRayPy. type.math.coord.Scalar3D( 0, -3, 0 )
config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )

config['ray-trace']={}
config['ray-trace']['depth'] = 16
config['ray-trace']['trash'] = 1.0/10000.0
config['ray-trace']['next'] = 17000

config['hot'] = {}
config['hot']['x'] = 75 #int( (1024/2048) * config['picture']['width'] )
config['hot']['y'] = 200 * 1 #int( ( 692/2048) * config['picture']['height'] )

config['window'] = {}
config['window'] = {}
config['window']['A'] = {}
config['window']['B'] = {}
config['window']['A']['x'] = 0 * int( config['picture']['width']  * 0.333 )
config['window']['A']['y'] = 0 * int( config['picture']['height'] * 0.333 )
config['window']['B']['x'] =     int( config['picture']['width']  * 1 )
config['window']['B']['y'] =     int( config['picture']['height'] * 1 )

config['room'] = {}

print( os.getcwd(), flush = True  )
print( platform.system(), flush = True  )

dll_path = IceRayPy.system.SearchCDLL()

if 0 != len( dll_path ):
    config['dll'] = IceRayPy.system.LoadCDLL( dll_path )
else:
    print("Can not find DLL")
    time.sleep(200)

dilatation  = 1;

radiusX_lo = 1.2;
radiusX_hi = 3; #< sde whole position

#radiusY_lo = 3; #< default unit position
#radiusY_hi = 2;

heightHi = 2;
heightLo = 0;

output = os.popen('wmic process get description, processid').read()

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

I_picture   = IceRayPy.type.graph.Picture( config['dll'] )
I_picture.size( 256, 256 )
IceRayPy.type.graph.Default( I_picture )
I_picture.storePNM( "default_256.pnm" )


for index in range( start, 360 * int( dilatation ), step ):

    config['index'] = index
    t = index / 360.0 / dilatation
    #t = 0
    alpha = t * ( 2 * 3.1415926 )
    #alpha = math.radians( 57 )
    height = heightLo #+ ( math.sin( alpha - math.pi/2 )*0.5 + 0.5 )*( heightHi - heightLo );
    x =  math.cos( alpha - math.pi/2 )
    y =  math.sin( alpha - math.pi/2 )

    if( math.degrees(alpha) < 360 ):
        radiusS = radiusX_lo + ( ( math.degrees(alpha) - 270.0)/90.0)*( radiusX_hi - radiusX_lo )
        height = heightHi + ( ( math.degrees(alpha) -270.0)/90.0)*( heightLo - heightHi );

    if( math.degrees(alpha) < 270 ):
        radiusS = radiusX_lo
        height = heightHi ;

    if( math.degrees(alpha) < 180 ):
        radiusS = radiusX_hi + ( ( math.degrees(alpha) -90.0)/90.0)*( radiusX_lo - radiusX_hi )
        height = heightLo + ( ( math.degrees(alpha) -90.0)/90.0)*( heightHi - heightLo );

    if( math.degrees(alpha) < 90 ):
        radiusS = radiusX_hi
        height = heightLo

    x =  x * radiusS
    y =  y * radiusS

    # debg overide
    #x =  3
    #y =  0
    #height = 0

    config['camera']['eye']  = IceRayPy.type.math.coord.Scalar3D( x, y, height );
    config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
    print( math.degrees(alpha), " _ " ,  x, ",", y, ",", height, "  ", math.sqrt( x*x+ y*y ) )
    print( "Hot: ", config['hot'], flush = True  )
    print( "Index:" + str(index) + "[" + os.getcwd() + "]", flush = True  )

    doRendering( config )
    print(str( gc.get_threshold() )  )
    print(str( gc.get_count() )  )
    print(str( gc.collect() )  )
    print(str( gc.get_count() )  )


#time.sleep( 20 )

