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

from IceRayPy import core
from IceRayPy import utility
from IceRayPy import library


import composer
import room
import decoration
import obseravtion
import signal
import faulthandler


gc.enable()
faulthandler.enable()

camera_list = {
    'F-persp'        : core.camera.flat.Perspective,
    'F-orth'         : core.camera.flat.Orthogonal,
    'F-super'        : core.camera.flat.Super,
    'S-horizontal'   : core.camera.sphere.Horizontal,
    'S-vertical'     : core.camera.sphere.Vertical,
    'S-fisheye'      : core.camera.sphere.Fisheye,
    'C-vertical'     : core.camera.cylinder.Vertical,
    'C-horizontal'   : core.camera.cylinder.Horizontal,
    'I-C-vertical'   : utility.camera.invert.CylinderVertical,
    'P-C-vertical'   : utility.camera.pin.PinCylinderVertical,
    'DOF-persp'       : core.camera.dof.Focus,
    'DOF-cone'        : core.camera.dof.Cone,
    'DOF-cylinder'    : core.camera.dof.Cylinder,
    }

light_list = {
        'dark'       : core.light.Dark, # No light at all
        point'      : core.light.Point,
        'reflector'  : core.light.Reflector,
        'line'       : core.light.Line,
        'spline'     : core.light.Spline, # TODO crash on Ubuntu
        'circle'     : core.light.Circle,
        'area'       : core.light.Area,
        'disc'       : core.light.Disc,
        #'confine'    : core.light.Confine, # TODO it is dark
        #'T-id'         : core.light.transform.Identity,     # TODO NYI
        #'T-translate'  : core.light.transform.Translate,    # TODO NYI
        #'T-affine'     : core.light.transform.Affine,       # TODO NYI
        #'T-homography' : core.light.transform.Homography,   # TODO NYI
        
        'sun-Point'   : utility.light.sun.Point, # TODO it is dark
        'sun-Area'    : utility.light.sun.Area,
        'sun-Line'    : utility.light.sun.Line,
        'sun-Circle'  : utility.light.sun.Circle,
        'sun-Disc'    : utility.light.sun.Disc
        'sphere'     : utility.light.sphere.unit.make,    # TODO NYI
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
     'S-sphere'        : core.geometry.simple.Sphere,
     'S-usphere'       : core.geometry.simple.USphere,
     'S-cylinder'      : core.geometry.simple.Cylinder,
     'S-util-cylinder' : utility.geometry.simple.Cylinder,
     'S-box'           : core.geometry.simple.Box,
     'S-torus'         : core.geometry.simple.Torus,
     'S-util-torus'    : utility.geometry.simple.Torus,
     'S-cone'          : core.geometry.simple.Cone,
     'S-util-cone'     : utility.geometry.simple.Cone,
     'S-disc'          : core.geometry.simple.Disc,
     'S-udisc'         : core.geometry.simple.UDisc,
     'S-ellipsoid'     : core.geometry.simple.Ellipsoid,
     'S-hyperboloid'   : core.geometry.simple.Hyperboloid,
     'S-util-hyperboloid'   : utility.geometry.simple.Hyperboloid,
     'S-paraboloid'    : core.geometry.simple.Paraboloid,
     'S-util-paraboloid'    : utility.geometry.simple.Paraboloid,
     'S-quadric'       : core.geometry.simple.Quadric,
     'S-triangle'      : core.geometry.simple.Triangle,
     'S-triangleU'      : core.geometry.simple.TriangleU, #!< TODO
     'S-plane'         : core.geometry.simple.Plane,
     'S-triangleU'     : core.geometry.simple.triangleU,
     'S-saddle'        : core.geometry.simple.Saddle,
     'S-cylinderu'     : core.geometry.simple.CylinderU,

     'hyper-nuke'           : utility.geometry.simple.hyperboloid.Nuke,
     'hyper-sphere'         : utility.geometry.simple.hyperboloid.Sphere,
     'hyper-cone'           : utility.geometry.simple.hyperboloid.Cone,
     'hyper-cylinder'       : utility.geometry.simple.hyperboloid.Cylinder,
     'hyper-negative'       : utility.geometry.simple.hyperboloid.Negative,

     'C-I-i-i'    : library.geometry.example.Intersect_IN_IN,
     'C-I-i-o'    : library.geometry.example.Intersect_IN_OUT,
     'C-I-i-s'    : library.geometry.example.Intersect_IN_SURFACE,
     'C-I-o-i'    : library.geometry.example.Intersect_OUT_IN,
     'C-I-o-o'    : library.geometry.example.Intersect_OUT_OUT,
     'C-I-o-s'    : library.geometry.example.Intersect_OUT_SURFACE,
     'C-I-s-i'    : library.geometry.example.Intersect_SURFACE_IN,
     'C-I-s-o'    : library.geometry.example.Intersect_SURFACE_OUT,
     'C-I-s-s'    : library.geometry.example.Intersect_SURFACE_SURFACE,

     #'C-Enclose'      : core.geometry.complex.Enclose, #NYI

     'C-hfieldI'      : library.geometry.hfield.Image,
     'C-hfieldLE'      : library.geometry.hfield.Expression, #NYI
     'C-hfieldT2x2'    : library.geometry.hfield.Table2x2,
     'C-hfieldT3x3'    : library.geometry.hfield.Table3x3,
     'C-hfieldT4x4'    : library.geometry.hfield.Table4x4,
     'C-hfieldT30x30'   : library.geometry.hfield.Table5x5,

     'T-identity'   : core.geometry.transform.Identity,
     'T-translate'  : core.geometry.transform.Translate,
     'T-affine'     : core.geometry.transform.Affine,
     'T-hgraphy'    : core.geometry.transform.Homography,
     'T-mblur'      : library.geometry.MotionBlur,

     'T-lensCS'      : library.geometry.lens.concave.Symetric,
     'T-lensCP'      : library.geometry.lens.concave.Plano,
     'T-lensVS'      : library.geometry.lens.convex.Symetric,
     'T-lensVP'      : library.geometry.lens.convex.Plano,

     'T-lensPCvA'      : library.geometry.example.IntersectGeneral,
     'T-lensPCvB'      : library.geometry.LensBiconcaveB,
     'T-lensPCvC'      : library.geometry.LensBiconcaveC,
     'T-lensPCvD'      : library.geometry.LensBiconcaveD,

     'V-Vacuum'    : core.geometry.volumetric.Vacuum,
     'V-Mist'      : core.geometry.volumetric.Mist,
     'V-Smoke'     : core.geometry.volumetric.Smoke,
     'library-1m'           : library.geometry.OneM,
     # NYI 'library-intersect'    : library.geometry.Intersect
     }

pigment_list = {
      'constant'                 : utility.material.pattern.Constant,
      # TODO NYI 'surface'                 : core.material.pigment.Surface,

      'P-noise-cells'      : utility.material.pattern.noise.Cells,
      'P-noise-crackle'    : utility.material.pattern.noise.Crackle,
      'P-noise-perlin'     : utility.material.pattern.noise.Perlin,
      'P-noise-random'     : utility.material.pattern.noise.Random,
      'P-noise-value'      : utility.material.pattern.noise.Value,
      'P-noise-vdc'        : utility.material.pattern.noise.VDC,
      'P-image'            : utility.material.pattern.Image,
      'P-checker'          : utility.material.pattern.Checker,
      'P-hexagon'          : utility.material.pattern.Hexagon,
      'P-onion'            : utility.material.pattern.Onion, #TODO check
      'P-level'            : utility.material.pattern.Level, #TODO check
      'P-gradient'         : utility.material.pattern.Gradient,

      'I-ALP'           : utility.material.illumination.Alp,       # OK OK
      'I-ambient'       : utility.material.illumination.Ambient,   # OK OK TODO align with ALP
      'I-AsDiffuse'     : utility.material.illumination.AsDiffuse, # OK OK TODO align with ALP
      'I-AsSpecular'    : utility.material.illumination.AsSpecular,# OK OK TODO align with ALP
      'I-Beckmann'      : utility.material.illumination.Beckmann,  # OK Check again  TODO problem on terminator
      'I-Blinn'         : utility.material.illumination.Blinn,     # OK OK TODO fix color TODO problem on terminator
      'I-Gaussian'      : utility.material.illumination.Gaussian,  # OK OK TODO problem on terminator
      'I-HsLambert'     : utility.material.illumination.HsLambert, # OK OK TODO align with Alp
      'I-HsPhong'       : utility.material.illumination.HsPhong,   # OK OK TODO align with Alp
      'I-Lambert'       : utility.material.illumination.Lambert,   #OK OK  TODO align with ALP
      'I-ONf29'         : utility.material.illumination.ON_f29,       # TODO in progress
      'I-ONf30'         : utility.material.illumination.ON_f30,        # TODO in progress
      'I-ONYFP'         : utility.material.illumination.ON_Fujii_Proposed,     # OK OK TODO align with Alp
      'I-ONYFQ'         : utility.material.illumination.ON_Fujii_Qualitative,  # OK OK TODO align with ALP
      'I-ONJvO'         : utility.material.illumination.ON_Ouwerkerk,  # OK OK TODO align with ???
      'I-Phong'         : utility.material.illumination.Phong,         # OK OK TODO align with ALP
      'I-WardApprox'    : utility.material.illumination.WardApprox,    # OK OK TODO align with ALP
      'I-WardIsotropic' : utility.material.illumination.WardIsotropic, # OK OK TODO align with ALP
      'I-WardReal'      : utility.material.illumination.WardReal,      # OK OK TODO align with ALP

     'M-o-ID'                     : utility.material.operation.mapping.Identity3D,
     'M-o-translate'              : utility.material.operation.mapping.Translate3D,
     'M-o-affine'                 : utility.material.operation.mapping.Affine3D,
     'M-o-homography'             : utility.material.operation.mapping.Homography3D,
     'M-o-Cartesian2Cylindric'    : utility.material.operation.mapping.Cartesian2Cylindric,  #TODO check
     'M-o-Cartesian2Package'      : utility.material.operation.mapping.Cartesian2Package,    #TODO check
     'M-o-Cartesian2Spherical'    : utility.material.operation.mapping.Cartesian2Spherical,  #TODO check
     'M-o-Cartesian2Torus'        : utility.material.operation.mapping.Cartesian2Torus,      #TODO check
     'M-o-Cartesian2Tablecloth'   : utility.material.operation.mapping.Cartesian2Tablecloth, #TODO check
     'M-o-Cartesian2WoodX'        : utility.material.operation.mapping.Cartesian2WoodX,      #TODO check
     'M-o-Cartesian2WoodY'        : utility.material.operation.mapping.Cartesian2WoodY,      #TODO check
     'M-o-Cartesian2WoodZ'        : utility.material.operation.mapping.Cartesian2WoodZ,      #TODO check
     'M-o-Cylindric2Cartesian'    : utility.material.operation.mapping.Cylindric2Cartesian,  #TODO check
     'M-o-Cylindric2Spherical'    : utility.material.operation.mapping.Cylindric2Spherical,  #TODO check
     'M-o-Spherical2Cartesian'    : utility.material.operation.mapping.Spherical2Cartesian,  #TODO check
     'M-o-Spherical2Cylindric'    : utility.material.operation.mapping.Spherical2Cylindric,  #TODO check
     'M-o-Euclid2Max'             : utility.material.operation.mapping.Euclid2Max,           #TODO check
     'M-o-Max2Euclid'             : utility.material.operation.mapping.Max2Euclid,           #TODO check
     'M-o-Cartesian2Fisheye'      : utility.material.operation.mapping.Cartesian2Fisheye,    #TODO check

     'T-0-reflect-One'               : utility.material.transmission.reflect.One,      #OK
     'T-0-reflect-mirror'            : utility.material.transmission.reflect.Mirror,      #OK
     'T-1-reflect-schlick'           : utility.material.transmission.reflect.Schlick,  #OK
     'T-2-reflect-blossom-Grid'      : utility.material.transmission.blossom.Grid,     #TODO edge bug
     'T-3-reflect-blossom-Hexagon'   : utility.material.transmission.blossom.Hexagon,  #CHECK
     'T-4-reflect-blossom-trg'       : utility.material.transmission.blossom.Triangle, #OK
     #'T-5-reflect-blossom-Pinwheel'  : utility.material.transmission.blossom.Pinwheel, #TODO
     #'T-5-reflect-blossom-penrose'  : utility.material.transmission.blossom.Penrose, #TODO
     'T-6-reflect-blossom-Rand'      : utility.material.transmission.blossom.Random,   #OK
     'T-7-reflect-blossom-VDC'       : utility.material.transmission.blossom.VDC,      #OK
     'T-8-refract-fresnel'           : utility.material.transmission.refract.Fresnel,  #OK
     'T-9-refract-Snell'             : utility.material.transmission.refract.Snell,    #OK
     'T-A-refract-schlick'           : utility.material.transmission.refract.Schlick,  #OK
}

room_list = {
      'vacuum'      : room.vacuum,
      'plane'       : room.plane,
      'plate'        : room.plate,
      'disc'        : room.disc
      'R-M-box'     : room.mirror_box,
       'R-M-sphere' : room.mirror_sphere,
      'C-radiosity' : room.cornell_radiosity,
      'C-0pen'      : room.cornel_open,
      'C-close'     : room.cornel_close
      'R-plane'     : room.radiosity_plane
    }
room_item = 'C-close'

decoration_list = {
      'vacuum'      : decoration.vacuum,
      'ptrs'        : decoration.pointers,
      #'ptrs-A'     : decoration.pointers,
      'radiosity'   : decoration.radiosity,
      'plate'       : decoration.plate
    }
decoration_item = 'vacuum'

path_list= {
        'default' : obseravtion.default,
        'debug' : obseravtion.debug,
        'circle'  : obseravtion.circle,
        'looker'  : obseravtion.looker
    }
path_item = 'looker'


GI_save_image_run = True
GI_save_image_image = True

def save_image( P_folder, P_name ):
    global GI_save_image_image
    print( "start:" + P_folder + "/"  + P_name + '.ppm'  )
    while( GI_save_image_run ):
        GI_save_image_image.storePNM( P_folder + "/"  + P_name + '.ppm' )
        time.sleep( 1 )
        print( P_folder + "/"  + P_name + '.ppm'  )
    print( "stop:" + P_folder + "/"  + P_name + '.ppm'  )
    print( P_folder + "/"  + P_name + '.ppm'  )

def render_light(P_config):
    for key_light, data_light in light_list.items():
        pass

def render_object_simple(P_config):
    for key_light, data_light in light_list.items():
        pass

def render_material_pattern(P_config):
    for key_light, data_light in light_list.items():
        pass

def render_material_illumination(P_config):
    for key_pigment, data_pigment in pigment_list.items():
        pass

def render_object_intersect(P_config):
    for key_pigment, data_pigment in pigment_list.items():
        pass

def render_object_hfield(P_config):
    for key_pigment, data_pigment in pigment_list.items():
        pass

def doRendering(P_config):
    folder = P_config['folder']

    global GI_save_image_run

    GI_save_image_run = False;
    global GI_save_image_image

    for key_room, data_room in room_list.items():
       for key_camera, data_camera in camera_list.items():
           for key_geometry, data_geometry in geometry_list.items():
            for key_medium, data_medium in medium_list.items():
                for key_pigment, data_pigment in pigment_list.items():
                   for key_light, data_light in light_list.items():
                       name = key_room +"_"+ key_camera +'_'+ key_geometry +"_"+ key_medium +"_"+ key_pigment+"_" + key_light
                       filen_name = folder + "/" + name + '_'+ "{:04d}".format( P_config['index'] ) + '.png'
                       print( filen_name, flush = True  )

                       my_file = pathlib.Path( filen_name )
                       if my_file.is_file():
                           continue

                       geometry = data_geometry( P_config['dll'] )

                       light_the = data_light( P_config['dll'] )

                       light_enclose = core.light.transform.Translate( P_config['dll'], light_the, IceRayPy.type.math.coord.Scalar3D( 0, 0, 2 ) )
                       light_blocked = core.light.Obstruct( P_config['dll'], light_enclose, geometry );
                       light_final = light_blocked

                       P_config['light'] = light_enclose
                       P_config['geometry'] = geometry
                       P_config['pigment']['light'] = light_enclose

                       pigment = data_pigment( P_config['dll'], P_config['pigment'] )
                       medium = data_medium( P_config['dll'] )
                       object = composer.object( P_config['dll'], geometry, pigment, medium )

                       camera = composer.camera( P_config['dll'], data_camera( P_config['dll'], P_config['camera'] ), P_config['camera'] )

                       room = data_room( P_config['dll'], P_config['room'], light_final, geometry )

                       scene = composer.arange( P_config['dll'], object, room, decoration_list[ decoration_item ](  P_config['dll'], {   }, light_final, object ) )

                       GI_save_image_image = IceRayPy.type.graph.Picture( P_config['dll'] )
                       GI_save_image_image.size( P_config['picture']['width'], P_config['picture']['height'] )

                       manager = composer.manager( P_config, camera, scene )
                       #print("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", flush = True)
                       #thread = threading.Thread( target= save_image, args=(folder, "temporal-image" ) )
                       GI_save_image_run = True
                       #thread.start()
                       #print("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", flush = True)
                       start = time.time()
                       manager.start( GI_save_image_image )
                       delta = time.time() - start
                       print( "Time:" + str( delta ), flush = True )
                       GI_save_image_run = False
                       #thread.join()

                       crop  = IceRayPy.type.graph.Picture( P_config['dll'] )

                       A = IceRayPy.type.math.coord.Size2D( P_config['window']['A']['x'], P_config['window']['A']['y'] )
                       B = IceRayPy.type.math.coord.Size2D( P_config['window']['B']['x'], P_config['window']['B']['y'] )

                       IceRayPy.type.graph.Crop( P_config['dll'], crop, GI_save_image_image, A, B )

                       crop.storePNG( filen_name )

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

config['index'] = 0

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
config['pigment']['ior'] = 1.0
config['pigment']['albedo'] = IceRayPy.type.color.RGB( 1, 1, 1 )

config['ray-trace']={}
config['ray-trace']['depth'] = 32
config['ray-trace']['trash'] = 1.0/10000.0
config['ray-trace']['next'] = 17000

config['room'] = {}
config['room']['radiosity'] = {}
config['room']['radiosity']['blossom'] = 'sobol'
config['room']['radiosity']['patch']  = math.radians( 4 )
config['room']['radiosity']['angle']  = math.radians( 89 )
config['room']['radiosity']['sample'] = int( (1 - math.cos(config['room']['radiosity']['angle']) ) / ( 1 - math.cos( config['room']['radiosity']['patch'] ) ) + 1 )
config['room']['radiosity']['jitter-angle'] = math.radians( 4 )
config['room']['radiosity']['jitter-type'] = 'none' #'random''sobol''vdc''none'

config['room']['radiosity']['correction-leader'] = True
config['room']['radiosity']['correction-cone']   = False
config['room']['radiosity']['correction-trim']   = False
config['room']['radiosity']['correction-claim']  = False

config['observer'] = {}
config['observer']['radius'] = 4
config['observer']['dilatation'] = 1
config['observer']['type'] = 1


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

dilatation  = 2;


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

path_item = 'looker' # 'looker', 'fixed', 'circle'

config['pigment']['sigma'] = IceRayPy.type.color.RGB( 1, 1, 1 )
config['pigment']['rho']   = IceRayPy.type.color.RGB( 3.1415926, 3.1415926, 3.1415926 )

gold = (math.sqrt(5)-1)/2

#for counter in range( 0, 500 ):
#    index = int( 360 * ( gold * counter ) ) % 360

#for step in [ int(360/3), int(360/4), int(360/5), int(360/6), int(360/24), int(360/8), int(360/9), int(360/10), int(360/12), int(360/15), int(360/18), 1 ] :
for index in range( start, 360 * int( dilatation ), step ):

    config['index'] = index
    t = index / 360.0 / dilatation

    [x,y,height] = path_list[path_item]( t, config['camera']['path'] ) #!< MAIN
    #[x,y,height] = path_list[path_item]( 135 / 360.0 / dilatation, config['camera']['path'] )#!< debug

    config['camera'][ 'eye'] = IceRayPy.type.math.coord.Scalar3D( x, y, height ) #!< MAIN
    config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 ) #!< MAIN

    config['camera']['view'] = IceRayPy.type.math.coord.Scalar3D( 0, 0,-0.15 - 0.7 ) #!< debug
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
    config['pigment']['ior'] = config['pigment']['ior'] + 0.01;
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

