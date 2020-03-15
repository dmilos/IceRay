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

def print_cylinder( P_cylinder ):
    print_string( "Interval: " )
    print_interval( P_cylinder.interval() )
    print_string( "; " )

    print_string( "radius: " )
    print_string( str( P_cylinder.radius() ) )

    print

print( '********************' )

cylinder1 = IceRayCpp.GeometrySimpleCylinder()
print_cylinder( cylinder1 )
cylinder1.radius( 4 )
print_cylinder( cylinder1 )