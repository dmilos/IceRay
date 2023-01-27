print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math

Coord3D = IceRayPy.type.math.coord.Scalar3D

G_inner = 0;

def Symetric( P_dll,
        P_center = Coord3D( 0, 0,0 ),
        P_normal = Coord3D( 0, 1,0 ),
        P_inner = 0.0,
        P_out = 1,
        ):
    #global G_inner
    #G_inner = G_inner + 0.01
    #P_out = G_inner
    delta = P_out/2 - P_inner/2
    radius = (delta*delta+1)/(2*delta)
    center = radius + P_inner/2
    print(__file__ + " inner: "  + str(P_inner), flush = True );
    print(__file__ + " out: "    + str(P_out),   flush = True );
    print(__file__ + " center: " + str(center), flush = True );
    print(__file__ + " radius: " + str(radius), flush = True );
    print(__file__ + " delta: " + str( radius - math.sqrt( radius*radius - 1 )), flush = True );
    print(__file__ + " distance(in): " + str( center - radius  ), flush = True );

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( 0,0, -center ), radius )
    right = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( 0,0, +center ), radius )

    union = IceRayPy.core.geometry.complex.Intersect( P_dll )
    union.left(   left, IceRayPy.core.geometry.complex.Intersect.OUT )
    union.right( right, IceRayPy.core.geometry.complex.Intersect.OUT )

    cylinder = IceRayPy.core.geometry.simple.Cylinder( P_dll )
    cylinder = IceRayPy.core.geometry.simple.Box( P_dll, Coord3D(-1,-1,-1), Coord3D(+1,+1,+1) )
    
    intersect = IceRayPy.core.geometry.complex.Intersect( P_dll )
    intersect.left( union, IceRayPy.core.geometry.complex.Intersect.OUT )
    intersect.right( cylinder, IceRayPy.core.geometry.complex.Intersect.IN ) #!< force IN

    return intersect

def Asymetric( P_dll,
        P_center = Coord3D( 0, 0,0 ),
        P_normal = Coord3D( 0, 1,0 ),
        P_inner = 0.1,
        P_out = 0.3,
        ): #<! TODO

    radius = 0.75
    center = 0.5
    #print(__file__ + " center: " + str(center), flush = True );
    #print(__file__ + " radius: " + str(radius), flush = True );

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( 0,0, -center ), radius )
    right = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( 0,0, +center ), radius )

    union = IceRayPy.core.geometry.complex.Intersect( P_dll )
    union.left(   left, IceRayPy.core.geometry.complex.Intersect.OUT )
    union.right( right, IceRayPy.core.geometry.complex.Intersect.OUT )

    cylinder = IceRayPy.core.geometry.simple.Box( P_dll, IceRayPy.type.math.coord.Scalar3D( -0.2,-0.2, -0.75 ), IceRayPy.type.math.coord.Scalar3D( +0.2, +0.2, +0.75 ) )
    intersect = IceRayPy.core.geometry.complex.Intersect( P_dll )
    intersect.left( union, IceRayPy.core.geometry.complex.Intersect.OUT )
    intersect.right( cylinder )

    return union

def Plano( P_dll,
        P_center = Coord3D( 0, 0,0 ),
        P_normal = Coord3D( 0, 1,0 ),
        P_inner = 0.1,
        P_out = 0.3,
        ): #<! TODO

    radius = 2
    center = 0.1 + radius
    width = 0.6
    height = 0.5
    #print(__file__ + " center: " + str(center), flush = True );
    #print(__file__ + " radius: " + str(radius), flush = True );

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( 0,0, -center ), radius )
    right = IceRayPy.core.geometry.simple.Plane( P_dll, IceRayPy.type.math.coord.Scalar3D( 0 , 0, 0 ), IceRayPy.type.math.coord.Scalar3D( -1, 0, 0 ) )

    union = IceRayPy.core.geometry.complex.Intersect( P_dll )
    union.left(   left, IceRayPy.core.geometry.complex.Intersect.OUT )
    union.right( right, IceRayPy.core.geometry.complex.Intersect.OUT )

    cylinder = IceRayPy.core.geometry.simple.Cylinder( P_dll )
    intersect = IceRayPy.core.geometry.complex.Intersect( P_dll )
    intersect.left( union, IceRayPy.core.geometry.complex.Intersect.OUT )
    intersect.right( cylinder, IceRayPy.core.geometry.complex.Intersect.IN ) #!< force IN

    return intersect





print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
