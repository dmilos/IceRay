import IceRayCpp


import IceRayCpp

def name(  ):
    return "constant"

def make( value =  IceRayCpp.GraphTypeColorRGB().fill( 0.9 ) ):
    m = IceRayCpp.MaterialMediumConstant( value )
    return { 'this': m }


make(  )