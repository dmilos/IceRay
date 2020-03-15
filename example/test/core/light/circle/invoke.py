import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

def print_string( P_string ):
    sys.stdout.write( P_string )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_color(P_color):
    sys.stdout.write( '(' + str( P_color[0] ) + ', ' + str( P_color[1] ) + ', ' +  str( P_color[2] ) + ')' )

def print_interval(P_interval):
    sys.stdout.write('( ')
    print_coord( P_interval.lo() )
    print_coord( P_interval.hi() )
    sys.stdout.write(' )')

def print_light_spot(P_spot):
    print_coord( P_spot.center() )
    print_color( P_spot._0() )
    print_color( P_spot._1() )
    print_color( P_spot._2() )

def print_circle( P_circle ):
    print_light_spot( P_circle.spot() )
    print_coord( P_circle.x() )
    print_coord( P_circle.y() )
    print( P_circle.sample() )
    
circle1 = IceRayCpp.LightCircle()

print_circle( circle1 )