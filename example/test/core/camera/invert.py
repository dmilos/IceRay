import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
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

def print_camera_invert( P_invert ):

    print

print( '********************' )

center = IceRayCpp.MathTypeCoord3D().load(123,123,123)
center[0] = 1
center[1] = 2
center[2] = 4

perspective1 = IceRayCpp.CameraFlatPerspective()

invert1 = IceRayCpp.CameraTransformInvert()
invert1.child( perspective1 )
print( invert1.child() )


invert1.child( perspective1 )

print( '------------' )
print_camera_invert( invert1 )
print()
