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
I_picture[ 'width']  = 800
I_picture['height']  = 600
I_picture['aspect']  = I_picture['width'] / I_picture['height']

if( 1 < len( sys.argv ) ):
    I_picture[ 'width'] = int( sys.argv[1] )
    I_picture['height'] = int( I_picture['width'] / I_picture['aspect'] )

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
I_scene['camera']     = 'F-persp'
I_scene['geometry']   = 'Q-sphere' # + cookie + torus ??
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'I-ALP'
I_scene['light']      = 'point'
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
I_config['pigment']  = {  }
I_config['camera']  = {}
I_config['room']   = {}
I_config['decoration']   = {}
I_config['light']   = {}
I_config['light']['sample']   = 1

g = 1.22074408460575947536 #(math.sqrt(5)+1)/2

g = (math.sqrt(5)+1)/2
p = 1.324717957244746025960908854
c = 1.22074408460575947536
I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( +c*p*g, +p*g , +g )
I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
I_config['camera']['aspect'] = I_picture['aspect']
#I_config['camera']['hfov']   = math.radians( 90 )
#I_config['camera']['vfov']   = math.radians( 90 )

pigment_list =[
      'I-ALP'           ,
      'I-ambient'       ,
      'I-AsDiffuse'     ,
      'I-AsSpecular'    ,
      'I-AS'    ,
      'I-beckmann-iso'  ,
      'I-Blinn'         ,
      'I-Burley-diff'   ,
      'I-Burley-spec'   ,
      'I-gaussian'      ,
      'I-HsLambert'     ,
      'I-HsPhong'       ,
      'I-Lambert'       ,
      'I-ONf29'         ,
      'I-ONf30'         ,
      'I-ONYFP'         ,
      'I-ONYFQ'         ,
      'I-ONJvO'         ,
      'I-Phong'         ,
      'I-WardApprox'    ,
      'I-WardIsotropic' ,
      'I-WardReal'      ,
      'I-CT'
]

I_config['composer'] = {}
I_config['composer']['hot'] = {}
I_config['composer']['hot']['x'] = 400
I_config['composer']['hot']['y'] = 300

geometry_list = [
      'Q-sphere'
     # 'F-box'
 ]

I_picture['prefix'] = ''

for geometry_item in geometry_list :
    I_scene['geometry']= geometry_item
    for pigment_item in pigment_list :
        I_scene['pigment']= pigment_item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

import os
def prepare_readme():
    os.rename( I_picture['folder']+'/'+    'TODO.pnm'            , I_picture['folder']+'/'+'TODO.pnm' ) 

##debug
#I_scene['geometry']=  'F-plane'
#
#for index in range( 0, 3, 4 ):
#    I_picture['index'] = index
#    #I_config['pigment']['specular']  = IceRayPy.type.color.RGB(1, 0.1, 0.01)
#    #I_config['pigment']['roughness'] = 0.3
#    #I_config['pigment']['gamma']     = 2
#    #I_config['pigment']['F0']        = 0.1
#
#    t = index / 360.0
#    I_picture['time'] = t
#    I_picture['index'] = index
#    [x,y,height] = library_path.list['circle']( t, {'height':2} )
#    I_config['camera'][ 'eye']   = IceRayPy.type.math.coord.Scalar3D( 0, -2,  3 )
#    I_config['camera']['view']   = IceRayPy.type.math.coord.Scalar3D(  0, 0, +1 )
#
#    I_scene['pigment']    = 'I-TR-ani'
#    render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )

#I_config['pigment']['diffuse']  = IceRayPy.type.color.RGB( 3.5, 2.5, 1.5 )
#I_config['pigment']['specular']  = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )

#for u in [10,1000, 10000]:
#    for v in [100,1000, 10000]:
#
#        I_picture['prefix'] = 'u'+str(u)+ "_v" + str(v)
#
#        I_picture['index'] = 0
#        I_config['pigment']['roughnessX']        = 30
#        I_config['pigment']['roughnessY']        = 30
#
#        I_scene['pigment']    = 'I-TR-ani'
#        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
#        break
#    break
