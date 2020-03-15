import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

print( '********************' )

color = IceRayCpp.MathTypeCoord3D()

color[0] = 1000;
color[1] = 1000;
color[2] = 1000;
print( '*****' )
print( color[0] )
print( color[1] )
print( color[2] )


coord1 = IceRayCpp.MathTypeCoord3D()
coord2 = IceRayCpp.MathTypeCoord3D()
coord3 = IceRayCpp.MathTypeCoord3D()

coord1[0] = 0.5
coord2[0] = 0.1

print( '************ coord3 = coord1 + coord2' )
coord3 = coord1 + coord2
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )

print( '************ coord3 = coord1 - coord2' )
coord3 = coord1 - coord2
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )


print( '************ coord2 = 0.1 * coord2' )
coord2 = 0.1 * coord2
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )

print( '************ coord3 = coord2 * 0.1' )
coord3 = coord2 * 0.1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )


print( '************ coord3 = coord2 / 0.1' )
coord3 = coord2 / 0.1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )

print( '************ coord3 /= 0.1' )
coord3 /= 0.1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )

print( '************ coord3 *= 0.1' )
coord3 *= 0.1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )

print( '************ coord3 += coord1' )
coord3 += coord1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )

print( '************ coord3 -= coord1' )
coord3 -= coord1
print( coord3[0] )
print( coord3[1] )
print( coord3[2] )

