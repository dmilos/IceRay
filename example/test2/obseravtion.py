import math
import IceRayPy

Coord3D = IceRayPy.type.math.coord.Scalar3D



def time( P_index, P_dilatation ):
    return P_index / P_dilatation


def alpha( P_time ):
    return math.radians( P_time )


def circle( P_alpha, P_config = None ):
    I_radius = 3

    if( 'radius' in P_config ):
        I_radius = P_config['radius']

    x = I_radius * math.cos( P_parameter - math.pi/2 )
    y = I_radius * math.sin( P_parameter - math.pi/2 )
    z = 0

    return [x,y,z]

def lookeer( P_parameter, P_config = None ):
    heightLo
    radiusX_lo
    heightHi
    radiusX_hi

    alpha = P_parameter * ( 2 * 3.1415926 )
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

    return [x,y,height]
