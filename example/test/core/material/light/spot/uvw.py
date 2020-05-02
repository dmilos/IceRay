import IceRayCpp

def name( ):
    return "side"


def make( P_light, P_diffuse = IceRayCpp.GraphTypeColorRGB().fill( 0.5 ) ):

    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialLightGenerator( P_light['this'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['3'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    #MaterialLightSpotUVW( TODO  )
    cargo['4'] = IceRayCpp.MaterialLightSpotUVW( 2, 0, 1, 0 )
    cargo['5'] = IceRayCpp.MaterialConvertCoord3D2Color( 2, 0 )


    surface.append( cargo['1'] )
    surface.append( cargo['2'] )
    surface.append( cargo['3'] )
    surface.append( cargo['4'] )
    surface.append( cargo['5'] )

    return { 'this' : surface, 'light': P_light, 'cargo': cargo  }

