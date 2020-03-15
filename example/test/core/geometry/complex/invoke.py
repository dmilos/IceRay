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

def print_complex_intersect(P_intersect):
    print_string( "Interval: " )
    print_interval( P_intersect.interval() )
    print()

print( '0 - ********************' )


sphere1 = IceRayCpp.GeometrySimpleSphere()
box1 = IceRayCpp.GeometrySimpleBox()
#print( '0 - ********************' )
intersect1 = IceRayCpp.GeometryComplexIntersect()
#print( '1 - ********************' )
print_complex_intersect( intersect1 )
#print() '2 - ********************' )
#intersect1.left( sphere1, IceRayCpp.Geometry_Inside.nowhere )
#print( '3 - ********************' )
print_complex_intersect( intersect1 )

intersect1.right( box1 )
intersect1.left( sphere1, IceRayCpp.Geometry_Inside.surface )
#print( '4 - ********************' )
print_complex_intersect( intersect1 )
