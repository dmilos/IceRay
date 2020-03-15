import IceRayCpp


import IceRayCpp

def name(  ):
    return "quadratic"

def make( value =  IceRayCpp.GraphTypeColorRGB().fill( 0.9 ) ):
    m = IceRayCpp.MaterialMediumQuadratic( value )
    return { 'this': m }


make(  )