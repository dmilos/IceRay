print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math
Coord3D = IceRayPy.type.math.coord.Scalar3D

def IntersectGeneral( P_dll
     ,surfaceA = IceRayPy.core.geometry.complex.Intersect.IN
     ,surfaceB = IceRayPy.core.geometry.complex.Intersect.IN
    ):

    radius = 1.2793044095787293670386339508102 #!< sqrt( 2/p+1 )

    edge = 0.999
    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( 0,0, 0 ), radius )
    right = IceRayPy.core.geometry.simple.Box( P_dll, IceRayPy.type.math.coord.Scalar3D(  -edge, -edge, -edge ), IceRayPy.type.math.coord.Scalar3D( +edge, +edge, +edge ) )

    intersect = IceRayPy.core.geometry.complex.Intersect( P_dll )
    intersect.left(  left, surfaceA )
    intersect.right( right  , surfaceB )

    return intersect

def Intersect_IN_IN( P_dll ):
    return IntersectGeneral( P_dll, IceRayPy.core.geometry.complex.Intersect.IN, IceRayPy.core.geometry.complex.Intersect.IN  )

def Intersect_IN_OUT( P_dll ):
    return IntersectGeneral( P_dll, IceRayPy.core.geometry.complex.Intersect.IN, IceRayPy.core.geometry.complex.Intersect.OUT  )

def Intersect_IN_SURFACE( P_dll ):
    return IntersectGeneral( P_dll, IceRayPy.core.geometry.complex.Intersect.IN, IceRayPy.core.geometry.complex.Intersect.SURFACE  )

def Intersect_OUT_IN( P_dll ):
    return IntersectGeneral( P_dll, IceRayPy.core.geometry.complex.Intersect.OUT, IceRayPy.core.geometry.complex.Intersect.IN  )

def Intersect_OUT_OUT( P_dll ):
    return IntersectGeneral( P_dll, IceRayPy.core.geometry.complex.Intersect.OUT, IceRayPy.core.geometry.complex.Intersect.OUT  )

def Intersect_OUT_SURFACE( P_dll ):
    return IntersectGeneral( P_dll, IceRayPy.core.geometry.complex.Intersect.OUT, IceRayPy.core.geometry.complex.Intersect.SURFACE  )

def Intersect_SURFACE_IN( P_dll ):
    return IntersectGeneral( P_dll, IceRayPy.core.geometry.complex.Intersect.SURFACE, IceRayPy.core.geometry.complex.Intersect.IN  )

def Intersect_SURFACE_OUT( P_dll ):
    return IntersectGeneral( P_dll, IceRayPy.core.geometry.complex.Intersect.SURFACE, IceRayPy.core.geometry.complex.Intersect.OUT  )

def Intersect_SURFACE_SURFACE( P_dll ):
    return IntersectGeneral( P_dll, IceRayPy.core.geometry.complex.Intersect.SURFACE, IceRayPy.core.geometry.complex.Intersect.SURFACE  )


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
