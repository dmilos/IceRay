import IceRayCpp


def make(
    P_light,
    P_IOR = 1.7,
    P_transmitance = IceRayCpp.GraphTypeColorRGB().fill( 0.9 ),
    P_ambient      = IceRayCpp.GraphTypeColorRGB().fill( 0.0 )
):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternScalarConstant( P_IOR,         1 ) #<! IOR
    cargo['4'] = IceRayCpp.MaterialPatternColorConstant( P_transmitance, 1 )

    ##MaterialTransmissionRefractOne( [coord]point, [coord]normal, [color]transmittance, [scalar]ior )
    cargo['5'] = IceRayCpp.MaterialTransmissionRefractOne( 0, 1, 1, 1 )

    #cargo['8'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 1.4, 1.5, 1.6 ), 1 )
    #cargo['9'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 40, 50, 60 ), 2 )
    ##MaterialIlluminationPhong( [color]result, [color]specular, [color]shininess, [size]spotCount )
    #cargo['A'] = IceRayCpp.MaterialIlluminationPhong( 0, 1, 2, 0 )

    cargo['F'] = IceRayCpp.MaterialPatternColorConstant( P_ambient, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )

    #surface.append( cargo['8'] )
    #surface.append( cargo['9'] )
    #surface.append( cargo['A'] )
    surface.append( cargo['F'] )

    return { 'this' : surface, 'cargo': cargo, 'light': P_light  }
