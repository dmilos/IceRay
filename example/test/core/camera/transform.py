import sys
import IceRayPy 
import IceRayCpp
from IceRayPy import *

print( '********************' )
#print( IceRayPy.core.__dict__ )
print( '********************' )

def print_string( P_string ):
    sys.stdout.write( P_string )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_interval(P_interval):
    sys.stdout.write('( ')
    print_coord( P_interval.lo() )
    print_coord( P_interval.hi() )
    sys.stdout.write(' )')

def print_camera_transform( P_transform ):

    print

t = IceRayPy.core.camera.Transform()


print( '********************' )

center = IceRayCpp.MathTypeCoord3D().load(123,123,123)
center[0] = 1
center[1] = 2
center[2] = 4

perspective1 = IceRayCpp.CameraFlatPerspective()

transform1 = IceRayCpp.CameraTransformAffine()

transform1.child( perspective1 )
aa = transform1.child()


affine = IceRayCpp.MathTypeAffine3D()

print( transform1.world() )
print( transform1.local() )


#transform1.scale( 2 )
#transform1.scale( IceRayCpp.MathTypeCoord3D( 1, 2, 3 ) )
#
#transform1.move( IceRayCpp.MathTypeCoord3D( 123 ) )
#transform1.move( IceRayCpp.MathTypeCoord3D( 1, 2, 3 ) )
#transform1.move( IceRayCpp.MathTypeCoord3D( 1, 2, 3 ) )
#
#transform1.rotate_x( 60 * 3.1415926/180 )
#transform1.rotate_y( 60 * 3.1415926/180 )
#transform1.rotate_z( 60 * 3.1415926/180 )


print( '------------' )
print_camera_transform( transform1 )
print
