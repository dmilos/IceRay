import IceRayCpp
import IceRayPy
import sys

# Make Object
object = IceRayCpp.CoreObject()

# Make geometry
sphere3 = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,2,0), 1 )

object.geometry( sphere3 )
# Make surface
surface = IceRayCpp.MaterialSurface()

a1 = IceRayCpp.MaterialPatternColorConstant( IceRayCpp.GraphTypeColorRGB().fill( 0.5 ), 0 )
a2 = IceRayCpp.MaterialIlluminationAmbient( 0, 0 )

surface.append( a1 )
surface.append( a2 )

object.surface( surface )

# Make image
image = IceRayCpp.GraphTypePicture( )
image.size( IceRayCpp.MathTypeSize2D().load( 1000, 1000 ) );

# Make engine
e = IceRayPy.core.render.Engine()
e.object( object )
print( 'Start rendering' )
sys.stdout.flush()
e.start( image )
print( 'End rendering' )

print( 'Save Image' )
file_name = "first.ppm"
print( IceRayCpp.GraphPictureStorePNM( file_name, image ) )

print( 'All Done' )
