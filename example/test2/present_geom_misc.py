#!/usr/bin/env python3

import time
import math
import os
import sys
import IceRayPy

import render

running_in_visual_studio = "VisualStudioVersion" in os.environ

dll_path = IceRayPy.system.SearchCDLL( P_preferDebug = running_in_visual_studio )

if 0 != len( dll_path ):
    I_dll = IceRayPy.system.LoadCDLL( dll_path )
else:
    print("Can not find DLL")
    time.sleep(200)
    exit()

I_picture ={}
I_picture[ 'width']  = int( 2560 )
I_picture['height']  = int( 1440 )
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
I_scene['camera']     =  'F-persp'
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


#I_picture['watermark']             = 'cos(x)*cos(y)*cos(z)'
#I_config['geometry']['expression'] = 'cos(x)*cos(y)*cos(z)'
#I_config['geometry']['interval']=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-6,-6,-6),IceRayPy.type.math.coord.Scalar3D(+6,+6,+6) )
#I_config['geometry'][    'box' ]=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-1,-1,-1),IceRayPy.type.math.coord.Scalar3D(+1,+1,+1) )

#I_picture['watermark']            = 'cos(x)+cos(y)+cos(z)'
#I_config['geometry']['expression']= 'cos(x)+cos(y)+cos(z)'
#I_config['geometry']['interval']=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-6,-6,-6),IceRayPy.type.math.coord.Scalar3D(+6,+6,+6) )
#I_config['geometry'][    'box' ]=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-1,-1,-1),IceRayPy.type.math.coord.Scalar3D(+1,+1,+1) )

#I_picture['watermark'] = 'heart'
#I_config['geometry']['expression']='pow( x*x + (9/4)*y*y + z*z - 1, 3 ) - x*x*z*z*z - (9/80)*y*y*z*z*z'
##I_config['geometry']['expression']='( x*x + (9/4)*y*y + z*z - 1)^3 - x*x*z*z*z - (9/200)*y*y*z*z*z'
#I_config['geometry']['expression']='pow( x*x + (9/4)*y*y + z*z - 1, 3) - x*x*z*z*z - (9/200)*y*y*z*z*z'
#I_config['geometry']['interval']=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-1.5,-1.5,-1.5),IceRayPy.type.math.coord.Scalar3D(+1.5,+1.5,+1.5) )
#I_config['geometry'][    'box' ]=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-1,-1,-1),IceRayPy.type.math.coord.Scalar3D(+1,+1,+1) )

I_picture['watermark'] = 'tower_max'
I_config['geometry']['expression']='max(max(y-1/x,x-1/y),y-1/z)-1'
I_config['geometry']['interval']=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-2.5,-2.5,-2.5),IceRayPy.type.math.coord.Scalar3D(+2.5,+2.5,+2.5) )
I_config['geometry'][    'box' ]=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-1,-1,-1),IceRayPy.type.math.coord.Scalar3D(+1,+1,+1) )


#I_picture['watermark'] = 'sphere'
#I_config['geometry']['expression']='sqrt(x*x+y*y+z*z)-1'
#I_config['geometry']['interval']=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-1.00,-1.00,-1.00),IceRayPy.type.math.coord.Scalar3D(+1.0,+1.0,+1.0) )
#I_config['geometry'][    'box' ]=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-1,-1,-1),IceRayPy.type.math.coord.Scalar3D(+1,+1,+1) )

#I_picture['watermark'] = 'torus'
#I_config['geometry']['expression']='(x*x+y*y+z*z+0.75*0.75-0.25*0.25)-2*0.75*sqrt(x*x+y*y)'
#I_config['geometry']['interval']=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-1.00,-1.00,-1.00),IceRayPy.type.math.coord.Scalar3D(+1.0,+1.0,+1.0) )
#I_config['geometry'][    'box' ]=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-1,-1,-1),IceRayPy.type.math.coord.Scalar3D(+1,+1,+1) )

#I_picture['watermark'] = 'cloud'
#I_config['geometry']['expression']='x*x+y*y+z*z-1+0.5*(x*x*x*x-3*x*x*y*y+y*y*y*y*)*sin(4*z)'
#I_config['geometry']['interval']=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-10.00,-10.00,-10.00),IceRayPy.type.math.coord.Scalar3D(+10.0,+10.0,+10.0) )
#I_config['geometry'][    'box' ]=IceRayPy.type.math.interval.Scalar3D( IceRayPy.type.math.coord.Scalar3D(-1,-1,-1),IceRayPy.type.math.coord.Scalar3D(+1,+1,+1) )

g = 1.22074408460575947536 #(math.sqrt(5)+1)/2

g = (math.sqrt(5)+1)/2  #1.6180339887498948482045868343656
p = 1.324717957244746025960908854
c = 1.22074408460575947536
I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( +c*p*g, +p*g , +g )
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
I_config['camera']['sample'] = 1
#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )
I_config['camera']['width']   = 1


geometry_list = [
     #'S-torus',
     #'L-Bpair'
     'E-implicit'
    #'Q-sphere'
  ]

I_config['composer'] = {}
I_config['composer']['hot'] = {}
I_config['composer']['hot']['x'] = 1280
I_config['composer']['hot']['y'] = 145

for index in range( I_begin, 360, 20 ):
    I_config['camera']['eye'] = library_path.looker( index/360.0 )
    I_picture['index'] = index
    for item in geometry_list :
        I_scene['geometry']= item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

import os
def prepare_readme():
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_S-torus_trans_T-B-refract-schlick_chand-nine_0000.pnm'       , I_picture['folder']+'/'+'geometry_torus.pnm' )

prepare_readme()

#done!