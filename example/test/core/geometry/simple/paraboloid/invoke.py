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

def print_paraboloid( P_paraboloid ):
    print_string( "Interval: " )
    print_interval( P_paraboloid.interval() )
    print_string( "; " )

    print_string( "radius: " )
    print_string( str( P_paraboloid.radius() ) )

    print

print( '********************' )

paraboloid1 = IceRayCpp.GeometrySimpleParaboloid()
print_paraboloid( paraboloid1 )