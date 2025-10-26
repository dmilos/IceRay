#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


import math
import IceRayPy.utility.material.pattern.noise
# TODO import IceRayPy.utility.material.pattern.size

def Constant(
      P_dll
     ,P_config
     ,P_color = IceRayPy.type.color.RGB(0.5,0.5,0.5)
    ):
    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_color, result ) )

    return I_surface


def Image(
      P_dll
     ,P_config
     ,P_filename = None
    ):

    I_picture = IceRayPy.type.graph.Picture( P_dll )
    if( None != P_filename ):
        I_picture.load( P_filename )
    else:
        if( 'filename' in P_config ):
            I_picture.load( P_config[ 'filename' ] )
        else:
            I_size = 512
            if( None != P_config ) and ( 'size' in P_config ):
                I_size = P_config['size']
            I_picture.size( I_size, I_size )
            IceRayPy.type.graph.Default( I_picture )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    scale = IceRayPy.core.material.instruction.label.scalar.dynamic._BEGIN
    point  = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    pointT = IceRayPy.core.material.instruction.label.coord3d.temp._BEGIN

    pointShift = pointT + 0
    pointScale = pointT + 1
    pointA     = pointT + 2
    pointB     = pointT + 3

    I_image = IceRayPy.core.material.pattern.Image( P_dll, I_picture )
    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    if( 'scale' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['scale'], scale ) )
        I_surface.append( IceRayPy.core.material.instruction.operation.coord3d.Scale( P_dll, pointA, scale, point ) )

    if( 'shift' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Coord3D( P_dll, P_config['shift'], pointShift ) )
        if( 'scale' in P_config ):
            I_surface.append( IceRayPy.core.material.instruction.operation.coord3d.Addition( P_dll, pointB, pointShift, pointA ) )
        else:
            I_surface.append( IceRayPy.core.material.instruction.operation.coord3d.Addition( P_dll, pointA, pointShift, point ) )

    if( ( 'scale'     in P_config ) and ( 'shift'     in P_config ) ):
        I_surface.append( IceRayPy.core.material.instruction.pattern.Color( P_dll, I_image, result, pointB ) )
    if( ( 'scale'     in P_config ) and ( 'shift' not in P_config ) ):
        I_surface.append( IceRayPy.core.material.instruction.pattern.Color( P_dll, I_image, result, pointA ) )
    if( ( 'scale' not in P_config ) and ( 'shift'     in P_config ) ):
        I_surface.append( IceRayPy.core.material.instruction.pattern.Color( P_dll, I_image, result, pointA ) )
    if( ( 'scale' not in P_config ) and ( 'shift' not in P_config ) ):
        I_surface.append( IceRayPy.core.material.instruction.pattern.Color( P_dll, I_image, result, point ) )

    return I_surface

def Brick(
      P_dll
     ,P_config
     ,P_mortar = None
     ,P_brick  = None
     ,P_move   = None
     ,P_size   = None
    ):

    I_mortar = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    if( 'mortar' in P_config ):
        I_mortar = P_config[ 'mortar' ]
    if(  None != P_mortar ):
        I_mortar = P_mortar

    I_brick = IceRayPy.type.color.RGB( 0.6, 0.25, 0.2 )
    if( 'brick' in P_config ):
        I_brick = P_config[ 'brick' ]
    if(  None != P_brick ):
        I_brick = P_brick

    I_size = IceRayPy.type.math.coord.Scalar3D( 2.5, 4.5, 6.1 )
    if( 'size' in P_config ):
        I_size = P_config[ 'size' ]
    if(  None != P_size ):
        I_size = P_size
        
    I_move = IceRayPy.type.math.coord.Scalar3D( 0.35, 0.5, 0.35 )
    if( 'move' in P_config ):
        I_move = P_config[ 'move' ]
    if(  None != P_move ):
        I_move = P_move

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    tempCoord  = IceRayPy.core.material.instruction.label.coord3d.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN

    switch = tempSize
    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )
    I_pattern = IceRayPy.core.material.pattern.Brick( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Coord3D( P_dll, I_size, tempCoord + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Coord3D( P_dll, I_move, tempCoord + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.coord3d.Addition( P_dll, tempCoord + 2, tempCoord+1, point ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.coord3d.Multiply( P_dll, tempCoord + 3, tempCoord+0, tempCoord+2 ) )

    I_surface.append( IceRayPy.core.material.instruction.pattern.Size( P_dll, I_pattern, switch, tempCoord + 3 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_mortar, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_brick, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.switch.Color( P_dll, tempColor + 2, switch, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Lambert(  P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 2 ) )

    return I_surface


def Checker(
      P_dll
     ,P_config
     ,P_black = None
     ,P_white = None
    ):

    I_black = IceRayPy.type.color.RGB(0,0,0)
    if( 'black' in P_config ):
        I_black = P_config[ 'black' ]
    if(  None != P_black ):
        I_black = P_black

    I_white = IceRayPy.type.color.RGB(1,1,1)
    if( 'white' in P_config ):
        I_white = P_config[ 'white' ]
    if(  None != P_white ):
        I_white = P_white

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN

    switch = tempSize
    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']


    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )
    I_pattern = IceRayPy.core.material.pattern.Checker( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.pattern.Size( P_dll, I_pattern, switch, point ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_black, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_white, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.switch.Color( P_dll, tempColor + 2, switch, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Lambert(  P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 2 ) )

    return I_surface

def Hexagon(
      P_dll
     ,P_config
     ,P_red   = IceRayPy.type.color.RGB(0.5,0,0)
     ,P_green = IceRayPy.type.color.RGB(0,1,0)
     ,P_blue  = IceRayPy.type.color.RGB(0,0,1)
    ):

    I_scale = 1;
    if( 'scale' in P_config ):
        I_scale = P_config['scale']
    
    I_pattern = IceRayPy.core.material.pattern.Hexagon( P_dll, I_scale )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    switch = IceRayPy.core.material.instruction.label.size.temp._BEGIN

    temp = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Size( P_dll, I_pattern, switch, point ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_red,   temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_green, temp + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_blue,  temp + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.switch.Color( P_dll, result, switch,  temp + 0 ) )

    return I_surface


def Onion(
      P_dll
     ,P_config
    ):

    I_pattern = IceRayPy.core.material.pattern.Onion( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    value = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN

    temp = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Scalar( P_dll, I_pattern, value, point ) )
    I_surface.append( IceRayPy.core.material.instruction.convert.Scalar2Color( P_dll, result, value ) )

    return I_surface

def Level(
      P_dll
     ,P_config
    ):

    I_pattern = IceRayPy.core.material.pattern.Level( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    value = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN

    temp = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Scalar( P_dll, I_pattern, value, point ) )
    I_surface.append( IceRayPy.core.material.instruction.convert.Scalar2Color( P_dll, result, value ) )

    return I_surface

def Gradient(
      P_dll
     ,P_config
     ,P_bottom = None
     ,P_top = None
     ,P_function = None
    ):

    I_gradient = IceRayPy.library.material.pattern.gradient.Topography( P_dll )
    if( None != P_function ):
        I_gradient.clear()
        for key in P_function:
         I_gradient.set(  key, P_function[key] )

    I_gradient.bottom( IceRayPy.type.math.coord.Scalar3D( -1, -1, -1 ) )
    if( None != P_bottom ):
        I_gradient.bottom( P_bottom )

    I_gradient.top(    IceRayPy.type.math.coord.Scalar3D( +1, +1, +1 ) )
    if( None != P_top ):
        I_gradient.top( P_top )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point  = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    value  = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN

    temp = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Color( P_dll, I_gradient, result, point ) )

    return I_surface

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
