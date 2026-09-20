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
I_picture[ 'width']  = int( 800 )
I_picture['height']  = int( 600 )
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

I_scene = {}
I_scene['room']       = 'C-close'
I_scene['camera']     = 'F-persp'
I_scene['geometry']   = 'Q-sphere'
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


I_inventory= {}
I_inventory['room']       = library_room.list
I_inventory['camera']     = library_camera.list
I_inventory['geometry']   = library_geometry.list
I_inventory['medium']     = library_medium.list
I_inventory['pigment']    = library_pigment.list
I_inventory['light']      = library_light.list
I_inventory['decoration'] = library_decoration.list

I_config  = {}
I_config['room']   = {}
I_config['camera']  = {}
I_config['pigment']  = {}
I_config['light']   = {}
I_config['light']['sample']   = 1
I_config['decoration']   = {}
I_config['geometry']   = {}
I_config['composer'] = {}
I_config['composer']['manager'] = {}
I_config['composer']['manager']['pixel'] = {}
I_config['composer']['manager']['pixel']['type'] = 'grid' #!< { 'center', 'grid', 'random', 'sobol', 'TODO-vdc' }
I_config['composer']['manager']['pixel']['size'] = 3


g = 1.22074408460575947536 #(math.sqrt(5)+1)/2

g = (math.sqrt(5)+1)/2  #1.6180339887498948482045868343656
p = 1.324717957244746025960908854
c = 1.22074408460575947536
I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( +c*p*g, +p*g , +g )
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )


pigment_reflect_list =[
    'T-0-reflect-One'               ,
    'T-0-reflect-diffusive'         ,
    'T-0-reflect-mirror'            ,
    'T-1-reflect-schlick'           ,
    'T-2-reflect-blossom-Grid'      ,
    'T-3-reflect-blossom-Hexagon'   ,
    'T-4-reflect-blossom-trg'       ,
  ##'T-5-reflect-blossom-LD'        ,
  ##'T-5-reflect-blossom-Pinwheel'  ,
  ##'T-5-reflect-blossom-penrose'   ,
   'T-6-reflect-blossom-Rand'      ,
   'T-7-reflect-blossom-sobol'     ,
   'T-8-reflect-blossom-VDC'       ,
   'T-8-reflect-blossom-congruent'
]

pigment_refract_list =[
     'T-9-refract-fresnel'           ,
     'T-A-refract-Snell'             ,
     'T-B-refract-schlick'           ,

     'T-C-refract-MgSO4_7H2O'                   ,
     'T-D-refract-Na2B4O5__OH_4_8H2O'           ,
     'T-E-refract-NaCaB5O6_OH_6_5H2O'           ,
     'T-F-refract-KAl2_AlSi3O10__F_OH_2'        ,
     'T-G-refract-K_Mg_Fe_3_AlSi3O10__F_OH_2'   ,
     'T-H-refract-Al2SiO4_F_OH_2'               ,
     'T-I-refract-Mg_Fe_2SiO4'                  ,
     'T-B-refract-CaTiO3'                       ,

     'T-B-refract-BaB2O4'                       ,
     'T-B-refract-Be3Al2_SiO3_6'                ,
     'T-B-refract-CaCO3'                        ,
     'T-B-refract-H2O'                          ,
     'T-B-refract-LiNbO3'                       ,
     'T-B-refract-MgF2'                         ,
     'T-B-refract-SiO2'                         ,
     'T-B-refract-Al2O3'                        ,
     'T-B-refract-TiO2'                         ,
     'T-B-refract-Al2O3'                        ,
     'T-B-refract-SiC'                          ,
     'T-B-refract-Tourmaline'                   ,
     'T-B-refract-ZrSiO4_hight'                 ,
     'T-B-refract-ZrSiO4_low'                   ,
 ]

geometry_list =[
    'F-box',
    'S-torus',
    'Q-sphere',
    'T-lensCS',
    'T-lensCP',
    'T-lensVS',
    'T-lensVP'
]

I_config['pigment']['specular']  = IceRayPy.type.color.RGB( 1, 0.1, 0.01 )

for geometry_name in geometry_list :
    I_scene['geometry']= geometry_name
    for pigment_name in pigment_refract_list :
        I_picture['watermark'] = pigment_name
        I_scene['pigment']= pigment_name
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )


import os
def prepare_readme():
    # os.mkdir('I_picture['folder']+'/readme')
    pass

#prepare_readme()