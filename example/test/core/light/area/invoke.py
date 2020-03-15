import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

def print_string( P_string ):
    sys.stdout.write( P_string )

    
def print_coord(P_coord):
    sys.stdout.write( '(' + str( P_coord[0] ) + ', ' + str( P_coord[1] ) + ', ' +  str( P_coord[2] ) + ')' )

def print_color(P_color):
    sys.stdout.write( '(' + str( P_color[0] ) + ', ' + str( P_color[1] ) + ', ' +  str( P_color[2] ) + ')' )

def print_interval(P_interval):
    sys.stdout.write('( ')
    print_coord( P_interval.lo() )
    print_coord( P_interval.hi() )
    sys.stdout.write(' )')

def print_light_spot(P_spot):
    print_coord( P_spot.center() )
    print_color( P_spot._0() )
    print_color( P_spot._1() )
    print_color( P_spot._2() )

def print_area( P_area ):
    print( area3.sample() )
    print_light_spot( area1.spot() )
    print_coord( area1.x() )
    print_coord( area1.y() )
    print( area1.sample() )

area1 = IceRayCpp.LightArea()
area2 = IceRayCpp.LightArea(IceRayCpp.LightTypeSpot(), IceRayCpp.MathTypeCoord3D().load(0,2,0), IceRayCpp.MathTypeCoord3D().load(0,2,0) )
area3 = IceRayCpp.LightArea(IceRayCpp.LightTypeSpot(), IceRayCpp.MathTypeCoord3D().load(0,2,0), IceRayCpp.MathTypeCoord3D().load(0,2,0), 20 )

print( area3.sample() )
area3.sample( 100 )
print( area3.sample() )

print_light_spot( area1.spot() )
area1.spot( IceRayCpp.LightTypeSpot() )
print_light_spot( area1.spot() )

print_coord( area1.x() )
area1.x( IceRayCpp.MathTypeCoord3D().load(0,2,0) )
print_coord( area1.x() )
print()

print_coord( area1.y() )
area1.y( IceRayCpp.MathTypeCoord3D().load(0,2,0) )
print_coord( area1.y() )
print()

print( area1.sample() )
area1.sample( 100 )
print( area1.sample() )

print_area( area1 )
