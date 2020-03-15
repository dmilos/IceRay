import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

def print_string( P_string ):
    sys.stdout.write( P_string )

def print_color(P_color):
    sys.stdout.write( '(' + str( P_color[0] ) + ', ' + str( P_color[1] ) + ', ' +  str( P_color[2] ) + ')' )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_interval(P_interval):
    sys.stdout.write('( ')
    print_coord( P_interval.lo() )
    print_coord( P_interval.hi() )
    sys.stdout.write(' )')

def print_Spot( P_spot ):
    print_coord( P_spot.center() )
    print_color( P_spot._0() )
    print_color( P_spot._1() )
    print_color( P_spot._2() )

    print

spot1 = IceRayCpp.LightTypeSpot()
spot2 = IceRayCpp.LightTypeSpot( IceRayCpp.MathTypeCoord3D() )
spot3 = IceRayCpp.LightTypeSpot( IceRayCpp.MathTypeCoord3D(),IceRayCpp.GraphTypeColorRGB().fill( 0.5 ),IceRayCpp.GraphTypeColorRGB().fill( 0.5 ),IceRayCpp.GraphTypeColorRGB().fill( 0.5 ) )



spot1.center( IceRayCpp.MathTypeCoord3D().load(0.5,0.5,0.5) )
print_coord( spot1.center() )

spot1._0( IceRayCpp.GraphTypeColorRGB().fill( 0.4 ) )
print_color( spot1._0() )

spot1._1( IceRayCpp.GraphTypeColorRGB().fill( 0.3 ) )
print_color( spot1._1() )

spot1._2( IceRayCpp.GraphTypeColorRGB().load(1,2,3) )
print_color( spot1._2() )





