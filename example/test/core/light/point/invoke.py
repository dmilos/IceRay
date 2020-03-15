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
    sys.stdout.write(' ( ')
    sys.stdout.write(' ( center:  '); print_coord( P_spot.center() );  sys.stdout.write(' )')
    sys.stdout.write(' ( 0:  '); print_color( P_spot._0() );  sys.stdout.write(' )')
    sys.stdout.write(' ( 1:  '); print_color( P_spot._1() );  sys.stdout.write(' )')
    sys.stdout.write(' ( 2:  '); print_color( P_spot._2() );  sys.stdout.write(' )')
    sys.stdout.write(' ) ')
    
def print_light_point( P_point ):
    print_light_spot( P_point.spot() )

point1 = IceRayCpp.LightPoint()

point1.spot( IceRayCpp.LightTypeSpot() )
print_light_point( point1 ); print

point1.center( IceRayCpp.MathTypeCoord3D().load(0,2,0) )

print_light_point( point1 )