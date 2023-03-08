#print( '<' + __name__ + ' name=\'' +   __file__ + '>' )

import IceRayPy


def Box(
     P_dll
    ,P_config = None
    ,P_color = IceRayPy.type.color.RGB(15,15,15)
    ,P_lo  = IceRayPy.type.math.coord.Scalar3D( -1.5+ -0.5, +1.5+ -0.5, 2 )
    ,P_hi  = IceRayPy.type.math.coord.Scalar3D( -1.5+  0.5, +1.5+  0.5, 2.01 )
    ):

    wrapper = IceRayPy.core.object.Wrapper( P_dll )

    pigment = IceRayPy.utility.material.illumination.Ambient( P_dll, P_config, P_color )
    wrapper.pigment( pigment )
    geometry = IceRayPy.core.geometry.flat.Box( P_dll )
    geometry.box( P_lo, P_hi )
    wrapper.geometrySet( geometry )

    return wrapper

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )