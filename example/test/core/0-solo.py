import sys
import time
import IceRayCpp

import engine
import image
import room
import surface
import light
import rendering


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
from geometry.simple.plane.unit import make
from geometry.simple.quadric.unit import make
from geometry.simple.sphere.unit import make
from geometry.simple.torus.unit import make
from geometry.simple.triangle.unit import make
from geometry.simple.usphere.unit import make
from geometry.volumetric.smoke.unit import make
from geometry.volumetric.vacuum.unit import make
from geometry.transform.mblur.unit import make
from geometry.complex.intersect.unit import make
from geometry.blobby.unit import make

from geometry.transform.mblur.unit import make
from geometry.transform.translate.unit import make
from geometry.transform.affine.unit import make

import material.pattern.unit
import material.geometry.unit
import material.illumination.hs.unit

import light
from light.circle.unit      import make
from light.area.unit        import make
from light.disc.unit        import make
from light.line.unit        import make
from light.point.unit       import make
from light.sun.unit         import make
from light.reflector.unit   import make
from light.spline.unit      import make
from light.sphere.unit      import make

from material.illumination.hs.unit      import *
from material.illumination.on.unit      import *
from material.illumination.ward.unit    import *


import camera

light_list = {
     'point'    : light.point.unit.make,
     #'line'     : light.line.unit.make,
     #'reflector': light.reflector.unit.make,
     #'circle'   : light.circle.unit.make,
     #'area'     : light.area.unit.make,
     #'disc'     : light.disc.unit.make,
     #'sun'      : light.sun.unit.make,
     #'spline'   : light.spline.unit.make
}

geometry_list = {
      'sphere'     :geometry.simple.sphere.unit.make,
     #'box':        geometry.simple.box.unit.make,
     #'affine'     :geometry.transform.affine.unit.make,
     #'blobby'     :geometry.blobby.unit.make,
     #'translate'  :geometry.transform.translate.unit.make,
     #'intersect'  :geometry.complex.intersect.unit.make,
     #'disc':       geometry.simple.disc.unit.make,
     #'cylinder'   :geometry.simple.cylinder.unit.make,
     #'plane':      geometry.simple.plane.unit.make,
     #'cone':       geometry.simple.cone.unit.make,
     #'paraboloid': geometry.simple.paraboloid.unit.make,
     #'quadric':    geometry.simple.quadric.unit.make,
     #'smoke'      :geometry.volumetric.smoke.unit.make,
     #'torus'      :geometry.simple.torus.unit.make,
     #'triangle'   :geometry.simple.triangle.unit.make,
     #'usphere'    :geometry.simple.usphere.unit.make,
     #'vacuum'     :geometry.volumetric.vacuum.unit.make,
     #'mblur'      :geometry.transform.mblur.unit.make,
}

surface_list = {
     'ward-aprox' : material.illumination.ward.unit.make_aprox,
     'ward-real'  : material.illumination.ward.unit.make_real,
     'ward-iso'   : material.illumination.ward.unit.make_isotropic,
     'gussian'   : surface.make_gussian,
     'lambert'   : surface.make_lambert,
     'ambient'   : surface.make_ambient,
     'blinn'     : surface.make_blinn,
     'beckmann'  : surface.make_Beckmann,
     'phong'     : surface.make_phong,
     'hs-lambert' : material.illumination.hs.unit.make_HSLambert,
     'hs-phong'   : material.illumination.hs.unit.make_HSPhong,
     'ONf30'      : material.illumination.on.unit.make_f30,
     'ONf29'      : material.illumination.on.unit.make_f29,

     }
#cam = IceRayCpp.CameraFlatPerspective()

camera_list = {
    'perspective' : IceRayCpp.CameraFlatPerspective,
    'cone'        : IceRayCpp.CameraCone,
    'focal'       : IceRayCpp.CameraFocus,
    }

cam = camera_list['perspective']()

#cam = IceRayCpp.CameraFocus()
#cam.aperture( IceRayCpp.MathTypeInterval1D( 0.1, 0 ) )
#cam.focus(    IceRayCpp.MathTypeInterval1D ( 6, 6 ) )
#cam.sample(4)
#cam.gauss(1)

#for alpha in range(0,200,2):
#    g = geometry_list['affine'](IceRayCpp.MathTypeCoord3D().load(1,1,alpha/1000))
#    l = light_make( light_list['point']() );
#    s = surface_list['gussian']( l )
#    c = camera.make( cam, IceRayCpp.MathTypeCoord3D().load( 1, 5, 3 )*0.4 )
#
#    main( '_!out\\asd_' + str(alpha), g, l, c, s )


for key_geometry, data_geometry in geometry_list.items():
    for key_surface, data_surface in surface_list.items():
        for key_light, data_light in light_list.items():

            exponat = data_geometry()
            l = light_make( data_light() );
            s = data_surface( l )
            c = camera.make( cam )

            print ( key_geometry +"-"+ key_surface+"-"+ key_light )
            rendering.work( '_!out\\' + key_geometry +"-"+key_surface +"-"+key_light, exponat, l, c, s )
            #break
        #break
    #break


