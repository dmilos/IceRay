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

def print_triangle( P_triangle ):
    print_string( "Interval: " )
    print_interval( P_triangle.interval() )
    print_string( "; " )
    
    print_string( "origin: " )
    print_coord( P_triangle.origin() )
    print_string( "e0: " )
    print_coord( P_triangle.eX() )
    print_string( "e1: " )
    print_coord( P_triangle.eY() )
    
    print

print( '********************' )

triangle1 = IceRayCpp.GeometrySimpleTriangle( )
triangle1.origin( IceRayCpp.MathTypeCoord3D() )
coord1 = IceRayCpp.MathTypeCoord3D().load( 1, 2, 3 )
triangle1.e0( coord1.load(1,0,0) )
triangle1.e1( coord1.load(0,1,0) )

print_triangle( triangle1 )