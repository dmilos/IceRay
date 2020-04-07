import IceRayCpp
import IceRayPy
import sys
import math
import time

def make_geometry_rtss_list( ): # P_center, P_radius
    I_center = IceRayCpp.MathTypeCoord3D().load(0,0,0)

    I_radius = 1
    sphere1 = IceRayCpp.GeometrySimpleSphere( I_center.load(0,0,1), I_radius )

    lo = IceRayCpp.MathTypeCoord3D().load(123,123,123)
    lo[0] = -2.5
    lo[1] = -2.5
    lo[2] = -0.1

    hi = IceRayCpp.MathTypeCoord3D().load(123,123,123)
    hi[0] = 2.5
    hi[1] = 2.5
    hi[2] = 0

    box = IceRayCpp.GeometrySimpleBox( lo, hi )
    list = IceRayCpp.GeometryRTSSList()

    geometry = IceRayCpp.GeometryRTSSGeometry( )
    geometry.rtss( list )

    geometry.push( sphere1 )
    geometry.push( box )

    return { 'geometry': geometry, '-1': list,  '1' :box, '2':sphere1 }
    #return { 'geometry': geometry }

def make_light_point( ):
    point = IceRayCpp.LightPoint()

    point.spot( IceRayCpp.LightTypeSpot() )

    point.center( IceRayCpp.MathTypeCoord3D().load( 1, 1, 3 ) )

    return { 'light': point }

def make_surface( ):
    surface = IceRayCpp.MaterialSurface()

    light_cargo = make_light_point( )

    a = {}
    a['1'] = IceRayCpp.MaterialLightGenerator( light_cargo['light'], 0 )
    #MaterialLightSpotSwarmA( [size]count, [light]light, [coord]point, [spot]start )
    cargo['2A'] = IceRayCpp.MaterialLightSpotSwarmA( 0, 0, 0, 0 )
    #MaterialLightSpotCull( [coord]point, [coord]normal, [spot]start, [size]count  )
    cargo['2B'] = IceRayCpp.MaterialLightSpotCull( 0, 1, 0, 0 )

    a['3'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.9 ), 1 )
    a['4'] = IceRayCpp.MaterialTransmissionReflectOne( 0, 1, 1 )

    a['5'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 0.1, 0.1, 0.1 ), 1 )
    a['6'] = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().load( 10.0, 10.0, 10.0 ), 2 )
    a['7'] = IceRayCpp.MaterialPatternCoord3DConstant( IceRayCpp.MathTypeCoord3D().load( 0, 0.0, 1.0 ), 2 )
    #MaterialIlluminationHSPhong( [Coord]point, [Coord]normal, [size]lightCount, [color]specular, [color]shiness, [coord]groovie, [color]result )
    a['8'] = IceRayCpp.MaterialIlluminationHSPhong( 0, 1, 1, 1, 2, 2, 0 )

    surface.append( a['1'] )
    surface.append( a['2A'] )
    surface.append( a['2B'] )
    surface.append( a['3'] )
    surface.append( a['4'] )
    surface.append( a['5'] )
    surface.append( a['6'] )
    surface.append( a['7'] )
    surface.append( a['8'] )

    return { 'this' : surface, '0': a, '1': light_cargo  }

def make_object(  ):
    object = IceRayCpp.CoreObject()

    cargo_geometry = make_geometry_rtss_list()
    object.geometry( cargo_geometry['geometry'] )

    cargo_surface = make_surface( )
    object.surface( cargo_surface['surface'] )

    return { 'object' : object, '0':cargo_geometry, '1': cargo_surface }

def make_camera( ): # P_eye, P_view, P_up
    perspective = IceRayCpp.CameraFlatPerspective()
    transform = IceRayCpp.CameraTransformAffine()

    transform.child( perspective )
    eye  = IceRayCpp.MathTypeCoord3D();  eye.load( 3, 3, 3 )
    view = IceRayCpp.MathTypeCoord3D(); view.load( 0, 0, 0 )
    up   = IceRayCpp.MathTypeCoord3D();   up.load( 0, 0, 1 )

    affine = IceRayCpp.MathAffine3D_lookAt( eye, view, up )
    transform.world( affine )

    return { 'camera' : transform, '0' : perspective }

def make_image(P_width,P_height):
    image = IceRayCpp.GraphTypePicture( )
    size = IceRayCpp.MathTypeSize2D()
    size.load( P_width, P_height )
    image.size( size );
    return { 'image' : image }

def make_engine():
    engine = IceRayPy.core.render.Engine()

    cargo_camera = make_camera()
    engine.camera( cargo_camera['camera'] )

    cargo_object = make_object()
    engine.object( cargo_object['object'] )

    return { 'engine': engine, '0': cargo_camera, '1': cargo_object  }


# Make engine
def main():
    cargo_engine = make_engine()

    print( 'Start rendering' )
    sys.stdout.flush()

    cargo_image = make_image( 600, 600 )
    clock = time.perf_counter()
    cargo_engine['engine'].start( cargo_image['image'] )
    clock = time.perf_counter() - clock
    print( 'Rendering time: ' + str( clock ) )
    print( 'End rendering' )

    print( 'Save Image' )
    angle = 0

    file_name = "hs-phong"
    file_name += '.ppm'

    print( IceRayCpp.GraphPictureStorePNM( file_name, cargo_image['image'] ) );

    print( 'All Done' )

main()


