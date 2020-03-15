import IceRayCpp
import IceRayPy
import sys
import math
import time

def make_geometry_rtss_uniform( ):
    I_center = IceRayCpp.MathTypeCoord3D().load(0,0,0)

    I_radius = 0.75
    sphere1 = IceRayCpp.GeometrySimpleSphere( I_center.load(0,2,0), I_radius )
    sphere2 = IceRayCpp.GeometrySimpleSphere( I_center.load(2,0,0), I_radius )
    sphere3 = IceRayCpp.GeometrySimpleSphere( I_center.load(0,0,2), I_radius )
    box = IceRayCpp.GeometrySimpleBox()

    uniform = IceRayCpp.GeometryRTSSUniform()
    #dimension = IceRayCpp.MathTypeCell3D()
    #dimension.load(1,1,1)
    #uniform.dimension( dimension )
    
    geometry = IceRayCpp.GeometryRTSSGeometry( )
    geometry.rtss( uniform )

    geometry.push( sphere1 )
    geometry.push( sphere2 )
    geometry.push( sphere3 )
    geometry.push( box )
    geometry.optimize();

    return { 'geometry': geometry, '-1': uniform,  '1' :box, '2':sphere1, '3':sphere2, '4':sphere3 }

def make_surface( ):
    surface = IceRayCpp.MaterialSurface()

    a1 = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.5 ), 0 )
    a2 = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )

    surface.append( a1 )
    surface.append( a2 )
    return { 'surface' : surface, '0':a1, '1':a2 }


def make_object(  ):
    object = IceRayCpp.CoreObject()

    cargo_geometry = make_geometry_rtss_uniform()
    object.geometry( cargo_geometry['geometry'] )

    cargo_surface = make_surface( )
    object.surface( cargo_surface['surface'] )

    return { 'object' : object, '0': cargo_geometry, '1': cargo_surface }

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

    cargo_image = make_image( 1256, 1256 )
    clock = time.perf_counter()
    cargo_engine['engine'].start( cargo_image['image'] )
    clock = time.perf_counter() - clock
    print( 'Rendering time: ' + str( clock ) )
    print( 'End rendering' )

    print( 'Save Image' )
    angle = 0

    file_name = "rtss-uniform"
    file_name += '.ppm'

    print( IceRayCpp.GraphPictureStorePNM( file_name, cargo_image['image'] ) );

    print( 'All Done' )

main()


