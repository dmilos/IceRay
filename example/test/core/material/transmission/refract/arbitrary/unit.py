import IceRayCpp


def make(
    P_light,
    P_ior = 1.7,
    P_reflectance  = IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ),
    P_transmitance = IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ),
    P_ambient = IceRayCpp.GraphTypeColorRGB().load( 0,0,0 )
):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['0'] = IceRayCpp.MaterialPatternColorConstant( P_ambient, 0 )
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternScalarConstant( P_ior, 1 ) #<! IOR
    cargo['4'] = IceRayCpp.MaterialPatternColorConstant( P_reflectance, 2 )
    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( P_transmitance, 3 )

    #MaterialTransmissionRefractArbitrary( point, normal, IOR, reflectance, transmittance )
    cargo['6'] = IceRayCpp.MaterialTransmissionRefractArbitrary(  0,1,  1, 2, 3  )

    surface.append( cargo['0'] )
    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )

    return { 'this' : surface, 'cargo': cargo, 'light': P_light  }
