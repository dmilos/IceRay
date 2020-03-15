import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

def print_string( P_string ):
    sys.stdout.write( P_string )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_interval( P_interval ):
    print_string( "(" )
    print_coord( P_interval.lo() )
    print_string( ", " )
    print_coord( P_interval.hi() )
    print_string(' )')

def print_plane( P_plane ):
    print_string( "Interval: " )
    print_interval( P_plane.interval() )
    print_string( "; " )
    
    print_string( "normal: " )
    print_coord( P_plane.normal() )
    print_string( "; " )
    print_string( "pivot: " )
    print_coord( P_plane.pivot() )
    print_string( "; " )
    print

print( '********************' )

plane1 = IceRayCpp.GeometrySimplePlane()
print_plane( plane1 )
 
plane1.pivot( IceRayCpp.MathTypeCoord3D().load(0,1,2)  )
print_plane( plane1 )

plane1.normal( IceRayCpp.MathTypeCoord3D().load(0,0,1)  )
print_plane( plane1 )
