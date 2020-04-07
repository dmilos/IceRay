import IceRayCpp

def AB( albedo, roughness ):
    A = IceRayCpp.GraphTypeColorRGB()
    B = IceRayCpp.GraphTypeColorRGB()

    A[0] = 1.0-0.5*( roughness[0]*roughness[0] )/( roughness[0]*roughness[0] +0.33 )
    A[1] = 1.0-0.5*( roughness[1]*roughness[1] )/( roughness[1]*roughness[1] +0.33 )
    A[2] = 1.0-0.5*( roughness[2]*roughness[2] )/( roughness[2]*roughness[2] +0.33 )

    B[0] =  0.45 *( roughness[0]*roughness[0] )/( roughness[0]*roughness[0] +0.09 )
    B[1] =  0.45 *( roughness[1]*roughness[1] )/( roughness[1]*roughness[1] +0.09 )
    B[2] =  0.45 *( roughness[2]*roughness[2] )/( roughness[2]*roughness[2] +0.09 )

    A[0] *= albedo[0]/ 3.141592653589
    A[1] *= albedo[1]/ 3.141592653589
    A[2] *= albedo[2]/ 3.141592653589
    B[0] *= albedo[0]/ 3.141592653589
    B[1] *= albedo[1]/ 3.141592653589
    B[2] *= albedo[2]/ 3.141592653589

    return A, B


def make_p44( P_light, albedo    = IceRayCpp.GraphTypeColorRGB().load( 3, 3, 3 )
                     , roughness = IceRayCpp.GraphTypeColorRGB().load( 0.095, 0.095, 0.095 ) ):

    surface = IceRayCpp.MaterialSurface()

    A, B = AB( albedo, roughness )

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( A, 1 )
    cargo['6'] = IceRayCpp.MaterialPatternColorConstant( B, 2 )

    #MaterialIlluminationONp44( [coord]point, [coord]normal, [size]lightCount, [color]A, [color]B, [color]result )
    cargo['7'] = IceRayCpp.MaterialIlluminationONp44( 0,1, 0, 1,2, 0 )


    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )

    return { 'this' : surface, 'list': cargo, 'light': P_light  }


def make_f29( P_light ):
    surface = IceRayCpp.MaterialSurface()

    rho   = IceRayCpp.GraphTypeColorRGB().load( 0.91, 0.92, 0.93 )
    sigma = IceRayCpp.GraphTypeColorRGB().load( 0.81, 0.82, 0.83 )

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['5'] = IceRayCpp.MaterialPatternColorConstant( rho, 1 )
    cargo['6'] = IceRayCpp.MaterialPatternColorConstant( sigma, 2 )

    #MaterialIlluminationONf29( [coord]point, [coord]normal, [size]lightCount, [color]rho, [color]sigma, [color]result )
    cargo['7'] = IceRayCpp.MaterialIlluminationONf29( 0,1, 0, 1,2, 0 )


    surface.append( cargo['1'] )
    surface.append( cargo['2A'] )
    surface.append( cargo['2B'] )
    surface.append( cargo['5'] )
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )

    return { 'this' : surface, 'list': cargo, 'light': P_light  }

def make_YasuhiroFujii( P_light ):

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
    cargo['8'] = IceRayCpp.MaterialPatternCoord3DConstant( IceRayCpp.MathTypeCoord3D().load( 0.0, 0.0, 1.0 ), 3 )

    #MaterialIlluminationONYF( [coord]point, [coord]normal, [size]lightCount, [color]rho, [color]sigma, [color]result )
    cargo['9'] = IceRayCpp.MaterialIlluminationONYF( 0,1, 0, 1,2, 0 )


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
    print( '-------------------------------')

    return { 'this' : surface, 'list': cargo, 'light': P_light  }
