import sys
import math
import time
import IceRayCpp
import os
import engine
import image
import room
import surface
import light
import rendering
from pathlib import Path


def light_make( P_light ):

    blocked = IceRayCpp.LightObstruct()

    blocked.light( P_light['this'] )

    return { 'this': blocked, '0': P_light }


import geometry
from geometry.simple.box.unit import make
from geometry.simple.cone.unit import make
from geometry.simple.cylinder.unit import make
from geometry.simple.disc.unit import make
from geometry.simple.paraboloid.unit import make
from geometry.simple.hyperboloid.unit import cone, nuke, sphere, cylinder, negative
from geometry.simple.saddle.unit import make
from geometry.simple.plane.unit import make
from geometry.simple.quadric.unit import *
from geometry.simple.sphere.unit import make
from geometry.simple.ellipsoid.unit import make
from geometry.simple.torus.unit import make
from geometry.simple.triangle.unit import make
from geometry.simple.usphere.unit import make
from geometry.simple.ucylinder.unit import make

from geometry.volumetric.smoke.unit import make
from geometry.volumetric.vacuum.unit import make
from geometry.complex.intersect.unit import make
from geometry.blobby.unit import make
from geometry.blobby.sphere.unit import solo
from geometry.hfield.unit import funktion
from geometry.rtss.unit import *


from geometry.transform.mblur.unit      import make
from geometry.transform.translate.unit  import *
from geometry.transform.affine.unit     import *
from geometry.transform.homography.unit import *
from geometry.transform.identity.unit  import *

from material.operation.mapping.cartesian2cylindric  import make
from material.operation.mapping.cartesian2package    import make
from material.operation.mapping.cartesian2spherical  import make
from material.operation.mapping.cartesian2tablecloth import make
from material.operation.mapping.cartesian2torus      import make
from material.operation.mapping.cylindric2cartesian  import make
from material.operation.mapping.cylindric2spherical  import make
from material.operation.mapping.spherical2cartesian  import make
from material.operation.mapping.spherical2cylindric  import make
from material.operation.mapping.cartesian2woodX      import make
from material.operation.mapping.cartesian2woodY      import make
from material.operation.mapping.cartesian2woodZ      import make
from material.operation.mapping.cartesian2fisheye    import make
from material.operation.mapping.euclid2max           import make
from material.operation.mapping.max2euclid           import make

import material.pattern.unit
import material.pattern.noise.unit
import material.geometry.unit
import material.illumination.hs.unit

import material.medium.constant
import material.medium.linear
import material.medium.quadratic
import material.medium.exponential



import light
from light.circle.unit      import make
from light.area.unit        import make
from light.disc.unit        import make
from light.line.unit        import make
from light.point.unit       import make, makeX, makeY
from light.sun.general      import point, circle
from light.sun.spot         import make
from light.reflector.unit   import make
from light.spline.unit      import make
from light.sphere.unit      import make
from light.dark.unit        import make
from light.chandelier.unit  import tetra, hexa, octa

from material.light.spot         import *
from material.light.spot.uvw        import *


from material.illumination.hs.unit               import *
from material.illumination.on.unit               import *
from material.illumination.ward.unit             import *
from material.illumination.AshShi.unit           import *
from material.illumination.phong.unit            import *
from material.illumination.ambient.unit          import *
from material.illumination.gaussian.unit         import *
from material.illumination.beckmann.unit         import *
from material.illumination.blinn.unit            import *
from material.illumination.lambert.unit          import *
from material.illumination.alp.unit              import *


from material.transmission.reflect.one.unit          import *
from material.transmission.reflect.schlick.unit      import *

from material.transmission.refract.one.unit          import *
from material.transmission.refract.arbitrary.unit    import *
from material.transmission.refract.fresnel.unit    import *
from material.transmission.refract.schlick.unit    import *

from material.transmission.blossom.grid.unit              import *
from material.transmission.blossom.hexagon.unit              import *
from material.transmission.blossom.random.unit              import *
from material.transmission.blossom.vdc.unit              import *

import kamera
import camera
from camera.flat.orthogonal.unit       import make
from camera.flat.perspective.unit      import make
from camera.flat.super.unit             import *

from camera.dof.cone.unit               import make
from camera.dof.focus.unit              import make
from camera.cylinder.horizontal.unit    import make
from camera.cylinder.vertical.unit      import make
from camera.sphere.horizontal.unit      import make
from camera.sphere.vertical.unit        import make
from camera.sphere.package.unit         import make
from camera.sphere.fisheye.unit         import make
from camera.invert.unit                 import cylinder



light_list = {
       #'dark'       : light.dark.unit.make,
       #'point'      : light.point.unit.makeZ,
       #'reflector'  : light.reflector.unit.make,
       #'sunPoint'   : light.sun.general.point,
       #'sunSpot'    : light.sun.spot.make,
       #'sunArea'    : light.sun.general.area,
       #'sunLine'    : light.sun.general.line,
       #'sunCircle'  : light.sun.general.circle,
       #'sunDisc'    : light.sun.general.disc,
        'line'       : light.line.unit.make,
       #'spline'     : light.spline.unit.make,
       #'circle'     : light.circle.unit.make,
       #'area'       : light.area.unit.make,
       #'disc'       : light.disc.unit.make,
       #'sphere'     : light.sphere.unit.make,
       #'chandelier-H'  : light.chandelier.unit.hexa,
       #'chandelier-T'  : light.chandelier.unit.tetra,
       #'chandelier-O'  : light.chandelier.unit.octa
}

geometry_list = {

      #'rtss-list'     : geometry.rtss.unit.list,
      #'rtss-uniform'  : geometry.rtss.unit.uniform,

      #'hfield-theone'     :geometry.hfield.unit.theone,
      #'hfield-function'   :geometry.hfield.unit.funktion,
      #'simple-box'        :geometry.simple.box.unit.make,
      'simple-usphere'    :geometry.simple.usphere.unit.make,
      #'simple-ucylinder'    :geometry.simple.ucylinder.unit.make,
      #'simple-sphere'     :geometry.simple.sphere.unit.make,
      #'simple-ellipsoid'  :geometry.simple.ellipsoid.unit.make,
      #'simple-plane'      :geometry.simple.plane.unit.make,
      #'simple-disc'       :geometry.simple.disc.unit.make,
      #'simple-torus'      :geometry.simple.torus.unit.make,
      #'simple-cylinder'   :geometry.simple.cylinder.unit.make,
      #'simple-cone':       geometry.simple.cone.unit.make,
      #'simple-saddle'         : geometry.simple.saddle.unit.make,
      #'simple-paraboloid': geometry.simple.paraboloid.unit.make,

      #'transform-identity'  :geometry.transform.identity.unit.make,
      #
      #'transform-translate-identity'   :geometry.transform.translate.unit.identical,
      #'transform-translate-make'       :geometry.transform.translate.unit.make,
      #
      #'transform-affine-identity'      :geometry.transform.affine.unit.identical,
      #'transform-affine-uniform'       :geometry.transform.affine.unit.uniform,
      #'transform-affine-translate'     :geometry.transform.affine.unit.translate,
      #'transform-affine-make'          :geometry.transform.affine.unit.make,
      #
      #'transform-homography-identity'  :geometry.transform.homography.unit.identical,
      #'transform-homography-uniform'   :geometry.transform.homography.unit.uniform,
      #'transform-homography-translate' :geometry.transform.homography.unit.translate,
      #
      #'transform-mblur'      :geometry.transform.mblur.unit.make,
      #'intersect'            :geometry.complex.intersect.unit.make,

       #'hyper-nuke'    : geometry.simple.hyperboloid.unit.nuke,
       #'hyper-sphere'  : geometry.simple.hyperboloid.unit.sphere,
       #'hyper-cone'    : geometry.simple.hyperboloid.unit.cone,
       #'hyper-cylinder': geometry.simple.hyperboloid.unit.cylinder,
       #'hyper-negative': geometry.simple.hyperboloid.unit.negative,

       #'quadric-planeZ':        geometry.simple.quadric.unit.planeZ,
       #'quadric-sphere':        geometry.simple.quadric.unit.sphere,
       #'quadric-paraboloid':    geometry.simple.quadric.unit.paraboloid,
       #'quadric-hyperboloid':   geometry.simple.quadric.unit.hyperboloid,
       #'quadric-cone':          geometry.simple.quadric.unit.cone,
       #'quadric-cylinder':      geometry.simple.quadric.unit.cylinder,

       #'volumetric-smoke'      :geometry.volumetric.smoke.unit.make,
       #'volumetric-vacuum'     :geometry.volumetric.vacuum.unit.make,
       #
       #'triangle'   :geometry.simple.triangle.unit.make,
       #'tetra'      :geometry.simple.triangle.unit.tetra,
       #'octa'       :geometry.simple.triangle.unit.octa,
       #'icosa'      :geometry.simple.triangle.unit.icosa,

      ## TODO'dodeka'      :geometry.simple.triangle.unit.dodeka,
      ## TODO'hexa'      :geometry.simple.triangle.unit.hexa,

      #'blobby'     :geometry.blobby.unit.make,
      #'blobby_s_solo'     :geometry.blobby.sphere.unit.solo,
      #'blobby_s_line'     :geometry.blobby.sphere.unit.line,
      #'blobby_s_triangle' :geometry.blobby.sphere.unit.triangle,
      #'blobby_s_tetra'    :geometry.blobby.sphere.unit.tetra,
      #'blobby_s_hexa'     :geometry.blobby.sphere.unit.hexa,
      #'blobby_s_octa'     :geometry.blobby.sphere.unit.octa,

  #    'blobby_a-s_a-s'  :geometry.blobby.unit.make_affine_affine_sphere,
  #    'blobby_a-solo'   :geometry.blobby.unit.make_affine_solo,
  #   #'blobby_s-a-s'    :geometry.blobby.unit.make_sphere_affine_sphere,
  #    'blobby_s-t-s'    :geometry.blobby.unit.make_sphere_translate_sphere,
  #    'blobby_s-t-us'   :geometry.blobby.unit.make_sphere_translate_USphere,
  #    'blobby_s-t-uc '  :geometry.blobby.unit.make_sphere_translate_UCylinderZ,
  #    'blobby_s-t-uw '  :geometry.blobby.unit.make_sphere_translate_UWaterZ,
  #    'blobby_s-us'     :geometry.blobby.unit.make_sphere_Usphere,
  #    'blobby_s-uc'     :geometry.blobby.unit.make_sphere_UCylinderZ,
  #    'blobby_s-uw'     :geometry.blobby.unit.make_sphere_UWaterZ,
  #    'blobby_s-solo'   :geometry.blobby.unit.make_sphere_solo,
  #    'blobby_us-solo'  :geometry.blobby.unit.make_USphere_solo,
  #    'blobby_uc-solo'  :geometry.blobby.unit.make_UCylinderZ_solo,
  #    'blobby_uw-solo'  :geometry.blobby.unit.make_UWaterZ_solo,
}

surface_list = {
         #'nothing'              : surface.make_nothing,
         #'mirror'               : surface.make_mirror,
         #'pattern-noisePerlin'          : material.pattern.noise.unit.perlin,
         #'pattern-noiseCrackle'         : material.pattern.noise.unit.crackle,
         #'pattern-noiseValue'           : material.pattern.noise.unit.value,
         #'pattern-noiseCells'           : material.pattern.noise.unit.cells,
         #'pattern-noiseRandom'          : material.pattern.noise.unit.random,
         #'pattern-noiseGold'            : material.pattern.noise.unit.gold,
         #'pattern-noiseVDC'             : material.pattern.noise.unit.vdc,
         #'pattern-hexagon'              : material.pattern.unit.hexagon,
         #'pattern-checker'              : material.pattern.unit.checker,
         #'pattern-brick'                : material.pattern.unit.brick,
         #'pattern-level'                : material.pattern.unit.level,
         #'pattern-onion'                : material.pattern.unit.onion,
         #'pattern-image'                : material.pattern.unit.image,
         #'pattern-waveSin'              : material.pattern.unit.wave_sin,
         #'pattern-waveSaw'              : material.pattern.unit.wave_saw,
         #'pattern-normal2ambient'       : material.pattern.unit.normal,
         #'pattern-spot-UVW'             : material.light.spot.uvw.make,

         #'mapping-cartesian2spherical'  :  material.operation.mapping.cartesian2spherical.make,
         #'mapping-cartesian2woodX'      :  material.operation.mapping.cartesian2woodX.make,
         #'mapping-cartesian2woodY'      :  material.operation.mapping.cartesian2woodY.make,
         #'mapping-cartesian2woodZ'      :  material.operation.mapping.cartesian2woodZ.make,
         #'mapping-cartesian2fisheye'    :  material.operation.mapping.cartesian2fisheye.make,
         #'mapping-cartesian2cylindric'  :  material.operation.mapping.cartesian2cylindric.make,
         #'mapping-cartesian2tablecloth' :  material.operation.mapping.cartesian2tablecloth.make,
         #'mapping-cartesian2torus'      :  material.operation.mapping.cartesian2torus.make,

         #'mapping-cylindric2cartesian'  :  material.operation.mapping.cylindric2cartesian.make,
         #'mapping-cylindric2spherical'  :  material.operation.mapping.cylindric2spherical.make,
         #'mapping-spherical2cartesian'  :  material.operation.mapping.spherical2cartesian.make,
         #'mapping-spherical2cylindric'  :  material.operation.mapping.spherical2cylindric.make,
         #'mapping-cartesian2package'    :  material.operation.mapping.cartesian2package.make,

         # TODO crash 'mapping-euclid2max'           :  material.operation.mapping.euclid2max.make,
         #'mapping-max2euclid'           :  material.operation.mapping.max2euclid.make,

         #'refractFresnel'        : material.transmission.refract.fresnel.unit.make,
         #'refractSchlick'        : material.transmission.refract.schlick.unit.make,
         #'refractArbitrary'      : material.transmission.refract.arbitrary.unit.make,
         #'refractOne'            : material.transmission.refract.one.unit.make,
         #'reflectSchlick'        : material.transmission.reflect.schlick.unit.make,
         #'reflectFresnel'        : material.transmission.reflect.fresnel.unit.make,
         #'reflectOne'            : material.transmission.reflect.one.unit.make,
         #'reflectBHex'           : material.transmission.blossom.hexagon.unit.make,
         #'reflectBGrid'          : material.transmission.blossom.grid.unit.make,
         #'reflectBRand'          : material.transmission.blossom.random.unit.make,
         #'reflectBVDC'           : material.transmission.blossom.vdc.unit.make,
         #'illum-ALP'             : material.illumination.alp.unit.make,
         #'illum-AshShiCmpl'      : material.illumination.AshShi.unit.make_complete,
         #'illum-AshShiDif'       : material.illumination.AshShi.unit.make_diffuse,
         #'illum-AshShiSpec'      : material.illumination.AshShi.unit.make_specular,
         #'illum-ambient'         : material.illumination.ambient.unit.make,
         #'illum-beckmann'        : material.illumination.beckmann.unit.make,
         #'illum-blinn'           : material.illumination.blinn.unit.make,
         #'illum-gaussian'        : material.illumination.gaussian.unit.make,
         #'illum-hs-lambert'      : material.illumination.hs.unit.make_HSLambert,
         #'illum-hs-phong'        : material.illumination.hs.unit.make_HSPhong,
         'illum-lambert'         : material.illumination.lambert.unit.make,
         #'illum-phong'           : material.illumination.phong.unit.make,
         #'illum-ONf30'           : material.illumination.on.unit.make_f30,
         #'illum-ONf29'           : material.illumination.on.unit.make_f29,
         #'illum-ONYF'           : material.illumination.on.unit.make_YasuhiroFujii,
         #'illum-ward-aprox'      : material.illumination.ward.unit.make_aprox,
         #'illum-ward-real'       : material.illumination.ward.unit.make_real,
         #'illum-ward-iso'        : material.illumination.ward.unit.make_isotropic,
     }


medium_list = {
      'constant'      : material.medium.constant.make,
      'exponential'   : material.medium.exponential.make,
      'constant'      : material.medium.linear.make,
      'quadratic'     : material.medium.quadratic.make,
    }



camera_list = {
       'flat-perspective'      : camera.flat.perspective.unit.make,
       #'flat-orthogonal'       : camera.flat.orthogonal.unit.make,

      # 'flat-super-X'            : camera.flat.super.unit.X,
      # 'flat-super-Y'            : camera.flat.super.unit.Y,
      # 'flat-super-orthogonal'   : camera.flat.super.unit.orthogonal,
      # 'flat-super-perspective'  : camera.flat.super.unit.perspective,

      #'cone'                  : camera.dof.cone.unit.make,
      #'focus'                 : camera.dof.focus.unit.make,
      #'sphere-horizontal'     : camera.sphere.horizontal.unit.make,
      #'sphere-vertical'       : camera.sphere.vertical.unit.make,
      #'sphere-fisheye'        : camera.sphere.fisheye.unit.make,
      #'cylinder-vertical'     : camera.cylinder.vertical.unit.make,
      #'cylinder-horizontal'   : camera.cylinder.horizontal.unit.make,

      #'invert-cylinder-vertical'  : camera.invert.unit.cylinder,

      #'sphere-package'    : camera.sphere.package.unit.make,
    }

room_list = {
      #'cornell-close'      : room.cornell_close,
      'cornell-open'      : room.cornell_open,
      #'cube'         : room.cube,
      #'sphere'       : room.sphere,
      #'cylinder'     : room.cylinder
      #'tetra'        : room.tetra
      #'octa'         : room.octa
      #'icosa'        : room.icosa
      #'plane'        : room.plane,
      #'plate'        : room.plate,
      #'vacuum'        : room.vacuum
    }

decoration_list = {
}


def doRendering(P_config):

    folder = str( os.getcwd()[0] ) + ':\\work\\code\\cpp\\prj\\github\\IceRay\\work\\example\\test\\core\\_!out'
    #folder = "_!out"
    for key_room, data_room in room_list.items():
       for key_camera, data_camera in camera_list.items():
           for key_geometry, data_geometry in geometry_list.items():
               for key_surface, data_surface in surface_list.items():
                   for key_light, data_light in light_list.items():

                       name = key_room +"-"+ key_camera +'-'+key_geometry +"-"+ key_surface+"-" + key_light
                       filen_name = folder + "\\" + name + '_'+ "{:04d}".format(P_config['index']) + '.ppm'
                       print ( filen_name )

                       my_file = Path(filen_name)
                       if my_file.is_file():
                          continue

                       exponat = data_geometry()
                       l = light_make( data_light() );
                       s = data_surface( l )
                       c = kamera.make( data_camera()
                                 , P_config['camera']['eye'], P_config['camera']['view'],
                        )
                       m = medium_list['constant']()
                       rendering.work( folder +"\\" + name, data_room, P_config, exponat, l, c, s, m )

                       #break
                   #break
               #break
           #break

def ellipse( P_alpha, P_minor ):
    return [ cos(P_alpha),P_minor*sin(P_alpha)]

def scale2( P_coord, P_alpha ):
    return [ P_alpha * P_coord[0] , P_alpha * P_coord[1] ]

def scale3( P_coord, P_alpha ):
    return [ P_alpha * P_coord[0] , P_alpha * P_coord[1], P_alpha * P_coord[2] ]

def translate( P_coord, P_move ):
    return [ P_move[0] + P_coord[0] , P_move[1] +  P_coord[1] ]

def rotate( P_coord, P_alpha ):
    return [ P_coord[0] * cos(P_alpha) - P_coord[1] * sin(P_alpha) ,
             P_coord[0] * sin(P_alpha) + P_coord[1] * cos(P_alpha) ]

#def angle( P_A, P_B ):
#    return [ P_coord[0] * cos(P_alpha) - P_coord[1] * sin(P_alpha) ,
#             P_coord[0] * sin(P_alpha) + P_coord[1] * cos(P_alpha) ]

def len3( P_coord ):
    #print ( P_coord )
    return math.sqrt(  P_coord[0]*P_coord[0] + P_coord[1]*P_coord[1]   )

def len_ABS( P_coord ):
    #print ( P_coord )
    return math.max( math.abs( P_coord[0]), math.abs( P_coord[1]),math.abs( P_coord[2]) )

start = 0;
if( 1 < len( sys.argv ) ):
    start= int( sys.argv[1] )

step = 1
if( 2 < len( sys.argv ) ):
    step  = int( sys.argv[2] )

for i in range( start, 360, step ):
    t = i/360.0
    alpha = t * ( 2 * 3.1415926 )

    height =     ( math.cos( 2* alpha ) + 1 )/2 ;
    height = 3 * ( math.cos(    alpha ) + 1 )/2 *  height;

    x = 2 * math.cos( alpha );
    y = ( 3*( math.cos( alpha ) +1)/2 + 1 ) * math.sin( alpha );
    eye = [x*0.8, y*0.8, height*0.8];

    print( "Index:" + str(i) + "[" + os.getcwd() + "]" )

    doRendering( { 'angle' : 0,
                   'sample': 1,
                   'index' : i,
                   'pixelStrategyGridSize': 1,
                   'ray-trace-depth': 32,
                   'hot' :{ 'x': 460, 'y': 214 },
                   'image': { 'scale': 1, 'width': 3.46*200, 'height': 3.46*200 },
                   #'room' { 'size':[1,1,1], 'move':[0,0,0]}
                   'camera': {
                       'eye' : IceRayCpp.MathTypeCoord3D().load( x, y, height )
                      ,'view': IceRayCpp.MathTypeCoord3D().fill( 0 )
                   }
                  } )
