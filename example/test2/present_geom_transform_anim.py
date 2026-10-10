#!/usr/bin/env python3

import time
import math
import os
import sys

import IceRayPy

import render
os.system('color')

running_in_visual_studio = "VisualStudioVersion" in os.environ
print( "******************* "   )
print( "running_in_visual_studio: " +  str( running_in_visual_studio ) )
print( "******************* "  )

dll_path = IceRayPy.system.SearchCDLL( P_preferDebug = running_in_visual_studio )

if 0 != len( dll_path ):
    I_dll = IceRayPy.system.LoadCDLL( dll_path )
else:
    print("Can not find DLL")
    time.sleep(200)
    exit()


I_picture ={}
I_picture[ 'width']  = int(1920/3)
I_picture['height']  = int(1080/3)
I_picture['aspect']  = I_picture['width'] / I_picture['height']

if( 1 < len( sys.argv ) ):
    I_picture[ 'width'] = int( sys.argv[1] )
    I_picture['height'] = int( I_picture['width'] / I_picture['aspect'] )

try:
    os.mkdir( "_out" )
except OSError as e:
    pass

I_picture['folder'] = './_out'
I_picture['extension'] = 'pnm'
I_picture['overwrite'] = False

I_picture['index'] = 0
I_picture['time'] = 0

I_picture['window'] = {}
I_picture['window']['A'] = {}
I_picture['window']['A']['x'] = 0
I_picture['window']['A']['y'] = 0
I_picture['window']['B'] = {}
I_picture['window']['B']['x'] = I_picture['width']
I_picture['window']['B']['y'] = I_picture['height']

#I_picture['window']['A']['x'] = 960-80
#I_picture['window']['A']['y'] = 360
#I_picture['window']['B']['x'] = 960+80
#I_picture['window']['B']['y'] = 420

I_scene = {}
I_scene['room']       = 'C-close'
I_scene['camera']     = 'F-persp'
I_scene['geometry']   = 'vacuum'
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'I-ALP'
I_scene['light']      = 'chand-nine'
I_scene['decoration'] = 'plate'



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
I_config['pigment']  = {}
I_config['camera']  = {}
I_config['room']   = {}
I_config['light']   = {}
I_config['light']['sample']   = 1
I_config['decoration']   = {}
I_config['geometry']   = {}
I_config['composer'] = {}
I_config['composer']['hot'] = {}
I_config['composer']['hot']['x'] = 320
I_config['composer']['hot']['y'] = 180

g = 1.22074408460575947536 #(math.sqrt(5)+1)/2

g = (math.sqrt(5)+1)/2
p = 1.324717957244746025960908854
c = 1.22074408460575947536
I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( +c*p*g, +p*g, +g )
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
I_config['camera']['sample'] = 1
#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )

geometry_list = [
     #'T-identity'  ,
     #'T-translate' ,
     #'T-affine'    ,
     'T-hgraphy'   ,
     #'T-mblur'    ,
 ]

Coord3D = IceRayPy.type.math.coord.Scalar3D

for index in range( 0, 360, 1 ):
    I_picture['index'] = index
    I_time = index/ 360.0
    I_config['camera']['eye']   = library_path.looker( I_time )

    sO = Coord3D( -1, -1, -1 )

    sX = Coord3D( +1, -1, -1 )
    sY = Coord3D( -1, +1, -1 )
    sZ = Coord3D( -1, -1, +1 )

    sT = Coord3D( +1, +1, +1 )

    tO = Coord3D( -1, -1, -1 )

    tX = Coord3D( +1, -1, -1 )
    tY = Coord3D( -1, +1, -1 )
    move = 300/360.0
    tZ = Coord3D( -1.0 + move, -1.0 + move, +1.0  )

    tT = Coord3D( +1.0 - move, +1.0 - move, +1.0  )

    I_config['geometry']['to_world'] = IceRayPy.type.math.homography.construct3D( I_dll, tO, tX, tY, tZ, tT, sO, sX, sY, sZ, sT )
    I_config['geometry']['child'] =  IceRayPy.core.geometry.simple.Sphere( I_dll, Coord3D( 0, 0, 0 ), 1 )
    I_config['geometry']['child'] =  IceRayPy.core.geometry.flat.Box( I_dll, Coord3D( -1, -1, -1 ), Coord3D( +1, +1, +1 ) )
    for item in geometry_list :
        I_scene['geometry']= item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

import os
def prepare_readme():
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_T-affine_trans_I-ALP_chand-nine_0000.pnm'     , I_picture['folder']+'/'+'geometry_transform_affine.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_T-hgraphy_trans_I-ALP_chand-nine_0000.pnm'    , I_picture['folder']+'/'+'geometry_transform_hgraphy.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_T-identity_trans_I-ALP_chand-nine_0000.pnm'   , I_picture['folder']+'/'+'geometry_transform_identity.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_T-mblur_trans_I-ALP_chand-nine_0000.pnm'      , I_picture['folder']+'/'+'geometry_transform_mblur.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_T-translate_trans_I-ALP_chand-nine_0000.pnm'  , I_picture['folder']+'/'+'geometry_transform_translate.pnm' )


prepare_readme()