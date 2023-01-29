import math
import IceRayPy

Coord3D = IceRayPy.type.math.coord.Scalar3D


def time( P_index, P_dilatation ):
    return P_index / P_dilatation


def alpha( P_time ):
    return math.radians( P_time )


def default( P_time, P_config = None ):
    I_radius = 3

    if( 'radius' in P_config ):
        I_radius = P_config['radius']

    x = 0
    y = I_radius
    z = 0

    return [x,y,z]

def debug( P_time, P_config = None ):
    I_radius = 3

    x = +0.25
    y = -0.25
    z = +0.25

    return [x,y,z]

def circle( P_time, P_config = None ):
    I_radius = 3
    I_height = 0

    if( 'radius' in P_config ):
        I_radius = P_config['radius']
    if( 'height' in P_config ):
        I_height = P_config['height']

    x = I_radius * math.cos( ( 2 * 3.1415926 ) * P_time - math.pi/2 )
    y = I_radius * math.sin( ( 2 * 3.1415926 ) * P_time - math.pi/2 )
    z = I_height

    return [x,y,z]

def looker( P_time, P_config = None ):

    radiusX_lo = 1.2
    radiusX_hi = 3

    heightHi = 2
    heightLo = 0


    alpha = P_time * ( 2 * 3.1415926 )
    height = heightLo
    x =  math.cos( alpha - math.pi/2 )
    y =  math.sin( alpha - math.pi/2 )

    if( math.degrees(alpha) < 360 ):
        radiusS = radiusX_lo + ( ( math.degrees(alpha) - 270.0)/90.0)*( radiusX_hi - radiusX_lo )
        height = heightHi + ( ( math.degrees(alpha) -270.0)/90.0)*( heightLo - heightHi );

    if( math.degrees(alpha) < 270 ):
        radiusS = radiusX_lo
        height = heightHi ;

    if( math.degrees(alpha) < 180 ):
        radiusS = radiusX_hi + ( ( math.degrees(alpha) -90.0)/90.0)*( radiusX_lo - radiusX_hi )
        height = heightLo + ( ( math.degrees(alpha) -90.0)/90.0)*( heightHi - heightLo );

    if( math.degrees(alpha) < 90 ):
        radiusS = radiusX_hi
        height = heightLo

    x =  x * radiusS
    y =  y * radiusS

    print( "Camera: ", math.degrees(alpha), " _ [" ,  x, ",", y, ",", height, "]  ||", math.sqrt( x*x+ y*y ), "||" )

    return [x,y,height]
