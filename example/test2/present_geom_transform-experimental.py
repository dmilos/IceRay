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
I_picture[ 'width']  = 1920
I_picture['height']  = 1080
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

I_picture['index'] = 0
I_picture['time'] = 0

I_picture['window'] = {}
I_picture['window']['A'] = {}
I_picture['window']['B'] = {}


# half shade
I_picture['window']['A']['x'] = int( 0.40 * I_picture['width'] )
I_picture['window']['B']['x'] = int( 0.60 * I_picture['width'] )
I_picture['window']['A']['y'] = int( 0.65 * I_picture['height'] ) # 43
I_picture['window']['B']['y'] = int( 0.70 * I_picture['height'] )

# ALL
I_picture['window']['A']['x'] = int( 0.00 * I_picture['width'] )
I_picture['window']['B']['x'] = int( 1.00 * I_picture['width'] )
I_picture['window']['A']['y'] = int( 0.00 * I_picture['height'] ) # 43
I_picture['window']['B']['y'] = int( 1.00 * I_picture['height'] )

# bot side
I_picture['window']['A']['x'] = int( 0.39 * I_picture['width'] )
I_picture['window']['B']['x'] = int( 0.62 * I_picture['width'] )
I_picture['window']['A']['y'] = int( 0.54 * I_picture['height'] ) # 43
I_picture['window']['B']['y'] = int( 0.75 * I_picture['height'] )

I_scene = {}
I_scene['room']       = 'C-close'
I_scene['camera']     = 'F-persp'
I_scene['geometry']   = 'vacuum'
I_scene['medium']     = 'trans'
I_scene['pigment']    = 'I-Lambert'
I_scene['light']      = 'point'
I_scene['decoration'] = 'vacuum'


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
I_config['pigment']  = {}
I_config['camera']  = {}
I_config['room']   = {}
I_config['light']   = {}
I_config['light']['sample']   = 1
I_config['decoration']   = {}
I_config['geometry']   = {}

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

I_config['composer'] = {}
I_config['composer']['hot'] = {}
I_config['composer']['hot']['x'] = 400
I_config['composer']['hot']['y'] = 300
I_config['composer']['manager'] = {}
I_config['composer']['manager']['pixel'] = {}
I_config['composer']['manager']['pixel']['type'] = 'center' # 'center', 'grid', 'random', 'sobol'
I_config['composer']['manager']['pixel']['size'] = 2

geometry_list = [
     #'T-identity'  ,
     #'T-translate' ,
     #'T-affine'    ,
     #'T-hgraphy'   ,
      'T-mblur'     ,
 ]

min_deltaC = 1;
min_deltaD = 100;
dispersion_min = 100;
average_ideal = 0.5
average_best  = 0

#for index in range( 1, 362880, 1 ): # 1, 2, 3, 4, 5,
#    #save = True
#    #I_picture['window']['A']['x'] = int( 0.40 * I_picture['width'] )
#    #I_picture['window']['B']['x'] = int( 0.60 * I_picture['width'] )
#    #I_picture['window']['A']['y'] = int( 0.65 * I_picture['height'] )
#    #I_picture['window']['B']['y'] = int( 0.70 * I_picture['height'] )
#    #
#    #for permutation in ( 449, 2591 ):
#    #    if( ( permutation  < index + 4 ) and ( index < permutation + 4 ) ):
#    #        I_picture['window']['A']['x'] = int( 0.00 * I_picture['width'] )
#    #        I_picture['window']['B']['x'] = int( 1.00 * I_picture['width'] )
#    #        I_picture['window']['A']['y'] = int( 0.00 * I_picture['height'] )
#    #        I_picture['window']['B']['y'] = int( 1.00 * I_picture['height'] )
#    #        save = True
#
#    I_config['camera'][ 'eye'] = IceRayPy.type.math.coord.Scalar3D( +c*p*g * math.cos( math.radians(90)  ), +1.5* p*g * math.sin( math.radians(90)  ),  +g )
#    for item in geometry_list :
#        #print( "-------------------------------------------------")
#        I_picture['prefix'] = item + '/' +"%04i"%(index)
#        I_scene['geometry']= item
#        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
#
#        #dispersion_current = I_picture['temp']['crop'].dispersion()
#        #if(  dispersion_current< dispersion_min ):
#        #    dispersion_min = dispersion_current
#        #    I_picture['temp']['crop'].storePNM( "min_" +"%04i"%(index) +  "-x.pnm" )
#        #    print( "%8i"%(index) +   " -  dispersion_current: " + "%10f"%(dispersion_current*256) )
#
#        average_current = I_picture['temp']['crop'].dispersion()
#        if( (  math.fabs( average_current - average_ideal ) < math.fabs( average_best - average_ideal )  ) ):
#            average_best = average_current
#            I_picture['temp']['crop'].storePNM( "average_" +"%06i"%(index) +  "-x.pnm" )
#            print( "%8i"%(index) +   " -  average_current: " + "%10f"%(average_current*256) )
#
#exit()

global_maxD = 1000;

for index in range( 1, 362880, 1 ):
    I_config['camera'][ 'eye'] = IceRayPy.type.math.coord.Scalar3D( +c*p*g * math.cos( math.radians(90)  ), +1.5* p*g * math.sin( math.radians(90)  ),  +g )
    for item in geometry_list :
        #print( "-------------------------------------------------")
        I_picture['prefix'] = item + '/' +"%04i"%(index)
        I_scene['geometry']= item
        render.doIt( I_dll, I_picture, I_scene, I_inventory, I_config )
        Size2D     = IceRayPy.type.math.coord.Size2D
        size = I_picture['temp']['object'].size();
        I_left = IceRayPy.type.graph.Picture( I_dll )
        I_right = IceRayPy.type.graph.Picture( I_dll )

        Ax = I_picture['window']['A']['x']
        Ay = I_picture['window']['A']['y']
        Bx = I_picture['window']['B']['x']
        By = I_picture['window']['B']['y']
        width = Bx-Ax
        height = By-Ay
        crop_size = I_picture['temp']['crop'].size()

        La = IceRayPy.type.color.RGB();
        Ra = IceRayPy.type.color.RGB();

        xT = 14
        yT = 6
        xC = int( width  / xT )
        yC = int( height / yT ) 
        local_deltaD = 0
        local_maxD = 0
        local_deltaC = 0
        for yp in range( 0, yT ):
            for xp in range( 0, int(xT/2+0.01) ):
                #print( str(yp) +" _ "+str(xp) )

                lA = Size2D( xp * xC, yp * yC )
                lB = Size2D( lA[0] + xC, lA[1]+ yC )

                rA = Size2D( width - lA[0] - xC, lA[1] )
                rB = Size2D( rA[0] + xC, rA[1]+ yC )

                IceRayPy.type.graph.Crop( I_left,  I_picture['temp']['crop'], lA, lB )
                IceRayPy.type.graph.Crop( I_right, I_picture['temp']['crop'], rA, rB )

                I_left.average( La )
                I_right.average( Ra )
                deltaC = IceRayPy.type.color.distanceRGB( La, Ra );
                if( local_deltaC  < deltaC  ):
                    local_deltaC  = deltaC;

                Ld = I_left.dispersion()
                Rd = I_right.dispersion()
                deltaD = math.fabs( Ld - Rd );
                maxD = max( Ld, Rd );
                if( local_deltaD  < deltaD ):
                    local_deltaD   = deltaD;
                if( local_maxD  < maxD ):
                    local_maxD   = maxD;

                #left_gray_average = (La[0]+La[1]+La[2])/3
                #left_gray_sum_lin  = left_gray_average
                #left_gray_sum_quad = left_gray_average*left_gray_average

        #dispersion_current =  left_gray_sum_quad / xT / yT - left_gray_sum_lin*left_gray_sum_lin/ ( xT * yT * xT * yT ) 

        #if( local_deltaC   < 64/255.0 ):
        #    #if( ( dispersion_current  < dispersion_min ) ):
        #    #    dispersion_min = dispersion_current;
        #    #    I_picture['temp']['crop'].storePNM( "minimal_" +"%08i"%(index) +  "-md.pnm" )
        #    #    print( "%8i"%(index) +   " - md: " + "disp:" + "%10f"%(dispersion_current*256) +" dist:" + "%10f"%(local_deltaD*256) )
        #
        #if( ( local_deltaD < min_deltaD ) ): #min_deltaD
        #    min_deltaD = local_deltaD;
        #    I_picture['temp']['crop'].storePNM( "minimal_" +"%08i"%(index) +  "-D.pnm" )
        #    #print( "%8i"%(index) +   " -  D: " + "disp:" + "%10f"%(dispersion_current*256) +" dist:" + "%10f"%(local_deltaD*256) )
        #    print( "%8i"%(index) +    " -  D: " + "disp:"  +" dist:" + "%10f"%(local_deltaD*256) )
        #
        #if( ( local_deltaC   < min_deltaC ) ):   #min_deltaC
        #    min_deltaC = local_deltaC;
        #    I_picture['temp']['crop'].storePNM( "minimal_" +"%08i"%(index) +  "-C.pnm" )
        #    print( "%8i"%(index) +   " -  Color: " + " dist:" + "%10f"%(min_deltaC*256) )

        #if(  ( local_deltaD  < min_deltaD ) and ( local_deltaC   < min_deltaC ) ):
            #print( "%8i"%(index) +   " -  D: " + "disp:"  +" dist:" + "%10f"%(local_deltaD*256) )
        #if( local_deltaC  < min_deltaC ):
            #min_deltaD = local_deltaD;
            #min_deltaC = local_deltaC;
            #print( "%8i"%(index) +   " -  Color: " + " dist:" + "%10f"%(min_deltaC*256) )
        if( local_maxD  < global_maxD ):
            global_maxD = local_maxD
            print( "%8i"%(index) +   " -  Color: " + " mm dispersion:" + "%10f"%(global_maxD*256) )
            I_picture['temp']['crop'].storePNM( "mm_" +"%04i"%(index) +  ".pnm" )


import os
def prepare_readme():
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_T-affine_trans_I-ALP_chand-nine_0000.pnm'     , I_picture['folder']+'/'+'geometry_transform_affine.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_T-hgraphy_trans_I-ALP_chand-nine_0000.pnm'    , I_picture['folder']+'/'+'geometry_transform_hgraphy.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_T-identity_trans_I-ALP_chand-nine_0000.pnm'   , I_picture['folder']+'/'+'geometry_transform_identity.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_T-mblur_trans_I-ALP_chand-nine_0000.pnm'      , I_picture['folder']+'/'+'geometry_transform_mblur.pnm' )
    os.rename( I_picture['folder']+'/'+    'C-close_F-persp_T-translate_trans_I-ALP_chand-nine_0000.pnm'  , I_picture['folder']+'/'+'geometry_transform_translate.pnm' )


