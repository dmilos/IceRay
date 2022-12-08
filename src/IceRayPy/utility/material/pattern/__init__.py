print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


import IceRayPy.utility.material.pattern.noise
# TODO import IceRayPy.utility.material.pattern.size

def Constant(
      P_dll
     ,P_config
     ,P_color = IceRayPy.type.color.RGB(0.5,0.5,0.5)
    ):
    I_pattern = IceRayPy.core.material.pattern.Checker( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_color, result ) )

    return I_surface


def Image(
      P_dll
     ,P_config
     ,P_filename = None
    ):
    I_picture   = IceRayPy.type.graph.Picture( P_dll )

    if( None != P_filename ):
        I_picture.load( P_filename )
    else:
        I_picture.size( 256, 256 )
        IceRayPy.type.graph.Default( I_picture )

    I_image = IceRayPy.core.material.pattern.Image( P_dll, I_picture )
    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    I_surface.append( IceRayPy.core.material.instruction.pattern.Color( P_dll, I_image, result, point ) )
    return I_surface

def Checker(
      P_dll
     ,P_config
     ,P_black = IceRayPy.type.color.RGB(0,0,0)
     ,P_white = IceRayPy.type.color.RGB(1,1,1)
    ):

    I_pattern = IceRayPy.core.material.pattern.Checker( P_dll )

    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    switch = IceRayPy.core.material.instruction.label.size.temp._BEGIN

    temp = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.pattern.Size( P_dll, I_pattern, switch, point ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_black, temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_white, temp + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.operation.switch.Color( P_dll, result, switch,  temp + 0 ) )

    return I_surface

def Hexagon(
      P_dll
     ,P_config
     ,P_red   = IceRayPy.type.color.RGB(1,0,0)
     ,P_green = IceRayPy.type.color.RGB(0,1,0)
     ,P_blue  = IceRayPy.type.color.RGB(0,0,1)
    ):

    I_pattern = IceRayPy.core.material.pattern.Hexagon( P_dll )

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

print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
print( '</' + __name__ + ' name=\'' +   __file__ + '>' )