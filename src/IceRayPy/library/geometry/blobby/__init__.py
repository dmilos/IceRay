#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math
Coord3D = IceRayPy.type.math.coord.Scalar3D

G_distance = 0.01

def Pair( P_dll, P_config = None ):

    global G_distance
    reuslt = IceRayPy.core.geometry.blobby.System( P_dll )
    s = IceRayPy.core.geometry.blobby.element.Sphere( P_dll )
    s.center( Coord3D(-G_distance,0,0))
    reuslt.push( s )
    s = IceRayPy.core.geometry.blobby.element.Sphere( P_dll )
    s.center( Coord3D(+G_distance,0,0))
    reuslt.push( s )

    G_distance = G_distance + 0.01
    return reuslt


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
