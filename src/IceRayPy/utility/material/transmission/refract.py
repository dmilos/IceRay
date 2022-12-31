print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


import IceRayPy

def Fresnel(
     P_dll
    ,P_config
    ,P_ior      = None
    ,P_albedo   = None
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_iorValue = 2.41
    if( 'ior' in P_config ):
        I_iorValue = P_config['ior']
    if( None != P_ior ):
        I_iorValue = P_ior

    I_albedoValue = IceRayPy.type.color.RGB( 0.9, 0.9, 0.9 )
    if( 'albedo' in P_config ):
        I_albedoValue = P_config['albedo']
    if( None != P_albedo ):
        I_albedoValue = P_albedo

    I_leader = tempSize + 0
    I_count = tempSize + 1
    I_ior    = tempScalar + 0
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_iorValue,      I_ior ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedoValue,   I_albedo ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Fresnel( P_dll, point, normal, I_ior, I_albedo, I_count, I_leader ) )

    return I_surface


def Snell(
     P_dll
    ,P_config
    ,P_ior          = None
    ,P_albedo       = None
    ,P_transparency = None
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_iorValue = 2.41
    if( 'ior' in P_config ):
        I_iorValue = P_config['ior']
    if( None != P_ior ):
        I_iorValue = P_ior

    I_albedoValue = IceRayPy.type.color.RGB( 0.9, 0.9, 0.9 )
    if( 'albedo' in P_config ):
        I_albedoValue = P_config['albedo']
    if( None != P_albedo ):
        I_albedoValue = P_albedo

    I_transparencyValue = IceRayPy.type.color.RGB( 0.9, 0.9, 0.9 )
    if( 'transparency' in P_config ):
        I_transparencyValue = P_config['transparency']
    if( None != P_transparency ):
        I_transparencyValue = P_transparency

    I_leader = tempSize + 1
    I_ior    = tempScalar + 0
    I_albedo = tempColor + 0
    I_transparency  = tempColor + 1

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_iorValue,          I_ior ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedoValue,       I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_transparencyValue, I_transparency ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Snell( P_dll, point, normal, I_ior, I_albedo, I_transparency, I_leader, ) )

    return I_surface

def Schlick(
     P_dll
    ,P_config
    ,P_ior      = None # 1.16, 1.54, 2.51, 2.94
    ,P_albedo   = None
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_leader = tempSize + 0
    I_count  = tempSize + 1
    I_ior    = tempScalar + 0
    I_albedo = tempScalar + 1

    I_iorValue = 2.51
    if( 'ior' in P_config ):
        I_iorValue = P_config['ior']
    if( None != P_ior ):
        I_iorValue = P_ior

    I_albedoValue = IceRayPy.type.color.RGB( 0.9, 0.9, 0.9 )
    if( 'albedo' in P_config ):
        I_albedoValue = P_config['albedo']
    if( None != P_albedo ):
        I_albedoValue = P_albedo

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_iorValue,    I_ior    ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedoValue, I_albedo ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Schlick( P_dll, point, normal, I_ior, I_albedo, I_count, I_leader ) )

    return I_surface


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )