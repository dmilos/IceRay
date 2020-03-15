import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

print( '********************' )

color = IceRayCpp.MathTypeCell3D()

color[0] = 1000;
color[1] = 1000;
color[2] = 1000;
print( '*****' )
print( color[0] )
print( color[1] )
print( color[2] )


Cell1 = IceRayCpp.MathTypeCell3D().load(123,123,123)
Cell2 = IceRayCpp.MathTypeCell3D().load(123,123,123)
Cell3 = IceRayCpp.MathTypeCell3D().load(123,123,123)

Cell1[0] = 0.5
Cell2[0] = 0.1

print( '************ Cell3 = Cell1 + Cell2' )
Cell3 = Cell1 + Cell2
print( Cell3[0] )
print( Cell3[1] )
print( Cell3[2] )

print( '************ Cell3 = Cell1 - Cell2' )
Cell3 = Cell1 - Cell2
print( Cell3[0] )
print( Cell3[1] )
print( Cell3[2] )


print( '************ Cell2 = 0.1 * Cell2' )
Cell2 = 0.1 * Cell2
print( Cell3[0] )
print( Cell3[1] )
print( Cell3[2] )

print( '************ Cell3 = Cell2 * 0.1' )
Cell3 = Cell2 * 0.1
print( Cell3[0] )
print( Cell3[1] )
print( Cell3[2] )


print( '************ Cell3 = Cell2 / 0.1' )
Cell3 = Cell2 / 2
print( Cell3[0] )
print( Cell3[1] )
print( Cell3[2] )

print( '************ Cell3 /= 0.1' )
Cell3 /= 3
print( Cell3[0] )
print( Cell3[1] )
print( Cell3[2] )

print( '************ Cell3 *= 0.1' )
Cell3 *= 10
print( Cell3[0] )
print( Cell3[1] )
print( Cell3[2] )

print( '************ Cell3 += Cell1' )
Cell3 += Cell1
print( Cell3[0] )
print( Cell3[1] )
print( Cell3[2] )

print( '************ Cell3 -= Cell1' )
Cell3 -= Cell1
print( Cell3[0] )
print( Cell3[1] )
print( Cell3[2] )

