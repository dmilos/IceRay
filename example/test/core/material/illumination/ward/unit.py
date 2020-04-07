import IceRayCpp


def make_aprox(
    P_light,
    P_albedo    = IceRayCpp.GraphTypeColorRGB().fill( 0.75 ),
    P_specular  = IceRayCpp.GraphTypeColorRGB().load( 0.91, 0.92, 0.93 ),
    P_alphaX    = IceRayCpp.GraphTypeColorRGB().load( 0.50, 0.50, 0.50 ),
    P_alphaY    = IceRayCpp.GraphTypeColorRGB().load( 0.10, 0.10, 0.10 ),
    P_direction = IceRayCpp.MathTypeCoord3D().load( 0.0, 0.0, 1.0 )
):

    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarmB( [coord]point, [light]light, [spot]start, [size]count )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_albedo , 1 )
    cargo['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant(   P_specular, 1 )
    cargo['6'] = IceRayCpp.MaterialPatternColorConstant(   P_alphaX  , 2 )
    cargo['7'] = IceRayCpp.MaterialPatternColorConstant(   P_alphaY  , 3 )
    cargo['8'] = IceRayCpp.MaterialPatternCoord3DConstant( P_direction, 3 )

    #MaterialIlluminationWardApprox( [coord]point, [coord]normal, [size]lightCount, [color]specular,[color]alphaX,[color]alphaY,[coord]direction, [color]result )
    cargo['9'] = IceRayCpp.MaterialIlluminationWardApprox( 0,1, 0, 1,2,3, 3, 0 )


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

    return { 'this' : surface, 'cargo': cargo, 'light': P_light  }

def make_isotropic( P_light ):

    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.9 ), 1 )
    cargo['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.91, 0.92, 0.93 ), 1 )
    cargo['6'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.25, 0.25, 0.25 ), 2 )
    #MaterialIlluminationWardIsotropic( [coord]point, [coord]normal, [size]lightCount, [color]specular, [color]alpha )
    cargo['7'] = IceRayCpp.MaterialIlluminationWardIsotropic( 0,1, 0, 1,2, 0 )

    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )

    return { 'this' : surface, 'list': cargo, 'light': P_light  }

def make_real( P_light ):

    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.9 ), 1 )
    cargo['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.91, 0.92, 0.93 ), 1 )
    cargo['6'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.5, 0.5 ), 2 )
    cargo['7'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.1, 0.1, 0.1 ), 3 )
    cargo['8'] = IceRayCpp.MaterialPatternCoord3DConstant( IceRayCpp.MathTypeCoord3D().load( 0.0, 0.0, 1 ), 3 )

    #MaterialIlluminationWardReal( [coord]point, [coord]normal, [size]lightCount,  [color]specular,[color]alphaX,[color]alphaY,[coord]direction, [color]result )
    cargo['9'] = IceRayCpp.MaterialIlluminationWardReal( 0,1, 0, 1,2,3, 3, 0 )


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

    return { 'this' : surface, 'list': cargo, 'light': P_light  }

