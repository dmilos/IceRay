import os
import IceRayCpp

def name( ):
    return "box"


def normal( P_light ):

    surface = IceRayCpp.MaterialSurface()

    a1 = IceRayCpp.MaterialConvertCoord3D2Color( 1, 1 )
    a2 = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface.append( a1 )
    surface.append( a2 )
    return { 'this' : surface, '0':a1, '1':a2, 'image' : image }

def uvw_sphere( P_light ):

    surface_cargo = {}

    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['uvw']={}
    surface_cargo['uvw']['geometry']= IceRayCpp.GeometrySimpleSphere()
    surface_cargo['uvw']['function'] = IceRayCpp.FunctionCoord3DGeometryUVW( surface_cargo['uvw']['geometry'] )

    surface_cargo['image']={}
    surface_cargo['image']['picture']  = IceRayCpp.GraphTypePicture(str( os.getcwd()[0] ) + ":\\work\\code\\cpp\\prj\\github\\IceRay\\work\\data\\gray-scale-x.pnm")
    surface_cargo['image']['function'] = IceRayCpp.FunctionColorImage( surface_cargo['image']['picture'] )

    surface_cargo['1'] = IceRayCpp.MaterialPatternCoord3DFunction( surface_cargo['uvw']['function'], 0, 1 )
    surface_cargo['2'] = IceRayCpp.MaterialPatternFunctionColor( surface_cargo['image']['function'], 1, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo

def uvw_box( P_light ):

    surface_cargo = {}

    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['uvw']={}
    surface_cargo['uvw']['geometry']= IceRayCpp.GeometrySimpleBox()
    surface_cargo['uvw']['function'] = IceRayCpp.FunctionCoord3DGeometryUVW( surface_cargo['uvw']['geometry'] )

    surface_cargo['image']={}
    surface_cargo['image']['picture']  = IceRayCpp.GraphTypePicture(str( os.getcwd()[0] ) + ":\\work\\code\\cpp\\prj\\github\\IceRay\\work\\data\\gray-scale-x.pnm")
    surface_cargo['image']['function'] = IceRayCpp.FunctionColorImage( surface_cargo['image']['picture'] )

    surface_cargo['1'] = IceRayCpp.MaterialPatternCoord3DFunction( surface_cargo['uvw']['function'], 0, 1 )
    surface_cargo['2'] = IceRayCpp.MaterialPatternFunctionColor( surface_cargo['image']['function'], 1, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo

def uvw_vacuum( P_light ):

    surface_cargo = {}

    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['uvw']={}
    surface_cargo['uvw']['geometry']= IceRayCpp.GeometryVolumetricVacuum()
    surface_cargo['uvw']['function'] = IceRayCpp.FunctionCoord3DGeometryUVW( surface_cargo['uvw']['geometry'] )

    surface_cargo['image']={}
    surface_cargo['image']['picture']  = IceRayCpp.GraphTypePicture(str( os.getcwd()[0] ) + ":\\work\\code\\cpp\\prj\\github\\IceRay\\work\\data\\gray-scale-x.pnm")
    surface_cargo['image']['function'] = IceRayCpp.FunctionColorImage( surface_cargo['image']['picture'] )

    surface_cargo['1'] = IceRayCpp.MaterialPatternCoord3DFunction( surface_cargo['uvw']['function'], 0, 1 )
    surface_cargo['2'] = IceRayCpp.MaterialPatternFunctionColor( surface_cargo['image']['function'], 1, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo

def uvw_torus( P_light ):

    surface_cargo = {}

    surface_cargo['this'] = IceRayCpp.MaterialSurface()

    surface_cargo['uvw']={}
    surface_cargo['uvw']['geometry']= IceRayCpp.GeometrySimpleTorus()
    surface_cargo['uvw']['function'] = IceRayCpp.FunctionCoord3DGeometryUVW( surface_cargo['uvw']['geometry'] )

    surface_cargo['image']={}
    surface_cargo['image']['picture']  = IceRayCpp.GraphTypePicture(str( os.getcwd()[0] ) + ":\\work\\code\\cpp\\prj\\github\\IceRay\\work\\data\\gray-scale-y.pnm")
    surface_cargo['image']['function'] = IceRayCpp.FunctionColorImage( surface_cargo['image']['picture'] )

    surface_cargo['1'] = IceRayCpp.MaterialPatternCoord3DFunction( surface_cargo['uvw']['function'], 0, 1 )
    surface_cargo['2'] = IceRayCpp.MaterialPatternFunctionColor( surface_cargo['image']['function'], 1, 1 )
    surface_cargo['3'] = IceRayCpp.MaterialIlluminationAmbient( 0, 1 )

    surface_cargo['this'].append( surface_cargo['1'] )
    surface_cargo['this'].append( surface_cargo['2'] )
    surface_cargo['this'].append( surface_cargo['3'] )

    return surface_cargo

