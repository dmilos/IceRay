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

    blocked = IceRayCpp.LightBlocked()

    blocked.light( P_light['this'] )

    return { 'this': blocked, '0': P_light }


import geometry
from geometry.complex.intersect.unit import make


import light
from light.point.unit       import make

import camera

light_list = {
    'point'    : light.point.unit.make,
}

geometry_list = {
    'intersect'  :geometry.complex.intersect.unit.make,
}

surface_list = {
    'lambert' : surface.make_lambert,
    }

#cam = IceRayCpp.CameraFlatPerspective()

camera_list = {
    'perspective' : IceRayCpp.CameraFlatPerspective,
    'cone'        : IceRayCpp.CameraCone,
    'focal'       : IceRayCpp.CameraFocus,
    }

cam = IceRayCpp.CameraFlatPerspective()

where2string={
    IceRayCpp.Geometry_Inside.nowhere      :     "nowhere"   ,
    IceRayCpp.Geometry_Inside.inside       :     "inside"        ,
    IceRayCpp.Geometry_Inside.outside      :     "outside"       ,
    IceRayCpp.Geometry_Inside.symmetric    :     "symmetric"  ,
    IceRayCpp.Geometry_Inside.surface      :     "surface"   ,
    IceRayCpp.Geometry_Inside.closure      :     "closure"   ,
    IceRayCpp.Geometry_Inside.complement   :     "complement",
    IceRayCpp.Geometry_Inside.everywhere   :     "everywhere"

}


for left in range( IceRayCpp.Geometry_Inside.nowhere,IceRayCpp.Geometry_Inside.everywhere+1):
    for right in range(IceRayCpp.Geometry_Inside.nowhere,IceRayCpp.Geometry_Inside.everywhere+1):
        g = geometry_list['intersect']( left, right )
        l = light_make( light_list['point']() );
        s = surface_list['lambert']( l )
        c = camera.make( cam, 0.6* IceRayCpp.MathTypeCoord3D().load( 2, 3, 1.8) )
    
        rendering.work( '_!out\\csg-' + where2string[  left ] + "-" + where2string[right], g, l, c, s )


