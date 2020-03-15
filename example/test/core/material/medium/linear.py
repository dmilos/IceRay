import IceRayCpp


import IceRayCpp

def name(  ):
    return "quadric"

def make( value =  IceRayCpp.GraphTypeColorRGB().fill( 0.9 ) ):
    m = IceRayCpp.MaterialMediumLinear( value , 0.1 , 0.1 )
    return { 'this': m }


make(  )