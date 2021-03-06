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

def print_disc( P_disc ):
    print_string( "Interval: " )
    print_interval( P_disc.interval() )
    print_string( "; " )

    print_string( "center: " )
    print_coord( P_disc.center() )
    print_string( "; " )
    
    print_string( "radius: " )
    print_string( str( P_disc.radius() ) )
    print_string( "; " )
    
    print_string( "normal: " )
    print_coord( P_disc.normal() )

    print

print( '********************' )

 