import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

def print_string( P_string ):
    sys.stdout.write( P_string )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_interval1D(P_interval):
    sys.stdout.write('( ')
    sys.stdout.write( str( P_interval.lo() ) )
    sys.stdout.write(', ')
    sys.stdout.write( str( P_interval.hi() ) )
    sys.stdout.write(' )')

def print_camera_focus( P_focus ):
    print( P_focus.child() )
    print_interval1D( P_focus.aperture() )
    print_interval1D( P_focus.focus() )
    print( P_focus.sample() )
    print( P_focus.gauss()  )
    

print( '********************' )

center = IceRayCpp.MathTypeCoord3D().load(123,123,123)
center[0] = 1
center[1] = 2
center[2] = 4

perspective1 = IceRayCpp.CameraFlatPerspective()

focus1 = IceRayCpp.CameraFocus()

print( focus1.child( perspective1 ) )
print( focus1.child( )              )

print( '------------' )
print_camera_focus( focus1 )
print()


