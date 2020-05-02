import ctypes

import IceRayPy

def Alp(  P_dll
         ,P_light     = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
         ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
         ,P_albedo    = IceRayPy.type.color.RGB( 0.05, 0.5, 0.5 )
         ,P_emission  = IceRayPy.type.color.RGB(0.1,0.1,0.1)
         ,P_diffuse   = IceRayPy.type.color.RGB(0.5,0.5,0.5)
         ,P_specular  = IceRayPy.type.color.RGB(0.5,0,1)
         ,P_shininess = IceRayPy.type.color.RGB(50,5,50)
        ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    temp       = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, P_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, temp + 0 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_emission , temp+0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_diffuse  , temp+1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular , temp+2 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_shininess, temp+3 ) )


    I_surface.append( IceRayPy.core.material.instruction.illumination.ALP( P_dll, result, point, normal, spotBegin, spotEnd, temp+0, temp+1, temp+2, temp+3 ) )

    return I_surface


def Ambient(
     P_dll
    ,P_light     = None
    ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ,P_emmision : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB(0.5,0,1)
    ):
    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    temp   = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_emmision, temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Ambient( P_dll, result, temp + 0 ) )
    return I_surface


def Lambert(
     P_dll
    ,P_light   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ,P_diffuse = IceRayPy.type.color.RGB( 1, 1, 1 )
    ):

    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    result    = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point     = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal    = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    temp      = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe  = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd   = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator(       P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA(          P_dll, spotEnd, spotBegin, lightThe, normal ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct(    P_dll, P_barrier, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_diffuse, temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Lambert(  P_dll, result, point, normal, spotBegin, spotEnd, temp + 0 ) )

    return I_surface


def Phong( P_dll
    ,P_light     = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ,P_albedo    = IceRayPy.type.color.RGB( 0.09, 0.9, 0.9 )
    ,P_specular  = IceRayPy.type.color.RGB( 1, 2, 1 )
    ,P_shininess = IceRayPy.type.color.RGB( 20, 200, 1 )
    ):

    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    result    = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point     = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal    = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    temp      = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe  = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  temp + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, temp + 2 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular,  temp + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_shininess, temp + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Phong( P_dll, result, spotBegin, spotEnd, temp + 0, temp + 1 ) )

    # todo reflect

    return I_surface






def HsLambert(
        P_dll
       ,P_light   = None
       ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ):

    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )

    # TODO

    return I_surface

def HsNormal(
        P_dll
       ,P_light   = None
       ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ):
    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )

    # TODO

    return I_surface

def HsPhong(
        P_dll
       ,P_light   = None
       ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ):
    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )

    # TODO

    return I_surface

def OnF29(
        P_dll
       ,P_light   = None
       ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ):
    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )

    # TODO

    return I_surface

def OnP44(
        P_dll
       ,P_light   = None
       ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
   ):
    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )

    # TODO

    return I_surface

def OnYF(
        P_dll
       ,P_light   = None
       ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ):
    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )

    # TODO

    return I_surface

def WardApprox(
        P_dll
       ,P_light   = None
       ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ):
    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )

    # TODO

    return I_surface

def WardIsotropic(
        P_dll
       ,P_light   = None
       ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ):
    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )

    # TODO

    return I_surface

def WardReal(
        P_dll
       ,P_light   = None
       ,P_barrier   = None #= IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )
    ):
    if( None == P_light ):
        P_light = IceRayPy.core.light.Point( P_dll, IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) )

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, P_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, normal ) )

    # TODO

    return I_surface
