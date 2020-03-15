import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

print( '********************' )

color = IceRayCpp.MathTypeCoord4D()

color[0] = 1000;
color[1] = 1000;
color[2] = 1000;
print(  '*****'  )
print(  color[0] )
print(  color[1] )
print(  color[2] )
print(  color[3] )


coord1 = IceRayCpp.MathTypeCoord4D().load(123,123,123,123)
coord2 = IceRayCpp.MathTypeCoord4D().load(123,123,123,123)
coord3 = IceRayCpp.MathTypeCoord4D().load(123,123,123,123)

coord1[0] = 0.5
coord2[0] = 0.1

print( '************ coord3 = coord1 + coord2' )
coord3 = coord1 + coord2
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )
print( coord3[3] )

print( '************ coord3 = coord1 - coord2' )
coord3 = coord1 - coord2
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )
print( coord3[3] )

print( '************ coord2 = 0.1 * coord2' )
coord2 = 0.1 * coord2
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )
print( coord3[3] )

print( '************ coord3 = coord2 * 0.1' )
coord3 = coord2 * 0.1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )
print( coord3[3] )

print( '************ coord3 = coord2 / 0.1' )
coord3 = coord2 / 0.1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )
print( coord3[3] )

print( '************ coord3 /= 0.1' )
coord3 /= 0.1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )
print( coord3[3] )
print( '************ coord3 *= 0.1' )
coord3 *= 0.1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )
print( coord3[3] )

print( '************ coord3 += coord1' )
coord3 += coord1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )
print( coord3[3] )

print( '************ coord3 -= coord1' )
coord3 -= coord1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )
print( coord3[3] )
