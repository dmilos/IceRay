import os
import math
import IceRayCpp

def name( ):
    return "hfield"

def theone(  ):

    cargo = {}
    cargo['this'] = IceRayCpp.GeometryHFieldSystem( )

    cargo['container'] = IceRayCpp.GeometryHFieldContainerTheOne( )
    cargo['object'] = IceRayCpp.GeometryHFieldObjectFlat()

    cargo['this'].container( cargo['container'] )
    cargo['this'].object( cargo['object'] )

    return cargo

def funktion(  ):
    cargo = {}
    cargo['this'] = IceRayCpp.GeometryHFieldSystem( )

    cargo['container'] = IceRayCpp.GeometryHFieldContainerFunction( )
    cargo['object'] = IceRayCpp.GeometryHFieldObjectFlat()

    cargo['this'].container( cargo['container'] )
    cargo['this'].object( cargo['object'] )

    return cargo


def geometry(  ):
    pass

def b3(  ):
    pass

def pattern(  ):

    cargo = {}
    cargo['this'] = IceRayCpp.GeometryHFieldSystem( )

    cargo['container'] = IceRayCpp.GeometryHFieldContainerTable( )
    cargo['object'] = IceRayCpp.GeometryHFieldObjectFlat()

    cargo['this'].container( cargo['container'] )
    cargo['this'].object( cargo['object'] )

    #image={}
    #image['type']     = IceRayCpp.GraphTypePicture()
    #image['type'].load( P_path );
    ##image['type'].load( str( os.getcwd()[0] ) + ":\\work\\code\\cpp\\prj\\github\\IceRay\\work\\data\\gray-scale-x.pnm");
    #
    #image['function'] = IceRayCpp.FunctionColorImage( image['type'] )


    return cargo

