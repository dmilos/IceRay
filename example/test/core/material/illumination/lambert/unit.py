import IceRayCpp


def make( P_light, P_diffuse = IceRayCpp.GraphTypeColorRGB().fill( 0.5 ) ):

    surface = IceRayCpp.MaterialSurface()
    point = 0
    normal = 1
    spotBegin = 0
    spotEnd = 1
    light = 0

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], light )
    #MaterialLightSpotSwarmA( [size]spotEnd, [size]spotBegin, [light]light, [coord]point )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( spotEnd, spotBegin, light, point )
    #MaterialLightSpotCull( [size]spotEnd, [coord]point, [coord]normal, [size]spotBegin, [size]spotEnd  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( spotEnd, point, normal, spotBegin, spotEnd )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_diffuse, 1 )
    #MaterialIlluminationLambert( [color]result, [coord]point, [coord]normal, [size]spotBegin, [size]spotEnd, [color]diffuse )
    cargo['4'] = IceRayCpp.MaterialIlluminationLambert( 0, point, normal, spotBegin, spotEnd, 1 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )

    return { 'this' : surface, 'light': P_light, 'cargo': cargo  }
