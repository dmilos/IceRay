import sys
import IceRayCpp

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

def print_render_pierce_base(P_base):
    print( P_base )

camera1 = IceRayCpp.CameraFlatPerspective()
    
base1 = IceRayCpp.RenderPierceProjector()

base1.camera( camera1 )

print_render_pierce_base( base1 )


