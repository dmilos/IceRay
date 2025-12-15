#print( '<' + __name__ + ' name=\'' +   __file__ + '>' )

import ctypes
import sys

import IceRayPy



def Alp(
      P_dll
     ,P_config
     ,P_albedo    = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
     ,P_emission  = IceRayPy.type.color.RGB(1/32,1/32,8/32)
     ,P_diffuse   = IceRayPy.type.color.RGB(0.39/4,0.39/4,0.39/0.5)
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
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN

    I_leader = tempSize + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_light = IceRayPy.core.light.Point( P_dll, IceRayPy.core.light.Spot( IceRayPy.type.math.coord.Scalar3D( 0, 0, 5 ) ) )
    if( 'light' in P_config ):
        I_light = P_config['light']

    I_barrier = IceRayPy.core.geometry.volumetric.Vacuum( P_dll )
    if( 'barrier' in P_config ):
        I_barrier = P_config['barrier']

    I_emission  = tempColor+0
    I_diffuse   = tempColor+1
    I_specular  = tempColor+2
    I_shininess = tempColor+3

    I_surface.append( IceRayPy.core.material.instruction.light.Generator(    P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA(       P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull(     P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0, I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_emission , I_emission  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_diffuse  , I_diffuse   ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular , I_specular  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_shininess, I_shininess ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.ALP( P_dll, result, point, normal, spotBegin, spotEnd, I_emission, I_diffuse, I_specular, I_shininess ) )
    return I_surface


def Ambient(
      P_dll
     ,P_config
     ,P_emission : IceRayPy.type.color.RGB = None
    ):
    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    tempColor   = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_emission = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    if( 'emission' in P_config ):
        I_emission = P_config['emission']
    if( None != P_emission ):
        I_emission = P_emission

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_emission, tempColor + 0 ) )
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


###

def Diffusive(
     P_dll
    ,P_config
    ,P_albedo    = IceRayPy.type.color.RGB( 1, 1, 1 )
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd


    I_coefficient  = 0.5
    if( 'coefficient' in P_config ):
        I_coefficient = P_config['coefficient']

    I_specular   = IceRayPy.type.color.RGB(1*2,2*2,3*2)
    if( 'specular' in P_config ):
        I_specular = P_config['specular']
 
    I_shininess = IceRayPy.type.color.RGB(10,100,1000)
    if( 'shininess' in P_config ):
        I_shininess = P_config['shininess']

    I_leader = tempSize + 0

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
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_coefficient,  tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.Diffusive( P_dll, point, normal, tempColor + 2, tempScalar + 0 ,I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_shininess, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Phong( P_dll, result, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface

###
def AsSpecular(
      P_dll
     ,P_config
     ,P_albedo   = None
     ,P_specular = None
     ,P_u        = None
     ,P_v        = None
    ):

    I_albedo     = IceRayPy.type.color.RGB( 0.75, 0.75, 0.75 )
    if( 'albedo' in P_config ):
        I_albedo = P_config['albedo']
    if( P_albedo != None ):
        I_albedo = P_albedo

    I_specular     = IceRayPy.type.color.RGB( 1, 0.85, 0 )
    if( 'specular' in P_config ):
        I_specular = P_config['specular']
    if( P_specular != None ):
        I_specular = P_specular

    I_u     = 10
    if( 'u' in P_config ):
        I_u = P_config['u']
    if( P_u != None ):
        I_u = P_u
    I_v     = 100
    if( 'v' in P_config ):
        I_v = P_config['v']
    if( P_v != None ):
        I_v = P_v

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
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

    #TODO ??? I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_albedo,  tempColor + 1, I_leader ) )
    #TODO ??? I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 1, I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, I_specular, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_u, tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_v, tempScalar + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.AsSpecular( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempScalar + 0, tempScalar + 1 ) )

    return I_surface


def AshikminShirley(
     P_dll
    ,P_config
    ,P_diffuse  = None
    ,P_specular = None
    ,P_albedo   = None
    ,P_u        = None
    ,P_v        = None
    ):
    I_albedo     = IceRayPy.type.color.RGB( 0.75, 0.75, 0.75 )
    if( 'albedo' in P_config ):
        I_albedo = P_config['albedo']
    if( P_albedo != None ):
        I_albedo = P_albedo

    I_diffuse     = IceRayPy.type.color.RGB(  3.5, 2.5, 1.5 )
    if( 'diffuse' in P_config ):
        I_diffuse = P_config['diffuse']
    if( P_diffuse != None ):
        I_diffuse = P_diffuse

    I_specular     = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    if( 'specular' in P_config ):
        I_specular = P_config['specular']
    if( P_specular != None ):
        I_specular = P_specular

    I_u     = 10
    if( 'u' in P_config ):
        I_u = P_config['u']
    if( P_u != None ):
        I_u = P_u
    I_v     = 100
    if( 'v' in P_config ):
        I_v = P_config['v']
    if( P_v != None ):
        I_v = P_v

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
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

    #TODO ??? I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_albedo,  tempColor + 1, I_leader ) )
    #TODO ??? I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 1, I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, I_diffuse,    tempColor + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, I_specular,   tempColor + 3 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_u,          tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_v,          tempScalar + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.setup.PlaneSurface( P_dll ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.AsSpecular( P_dll, tempColor + 0, point, normal, spotBegin, spotEnd, tempColor + 3, tempScalar + 0, tempScalar + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.AsDiffuse(  P_dll, tempColor + 1, point, normal, spotBegin, spotEnd, tempColor + 2, tempColor + 3 ) )

    I_surface.append( IceRayPy.core.material.instruction.operation.color.Addition( P_dll, result, tempColor + 1, tempColor + 0 ) )

    return I_surface


def Beckmann_Isotropic(
      P_dll
     ,P_config
     ,P_albedo    = None
     ,P_specular  = None
     ,P_roughness = None
    ):

    I_albedo     = IceRayPy.type.color.RGB( 0.75, 0.75, 0.75 )
    if( 'albedo' in P_config ):
        I_albedo = P_config['albedo']
    if( P_albedo != None ):
        I_albedo = P_albedo

    I_specular     = IceRayPy.type.color.RGB( 1, 1, 1 )
    if( 'specular' in P_config ):
        I_specular = P_config['specular']
    if( P_specular != None ):
        I_specular = P_specular

    I_roughness     = IceRayPy.type.color.RGB(1/8.0,1/8.0,1/8.0)
    if( 'roughness' in P_config ):
        I_roughness = P_config['roughness']
    if( P_roughness != None ):
        I_roughness = P_roughness

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0

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

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_albedo,  tempColor + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2, I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_roughness, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Beckmann_Isotropic( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface

def Beckmann_Anisotropic(
      P_dll
     ,P_config
     ,P_albedo    = IceRayPy.type.color.RGB( 0.5, 0.5, 1.5 )
     ,P_specular  = IceRayPy.type.color.RGB( 1.0, 1.0, 1.0 )
     ,P_roughnessX = 1
     ,P_roughnessY = 1/500.0
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0

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
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2, I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_roughnessX, tempScalar + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_roughnessY, tempScalar + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Beckmann_Anisotropic( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempScalar + 1, tempScalar + 2 ) )

    return I_surface

def TrowbridgeReitz_Isotropic(
      P_dll
     ,P_config
     ,P_albedo    = None
     ,P_specular  = None
     ,P_roughness = None
    ):

    I_albedo = IceRayPy.type.color.RGB( 0.5, 0.5, 1.5 )
    if( 'albedo' in P_config ):
        I_albedo = P_config['albedo']
    if( P_albedo != None ):
        I_albedo = P_albedo

    I_specular = IceRayPy.type.color.RGB( 1 ,1 ,1 )
    if( 'specular' in P_config ):
        I_specular = P_config['specular']
    if( P_specular != None ):
        I_specular = P_specular

    I_roughness = 1/8.0
    if( 'roughness' in P_config ):
        I_roughness = P_config['roughness']
    if( P_roughness != None ):
        I_roughness = P_roughness



    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0

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

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_albedo,  tempColor + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2, I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_roughness, tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.TrowbridgeReitz_Isotropic( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempScalar + 0 ) )

    return I_surface

def TrowbridgeReitz_Anisotropic(
      P_dll
     ,P_config
     ,P_albedo     = None
     ,P_specular   = None
     ,P_roughnessX = None
     ,P_roughnessY = None
    ):

    I_albedo     = IceRayPy.type.color.RGB( 0.5, 0.5, 1.5 )
    if( 'albedo' in P_config ):
        I_albedo = P_config['albedo']
    if( P_albedo != None ):
        I_albedo = P_albedo

    I_specular     = IceRayPy.type.color.RGB( 1 ,1 ,1 )
    if( 'specular' in P_config ):
        I_specular = P_config['specular']
    if( P_specular != None ):
        I_specular = P_specular

    I_roughnessX     = 10
    if( 'roughnessX' in P_config ):
        I_roughnessX = P_config['roughnessX']
    if( P_roughnessX != None ):
        I_roughnessX = P_roughnessX

    I_roughnessY     = 10
    if( 'roughnessY' in P_config ):
        I_roughnessY = P_config['roughnessY']
    if( P_roughnessY != None ):
        I_roughnessY = P_roughnessY


    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN

    I_leader = tempSize + 0

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

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_albedo,  tempColor + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2, I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.setup.Reflect( P_dll ) )
    I_surface.append( IceRayPy.core.material.instruction.setup.PlaneSurface( P_dll ) )
    I_surface.append( IceRayPy.core.material.instruction.setup.PlaneReflect( P_dll ) )
    I_surface.append( IceRayPy.core.material.instruction.setup.PlaneIncident( P_dll ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll,  I_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_roughnessX, tempScalar + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_roughnessY, tempScalar + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.TrowbridgeReitz_Anisotropic( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempScalar + 1, tempScalar + 2 ) )

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
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0

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
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2, I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_shininess, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Blinn( P_dll, result, point, normal, spotBegin, spotEnd, tempColor +0, tempColor + 1 ) )

    return I_surface


def Burley_Diffuse(
      P_dll
     ,P_config
     ,P_diffuse   = None
     ,P_roughness = None
    ):

    I_diffuse = IceRayPy.type.color.RGB( 1, 0.1, 0.01 )
    if( 'diffuse' in P_config ):
        I_diffuse = P_config['diffuse']
    if( P_diffuse != None ):
        I_diffuse = P_diffuse
    I_roughness = 2.5
    if( 'roughness' in P_config ):
        I_roughness = P_config['roughness']
    if( P_roughness != None ):
        I_roughness = P_roughness


    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0

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

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, I_diffuse,   tempColor  + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_roughness, tempScalar + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Burley_Diffuse( P_dll, result, point, normal, spotBegin, spotEnd, tempColor +0, tempScalar + 1 ) )

    return I_surface

def Burley_Specular(
      P_dll
     ,P_config
     ,P_specular  = None
     ,P_roughness = None
     ,P_gamma     = None
     ,P_F0        = None
    ):

    I_specular = IceRayPy.type.color.RGB( 1, 0.1, 0.01 )
    if( 'specular' in P_config ):
        I_specular = P_config['specular']
    if( P_specular != None ):
        I_specular = P_specular
    I_roughness = 0.3
    if( 'roughness' in P_config ):
        I_roughness = P_config['roughness']
    if( P_roughness != None ):
        I_roughness = P_roughness
    I_gamma = 2.5
    if( 'gamma' in P_config ):
        I_gamma = P_config['gamma']
    if( P_gamma != None ):
        I_gamma = P_gamma
    I_F0 = 0.1
    if( 'F0' in P_config ):
        I_F0 = P_config['F0']
    if( P_F0 != None ):
        I_F0 = P_F0

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0

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

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, I_specular,  tempColor  + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_roughness, tempScalar + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_gamma,     tempScalar + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_F0,        tempScalar + 3 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.Burley_Specular( P_dll, result, point, normal, spotBegin, spotEnd, tempColor +0, tempScalar + 1, tempScalar + 2, tempScalar + 3 ) )

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
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0

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
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2, I_leader ) )

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
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempColor   = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    tempCoord3D = IceRayPy.core.material.instruction.label.coord3d.temp._BEGIN
    lightThe    = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin   = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd     = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0

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
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2, I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Coord3D( P_dll, P_groove,  tempCoord3D + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_shininess, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.illumination.HsPhong( P_dll, result, point, normal, spotBegin, spotEnd, tempCoord3D +0, tempColor + 0, tempColor + 1  ) )


    return I_surface


def Lambert(
      P_dll
     ,P_config
     ,P_diffuse = None
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

    I_diffuseValue = IceRayPy.type.color.RGB( 1, 1, 1 )
    if( 'diffuse' in P_config ):
        I_diffuseValue = P_config['diffuse']
    if( P_diffuse != None ):
        I_diffuseValue = P_diffuse

    I_surface.append( IceRayPy.core.material.instruction.light.Generator(       P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA(          P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull( P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct(    P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(        P_dll, I_diffuseValue, tempColor + 0 ) )
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

    I_surface.append( IceRayPy.core.material.instruction.light.Generator(    P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA(       P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull(     P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(     P_dll, P_rho,   tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(     P_dll, P_sigma, tempColor + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.ON_f29( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1 ) )

    return I_surface

def ON_f30(
      P_dll
     ,P_config
     ,P_rho     = None
     ,P_sigma   = None
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

    I_rhoVlue     = IceRayPy.type.color.RGB( 3.1415926, 3.1415926, 3.1415926 )
    if( 'rho' in P_config ):
        I_rhoVlue = P_config['rho']
    if( P_rho != None ):
        I_rhoVlue = P_rho

    I_sigmaVlue     = IceRayPy.type.color.RGB( 0, 0, 0 )
    if( 'sigma' in P_config ):
        I_sigmaVlue = P_config['sigma']
    if( P_sigma != None ):
        I_sigmaVlue = P_sigma

    I_surface.append( IceRayPy.core.material.instruction.light.Generator(    P_dll, I_light, lightThe ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SwarmA(       P_dll, spotEnd, spotBegin, lightThe, point ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotCull(     P_dll, point, normal, spotEnd, spotBegin, spotEnd ) )
    I_surface.append( IceRayPy.core.material.instruction.light.SpotObstruct( P_dll, I_barrier, spotEnd, spotBegin, spotEnd ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(      P_dll, I_rhoVlue,   tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(      P_dll, I_sigmaVlue, tempColor + 1 ) )

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

     ,P_albedo    = IceRayPy.type.color.RGB( 1, 1, 1 )
     ,P_specular  = IceRayPy.type.color.RGB(1*2,2*2,3*2)
     ,P_shininess = IceRayPy.type.color.RGB(5,50,500)
    ):

    result    = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point     = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal    = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempColor = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe  = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd   = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0

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
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2, I_leader ) )

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

def CookTorrance(
      P_dll
     ,P_config
     ,P_albedo    = None
     ,P_specular  = None
     ,P_roughness = None
     ,P_IOR       = None
    ):

    I_albedo     = IceRayPy.type.color.RGB( 0.75, 0.75, 0.75 )
    if( 'albedo' in P_config ):
        I_albedo = P_config['albedo']
    if( P_albedo != None ):
        I_albedo = P_albedo

    I_specular     = IceRayPy.type.color.RGB( 1, 1, 1 )
    if( 'specular' in P_config ):
        I_specular = P_config['specular']
    if( P_specular != None ):
        I_specular = P_specular

    I_roughness     = IceRayPy.type.color.RGB(1/8.0,1/8.0,1/8.0)
    if( 'roughness' in P_config ):
        I_roughness = P_config['roughness']
    if( P_roughness != None ):
        I_roughness = P_roughness

    I_IOR     = 0.1
    if( 'IOR' in P_config ):
        I_IOR = P_config['IOR']
    if( P_IOR != None ):
        I_IOR = P_IOR


    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd


    I_leader = tempSize + 0

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

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_albedo,  tempColor + 2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 2, I_leader ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_specular,  tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, I_roughness, tempColor + 1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, I_IOR, tempScalar + 0 ) )

    I_surface.append( IceRayPy.core.material.instruction.illumination.CookTorrance( P_dll, result, point, normal, spotBegin, spotEnd, tempColor + 0, tempColor + 1, tempScalar + 0 ) )

    return I_surface



#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )