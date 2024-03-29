#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math
Coord3D = IceRayPy.type.math.coord.Scalar3D

def Cookie( P_dll, P_config = None ):

    radius = 1;
    top = 0
    bottom = -0.5

    cylinder = IceRayPy.utility.geometry.simple.CylinderG( P_dll )
    cylinder.top(    Coord3D( 0, 0,  top    ) )
    cylinder.bottom( Coord3D( 0, 0,  bottom ) )
    cylinder.radius( radius )

    torus = IceRayPy.utility.geometry.simple.Torus( P_dll )
    torus.minor( 0.2 )
    torus.mayor( 0.8 )
    torus.center( Coord3D( 0, 0, top ) )
    torus.normal( Coord3D( 0, 0, 1 ) )

    discT = IceRayPy.core.geometry.flat.Plane( P_dll )
    discT.origin( Coord3D( 0, 0, top - 0.0001 ) )
    discT.normal( Coord3D( 0, 0,  +1 ) )

    unionA = IceRayPy.core.geometry.complex.Intersect( P_dll )
    unionA.left(  cylinder )
    unionA.right( discT    )

    discB = IceRayPy.core.geometry.flat.Plane( P_dll )
    discB.origin( Coord3D( 0, 0,  bottom + 0.0001 ) )
    discB.normal( Coord3D( 0, 0, -1 ) )

    unionB = IceRayPy.core.geometry.complex.Intersect( P_dll )
    unionB.left(  unionA  )
    unionB.right( discB   )

    unionC = IceRayPy.core.geometry.complex.Intersect( P_dll )
    unionC.left(  unionB, IceRayPy.core.geometry.complex.Intersect.OUT )
    unionC.right( torus,  IceRayPy.core.geometry.complex.Intersect.OUT )
    unionC.invert( True )

    return unionC

def IntersectGeneral( P_dll
     ,surfaceA = IceRayPy.core.geometry.complex.Intersect.IN
     ,surfaceB = IceRayPy.core.geometry.complex.Intersect.IN
    ):

    radius = 1.2793044095787293670386339508102 #!< sqrt( 2/p+1 )

    edge = 0.999
    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( 0,0, 0 ), radius )
    right = IceRayPy.core.geometry.flat.Box( P_dll, IceRayPy.type.math.coord.Scalar3D(  -edge, -edge, -edge ), IceRayPy.type.math.coord.Scalar3D( +edge, +edge, +edge ) )

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


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
