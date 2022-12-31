import sys

def toSomething( index ):
    return '0123456789ABCDEFGHIJKLMNOPQRSTUVXYZ'[index%35]

def boja( index ):
    if( 1 == index % 7 ):
        return '#ff0000'
    if( 2 == index % 7 ):
        return '#00ff00'
    if( 3 == index % 7 ):
        return '#0000ff'
    if( 4 == index % 7 ):
        return '#00ffff'
    if( 5 == index % 7 ):
        return '#ff00ff'
    if( 6 == index % 7 ):
        return '#ffff00'
    return '#000000'


for y in range(0,60 - 2 ):
    for x in range(0,20):
        print("<rect ", end='' )
        print( "x=\"" + str(2*x*5+ 5* (y%2)) + "\" " + "y=\"" + str( y*5  ) + "\" ", end='' )
        print( "width=\"" + str( 5) + "\" " + "height=\"" + str( 5) + "\" ", end='' )
        print( "style=\"fill:" + boja( x + y ) +";stroke-width:0;\" ", end='' )
        print("/>" )
        print("<text ", end='' )
        print( "x=\"" + str(2*x*5+ 5* (y%2)) + "\" " + "y=\"" + str( y*5 + 5 - ( 5-3.953125) ) + "\" ", end='' )
        print( "style=\"font-size:3.5px;fill:#ffffff;stroke-width:0\" ", end='' )
        print(">", end=''  )
        print( toSomething(x), end='' )
        print( toSomething(y), end='' )
        print("</text>" )
    print("<!-- -->")


