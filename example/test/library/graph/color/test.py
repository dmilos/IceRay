import sys
import IceRayCpp

print( '********************' )
#print( IceRayCpp.__dict__ )
print( '********************' )

print( '********************' )

def print_color(P_color):
    sys.stdout.write( '(' + str( P_color[0] ) + ', ' + str( P_color[1] ) + ', ' +  str( P_color[2] ) + ')' )


color = IceRayCpp.GraphTypeColorRGB()
color2 = IceRayCpp.GraphTypeColorRGB().fill( 0.666 )

print_color( color2 )

color[0] = 1000;
color[1] = 1000;
color[2] = 1000;
print( '*****' )
print_color( color )

color1 = IceRayCpp.GraphTypeColorRGB()
color2 = IceRayCpp.GraphTypeColorRGB()
color3 = IceRayCpp.GraphTypeColorRGB()

color1[0] = 0.5
color2[0] = 0.1

print( '************ color3 = color1 + color2' )
color3 = color1 + color2
print_color( color3 )

print( '************ color3 = color1 - color2' )
color3 = color1 - color2
print_color( color3 )

print( '************ color2 = 0.1 * color2' )
color2 = 0.1 * color2
print_color( color2 )

print( '************ color3 = color2 * 0.1' )
color3 = color2 * 0.1
print_color( color3 )

print( '************ color3 = color2 / 0.1' )
color3 = color2 / 0.1
print_color( color3 )

print( '************ color3 /= 0.1' )
color3 /= 0.1
print_color( color3 )

print( '************ color3 *= 0.1' )
color3 *= 0.1
print_color( color3 )

print( '************ color3 += color1' )
color3 += color1
print_color( color3 )


print( '************ color3 -= color1' )
color3 -= color1
print_color( color3 )

print( '************ color2.load(1,2,3)' )
color2.load(1,2,3)

print_color( color2 )