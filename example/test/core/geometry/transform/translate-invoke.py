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

def print_translate( P_translate ):
    print_string( "Interval: " )
    print_interval( P_translate.interval() )
    print( P_translate.__dict__ )
    print

print( '********************' )

move1 = IceRayCpp.MathTypeCoord3D().load(123,123,123)
move1[0] = 0
move1[1] = 0
move1[2] = 0

translate1 = IceRayCpp.GeometryTransformTranslate()
translate2 = IceRayCpp.GeometryTransformTranslate( move1 )

sphere3 = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 10 )

translate2.child( sphere3 )

translate2.move( IceRayCpp.MathTypeCoord3D().load(0,2,0) )

print( '------------' )
print_translate( translate1 )
print_translate( translate2 )
print()
