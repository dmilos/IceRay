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

def print_chandelier( P_chandelier ):
    print( P_chandelier.size( ) )

chandelier1 = IceRayCpp.LightChandelier()

print_chandelier( chandelier1 )

line1 = IceRayCpp.LightLine()
chandelier1.add( line1 )

print_chandelier( chandelier1 )