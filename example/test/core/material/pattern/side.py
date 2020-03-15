import IceRayCpp

def name( ):
    return "side"


def value( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['valueNoise']={}
    surface_cargo['valueNoise']['function'] = IceRayCpp.FunctionScalarNoiseValue( 10, 4.6, 0.4 )


    surface_cargo['1'] = IceRayCpp.MaterialPatternScalarFunction( surface_cargo['valueNoise']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo
