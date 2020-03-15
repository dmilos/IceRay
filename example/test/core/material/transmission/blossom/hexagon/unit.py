import math
import IceRayCpp


def make(
    P_light,
    P_albedo   = IceRayCpp.GraphTypeColorRGB().fill( 0.9 ),
    P_sample   = 10,
    P_angle    = math.radians( 30 ),
    P_gauss    = 1,
    P_ambient  = IceRayCpp.GraphTypeColorRGB().fill( 0.0 )
):
    surface = IceRayCpp.MaterialSurface( )

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarm( [coord]point, [light]light, [spot]start, [size]count  )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarm( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    cargo['3'] = IceRayCpp.MaterialPatternColorConstant( P_albedo, 1 )
    #MaterialTransmissionReflectOne( [coord]point, [coord]normal, [color]albedo )
    cargo['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )
    I_laeder  = 0
    cargo['5'] = IceRayCpp.MaterialPatternSizeConstant(   I_laeder,1 ) # leader
    cargo['6'] = IceRayCpp.MaterialPatternSizeConstant(   P_sample, 2 ) # sample
    cargo['7'] = IceRayCpp.MaterialPatternScalarConstant( P_angle, 2 ) # angle
    cargo['8'] = IceRayCpp.MaterialPatternScalarConstant( P_gauss, 3 ) # gauss

    #MaterialTransmissionBlossom( [coord]normal, [scalar]leader, [size]circles, [scalar]angle, [scalar]gauss )
    cargo['8'] = IceRayCpp.MaterialTransmissionBlossomHexagon( 1, 1, 2, 2, 3 )

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
    surface.append( cargo['6'] )
    surface.append( cargo['7'] )
    surface.append( cargo['8'] )

    surface.append( cargo['F'] )

    return { 'this' : surface, 'cargo': cargo, 'light': P_light  }
