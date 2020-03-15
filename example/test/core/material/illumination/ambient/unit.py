import IceRayCpp


def make( P_light, P_color = IceRayCpp.GraphTypeColorRGB().fill( 0.5 ) ):
    surface = IceRayCpp.MaterialSurface()

    cargo = {}
    cargo['1'] = IceRayCpp.MaterialPatternColorConstant( P_color, 1 )
    #MaterialIlluminationAmbient( [color]result, [color]emission )
    cargo['2'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface.append( cargo['1'] )
    surface.append( cargo['2'] )

    return { 'this' : surface, 'light': P_light, 'cargo': cargo  }