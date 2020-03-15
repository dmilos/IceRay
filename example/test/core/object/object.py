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

def print_sphere(P_sphere):
    print_string( "Interval: " )
    print_interval( P_sphere.interval() )
    print_string( "; " )
    print_string( "radius:" + str( P_sphere.radius() ) )
    print_string( "; " )
    print_string( "center:" )
    print_coord( P_sphere.center() )
    print

print( '********************' )

sphere3 = IceRayCpp.GeometrySimpleSphere( IceRayCpp.MathTypeCoord3D().load(0,0,0), 1 )

object = IceRayCpp.CoreObject()

object.geometry( sphere3 )

surface = IceRayCpp.MaterialSurface()

surface.append( IceRayCpp.MaterialIlluminationAmbient( 0, 0 ) )
surface.append( IceRayCpp.MaterialIlluminationAmbient( 0, 0 ) )

object.surface( surface )

object.medium( IceRayCpp.MaterialMediuamConstant() )



