import IceRayCpp
import IceRayPy
import sys
import math
import time
import unit


def make_geometry_oposit():
    I_center = IceRayCpp.MathTypeCoord3D().load(0,0,0)
    I_radius = 1
    sphere = IceRayCpp.GeometrySimpleSphere( I_center.load(1,-1,0), I_radius )
    return{ 'this' : sphere }

def make_geometry_rtss_list( ):

    oposit_cargo = make_geometry_oposit()
    sample_cargo = unit.make()

    lo = IceRayCpp.MathTypeCoord3D()
    lo[0] = -3
    lo[1] = -3
    lo[2] = -1.1

    hi = IceRayCpp.MathTypeCoord3D()
    hi[0] = 3
    hi[1] = 3
    hi[2] = -1

    box = IceRayCpp.GeometrySimpleBox( lo, hi )
    list = IceRayCpp.GeometryRTSSList()

    geometry = IceRayCpp.GeometryRTSSGeometry( )
    geometry.rtss( list )

    geometry.push( sample_cargo['this'] )
    geometry.push( box )

    return { 'this': geometry, '-1': list,  '1' : sample_cargo, '2': 'box', '3': oposit_cargo }
    #return { 'geometry': geometry }

def make_light_blocked( ):

    blocked = IceRayCpp.LightObstruct()

    point = IceRayCpp.LightPoint()

    point.spot( IceRayCpp.LightTypeSpot() )

    point.center( IceRayCpp.MathTypeCoord3D().load(0,0,10) )


    blocked.light( point )

    return { 'this': blocked, '0': point }

def make_surface( ):
    surface = IceRayCpp.MaterialSurface()

    light_cargo = make_light_blocked( )

    a = {}
    a['1'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.1 ), 0 )
    a['2'] = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )
    a['3'] = IceRayCpp.MaterialLightGenerator( light_cargo['this'], 0 )
    a['4'] = IceRayCpp.MaterialLightSwarm0( 0, 0 )
    a['5'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.5 ), 1 )
    a['6'] = IceRayCpp.MaterialIlluminationLambert( 0, 0, 1, 0, 1 )

    surface.append( a['1'] )
    surface.append( a['2'] )
    surface.append( a['3'] )
    surface.append( a['4'] )
    surface.append( a['5'] )
    surface.append( a['6'] )

    return { 'this' : surface, 'light': light_cargo, '0': a  }

def make_object(  ):
    object = IceRayCpp.CoreObject()

    cargo_geometry = make_geometry_rtss_list()
    object.geometry( cargo_geometry['this'] )

    cargo_surface = make_surface( )
    object.surface( cargo_surface['this'] )

    cargo_surface['light']['this'].barrier( cargo_geometry['this'] )

    return { 'this' : object, 'geometry' : cargo_geometry, 'surface': cargo_surface }

def make_camera( ): # P_eye, P_view, P_up
    perspective = IceRayCpp.CameraFlatPerspective()
    transform = IceRayCpp.CameraTransformAffine()

    transform.child( perspective )
    eye  = IceRayCpp.MathTypeCoord3D();  eye.load( 1, 5, 3 )
    view = IceRayCpp.MathTypeCoord3D(); view.load( 0, 0, 0 )
    up   = IceRayCpp.MathTypeCoord3D();   up.load( 0, 0, 1 )

    affine = IceRayCpp.MathAffine3D_lookAt( eye, view, up )
    transform.world( affine )

    return { 'this' : transform, '0':perspective }

def make_image(P_width,P_height):
    image = IceRayCpp.GraphTypePicture( )
    image.size( IceRayCpp.MathTypeSize2D().load( P_width, P_height ) );
    return { 'this' : image }

def make_engine():
    engine = IceRayPy.core.render.Engine()

    cargo_camera = make_camera()
    engine.camera( cargo_camera['this'] )

    cargo_object = make_object()
    engine.object( cargo_object['this'] )

    return { 'this': engine, '0': cargo_camera, '1': cargo_object  }


# Make engine
def main():
    cargo_engine = make_engine()

    print( 'Start rendering' )
    sys.stdout.flush()

    cargo_image = make_image( 600, 600 )
    clock = time.perf_counter()
    cargo_engine['this'].start( cargo_image['this'] )
    clock = time.perf_counter() - clock
    print( 'Rendering time: ' + str( clock ) )
    print( 'End rendering' )

    print( 'Save Image' )
    angle = 0

    file_name = "intersect"
    file_name += '.ppm'

    print( IceRayCpp.GraphPictureStorePNM( file_name, cargo_image['this'] ) );

    print( 'All Done' )

main()


