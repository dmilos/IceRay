import math
import IceRayPy

from IceRayPy import utility


Coord3D = IceRayPy.type.math.coord.Scalar3D

def vacuum( P_dll, P_config = None, P_light = None, P_exponat = None ):
    geometry = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( geometry )
    return wrapper


def pointers( P_dll, P_config = { 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):

    distance = 1
    radius = 0.05

    colorX={
        'dark'   : IceRayPy.type.color.RGB( 0.1, 0.1, 0.1 ),
        'gray'   : IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ),
        'white'  : IceRayPy.type.color.RGB( 1.0, 1.0, 1.0 ),
        'red'    : IceRayPy.type.color.RGB( 1.0, 0.0, 0.0 ),
        'green'  : IceRayPy.type.color.RGB( 0.0, 1.0, 0.0 ),
        'blue'   : IceRayPy.type.color.RGB( 0.0, 0.0, 1.0 ),
        'cyan'   : IceRayPy.type.color.RGB( 0.0, 1.0, 1.0 ),
        'magenta': IceRayPy.type.color.RGB( 1.0, 0.0, 1.0 ),
        'yellow' : IceRayPy.type.color.RGB( 1.0, 1.0, 0.0 ),
     }

    white = IceRayPy.core.object.Wrapper( P_dll )
    white.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, colorX['white'] ) )
    white.geometrySet( IceRayPy.core.geometry.simple.Sphere( P_dll, Coord3D( +distance, +distance, +distance ) , radius ) )

    dark = IceRayPy.core.object.Wrapper( P_dll )
    dark.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, colorX['dark'] ) )
    dark.geometrySet( IceRayPy.core.geometry.simple.Sphere( P_dll, Coord3D( -distance, -distance, -distance ) , radius ) )

    gray = IceRayPy.core.object.Wrapper( P_dll )
    gray.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, colorX['gray'] ) )
    gray.geometrySet( IceRayPy.core.geometry.simple.Sphere( P_dll, Coord3D(  0,  0,  0 ) , radius ) )

    red = IceRayPy.core.object.Wrapper( P_dll )
    red.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{},  colorX['red'] ) )
    red.geometrySet( IceRayPy.core.geometry.simple.Sphere( P_dll, Coord3D(  distance, 0, 0) , radius ) )

    cyan = IceRayPy.core.object.Wrapper( P_dll )
    cyan.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, colorX['cyan'] ) )
    cyan.geometrySet( IceRayPy.core.geometry.simple.Sphere( P_dll, Coord3D(  -distance, 0, 0 ) , radius ) )

    green = IceRayPy.core.object.Wrapper( P_dll )
    green.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, colorX['green'] ) )
    green.geometrySet( IceRayPy.core.geometry.simple.Sphere( P_dll, Coord3D(  0, distance, 0 ) , radius ) )

    magenta = IceRayPy.core.object.Wrapper( P_dll )
    magenta.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, colorX['magenta'] ) )
    magenta.geometrySet( IceRayPy.core.geometry.simple.Sphere( P_dll, Coord3D( 0, -distance, 0 ) , radius ) )

    blue = IceRayPy.core.object.Wrapper( P_dll )
    blue.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, colorX['blue'] ) )
    blue.geometrySet( IceRayPy.core.geometry.simple.Sphere( P_dll, Coord3D(  0, 0, distance ) , radius ) )

    yellow = IceRayPy.core.object.Wrapper( P_dll )
    yellow.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, colorX['yellow'] ) )
    yellow.geometrySet( IceRayPy.core.geometry.simple.Sphere( P_dll, Coord3D( 0, 0, -distance) , radius ) )

    rtss = IceRayPy.core.geometry.rtss.Object( P_dll, IceRayPy.core.geometry.rtss.List( P_dll ))

    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, white.cast2Geometry(),  white  ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, dark.cast2Geometry(),  dark  ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, gray.cast2Geometry(),   gray  ) )

    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, red.cast2Geometry(),   red   ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, green.cast2Geometry(), green ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, blue.cast2Geometry(),  blue  ) )

    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, cyan.cast2Geometry(),     cyan    ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, yellow.cast2Geometry(),   yellow  ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, magenta.cast2Geometry(),  magenta ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( rtss )

    return wrapper

