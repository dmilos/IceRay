import os
import IceRayCpp

def name( ):
    return "box"


def hexagon( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['hexagon']={}
    surface_cargo['hexagon']['function'] = IceRayCpp.FunctionSizeHexagon()

    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionSize( surface_cargo['hexagon']['function'], 1, 0 )

    surface_cargo['2'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.5, 0.0, 0.0 ), 2 )
    surface_cargo['3'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.0, 0.5, 0.0 ), 3 )
    surface_cargo['4'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.0, 0.0, 0.5 ), 4 )

    surface_cargo['5'] = IceRayCpp.MaterialSwitchColor( 1, 1, 2 )
    surface_cargo['6'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )
    surface_cargo['this'].append( surface_cargo['4'] )
    surface_cargo['this'].append( surface_cargo['5'] )
    surface_cargo['this'].append( surface_cargo['6'] )

    return surface_cargo


def brick( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['brick']={}
    surface_cargo['brick']['function'] = IceRayCpp.FunctionSizeBrick()

    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionSize( surface_cargo['brick']['function'], 1, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.5, 0, 0.0 ), 2 )
    surface_cargo['3'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.5, 0, 0.5 ), 3 )

    surface_cargo['4'] = IceRayCpp.MaterialSwitchColor( 1, 1, 2 )
    surface_cargo['5'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )
    surface_cargo['this'].append( surface_cargo['4'] )
    surface_cargo['this'].append( surface_cargo['5'] )

    return surface_cargo


def checker( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['checker']={}
    surface_cargo['checker']['function'] = IceRayCpp.FunctionSizeChecker()

    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionSize( surface_cargo['checker']['function'], 1, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.5, 0, 0.0 ), 2 )
    surface_cargo['3'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.5, 0, 0.5 ), 3 )

    surface_cargo['4'] = IceRayCpp.MaterialSwitchColor( 1, 1, 2 )
    surface_cargo['5'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )
    surface_cargo['this'].append( surface_cargo['4'] )
    surface_cargo['this'].append( surface_cargo['5'] )

    return surface_cargo

def level( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['level']={}
    surface_cargo['level']['function'] = IceRayCpp.FunctionScalarLevel( IceRayCpp.MathTypeCoord3D().load(0,0,0.5) )


    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['level']['function'], 0, 0 )
    surface_cargo['1a'] = IceRayCpp.MaterialScalarClipSaw( 0, 0 )

    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['1a'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo

def onion( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['onion']={}
    surface_cargo['onion']['function'] = IceRayCpp.FunctionScalarOnion()


    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['onion']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo


def image( P_light , P_path = str( os.getcwd()[0] ) + ":\\work\\code\\cpp\\prj\\github\\IceRay\\work\\data\\di.pnm" ):

    image={}
    image['type']     = IceRayCpp.GraphTypePicture()
    image['type'].load( P_path );
    #image['type'].load( str( os.getcwd()[0] ) + ":\\work\\code\\cpp\\prj\\github\\IceRay\\work\\data\\gray-scale-x.pnm");

    image['function'] = IceRayCpp.FunctionColorImage( image['type'] )

    surface = IceRayCpp.MaterialSurface()

    a1 = IceRayCpp.MaterialPatternFunctionColor( image['function'], 1, 0 )
    a2 = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface.append( a1 )
    surface.append( a2 )
    return { 'this' : surface, '0':a1, '1':a2, 'image' : image }

def normal( P_light ):
    surface = IceRayCpp.MaterialSurface()

    a1 = IceRayCpp.MaterialConvertCoord3D2Color( 1, 1 )
    a2 = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface.append( a1 )
    surface.append( a2 )
    return { 'this' : surface, '0':a1, '1':a2, 'image' : image }

def wave_sin( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['crackle']={}
    surface_cargo['crackle']['function'] = IceRayCpp.FunctionScalarWaveSin()

    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['crackle']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )
    
    return surface_cargo

def wave_saw( P_light ):

    surface_cargo = {}
    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['crackle']={}
    surface_cargo['crackle']['function'] = IceRayCpp.FunctionScalarWaveSaw()

    surface_cargo['1'] = IceRayCpp.MaterialPatternFunctionScalar( surface_cargo['crackle']['function'], 0, 0 )
    surface_cargo['2'] = IceRayCpp.MaterialConvertScalar2Color( 0, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo
