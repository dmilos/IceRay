import sys
import os
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

print( '********************' )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_matrix(P_matrix):
    sys.stdout.write( '( ' )
    sys.stdout.write( '( ' + str( P_matrix.element( 0, 0 ) ) + ', ' + str( P_matrix.element( 0, 1 ) ) + ', ' +  str( P_matrix.element( 0, 2 ) ) + ' ), ' )
    sys.stdout.write( '( ' + str( P_matrix.element( 1, 0 ) ) + ', ' + str( P_matrix.element( 1, 1 ) ) + ', ' +  str( P_matrix.element( 1, 2 ) ) + ' ), ' )
    sys.stdout.write( '( ' + str( P_matrix.element( 2, 0 ) ) + ', ' + str( P_matrix.element( 2, 1 ) ) + ', ' +  str( P_matrix.element( 2, 2 ) ) + ' )' )
    sys.stdout.write( ' )' )
    
matrix1 = IceRayCpp.MathTypeMatrix3D( )

matrix1.element( 0, 0, 5 ); matrix1.element( 0, 1, 4 ); matrix1.element( 0, 2, 3 )
matrix1.element( 1, 0, 0 ); matrix1.element( 1, 1, 1 ); matrix1.element( 1, 2, 2 )
matrix1.element( 2, 0, 1 ); matrix1.element( 2, 1, 2 ); matrix1.element( 2, 2, 3 )

print
print_coord( matrix1.row( 0 ) )

print
matrix1.row( 0, IceRayCpp.MathTypeCoord3D().load( 1, 2, 3 ) );  print; print_coord( matrix1.row(0) )
matrix1.row( 1, IceRayCpp.MathTypeCoord3D().load( 4, 5, 6 ) );  print; print_coord( matrix1.row(1) )
matrix1.row( 2, IceRayCpp.MathTypeCoord3D().load( 7, 8, 9 ) );  print; print_coord( matrix1.row(2) )

print
matrix1.column( 0, IceRayCpp.MathTypeCoord3D().load( -1, -2, -3 ) ); print; print_coord( matrix1.row(0) ); print; print_coord( matrix1.row(1) ); print; print_coord( matrix1.row(2) ); 
matrix1.column( 1, IceRayCpp.MathTypeCoord3D().load( -4, -5, -6 ) ); print; print_coord( matrix1.row(0) ); print; print_coord( matrix1.row(1) ); print; print_coord( matrix1.row(2) ); 
matrix1.column( 2, IceRayCpp.MathTypeCoord3D().load( -7, -8, -9 ) ); print; print_coord( matrix1.row(0) ); print; print_coord( matrix1.row(1) ); print; print_coord( matrix1.row(2) ); 

print
print
print_matrix(matrix1)

x1 = IceRayCpp.MathTypeCoord3D()
x1 .load( 17, 18, -19 )
x2 = IceRayCpp.MathTypeCoord3D()
x2 .load( 14, 15, 16 )
x3 = IceRayCpp.MathTypeCoord3D()
x3 .load( 11, 12, 13 )

matrix1.load( x1, x2, x3 )

print
print_matrix(matrix1)
