import IceRayCpp


def make_diffuse( P_light,
                  P_diffuse  = IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ),
                  P_specular = IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 )
                ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarm( [coord]point, [light]light, [spot]start, [size]count  )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarm( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_diffuse,  1 )
    cargo['4'] = IceRayCpp.MaterialPatternColorConstant( P_specular, 2 )

    #MaterialIlluminationAshikhminShirleyDiffuse( [coord]point, [coord]normal, [size]spotCount, [color]diffuse, [color]specular, [color]result )
    cargo['5'] = IceRayCpp.MaterialIlluminationAshikhminShirleyDiffuse( 0, 1, 0, 1, 2, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )

    return { 'this' : surface, '0': cargo, '1': P_light  }

def make_specular( P_light,
                   P_specular = IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.4, 0.3 ),
                   P_u = 10,
                   P_v = 1000
                 ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarm( [coord]point, [light]light, [spot]start, [size]count  )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarm( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_specular, 1 )
    cargo['4'] = IceRayCpp.MaterialPatternScalarConstant( P_u, 2 )
    cargo['5'] = IceRayCpp.MaterialPatternScalarConstant( P_v, 3 )

    #MaterialIlluminationAshikhminShirleySpecular( [coord]point, [coord]normal, [size]spotCount, [color]specular, [scalar]nu, [scalar]nv, [color]result )
    cargo['6'] = IceRayCpp.MaterialIlluminationAshikhminShirleySpecular( 0,1, 0, 1,2,3, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )

    return { 'this' : surface, '0': cargo, 'l': P_light  }


def make_complete( P_light,
                  P_diffuse  = IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ),
                  P_specular = IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ),
                  P_u = 10,
                  P_v = 1000
                 ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarm( [coord]point, [light]light, [spot]start, [size]count  )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarm( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_diffuse,  1 )
    cargo['4'] = IceRayCpp.MaterialPatternColorConstant( P_specular, 2 )

    cargo['5'] = IceRayCpp.MaterialPatternScalarConstant( P_u, 2 )
    cargo['6'] = IceRayCpp.MaterialPatternScalarConstant( P_v, 3 )

    #MaterialIlluminationAshikhminShirleySpecular( [coord]point, [coord]normal, [size]lightCount, [color]specular, [scalar]nu, [scalar]nv, [color]result )
    cargo['7'] = IceRayCpp.MaterialIlluminationAshikhminShirleySpecular( 0,1,1, 2,2,3, 3 )

    #MaterialIlluminationAshikhminShirleyDiffuse( [coord]point, [coord]normal, [size]spotCount, [color]diffuse, [color]specular, [color]result )
    cargo['8'] = IceRayCpp.MaterialIlluminationAshikhminShirleyDiffuse( 0,1, 0, 1,2, 4 )

    cargo['9'] = IceRayCpp.MaterialColorArithmeticPlus( 3, 4, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )
    surface.append( cargo['8'] )
    surface.append( cargo['9'] )

    return { 'this' : surface, '0': cargo, '1': P_light  }
