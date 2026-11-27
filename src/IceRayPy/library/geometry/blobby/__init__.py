#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math
Coord3D = IceRayPy.type.math.coord.Scalar3D


def Pair( P_dll, P_config = None ):

    I_distance = 0.5
    if( None != P_config ):
        if( 'distance' in P_config ):
            I_distance = P_config['distance']

    I_radius = 0.5
    if( None != P_config ):
        if( 'radius' in P_config ):
            I_radius = P_config['radius']

    I_influence = 0.5
    if( None != P_config ):
        if( 'influence' in P_config ):
            I_influence = P_config['influence']

    reuslt = IceRayPy.core.geometry.blobby.System( P_dll )
    s = IceRayPy.core.geometry.blobby.element.Sphere( P_dll )
    s.center( Coord3D( -I_distance, 0, 0 ) )
    s.radius( I_radius )
    s.influence( I_influence )
    reuslt.push( s )

    s = IceRayPy.core.geometry.blobby.element.Sphere( P_dll )
    s.center( Coord3D( +I_distance, 0, 0 ) )
    s.radius( I_radius )
    s.influence( I_influence )
    reuslt.push( s )

    s = IceRayPy.core.geometry.blobby.element.Sphere( P_dll )
    s.center( Coord3D( 0, 0, ( 2*I_distance  )*math.sqrt( 3 )/2.0  ) )
    s.radius( I_radius )
    s.influence( I_influence )
    reuslt.push( s )


    return reuslt


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
