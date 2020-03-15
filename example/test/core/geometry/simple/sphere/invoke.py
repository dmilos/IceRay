import sys
import IceRayCpp

import IceRayPy 
from IceRayPy import *

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

def print_sphere( P_sphere ):
    print_string( "Interval: " )
    print_interval( P_sphere.interval() )
    print_string( "; " )
    print_string( "radius:" + str( P_sphere.radius ) )
    print_string( "; " )
    print_string( "center:" )
    print_coord( P_sphere.center )
    print( P_sphere.__dict__ )

    print

print( '********************' )

center1 = IceRayCpp.MathTypeCoord3D().load(123,123,123)
center1[0] = 1
center1[1] = 2
center1[2] = 4.56

sphere1 = IceRayCpp.GeometrySimpleSphere()
sphere2 = IceRayCpp.GeometrySimpleSphere( center1, 1 )
sphere3 = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D(13), 1 )

print( '------------' )
print_sphere( sphere1 )
print

sphere1.radius = 1

print( '------------' )
sphere1.center = center1
print_sphere( sphere1 )
print


print( '------------' )
sphere1.radius = 0.256
print_sphere( sphere1 )

s0 = IceRayPy.core.geometry.simple.Sphere( )
s1 = IceRayPy.core.geometry.simple.Sphere( IceRayCpp.MathTypeCoord3D(1)  )
s2 = IceRayPy.core.geometry.simple.Sphere( IceRayCpp.MathTypeCoord3D(1), 1  )

print( s0.__dict__ )


