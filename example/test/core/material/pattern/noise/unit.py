import IceRayCpp

def name( ):
    return "noise"

def crackle( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['crackle']={}
    surface_cargo['crackle']['function'] = IceRayCpp.FunctionScalarCrackle()

    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['crackle']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo


def value( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['valueNoise']={}
    surface_cargo['valueNoise']['function'] = IceRayCpp.FunctionScalarNoiseValue( 10, 4.6, 0.4 )


    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['valueNoise']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo

def perlin( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['perlin']={}
    surface_cargo['perlin']['function'] = IceRayCpp.FunctionScalarNoisePerlin( 7, 2.718281, 0.75 )


    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['perlin']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo

def cells( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['cells']={}
    surface_cargo['cells']['function'] = IceRayCpp.FunctionScalarNoiseCells(  )


    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['cells']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo

def random( P_light ):
    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['random']={}
    surface_cargo['random']['function'] = IceRayCpp.FunctionScalarNoiseRandom()


    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['random']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo

def gold( P_light ):
    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['gold']={}
    surface_cargo['gold']['function'] = IceRayCpp.FunctionScalarNoiseGold()


    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['gold']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo

def vdc( P_light ):
    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['vdc']={}
    surface_cargo['vdc']['function'] = IceRayCpp.FunctionScalarNoiseVDC()


    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['vdc']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo
