print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


import IceRayPy

def Fresnel(
     P_dll
    ,P_config
    ,P_ior       = 2.41
    ,P_albedo   : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, P_ior,   tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, P_albedo,   tempColor + 0 ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Fresnel( P_dll, point, normal, tempScalar + 0, tempColor + 0 ) )

    return I_surface


def Snell(
     P_dll
    ,P_config
    ,P_ior          = 2.41
    ,P_albedo       : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 1, 1, 1 )
    ,P_transparency : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 1, 1, 1 )
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, P_ior,   tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, P_albedo,       tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, P_transparency, tempColor + 1 ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Snell( P_dll, point, normal, tempScalar + 0, tempColor + 0, tempColor + 1 ) )

    return I_surface


def Schlick(
     P_dll
    ,P_config
    ,P_ior          = 2.41
    ,P_albedo   : IceRayPy.type.color.RGB = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, P_ior, tempScalar + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, P_albedo,   tempColor + 0 ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Schlick( P_dll, point, normal, tempScalar + 0, tempColor + 0 ) )

    return I_surface


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )