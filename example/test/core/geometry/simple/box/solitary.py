import IceRayCpp
import IceRayPy
import sys
import math
import time
import unit


def make_surface( ):
    surface = IceRayCpp.MaterialSurface()

    a1 = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.5 ), 0 )
    a2 = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )

    surface.append( a1 )
    surface.append( a2 )
    return { 'this' : surface, '0':a1, '1':a2 }

def make_object(  ):
    object = IceRayCpp.CoreObject()

    cargo_geometry = unit.make()
    object.geometry( cargo_geometry['this'] )

    cargo_surface = make_surface( )
    object.surface( cargo_surface['this'] )

    return { 'this' : object, 'geometry':cargo_geometry, 'surface': cargo_surface }

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

    return { 'this': engine, 'camera': cargo_camera, 'object': cargo_object  }


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

    file_name = "solitary-box"
    file_name += '.ppm'

    print( IceRayCpp.GraphPictureStorePNM( file_name, cargo_image['this'] ) );

    print( 'All Done' )

main()

