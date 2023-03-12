#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy

Coord3D = IceRayPy.type.math.coord.Scalar3D

def Symetric( P_dll,
        P_center = Coord3D( 0, 0,0 ),
        P_normal = Coord3D( 1, 1, 1 ),
        P_radius = 2,
        P_thick = 0.3
        ):

    radius = ( (P_radius/2)*(P_radius/2) + (P_thick/2)*(P_thick/2) ) / P_thick
    center = radius - P_thick / 2
    #print(__file__ + " center: " + str(center), flush = True );
    #print(__file__ + " radius: " + str(radius), flush = True );
    I_normal = IceRayPy.type.math.coord.scale3D( P_dll, 1.0 / IceRayPy.type.math.coord.length3D( P_dll, P_normal), P_normal )
    cL = IceRayPy.type.math.coord.addition3D( P_dll, IceRayPy.type.math.coord.scale3D( P_dll, +center, I_normal ), P_center )
    cR = IceRayPy.type.math.coord.addition3D( P_dll, IceRayPy.type.math.coord.scale3D( P_dll, -center, I_normal ), P_center )

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, cL, radius )
    right = IceRayPy.core.geometry.simple.Sphere( P_dll, cR, radius )
    result = IceRayPy.core.geometry.complex.Intersect( P_dll )

    result.left( left )
    result.right( right )

    return result

def Asymetric( P_dll,
        P_center = Coord3D( 0, 0,0 ),
        P_normal = Coord3D( 1, 1, 1 ),
        P_inner = 0.1,
        P_out = 0.3,
        P_shift = 0.1,
        ): #<! TODO

    radius = 0.75
    center = 0.5
    #print(__file__ + " center: " + str(center), flush = True );
    #print(__file__ + " radius: " + str(radius), flush = True );

    I_normal = IceRayPy.type.math.coord.scale3D( P_dll, 1.0 / IceRayPy.type.math.coord.length3D( P_dll, P_normal), P_normal )
    cL = IceRayPy.type.math.coord.addition3D( P_dll, IceRayPy.type.math.coord.scale3D( P_dll, +center, I_normal ), P_center )
    cR = IceRayPy.type.math.coord.addition3D( P_dll, IceRayPy.type.math.coord.scale3D( P_dll, -center, I_normal ), P_center )

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, cL, radius )
    right = IceRayPy.core.geometry.simple.Sphere( P_dll, cR, radius )

    union = IceRayPy.core.geometry.complex.Intersect( P_dll )
    union.left(   left, IceRayPy.core.geometry.complex.Intersect.OUT )
    union.right( right, IceRayPy.core.geometry.complex.Intersect.OUT )

    cylinder = IceRayPy.core.geometry.flat.Box( P_dll, IceRayPy.type.math.coord.Scalar3D( -0.2,-0.2, -0.75 ), IceRayPy.type.math.coord.Scalar3D( +0.2, +0.2, +0.75 ) )
    intersect = IceRayPy.core.geometry.complex.Intersect( P_dll )
    intersect.left( union, IceRayPy.core.geometry.complex.Intersect.OUT )
    intersect.right( cylinder )

    return union


def Plano( P_dll,
        P_center = Coord3D( 0, 0, 0 ),
        P_normal = Coord3D( 1, 1, 1 ),
        P_radius = 2,
        P_thick = 0.3/2
        ):

    radius = ( (P_radius/2)*(P_radius/2) + (P_thick)*(P_thick) ) / (2*P_thick)
    center = radius - P_thick
    #print(__file__ + " center: " + str(center), flush = True );
    #p rint(__file__ + " radius: " + str(radius), flush = True );
    I_normal = IceRayPy.type.math.coord.scale3D( P_dll, -1.0 / IceRayPy.type.math.coord.length3D( P_dll, P_normal), P_normal )
    cL = IceRayPy.type.math.coord.addition3D( P_dll, IceRayPy.type.math.coord.scale3D( P_dll, +center, I_normal ), P_center )

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, cL, radius )
    right = IceRayPy.core.geometry.flat.Plane( P_dll, P_center, I_normal )
    intersect = IceRayPy.core.geometry.complex.Intersect( P_dll )

    intersect.left( left )
    intersect.right( right )

    return intersect

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
