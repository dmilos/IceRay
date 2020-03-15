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

def print_blobby_system( P_uspehre ):
    #print_string( "Interval: " )
    #print_interval( P_uspehre.interval() )
    print_string( "; " )

    print()

print( '********************' )


system1 = IceRayCpp.GeometryBlobbySystem()
sphere1 = IceRayCpp.GeometryBlobbySphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 0.5, 1 )

print_blobby_system( system1 )
# TODO system1.add( sphere1 )
