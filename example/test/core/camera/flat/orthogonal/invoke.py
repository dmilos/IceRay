import sys
import IceRayCpp

def print_string( P_string ):
    sys.stdout.write( P_string )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_interval(P_interval):
    sys.stdout.write('( ')
    print_coord( P_interval.lo() )
    print_coord( P_interval.hi() )
    sys.stdout.write(' )')

def print_camera_orthogonal( P_orthogonal ):

    print

print( '********************' )


orthogonal1 = IceRayCpp.CameraFlatOrthogonal()

#orthogonal1.aspect( 4/3 )


print( '------------' )
print_camera_orthogonal( orthogonal1 )
print()
