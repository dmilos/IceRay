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
    print( P_interval.lo() )
    print( P_interval.hi() )
    sys.stdout.write(' )')

def print_camera_cone( P_cone ):
    print( P_cone.child()    )
    print( P_cone.aperture() )
    print( P_cone.sample()   )
    print( P_cone.gauss()    )
    

print( '********************' )

center = IceRayCpp.MathTypeCoord3D().load(123,123,123)
center[0] = 1
center[1] = 2
center[2] = 4

perspective1 = IceRayCpp.CameraFlatPerspective()

cone1 = IceRayCpp.CameraCone()

print( cone1.child( perspective1 ) )
print( cone1.child( )              )

print( '------------' )
print_camera_cone( cone1 )
print()
