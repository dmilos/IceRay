#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math

Size2D = IceRayPy.type.math.coord.Size2D
Coord3D = IceRayPy.type.math.coord.Scalar3D
def Identity( P_dll,
        P_config = None,
        ):
    result = IceRayPy.core.geometry.transform.Identity(P_dll)

    I_child =  IceRayPy.core.geometry.simple.Sphere( P_dll ) #<! default

    if( None != P_config ):
        if( 'child' in P_config ):
            I_child = P_config['child']

    result.child( I_child )
    return result

def Translate( P_dll,
        P_config = None,
        ):
    result = IceRayPy.core.geometry.transform.Translate( P_dll )

    I_child =  IceRayPy.core.geometry.simple.Sphere( P_dll ) #<! default

    I_move = Coord3D( 0, 0, 0.5 )

    if( None != P_config ):
        if( 'move' in P_config ):
            I_move = P_config['move']
        if( 'child' in P_config ):
            I_child = P_config['child']

    result.child( I_child )
    result.move( I_move )
    return result

def Affine( P_dll,
        P_config = None,
        ):

    result = IceRayPy.core.geometry.transform.Affine(P_dll)

    I_child =  IceRayPy.core.geometry.simple.Cylinder( P_dll )
    I_child =  IceRayPy.core.geometry.flat.Box( P_dll, Coord3D( -1, -1, -1 ), Coord3D( +1, +1, +1 ) )
    I_child =  IceRayPy.core.geometry.simple.Sphere( P_dll ) #<! default

    sO = Coord3D( -1, -1, -1 )
    sX = Coord3D(  1, -1, -1 )
    sY = Coord3D( -1, +1, -1 )
    sZ = Coord3D( -1, -1, +1 )

    tO = Coord3D( -1, -1, -1.0 )
    tX = Coord3D(  1, -1, -1.0 )
    tY = Coord3D( -1, +1, -1.0 )
    tZ = Coord3D( -0.0, -0.0, +1.0 )

    I_2world = IceRayPy.type.math.affine.construct3D( P_dll, tO, tX, tY, tZ, sO, sX, sY, sZ )

    if( None != P_config ):
        if( 'to_world' in P_config ):
            I_2world = P_config['to_world']
        if( 'child' in P_config ):
            I_child = P_config['child']

    result.child( I_child )
    result.toWorld( I_2world )
    return result

def Homography( P_dll,
        P_config = None,
        ):
    result = IceRayPy.core.geometry.transform.Homography( P_dll )

    I_child = IceRayPy.core.geometry.simple.Sphere( P_dll ) #<! default

    sO = Coord3D( -1, -1, -1 )

    sX = Coord3D( +1, -1, -1 )
    sY = Coord3D( -1, +1, -1 )
    sZ = Coord3D( -1, -1, +1 )

    sT = Coord3D( +1, +1, +1 )

    tO = Coord3D( -1, -1, -1 )

    tX = Coord3D( +1, -1, -1 )
    tY = Coord3D( -1, +1, -1 )
    tZ = Coord3D( -1, -1, +1 )

    tT = Coord3D( +1, +1, +1 )

    I_2world = IceRayPy.type.math.homography.construct3D( P_dll, tO, tX, tY, tZ, tT, sO, sX, sY, sZ, sT )

    if( None != P_config ):
        if( 'to_world' in P_config ):
            I_2world = P_config['to_world']
        if( 'child' in P_config ):
            I_child = P_config['child']

    result.child( I_child )
    result.toWorld( I_2world )
    return result

