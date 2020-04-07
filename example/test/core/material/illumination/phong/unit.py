import IceRayCpp


def make(
    P_light,
    P_albedo   = IceRayCpp.GraphTypeColorRGB().fill( 0.5 ),
    P_specular = IceRayCpp.GraphTypeColorRGB().load( 1.0, 1.0, 1.0 ),
    P_shines   = IceRayCpp.GraphTypeColorRGB().load( 8, 16, 32 )
):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}

    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_albedo, 1 )
    #MaterialTransmissionReflectOne( [coord]point, [coord]normal, [color]transmittance )
    cargo['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( P_specular, 1 )
    cargo['6'] = IceRayCpp.MaterialPatternColorConstant( P_shines, 2 )
    #MaterialIlluminationPhong( [color]result, [color]specular, [color]shininess, [size]spotCount )
    cargo['7'] = IceRayCpp.MaterialIlluminationPhong( 0, 1, 2, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )

    return { 'this' : surface, 'cargo': cargo, '1ight': P_light  }