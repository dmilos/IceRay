print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy


def Mirror(
     P_dll
    ,P_config
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_albedo = tempColor + 0
    I_leader = tempSize + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 1, 1, 1 ), I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    return I_surface

def One(
     P_dll
    ,P_config
    ,P_albedo : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_albedo = tempColor + 0
    I_leader = tempSize + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    return I_surface

def Schlick(
     P_dll
    ,P_config
    ,P_ior       = 1
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_leader = tempSize + 0
    I_ior = tempScalar + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(               P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(              P_dll, P_ior, I_ior ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.Schlick( P_dll, point, normal, I_ior, I_leader ) )

    return I_surface


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )