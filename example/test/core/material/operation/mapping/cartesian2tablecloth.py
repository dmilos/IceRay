import os
import IceRayCpp


def make( P_light, P_image = str( os.getcwd()[0] ) + ":\\work\\code\\cpp\\prj\\github\\IceRay\\work\\data\\di.pnm" ):

    surface_cargo = {}

    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['image']={}
    surface_cargo['image']['picture']  = IceRayCpp.GraphTypePicture( P_image )
    surface_cargo['image']['function'] = IceRayCpp.FunctionColorImage( surface_cargo['image']['picture'] )

    surface = IceRayCpp.MaterialSurface()

    surface_cargo['1'] = IceRayCpp.MaterialCoord3DMappingCartesian2Tablecloth( 0, 1 )
    surface_cargo['2'] = IceRayCpp.MaterialPatternColorFunction( surface_cargo['image']['function'], 1, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo