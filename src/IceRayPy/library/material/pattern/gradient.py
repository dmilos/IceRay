#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy

Coord3D = IceRayPy.type.math.coord.Scalar3D

def BW( P_dll,
         P_config = {}
        ,P_bottom = Coord3D( 0, 0, 0 )
        ,P_top    = Coord3D( 1, 0, 0 )
        ):

    result = IceRayPy.core.material.pattern.Gradient( P_dll )
    result.bottom( P_bottom )
    result.top( P_top )

    result.set(  0 , IceRayPy.type.color.RGB( 0, 0, 0 ) )
    result.set(  1 , IceRayPy.type.color.RGB( 1, 1, 1 ) )

    return result


def Rainbow( P_dll,
         P_config = {}
        ,P_bottom = Coord3D( 0, 0, 0 )
        ,P_top    = Coord3D( 1, 0, 0 )
        ):

    result = IceRayPy.core.material.pattern.Gradient( P_dll )
    result.bottom( P_bottom )
    result.top( P_top )
    I_step = 1.0/12.0

    result.set(  0*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB(   0, 100,  50 ) ) )
    result.set(  1*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB(  30, 100,  50 ) ) )
    result.set(  2*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB(  60, 100,  50 ) ) )
    result.set(  3*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB(  90, 100,  50 ) ) )
    result.set(  4*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 120, 100,  50 ) ) )
    result.set(  5*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 150, 100,  50 ) ) )
    result.set(  6*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 180, 100,  50 ) ) )
    result.set(  7*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 210, 100,  50 ) ) )
    result.set(  8*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 240, 100,  50 ) ) )
    result.set(  9*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 270, 100,  50 ) ) )
    result.set( 11*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 300, 100,  50 ) ) )
    result.set( 12*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 330, 100,  50 ) ) )

    return result

def Topography( P_dll,
         P_config = {}
        ,P_bottom = Coord3D( 0, 0, 0 )
        ,P_top    = Coord3D( 1, 0, 0 )
        ):

    result = IceRayPy.core.material.pattern.Gradient( P_dll )
    result.bottom( P_bottom )
    result.top( P_top )

    I_step = 1.0/8.0

    result.set( 0*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 240, 100,  50 ) ) )

    result.set( 0.40*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 165, 100, 50 ) ) )
    result.set( 0.50*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 165, 100,  0 ) ) )
    result.set( 0.60*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 165, 100, 50 ) ) )

    result.set( 1*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 150, 100,  50 ) ) )

    result.set( 1.40*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 135, 100, 50 ) ) )
    result.set( 1.50*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 135, 100,  0 ) ) )
    result.set( 1.60*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 135, 100, 50 ) ) )

    result.set( 2*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 120, 100,  50 ) ) )
    result.set( 2.40*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 105, 100, 50 ) ) )
    result.set( 2.50*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 105, 100,  0 ) ) )
    result.set( 2.60*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 105, 100, 50 ) ) )

    result.set( 3*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB(  90, 100,  50 ) ) )
    result.set( 3.40*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 75, 100, 50 ) ) )
    result.set( 3.50*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 75, 100,  0 ) ) )
    result.set( 3.60*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 75, 100, 50 ) ) )

    result.set( 4.00*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB(  60, 100,  50 ) ) )
    result.set( 4.40*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 45, 100, 50 ) ) )
    result.set( 4.50*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 45, 100,  0 ) ) )
    result.set( 4.60*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 45, 100, 50 ) ) )

    result.set( 5.00*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB(  30, 100,  50 ) ) )
    result.set( 5.40*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 15, 100, 50 ) ) )
    result.set( 5.50*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 15, 100,  0 ) ) )
    result.set( 5.60*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 15, 100, 50 ) ) )

    result.set( 6*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB(   0, 100,  50 ) ) )
    result.set( 6.40*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 360-15, 100,  50 ) ) )
    result.set( 6.50*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 360-15, 100,  0 ) ) )
    result.set( 6.60*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 360-15, 100,  50 ) ) )

    result.set( 7*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB(  360-30, 100,  50 ) ) )
    result.set( 7.40*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 360-45, 100,  50 ) ) )
    result.set( 7.50*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 360-45, 100,  0 ) ) )
    result.set( 7.60*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB( 360-45, 100,  50 ) ) )

    result.set( 8*I_step, IceRayPy.type.color.HSL2RGB( P_dll, IceRayPy.type.color.RGB(  360-60, 100,  50 ) ) )

    return result


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
