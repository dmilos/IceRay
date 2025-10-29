#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import math

Size2D = IceRayPy.type.math.coord.Size2D
Coord3D = IceRayPy.type.math.coord.Scalar3D

def Mist( P_dll,
        P_config = None,
        P_density = None,
        P_lo = None,
        P_hi = None,
        ):

    result = IceRayPy.core.geometry.volumetric.Mist(P_dll)
    hull   = IceRayPy.core.geometry.flat.Box(P_dll)

    I_density = 0.5;
    I_lo = Coord3D(-1,-1,-1);
    I_hi = Coord3D(+1,+1,+1);

    if( None != P_config ):
        if( 'density' in P_config ):
            I_density = P_config['density']
        if( 'lo' in P_config ):
            I_lo = P_config['lo']
        if( 'hi' in P_config ):
            I_hi = P_config['hi']

    hull.lo( I_lo )
    hull.hi( I_hi )
    result.density( I_density )
    result.hull( hull )
    return result

#def Smoke( P_dll,
#        P_config = None,
#        P_density = "x",
#        P_lo = None,
#        P_hi = None,
#        ):
