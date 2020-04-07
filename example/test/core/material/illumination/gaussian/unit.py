import IceRayCpp


def make(
    P_light,
    P_albedo     = IceRayCpp.GraphTypeColorRGB().fill( 0.75 ),
    P_specular   = IceRayCpp.GraphTypeColorRGB().load( 0.4, 0.5, 0.6 ),
    P_smoothness = IceRayCpp.GraphTypeColorRGB().fill( 0.5 )
):

    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_albedo, 1 )
    cargo['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )     #MaterialTransmissionReflectOne( [coord]point, [coord]normal, [color]albedo )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( P_specular,   1 )
    cargo['6'] = IceRayCpp.MaterialPatternColorConstant( P_smoothness, 2 )
    #MaterialIlluminationGaussian( [coord]point, [coord]normal, [size]spotCount, [color]specular, [color]smoothness ,[color]result )
    cargo['7'] = IceRayCpp.MaterialIlluminationGaussian( 0, 1, 0, 1, 2, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )

    return { 'this' : surface, '0': cargo, ';': P_light  }

