import sys
import os
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print('********************' )

print('********************' )

def print_coord(P_cord):
    sys.stdout.write( '(' + str( P_cord[0] ) + ', ' + str( P_cord[1] ) + ', ' +  str( P_cord[2] ) + ')' )

def print_matrix(P_matrix):
    sys.stdout.write( '( ' )
    sys.stdout.write( '  ( ' + str( P_matrix.element( 0, 0 ) ) + ', ' + str( P_matrix.element( 0, 1 ) ) + ', ' +  str( P_matrix.element( 0, 2 ) ) + ' ), \n' )
    sys.stdout.write( '  ( ' + str( P_matrix.element( 1, 0 ) ) + ', ' + str( P_matrix.element( 1, 1 ) ) + ', ' +  str( P_matrix.element( 1, 2 ) ) + ' ), \n' )
    sys.stdout.write( '  ( ' + str( P_matrix.element( 2, 0 ) ) + ', ' + str( P_matrix.element( 2, 1 ) ) + ', ' +  str( P_matrix.element( 2, 2 ) ) + ' )\n' )
    sys.stdout.write( ' )' )

def print_affine(P_affine):
    sys.stdout.write( '(\n  ' )
    print_coord(P_affine.coord())
    print
    print_matrix(P_affine.matrix())
    sys.stdout.write( ') ' )

affine1 = IceRayCpp.MathTypeAffine3D()

affine1.coord( )
affine1.coord( IceRayCpp.MathTypeCoord3D().load(10,10,10) )

print_coord( affine1.coord( ) )

affine1.matrix( IceRayCpp.MathTypeMatrix3D( ) )

print_affine(affine1)

affine1.row( 0, IceRayCpp.MathTypeCoord3D().load( 1, 2, 3 ) );  print; print_coord( affine1.row(0) )
affine1.row( 1, IceRayCpp.MathTypeCoord3D().load( 4, 5, 6 ) );  print; print_coord( affine1.row(1) )
affine1.row( 2, IceRayCpp.MathTypeCoord3D().load( 7, 8, 9 ) );  print; print_coord( affine1.row(2) )

print
affine1.column( 0, IceRayCpp.MathTypeCoord3D().load( 1, 2, 3 )  ); print_coord( affine1.column(0) ); 
affine1.column( 1, IceRayCpp.MathTypeCoord3D().load( 4, 5, 6 )  ); print_coord( affine1.column(1) ); 
affine1.column( 2, IceRayCpp.MathTypeCoord3D().load( 7, 8, 9 )  ); print_coord( affine1.column(2) ); 

print
print_affine(affine1)

print
print( '********************')
affine1.load( IceRayCpp.MathTypeCoord3D().load( 1, 2, 3 ), IceRayCpp.MathTypeCoord3D().load( 4, 5, 6 ), IceRayCpp.MathTypeCoord3D().load( 7, 8, -9 ), IceRayCpp.MathTypeCoord3D().load( 11, 12, -13 ) )
print
print( '********************')
print_affine(affine1)
print( '********************')
affine2 = IceRayCpp.MathTypeAffine3D()
print( '********************')
print_affine(affine2)
print( '********************')

x1 = IceRayCpp.MathTypeCoord3D(); x1 .load( 1, -1, 1 )
x2 = IceRayCpp.MathTypeCoord3D(); x2 .load( 0,  0, 0 )
x3 = IceRayCpp.MathTypeCoord3D(); x3 .load( 0,  0, 1 )

print( '******** AAAAAAAAA ********'  )
affine2 = IceRayCpp.MathAffine3D_lookAt( x1, x2, x3 )

print( '********************' )

print_affine(affine2)