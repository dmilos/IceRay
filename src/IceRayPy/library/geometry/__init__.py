print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math
Coord3D = IceRayPy.type.math.coord.Scalar3D

def OneM( P_dll ):

    X = 40
    Y = 40
    Z = 40
    rtss = IceRayPy.core.geometry.rtss.Object( P_dll )

    rtss.rtss( IceRayPy.core.geometry.rtss.Uniform( P_dll, IceRayPy.type.math.coord.Size3D(X,Y,Z) ) )
    #rtss.rtss( IceRayPy.core.geometry.rtss.List( P_dll ) )

    radius = 1
    r = radius * ( 2/X )/2

    for i in range( 0, X ):
        for j in range( 0, Y ):
            for k in range( 0, Z ):
                x = i* 2/X + 1/X - 1
                y = j* 2/Y + 1/Y - 1
                z = k* 2/Z + 1/Z - 1

                rtss.push( IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( x , y, z ), r ) )

    rtss.optimize()

    return rtss

def MotionBlur( P_dll ):
    radius = 0.5
    center = Coord3D( -1+radius, 0, 0 )
    direction = Coord3D( -center[0]-center[0], -center[1]-center[1], -center[2]-center[2] )

    result = IceRayPy.core.geometry.transform.MotionBlur( P_dll )
    child = IceRayPy.core.geometry.simple.Sphere( P_dll, center, radius )

    result.direction( direction )
    result.child( child )

    return result

def Lens( P_dll,
        P_center = Coord3D( 0, 0,0 ),
        P_normal = Coord3D( 0, 1,0 ),
        P_radius = 2,
        P_thick = 0.3
        ):

    radius = ( (P_radius/2)*(P_radius/2) + (P_thick/2)*(P_thick/2) ) / P_thick 
    center = radius - P_thick / 2
    #print(__file__ + " center: " + str(center), flush = True );
    #print(__file__ + " radius: " + str(radius), flush = True );

    left  = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( -center , 0, 0 ), radius )
    right = IceRayPy.core.geometry.simple.Sphere( P_dll, IceRayPy.type.math.coord.Scalar3D( +center , 0, 0 ), radius )
    result = IceRayPy.core.geometry.complex.Intersect( P_dll )

    result.left( left )
    result.right( right )

    return result


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
