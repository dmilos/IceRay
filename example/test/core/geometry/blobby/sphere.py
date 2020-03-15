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
    sys.stdout.write( '( ')
    print_coord( P_interval.lo() )
    print_coord( P_interval.hi() )
    sys.stdout.write(' )')

def print_blobby_sphere( P_spehre ):
    print_string( 'center: ' )
    print_coord( P_spehre.center() )
    print_string( '; ' )
    print_string( 'influence: ' )
    print_string( str( P_spehre.influence() ) )
    print_string( '; ' )
    print_string( 'radius: ' )
    print_string( str( P_spehre.radius() ) )
    print_string( "; " )

    print()

print( '********************' )


sphere1 = IceRayCpp.GeometryBlobbySphere()
sphere2 = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(0,0,0) )
sphere3 = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.5, 1 )

sphere1.radius( 0.666 )
sphere1.influence( 5 )

print_blobby_sphere( sphere1 )