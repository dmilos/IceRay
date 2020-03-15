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

def print_box( P_box ):
    print_string( "Interval: " )
    print_interval( P_box.interval() )
    print_string( "; " )
    
    print_string( "lo: " )
    print_coord( P_box.lo() )
    print_string( "ho: " )
    print_coord( P_box.hi() )
    
    print

print( '********************' )

lo = IceRayCpp.MathTypeCoord3D().load(123,123,123)
lo[0] = 1
lo[1] = 2
lo[2] = 4

hi = IceRayCpp.MathTypeCoord3D().load(123,123,123)
hi[0] = 1
hi[1] = 2
hi[2] = 4

box1 = IceRayCpp.GeometrySimpleBox()
box2 = IceRayCpp.GeometrySimpleBox( lo, hi )
box3 = IceRayCpp.GeometrySimpleBox( )

print( '------------' )
print_box( box1 )
print

print( '------------' )
print( box1.lo( lo ) )
print_box( box1 )
print

#print( '------------' )
#todo print( box1.lo( 1,2,3 ) )
#print_box( box1 )
#print


#print( '------------' )
# todo print( box1.hi( -1,-2,-3 ) )
#print_box( box1 )
#print

print( '------------' )
print( box1.load( lo, hi ) )
print_box( box1 )
print()



