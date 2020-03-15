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

def print_blobby_UCylinderZ( P_ucz ):
    #print_string( "Interval: " )
    #print_interval( P_ucz.interval() )
    print_string( str( P_ucz.radius() ) )
    print_string( "; " )

    print

print( '********************' )


usylinderz1 = IceRayCpp.GeometryBlobbyUCylinderZ()
usylinderz1.radius( 0.666 )

print_blobby_UCylinderZ( usylinderz1 )