import sys
import os
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

print( '********************' )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_interval(P_interval):
    sys.stdout.write('( ')
    print_coord( P_interval.lo() )
    print_coord( P_interval.hi() )
    sys.stdout.write(' ) ')

coord1 = IceRayCpp.MathTypeCoord3D(2)
coord2 = IceRayCpp.MathTypeCoord3D()
coord3 = IceRayCpp.MathTypeCoord3D()

coord2[0] = 1
coord2[1] = 2
coord2[2] = 3

coord3[0] = 1
coord3[1] = 2
coord3[2] = 3



#interval1 = IceRayCpp.MathTypeInterval3S(coord1)
interval2 = IceRayCpp.MathTypeInterval3D(coord1,coord2)

interval2.lo()
interval2.hi()

coord3[0] = 121
coord3[1] = 122
coord3[2] = 123

interval2.lo(coord3)
coord3[0] = 8
coord3[1] = 7
coord3[2] = -5

interval2.hi( coord3 )

print_interval( interval2 )
print
interval2.correct()
print_interval( interval2 )
print

coord3[0] = 10


interval2.load( coord1, coord2 )
print_interval( interval2 )
print
interval2.correct()
print_interval( interval2 )
print

print( interval2.inside( coord3 ) )
print( interval2.outside( coord3 ) )


IceRayCpp.MathTypeInterval1D( 0, 1 )

