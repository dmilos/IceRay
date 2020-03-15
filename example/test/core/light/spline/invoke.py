import sys

import IceRayCpp
import IceRayPy

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

def print_spline( P_spline ):
    print_light_spot( P_spline.spot() )
    print_coord( spline1.cp( 0 ) )
    print_coord( spline1.cp( 1 ) )
    print_coord( spline1.cp( 2 ) )
    print( spline1.sample( ) )

spline1 = IceRayCpp.LightSpline( )

spline1.spot( IceRayCpp.LightTypeSpot() )
spline1.sample( 10 )
spline1.cp( 5 )
spline1.cp( 5, IceRayCpp.MathTypeCoord3D().load(0,2,0)  )

print_spline( spline1 )
