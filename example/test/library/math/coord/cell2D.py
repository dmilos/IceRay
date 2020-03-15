import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

print( '********************' )

cell = IceRayCpp.MathTypeCell2D()

cell[0] = 1000;
cell[1] = 1000;
print( '*****' )
print( cell[0] )
print( cell[1] )



coord1 = IceRayCpp.MathTypeCell2D()
coord2 = IceRayCpp.MathTypeCell2D()
coord3 = IceRayCpp.MathTypeCell2D()

coord1[0] = 0.5
coord2[0] = 0.1

print( '************ coord3 = coord1 + coord2' )
coord3 = coord1 + coord2
print( coord3[0] )
print( coord3[1] )


print( '************ coord3 = coord1 - coord2' )
coord3 = coord1 - coord2
print( coord3[0] )
print( coord3[1] )


print( '************ coord2 = 0.1 * coord2' )
coord2 = 0.1 * coord2
print( coord3[0] )
print( coord3[1] )

print( '************ coord3 = coord2 * 0.1' )
coord3 = coord2 * 0.1
print( coord3[0] )
print( coord3[1] )

print( '************ coord3 = coord2 / 0.1'
coord3 = coord2 / 0.1
print( coord3[0]
print( coord3[1]


print( '************ coord3 /= 0.1' )
coord3 /= 0.1
print( coord3[0] )
print( coord3[1] )


print( '************ coord3 *= 0.1' )
coord3 *= 0.1
print( coord3[0] )
print( coord3[1] )


print( '************ coord3 += coord1' )
coord3 += coord1
print( coord3[0] )
print( coord3[1] )


print( '************ coord3 -= coord1' )
coord3 -= coord1
print( coord3[0] )
print( coord3[1] )


