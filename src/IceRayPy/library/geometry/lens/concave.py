#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math

Coord3D = IceRayPy.type.math.coord.Scalar3D

def Symetric( P_dll, P_config = None ):

    I_center = Coord3D( 0, 0, 0 )
    I_normal = Coord3D( 1, 1, 1 )
    I_inner = 0.1
    I_out = 0.5

    center = ( I_out/2+I_inner/2 + 1/( I_out/2-I_inner/2 ) ) /2
    radius = math.fabs( center - I_inner/2 )

    #print(__file__ + " inner: "  + str(P_inner), flush = True );
    #print(__file__ + " out: "    + str(P_out),   flush = True );
    #print(__file__ + " center: " + str(center), flush = True );
    #print(__file__ + " radius: " + str(radius), flush = True );
    #print(__file__ + " distance(in): " + str( center - radius  ), flush = True );
    #print(__file__ + " ZERO(test): " + str( (P_out/2-center)*(P_out/2-center) + 1 - radius*radius ), flush = True );

    I_normal = IceRayPy.type.math.coord.scale3D( P_dll, 1.0 / IceRayPy.type.math.coord.length3D( P_dll, I_normal ), I_normal )
    cL = IceRayPy.type.math.coord.addition3D( P_dll, IceRayPy.type.math.coord.scale3D( P_dll, +center, I_normal ), I_center )
    cR = IceRayPy.type.math.coord.addition3D( P_dll, IceRayPy.type.math.coord.scale3D( P_dll, -center, I_normal ), I_center )

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, cL, radius )
    right = IceRayPy.core.geometry.simple.Sphere( P_dll, cR, radius )

    union = IceRayPy.core.geometry.complex.Intersect( P_dll )
    union.left(   left, IceRayPy.core.geometry.complex.Intersect.OUT )
    union.right( right, IceRayPy.core.geometry.complex.Intersect.OUT )

    cylinder = IceRayPy.utility.geometry.simple.CylinderG( P_dll )
    cylinder.top( cL )
    cylinder.bottom( cR )
    cylinder.radius( 1 )

    intersect = IceRayPy.core.geometry.complex.Intersect( P_dll )
    intersect.left(     union, IceRayPy.core.geometry.complex.Intersect.IN )
    intersect.right( cylinder, IceRayPy.core.geometry.complex.Intersect.IN ) #!< force IN

    return intersect

def Asymetric( P_dll, P_config = None ):

    I_center = Coord3D( 0, 0,0 ), #!< TODO
    I_normal = Coord3D( 0, 1,0 ), #!< TODO
    I_inner = 0.1,
    I_out = 0.3,
    I_shift = 0.3,

    radius = 0.75
    center = 0.5
    #print(__file__ + " center: " + str(center), flush = True );
    #print(__file__ + " radius: " + str(radius), flush = True );

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( 0,0, -center ), radius )
    right = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( 0,0, +center ), radius )

    union = IceRayPy.core.geometry.complex.Intersect( P_dll )
    union.left(   left, IceRayPy.core.geometry.complex.Intersect.OUT )
    union.right( right, IceRayPy.core.geometry.complex.Intersect.OUT )

    cylinder = IceRayPy.core.geometry.flat.Box( P_dll, IceRayPy.type.math.coord.Scalar3D( -0.2,-0.2, -0.75 ), IceRayPy.type.math.coord.Scalar3D( +0.2, +0.2, +0.75 ) )
    intersect = IceRayPy.core.geometry.complex.Intersect( P_dll )
    intersect.left( union, IceRayPy.core.geometry.complex.Intersect.OUT )
    intersect.right( cylinder )

    return union

def Plano( P_dll, P_config = None ):

    P_center = Coord3D( 0, 0, 0 ) 
    P_normal = Coord3D( 1, 1, 1 ) 
    P_inner = 0.1 
    P_out = 0.25 

    center = ( P_out+P_inner + 1/( P_out-P_inner ) ) /2
    radius = math.fabs( center - P_inner )

    print(__file__ + " inner: "  + str(P_inner), flush = True );
    print(__file__ + " out: "    + str(P_out),   flush = True );
    print(__file__ + " center: " + str(center), flush = True );
    print(__file__ + " radius: " + str(radius), flush = True );
    print(__file__ + " distance(in): " + str( center - radius  ), flush = True );
    print(__file__ + " ZERO(test): " + str( (P_out-center)*(P_out-center) + 1 - radius*radius ), flush = True );

    I_normal = IceRayPy.type.math.coord.scale3D( P_dll, -1.0 / IceRayPy.type.math.coord.length3D( P_dll, P_normal ), P_normal )
    cL = IceRayPy.type.math.coord.addition3D( P_dll, IceRayPy.type.math.coord.scale3D( P_dll, -center, I_normal ), P_center )
    cR = IceRayPy.type.math.coord.addition3D( P_dll, IceRayPy.type.math.coord.scale3D( P_dll, +center, I_normal ), P_center )

    sphere  = IceRayPy.core.geometry.simple.Sphere( P_dll, cL, radius )
    plane  = IceRayPy.core.geometry.flat.Plane( P_dll, P_center, I_normal )
    cylinder = IceRayPy.core.geometry.simple.Cylinder( P_dll )
    cylinder = IceRayPy.utility.geometry.simple.CylinderG( P_dll )
    cylinder.top( cL )
    cylinder.bottom( cR )
    cylinder.radius( 1 )

    union = IceRayPy.core.geometry.complex.Intersect( P_dll )
    union.left(    sphere, IceRayPy.core.geometry.complex.Intersect.OUT )
    union.right( cylinder, IceRayPy.core.geometry.complex.Intersect.IN  )

    result = IceRayPy.core.geometry.complex.Intersect( P_dll )
    result.left(  union, IceRayPy.core.geometry.complex.Intersect.IN )
    result.right( plane, IceRayPy.core.geometry.complex.Intersect.IN ) #!< force IN

    return result


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
