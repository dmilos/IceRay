import IceRayCpp
import IceRayPy
import sys
import math

def make_geometry_intersect( ): # P_center, P_radius

    sphere = IceRayCpp.GeometrySimpleSphere()
    box = IceRayCpp.GeometrySimpleBox()

    intersect = IceRayCpp.GeometryComplexIntersect()
    intersect.right( box )
    intersect.left( sphere, IceRayCpp.Geometry_Inside.surface )

    return { 'geometry': intersect, '0' : sphere, '1' : box }

def make_surface( ):
    surface = IceRayCpp.MaterialSurface()

    a1 = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.5 ), 0 )
    a2 = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )

    surface.append( a1 )
    surface.append( a2 )
    return { 'surface' : surface, '0':a1, '1':a2 }


def make_object(  ):
    object = IceRayCpp.CoreObject()

    cargo_geometry = make_geometry_intersect()
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

    return { 'camera' : transform, '0':perspective }

def make_image(P_width,P_height):
    image = IceRayCpp.GraphTypePicture( )
    image.size( IceRayCpp.MathTypeSize2D().load( P_width, P_height ) );
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

    cargo_image = make_image( 256, 256 )
    cargo_engine['engine'].start( cargo_image['image'] )

    print( 'End rendering' )

    print( 'Save Image' )
    angle = 0

    file_name = "intersect_ii"
    file_name += '.ppm'

    print( IceRayCpp.GraphPictureStorePNM( file_name, cargo_image['image'] ) );

    print( 'All Done' )

main()


