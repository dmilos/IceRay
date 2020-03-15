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

camera_perspective = IceRayCpp.CameraFlatPerspective()
camera_focus = IceRayCpp.CameraFocus( )

aperture = IceRayCpp.MathTypeInterval1D( 0, 1 )
camera_focus.aperture( aperture )
focus = IceRayCpp.MathTypeInterval1D( 20, 20 )
camera_focus.focus( focus )

sample = 10
camera_focus.sample( sample )
camera_focus.child( camera_perspective )
engine.camera( camera_focus )

print( '2 - Render' )
sys.stdout.flush()
engine.start( image )

print( '2 - *****' )
file_name = "focus-render-"
file_name += 's('+ str(sample)+')'
file_name += 'f('+ str(focus.lo())+','+str(focus.hi())+')'
file_name += 'a('+ str(aperture.lo())+','+str(aperture.hi())+')'
file_name += '.ppm'
print( IceRayCpp.GraphPictureStorePNM( file_name, image ) );

aperture = IceRayCpp.MathTypeInterval1D( 0, 0 )
camera_focus.aperture( aperture )
print( '3 - *****' )
sys.stdout.flush()
engine.start( image )
file_name = "focus-render-"
file_name += 's('+ str(sample)+')'
file_name += 'f('+ str(focus.lo())+','+str(focus.hi())+')'
file_name += 'a('+ str(aperture.lo())+','+str(aperture.hi())+')'
file_name += '.ppm'
print( IceRayCpp.GraphPictureStorePNM( file_name, image ) );

