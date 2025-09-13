#!/usr/bin/env python3

import time
import math
import os
import sys
import IceRayPy

import IceRayPy

import render

dll_path = IceRayPy.system.SearchCDLL( P_preferDebug = False )

if 0 != len( dll_path ):
    I_dll = IceRayPy.system.LoadCDLL( dll_path )
else:
    print("Can not find DLL")
    time.sleep(200)
    exit()

I_picture ={}
I_picture[ 'width']  = int( 800/2 )
I_picture['height']  = int( 600/2 )
I_picture['aspect']  = I_picture['width'] / I_picture['height']

#if( 1 < len( sys.argv ) ):
#    I_picture[ 'width'] = int( sys.argv[1] )
#    I_picture['height'] = int( I_picture['width'] / I_picture['aspect'] )

I_picture['prefix'] = ''
try:
    os.mkdir( "_out" )
except OSError as e:
    pass
I_picture['folder'] = './_out'
I_picture['extension'] = 'pnm'

I_picture['index'] = 0
I_picture['time'] = 0
I_picture['watermark'] = "%index"

I_picture['window'] = {}
I_picture['window']['A'] = {}
I_picture['window']['A']['x'] = 0
I_picture['window']['A']['y'] = 0
I_picture['window']['B'] = {}
I_picture['window']['B']['x'] = I_picture['width']
I_picture['window']['B']['y'] = I_picture['height']

I_scene = {}
I_scene['room']       = 'P-radiosity'  #  'C-close'
I_scene['camera']     = 'F-persp'
I_scene['geometry']   = 'Q-sphere'
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'T-B-refract-schlick'
I_scene['light']      = 'dark' #'point'
I_scene['decoration'] = 'radiosity'


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
I_config['room']['radiosity']={}
I_config['room']['radiosity']['sample' ]  = 16
I_config['room']['radiosity']['angle'  ]   = math.radians( 90 )
I_config['room']['radiosity']['albedo' ]   = IceRayPy.type.color.RGB( 0.99, 0.99, 0.99 )
I_config['room']['radiosity']['blossom']   = 'sobol'
I_config['room']['radiosity']['correction'] = "trim"
I_config['light']   = {}
I_config['light']['sample']   = 1
I_config['decoration']   = {}

g = 1.22074408460575947536 #(math.sqrt(5)+1)/2

g = (math.sqrt(5)+1)/2
p = 1.324717957244746025960908854
c = 1.22074408460575947536
I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( 0* +c*p*g,+ 1.5* p*g ,  +g )
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )

I_config['composer']={}
I_config['composer']['ray-trace']={}
I_config['composer']['ray-trace']['depth'] = 12
I_config['composer']['ray-trace']['trash'] = 1.0/10000.0
I_config['composer']['ray-trace']['next'] = 17000
I_config['composer']['hot'] = {}
I_config['composer']['hot']['x'] = 132
I_config['composer']['hot']['y'] = 316

index = 0;

I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
for index in range( 1, 100, 1 ): 
    I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( 2.6 * math.cos( math.radians( 225 ) ), 2.6 * math.sin( math.radians( 225 ) ) ,  +g )
    for jitter in [ 'none' ]:  # , 'vdc', 'triangle', 'sobol', 'random', 'sunflower', 'congruent', 'grid', 'hexagon' 
        for object in [ 'V-vacuum',  ]:  #'Q-sphere' 'V-vacuum', 'Q-sphere''Q-util-cylinder', 
            I_scene['geometry']   = object
            for blossom in [ 'triangle' ]: # , 'sunflower' , 'grid', 'hexagon', 'vdc', 'sobol', 'random', 'congruent'
                I_picture['index'] = index
                I_picture['prefix'] = "%03i"%(index) + '_' + blossom + "_"
                I_config['room']['radiosity']['patch']  = math.radians( 60.99 )/index #<! Used also for sample number calculation
                I_config['room']['radiosity']['jitter-type' ]   = jitter
                I_config['room']['radiosity']['jitter-angle' ]   = 0.5 * I_config['room']['radiosity']['patch']
                I_config['room']['radiosity']['correction-leader' ]  = True
                I_config['room']['radiosity']['angle'  ] = math.radians( 45 )
                I_config['room']['radiosity']['sample'] = index +0* int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
                I_config['room']['radiosity']['blossom']  = blossom
                render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
        index = index + 1

exit()

I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( 0* +c*p*g,+ 1.5* p*g ,  +g )
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )

for index in ( 1, 2, 5 ):# , 10, 20, 50, 100, 200, 500, 1000
    for jitter in [ 'none', 'vdc', 'triangle', 'sobol', 'random', 'sunflower', 'congruent', 'grid', 'hexagon' ]:  #  
        for object in [ 'Q-sphere',  ]:  #'Q-sphere' 'V-vacuum', 'Q-sphere''Q-util-cylinder', 
            I_scene['geometry']   = object
            for blossom in [ 'triangle', 'sunflower' , 'grid', 'hexagon' ]: # ,'vdc', 'sobol', 'random', 'congruent'
                I_picture['index'] = index
                I_picture['prefix'] = "%03i"%(index) + '_' + blossom + "_"
                I_config['room']['radiosity']['patch']  = math.radians( 60.99 )/index #<! Used also for sample number calculation
                I_config['room']['radiosity']['jitter-type' ]   = jitter
                I_config['room']['radiosity']['jitter-angle' ]   = 0.5 * I_config['room']['radiosity']['patch']
                I_config['room']['radiosity']['correction-leader' ]  = True
                I_config['room']['radiosity']['angle'  ] = math.radians( 60.99 )
                I_config['room']['radiosity']['sample'] = index+0* int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
                I_config['room']['radiosity']['blossom']  = blossom
                render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
        index = index + 1

exit()
for index in ( 1, 2, 5 ):# , 10, 20, 50, 100, 200, 500, 1000
    for jitter in [ 'none' ]:  #, 'vdc', 'triangle', 'sobol', 'random', 'sunflower', 'congruent', 'grid', 'hexagon' 
        for object in [ 'Q-sphere',  ]:  #'Q-sphere' 'V-vacuum', 'Q-sphere''Q-util-cylinder', 
            I_scene['geometry']   = object
            for blossom in [ 'vdc', 'sobol', 'random', 'congruent'  ]: # 'triangle', 'sunflower' , 'grid', 'hexagon',
                I_picture['index'] = index
                I_picture['prefix'] = "%03i"%(index) + '_' + blossom + "_"
                I_config['room']['radiosity']['patch']  = math.radians( 24 ) #<! Used also for sample number calculation
                I_config['room']['radiosity']['jitter-type' ]   = jitter
                I_config['room']['radiosity']['jitter-angle' ]   = 0.5 * I_config['room']['radiosity']['patch']
                I_config['room']['radiosity']['correction-leader' ]  = True
                I_config['room']['radiosity']['angle'  ] = math.radians( 60.99 )
                I_config['room']['radiosity']['sample'] = index+0* int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
                I_config['room']['radiosity']['blossom']  = blossom
                render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
        index = index + 1


exit()
I_scene['pigment']    = 'T-0-reflect-mirror'
for index in ( 1, 2, 5 ): #, 10, 20, 50, 100, 200, 500, 1000 
    for blossom in [ 'sunflower', 'triangle', 'grid', 'hexagon' ]: #  #'vdc', 'congruent', 'sobol', 'random' 
        for object in [ 'Q-util-cylinder' ]:  #, 'Q-sphere' 'V-vacuum', 'Q-sphere''Q-util-cylinder', 
            I_scene['geometry']   = object # 'Q-util-cylinder'  #'V-vacuum' 'Q-sphere'  'S-util-torus'
            I_picture['index'] = index
            I_picture['prefix'] = "%03i"%(index)+ '_' + blossom + "_"
            I_config['room']['radiosity'][ 'patch' ]  = math.radians( 90 )/index  #<! Used for sample number calculation
            I_config['room']['radiosity'][ 'jitter-type' ]   = "none"
            I_config['room']['radiosity'][ 'jitter-angle' ]  = I_config['room']['radiosity']['patch']
            I_config['room']['radiosity'][ 'correction-leader' ]  = True
            I_config['room']['radiosity'][ 'angle' ]  = math.radians( 60.99 )
            I_config['room']['radiosity'][ 'sample'] = index+0*int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
            I_config['room']['radiosity'][ 'blossom']  = blossom
            render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

exit()

start = 0;
if( 1 < len( sys.argv ) ):
    start = int( sys.argv[1] )

end = 10;
if( 2 < len( sys.argv ) ):
    end = int( sys.argv[2] )


I_picture['window']['A']['x'] = int( I_picture['width']/2 - I_picture['width']/10 )
I_picture['window']['B']['x'] = int( I_picture['width']/2 + I_picture['width']/10 )
I_picture['window']['A']['y'] = int( I_picture['height']/2 + I_picture['height']/6  )
I_picture['window']['B']['y'] = int( I_picture['height']/2 + I_picture['height']/6 + I_picture['height']/10 )

resolution = 2000
I_pictureAverage = IceRayPy.type.graph.Picture( I_dll )
I_pictureAverage.size( resolution,resolution)
I_pictureAverage.clear( IceRayPy.type.color.RGB( 0, 0, 0 ) )
I_pictureDispersion = IceRayPy.type.graph.Picture( I_dll )
I_pictureDispersion.size(resolution,resolution)
I_pictureDispersion.clear( IceRayPy.type.color.RGB( 0, 0, 0 ) )
time_start = time.time()


for x in range( start, end ): # 
    for y in range( x, int(resolution/2) ):
        I_blossom = 'congruent'
        I_scene['geometry']   = 'V-vacuum'
        I_picture['index'] = index
        I_picture['prefix'] = "%03i"%(index)+ '_' + I_blossom + "_"
        #I_scene['pigment']    = 'T-0-reflect-mirror'  #<! irrelevant
        #I_config['pigment']['angle']  = math.radians( 89.9 )
        I_config['room']['radiosity'][ 'patch' ]  = math.radians( 10 )  #<! Used for sample number calculation
        I_config['room']['radiosity'][ 'jitter-type' ]   = "none"
        I_config['room']['radiosity'][ 'jitter-angle' ]  = I_config['room']['radiosity']['patch']
        I_config['room']['radiosity'][ 'correction-leader' ]  = True
        I_config['room']['radiosity'][ 'angle' ]  = math.radians( 89.99 )
        I_config['room']['radiosity'][ 'sample'] =  int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
        I_config['room']['radiosity'][ 'blossom']  = I_blossom
        I_config['decoration'][ 'center']  = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
        I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( 3, 0 , 0 )
        I_config['camera'][ 'view']  = IceRayPy.type.math.coord.Scalar3D( 0, 0 , 0 )
        I_result = {}
        I_dll.IceRayC_Utility_Random_Table_Next( x/resolution, y/resolution, resolution )
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config, I_result )

        c = I_result['picture']['average'].r
        c = ( 255.0*c - (161.048-50.0) )/100.0
        if( c < 0 ): c = 0
        if( 1 < c ): c = 1
        I_pictureAverage.set(    IceRayPy.type.math.coord.Size2D( x, y ), IceRayPy.type.color.RGB( c, c, c ) )
        I_pictureAverage.set(    IceRayPy.type.math.coord.Size2D( y, x ), IceRayPy.type.color.RGB( c, c, c ) )

        d = 10*I_result['picture']['dispersion']
        I_pictureDispersion.set( IceRayPy.type.math.coord.Size2D( x, y ), IceRayPy.type.color.RGB( d, d, d ) )
        I_pictureDispersion.set( IceRayPy.type.math.coord.Size2D( y, x ), IceRayPy.type.color.RGB( d, d, d ) )

        print( "Image Statistics: [ " + str(x)+ "," +str(y)+ " ] " + str( I_result ) )
        index = index + 1
  #      break
    I_pictureAverage.storePNG(    "statistic-"+str(resolution)+"_"+"%04i"%(start) + "-" "%04i"%(end)+"-average.png" )
    I_pictureDispersion.storePNG( "statistic-"+str(resolution)+"_"+"%04i"%(start) + "-" "%04i"%(end)+"-dispersion.png" )
  #  break

time_delta = time.time() - time_start
print( "Time Total:" + str( time_delta ), flush = True )

#start = 0;
#if( 1 < len( sys.argv ) ):
#    start = int( sys.argv[1] )
#
#for index in range( start, 360, 10 ):  # 'V-Vacuum'
#    I_scene['geometry']   = 'Q-sphere'
#    for blossom in [ 'sobol' ]: # , 'vdc', 'congruent', 'sobol', 'random', 'sunflower', 'triangle', 'grid', 'hexagon', ##'LD'
#        I_picture['index'] = index
#        I_picture['prefix'] = "%03i"%(index) + '_' + blossom + "_"
#        I_config['room']['radiosity']['patch' ]  = math.radians( 2.5 )
#        I_config['room']['radiosity']['jitter-type' ]   = "none"
#        I_config['room']['radiosity']['jitter-angle' ]   = 0.25*I_config['room']['radiosity']['patch']
#        I_config['room']['radiosity'][ 'correction-leader' ]  = True
#        I_config['room']['radiosity']['angle'  ]  = math.radians( 89.9 )
#        I_config['room']['radiosity']['sample'] = int( (1 - math.cos(I_config['room']['radiosity']['angle']) ) / ( 1 - math.cos( I_config['room']['radiosity']['patch'] ) ) + 1 )
#        I_config['room']['radiosity']['blossom']  = blossom
#        I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( 2.6 * math.cos( math.radians( index ) ), 2.6 * math.sin( math.radians( index ) ) ,  +g )
#        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
#        index = index + 1

