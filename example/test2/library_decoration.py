import math
import IceRayPy

from IceRayPy import utility


Coord3D = IceRayPy.type.math.coord.Scalar3D
RGB = IceRayPy.type.color.RGB



def vacuum( P_dll, P_config = None, P_light = None, P_exponat = None ):
    geometry = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( geometry )
    return wrapper


def pointers( P_dll, P_config = { 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):

    distance = 1
    radius = 0.05

    colorX={
        'black'  : IceRayPy.type.color.RGB( 0.0, 0.0, 0.0 ),
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

def grid( P_dll, P_config = { 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):

    radius = 0.01
    rtss = IceRayPy.core.geometry.rtss.Object( P_dll, IceRayPy.core.geometry.rtss.List( P_dll ))

    for u in [-1,+1] :
        for v in [-1,+1] :

            blue = IceRayPy.core.object.Wrapper( P_dll )
            blue.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, RGB(0,0,1) ) )
            blue.geometrySet( IceRayPy.utility.geometry.simple.CylinderG( P_dll,  { 'top' : Coord3D( u, v, -1), 'bottom' : Coord3D( u, v, +1) , 'radius' : radius } ) )
            rtss.push( IceRayPy.core.geometry.Pretender( P_dll, blue.cast2Geometry(),  blue ) )

            green = IceRayPy.core.object.Wrapper( P_dll )
            green.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, RGB(0,1,0) ) )
            green.geometrySet( IceRayPy.utility.geometry.simple.CylinderG( P_dll,   { 'top' : Coord3D( u, -1, v), 'bottom' : Coord3D( u, +1, v) , 'radius' : radius } ) )
            rtss.push( IceRayPy.core.geometry.Pretender( P_dll, green.cast2Geometry(),  green ) )

            red = IceRayPy.core.object.Wrapper( P_dll )
            red.pigment( IceRayPy.utility.material.pattern.Constant( P_dll,{}, RGB(1,0,0) ) )
            red.geometrySet( IceRayPy.utility.geometry.simple.CylinderG( P_dll, { 'top' : Coord3D( -1, u, v), 'bottom' : Coord3D( +1, u, v) , 'radius' : radius } ) )
            rtss.push( IceRayPy.core.geometry.Pretender( P_dll, red.cast2Geometry(),  red ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( rtss )

    return wrapper

def rings( P_dll, P_config = { 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):

    if( None != P_light ):
        P_config['light'] = P_light

    distance = 1
    radius = 0.05

    colorX={
        'red'    : IceRayPy.type.color.RGB( 1.0, 0.0, 0.0 ),
        'green'  : IceRayPy.type.color.RGB( 0.0, 1.0, 0.0 ),
        'blue'   : IceRayPy.type.color.RGB( 0.0, 0.0, 1.0 ),
     }

    mayor = 1
    minor = 0.02
    red_geometry = IceRayPy.utility.geometry.simple.Torus( P_dll );
    red_geometry.minor( minor )
    red_geometry.mayor( mayor )
    red_geometry.center( Coord3D(  0, 0, 0 ) )
    red_geometry.normal( Coord3D(  1, 0, 0 ) )

    red = IceRayPy.core.object.Wrapper( P_dll )
    red.pigment( IceRayPy.utility.material.illumination.Alp( P_dll, P_config, P_emission=IceRayPy.type.color.RGB( 0.01, 0.01, 0.01 ), P_albedo = IceRayPy.type.color.RGB( 0.2, 0.2, 0.2 ), P_diffuse = colorX['red'] ) )
    #red.pigment( IceRayPy.utility.material.illumination.Lambert( P_dll, P_config, P_diffuse = colorX['red'] ) )
    red.geometrySet( red_geometry )

    green_geometry = IceRayPy.utility.geometry.simple.Torus( P_dll );
    green_geometry.minor( minor )
    green_geometry.mayor( mayor )
    green_geometry.center( Coord3D(  0, 0, 0 ) )
    green_geometry.normal( Coord3D(  0, 1, 0 ) )
    green = IceRayPy.core.object.Wrapper( P_dll )
    green.pigment( IceRayPy.utility.material.illumination.Alp( P_dll, P_config, P_albedo = IceRayPy.type.color.RGB( 0.2, 0.2, 0.2 ), P_diffuse = colorX['green']  ) )
    #green.pigment( IceRayPy.utility.material.illumination.Lambert( P_dll, P_config, P_diffuse = colorX['green']  ) )
    green.geometrySet( green_geometry )

    blue_geometry = IceRayPy.utility.geometry.simple.Torus( P_dll );
    blue_geometry.minor( minor )
    blue_geometry.mayor( 1 )
    blue_geometry.center( Coord3D(  0, 0, 0 ) )
    blue_geometry.normal( Coord3D(  0, 0, 1 ) )
    blue = IceRayPy.core.object.Wrapper( P_dll )
    blue.pigment( IceRayPy.utility.material.illumination.Alp( P_dll, P_config, P_albedo = IceRayPy.type.color.RGB( 0.2, 0.2, 0.2 ), P_diffuse = colorX['blue']  ) )
    #blue.pigment( IceRayPy.utility.material.illumination.Lambert( P_dll, P_config, P_diffuse = colorX['blue']  ) )
    blue.geometrySet( blue_geometry )

    rtss = IceRayPy.core.geometry.rtss.Object( P_dll, IceRayPy.core.geometry.rtss.List( P_dll ))

    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, red.cast2Geometry(),   red   ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, green.cast2Geometry(), green ) )
    rtss.push( IceRayPy.core.geometry.Pretender( P_dll, blue.cast2Geometry(),  blue  ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.geometrySet( rtss )

    return wrapper


def plate( P_dll, P_config = { 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):

    geometry = IceRayPy.core.geometry.flat.Box( P_dll, Coord3D( -2, -2, -1.1 ), Coord3D( +2, +2, -0.99 ) )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.pigment( IceRayPy.utility.material.pattern.Image( P_dll,{ 'scale': 0.25, 'shift': Coord3D( -0.5, -0.5, 0 ), 'size': 2048 } ) )

    wrapper.geometrySet( geometry )
    return wrapper

def radiosity( P_dll, P_config = { 'shadow': False, 'pigment': None }, P_light = None, P_exponat = None ):
    I_room = [ 8, 8, 4 ] # [ 6, 6, 3.5 ]
    I_move = [ 1, 1, I_room[2]/2-1 ]

    I_size  = [ 1.8, 1.8, 0.1 ] #!< original
    I_size  = [ 0.6, 0.6, 0.1 ] #!< debug
    I_angle = 0;
    if( 'angle' in P_config ):
        I_angle = P_config['angle']

    I_scale = 1.5
    I_scaleZ = 0.6
    I_center = [ I_scale * I_room[0]/6 * math.cos( I_angle ), I_scale * I_room[1]/6* math.sin( I_angle ), I_scaleZ*(I_room[2]/2 + I_move[2]) ]

    I_color = IceRayPy.type.color.RGB( 4.6, 4.6, 4.6 )
    I_color = IceRayPy.type.color.RGB( 25.6, 25.6,  25.6 )

    lo = Coord3D()
    lo[0] = -I_size[0]/2 + I_center[0]
    lo[1] = -I_size[1]/2 + I_center[1]
    lo[2] = -I_size[2]/2 + I_center[2]
    hi = Coord3D()
    hi[0] = +I_size[0]/2 + I_center[0]
    hi[1] = +I_size[1]/2 + I_center[1]
    hi[2] = +I_size[2]/2 + I_center[2]

    geometry = IceRayPy.core.geometry.flat.Box( P_dll )
    geometry.box( Coord3D( lo[0], lo[1], lo[2] ), Coord3D( hi[0], hi[1], hi[2] ) )
    pigment = IceRayPy.utility.material.pattern.Hexagon( P_dll, {}, RGB(15,0,0), RGB(0,15,0), RGB(0,0,15) )
    pigment = IceRayPy.utility.material.pattern.Constant( P_dll, {}, I_color )

    wrapper = IceRayPy.core.object.Wrapper( P_dll )
    wrapper.pigment( pigment )
    wrapper.geometrySet( geometry )
    return wrapper

list = {
      'vacuum'      : vacuum,
      'ptrs'        : pointers,
      #'ptrs-A'     : pointers,
      'radiosity'   : radiosity,
      'plate'       : plate,
      'rings'       : rings,
      'grid'        : grid
    }
