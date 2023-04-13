#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math
Coord3D = IceRayPy.type.math.coord.Scalar3D


def Pair( P_dll, P_config = None ):

    I_distance = 0
    if( None != P_config ):
        if( 'distance' in P_config ):
            I_distance = P_config['distance']

    reuslt = IceRayPy.core.geometry.blobby.System( P_dll )
    s = IceRayPy.core.geometry.blobby.element.Sphere( P_dll )
    s.center( Coord3D(-I_distance,0,0))
    reuslt.push( s )
    s = IceRayPy.core.geometry.blobby.element.Sphere( P_dll )
    s.center( Coord3D(+I_distance,0,0))
    reuslt.push( s )

    return reuslt


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
