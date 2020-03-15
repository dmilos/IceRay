import IceRayCpp
import IceRayPy
import sys

print( '0 - OBJECT' )
object = IceRayCpp.CoreObject()

sphere3 = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,2,0), 1 )

object.geometry( sphere3 )

surface = IceRayCpp.MaterialSurface()

a1 = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.5 ), 0 )
a2 = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )

surface.append( a1 )
surface.append( a2 )

object.surface( surface )


print( '1 - ENGINE' )
image = IceRayCpp.GraphTypePicture( )
image.size( IceRayCpp.MathTypeSize2D().load( 1000, 1000 ) );

engine = IceRayPy.core.render.Engine()
engine.object( object )

camera_perspective = IceRayCpp.CameraFlatOrthogonal()
camera_cone = IceRayCpp.CameraCone( )
aperture = 0
camera_cone.aperture( aperture)
sample = 10
camera_cone.sample( sample )
camera_cone.child( camera_perspective )
engine.camera( camera_cone )

print( '2 - Render' )
sys.stdout.flush()
engine.start( image )

print( '2 - *****' )
file_name = "cone-render-"
file_name += 's('+ str(sample)+')'
file_name += 'a('+ str(aperture) + ')'
file_name += '.ppm'
print( IceRayCpp.GraphPictureStorePNM( file_name, image ) );

aperture = 0.05
camera_cone.aperture( aperture )
print( '3 - *****' )
sys.stdout.flush()
engine.start( image )
file_name = "cone-render-"
file_name += 's('+ str(sample)+')'
file_name += 'a('+ str(aperture) + ')'
file_name += '.ppm'
print( IceRayCpp.GraphPictureStorePNM( file_name, image ) );

