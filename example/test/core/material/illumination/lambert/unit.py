import IceRayCpp


def make( P_light, P_diffuse = IceRayCpp.GraphTypeColorRGB().fill( 0.5 ) ):

    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarm( [coord]point, [light]light, [spot]start, [size]count  )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarm( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_diffuse, 1 )
    #MaterialIlluminationLambert( [color]result, [coord]point, [coord]normal, [size]spotCount, [color]diffuse )
    cargo['4'] = IceRayCpp.MaterialIlluminationLambert( 0, 0, 1, 0, 1 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )

    return { 'this' : surface, 'light': P_light, 'cargo': cargo  }
