import ctypes

import IceRayPy



def Alp(
      P_dll
     ,P_config
     ,P_albedo    = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
     ,P_emission  = IceRayPy.type.color.RGB(1/32,1/32,1/32)
     ,P_diffuse   = IceRayPy.type.color.RGB(0.39/4,0.39/4,0.39/4)
     ,P_specular  = IceRayPy.type.color.RGB(1*2,2*2,3*2)
     ,P_shininess = IceRayPy.type.color.RGB(10,100,1000)
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_emission , tempColor+0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_diffuse  , tempColor+1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular , tempColor+2 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_shininess, tempColor+3 ) )


    I_surface.append( IceRayPy.core.material.instruction.illumination.ALP( P_dll, result, point, normal, spotBegin, spotEnd, tempColor+0, tempColor+1, tempColor+2, tempColor+3 ) )

    return I_surface


def Ambient(
      P_dll
     ,P_config
     ,P_emmision : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ):
    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    tempColor   = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_emmision, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Ambient( P_dll, result, tempColor + 0 ) )
    return I_surface


def AsDiffuse(
     P_dll
    ,P_config
    ,P_diffuse  = IceRayPy.type.color.RGB( 3, 3, 3 )
    ,P_specular = IceRayPy.type.color.RGB( 0.1, 0.1, 0.1 )
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_diffuse,   tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular,  tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.AsDiffuse( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface

def AsSpecular(
      P_dll
     ,P_config
     ,P_specular = IceRayPy.type.color.RGB( 1, 2, 3 )
     ,P_u = 10
     ,P_v = 10
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    #TODO reflect ???

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_specular, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_u, tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_v, tempScalar + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.AsSpecular( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempScalar + 0, tempScalar + 1 ) )

    return I_surface


def Beckmann(
      P_dll
     ,P_config
     ,P_albedo    = IceRayPy.type.color.RGB( 0.5, 0.5, 1.5 )
     ,P_specular  = IceRayPy.type.color.RGB(1 ,1 ,1 )
     ,P_roughness = IceRayPy.type.color.RGB(1/8.0,1/16.0,1/32.0)
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_roughness, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Beckmann( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface


def Blinn(
      P_dll
     ,P_config
     ,P_albedo    = IceRayPy.type.color.RGB( 0.75, 0.75, 0.75 )
     ,P_specular  = IceRayPy.type.color.RGB( 1, 0.8, 0.6 )
     ,P_shininess = IceRayPy.type.color.RGB( 100, 100, 100 )
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor       = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_shininess, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Blinn( P_dll, result, point, normal, spotBegin, spotEnd, tempColor +0, tempColor + 1 ) )

    return I_surface


def Gaussian(
      P_dll
     ,P_config
     ,P_albedo    = IceRayPy.type.color.RGB( 0.75, 0.75, 0.75 )
     ,P_specular  = IceRayPy.type.color.RGB( 1, 1, 1 )
     ,P_roughness = IceRayPy.type.color.RGB( 0.32, 0.16, 0.08 )
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo, tempColor + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_roughness, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Gaussian( P_dll, result, point, normal, spotBegin, spotEnd, tempColor +0, tempColor + 1 ) )

    return I_surface


def HsLambert(
      P_dll
     ,P_config
     ,P_groove     = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
     ,P_diffuse    = IceRayPy.type.color.RGB( 1, 1, 1 )
    ):

    result       = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point        = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal       = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor    = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    tempCoord3D  = IceRayPy.core.material.instruction.label.coord3d.temp._BEGIN
    lightThe     = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin    = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd      = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Coord3D( P_dll, P_groove,  tempCoord3D + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(   P_dll, P_diffuse, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.HsLambert( P_dll, result, point, normal, spotBegin, spotEnd, tempCoord3D + 0, tempColor + 0 ) )

    return I_surface

def HsPhong(
      P_dll
     ,P_config
     ,P_albedo     = IceRayPy.type.color.RGB( 0.9, 0.9, 0.9 )
     ,P_groove     = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
     ,P_specular   = IceRayPy.type.color.RGB( 0.6, 0.7, 1  )
     ,P_shininess  = IceRayPy.type.color.RGB( 10.0, 10.0, 10.0 )
    ):
    result      = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point       = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal      = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor   = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    tempCoord3D = IceRayPy.core.material.instruction.label.coord3d.temp._BEGIN
    lightThe    = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin   = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd     = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Coord3D( P_dll, P_groove,  tempCoord3D + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_shininess, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.HsPhong( P_dll, result, point, normal, spotBegin, spotEnd, tempCoord3D +0, tempColor + 0, tempColor + 1  ) )


    return I_surface


def Lambert(
      P_dll
     ,P_config
     ,P_diffuse = IceRayPy.type.color.RGB( 1, 1, 1 )
    ):

    result    = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point     = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal    = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe  = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd   = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator(       P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA(          P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct(    P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_diffuse, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Lambert(  P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0 ) )

    return I_surface

def ON_f29(
      P_dll
     ,P_config
     ,P_rho     = IceRayPy.type.color.RGB( 3.14, 3.14,3.14 )
     ,P_sigma   = IceRayPy.type.color.RGB( 1, 1, 1 )
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_rho,   tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_sigma, tempColor + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.ON_f29( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface

def ON_f30(
      P_dll
     ,P_config
     ,P_rho     = IceRayPy.type.color.RGB( 3.14, 3.14,3.14 )
     ,P_sigma   = IceRayPy.type.color.RGB( 1, 1, 1 )
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor       = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_rho,   tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_sigma, tempColor + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.ON_f30( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface

def ON_Fujii_Proposed(
      P_dll
     ,P_config
     ,P_rho     = IceRayPy.type.color.RGB( 1, 1, 1 )
     ,P_sigma   = IceRayPy.type.color.RGB( 5, 5, 5 )
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_rho, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_sigma, tempColor + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.ON_Fujii_Proposed( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface

def ON_Fujii_Qualitative(
      P_dll
     ,P_config
     ,P_rho     = IceRayPy.type.color.RGB( 1, 1, 1 )
     ,P_sigma   = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_rho, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_sigma, tempColor + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.ON_Fujii_Qualitative( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface


def ON_Ouwerkerk(
      P_dll
     ,P_config
     ,P_rho     = IceRayPy.type.color.RGB( 3.14, 3.14,3.14 )
     ,P_sigma   = IceRayPy.type.color.RGB( 15, 15, 15 )
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_rho, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, P_sigma, tempColor + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.ON_Ouwerkerk( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface


def Phong(
     P_dll
    ,P_config
    #,P_albedo    = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    #,P_specular  = IceRayPy.type.color.RGB( 1, 2, 1 )
    #,P_shininess = IceRayPy.type.color.RGB( 20, 200, 1 )

     ,P_albedo    = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
     ,P_specular  = IceRayPy.type.color.RGB(1*2,2*2,3*2)
     ,P_shininess = IceRayPy.type.color.RGB(5,50,500)
    ):

    result    = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point     = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal    = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe  = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd   = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2 ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_shininess, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Phong( P_dll, result, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface


def WardApprox(
      P_dll
     ,P_config
     ,P_specular   = IceRayPy.type.color.RGB( 1, 1, 1 )
     ,P_alphaX     = 0.1
     ,P_alphaY     = 0.8
     ,P_direction  = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
    ):
    result      = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point       = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal      = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempScalar  = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor   = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    tempCoord3D = IceRayPy.core.material.instruction.label.coord3d.temp._BEGIN
    lightThe    = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin   = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd     = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Coord3D( P_dll, P_direction,  tempCoord3D + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(   P_dll, P_specular, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(   P_dll, P_alphaX,   tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(   P_dll, P_alphaY,   tempScalar + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.WardApprox( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempScalar + 0, tempScalar + 1, tempCoord3D + 0 ) )

    return I_surface

def WardIsotropic(
      P_dll
     ,P_config
     ,P_specular   = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
     ,P_alpha      = IceRayPy.type.color.RGB( 0.4, 0.20, 0.1 )
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(     P_dll, P_specular, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(     P_dll, P_alpha,    tempColor + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.WardIsotropic( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface

def WardReal(
      P_dll
     ,P_config
     ,P_specular   = IceRayPy.type.color.RGB( 1, 1, 1 )
     ,P_alphaX     = 0.1
     ,P_alphaY     = 0.8
     ,P_direction  = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
    ):
    result      = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point       = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal      = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempScalar  = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempCoord3D = IceRayPy.core.material.instruction.label.coord3d.temp._BEGIN
    tempColor   = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe    = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin   = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd     = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_surface.append( IceRayPy.core.material.instruction.light.Generator( P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA( P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Coord3D( P_dll, P_direction,tempCoord3D + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(   P_dll, P_specular, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(   P_dll, P_alphaX,  tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(   P_dll, P_alphaY,  tempScalar + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.WardReal( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempScalar + 0, tempScalar + 1, tempCoord3D + 0 ) )

    return I_surface
