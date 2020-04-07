import IceRayCpp


import IceRayCpp

def name(  ):
    return "quadratic"

def make( value =  IceRayCpp.GraphTypeColorRGB().fill( 0.9 ) ):
    m = IceRayCpp.MaterialMediumQuadratic( value, 0.1, 0.1, 0.1 )
    return { 'this': m }


make(  )