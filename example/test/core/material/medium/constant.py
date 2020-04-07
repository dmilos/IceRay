import IceRayCpp


import IceRayCpp

def name(  ):
    return "constant"

def make( value = IceRayCpp.GraphTypeColorRGB().fill( 0.9 ), deplete = IceRayCpp.GraphTypeColorRGB().fill( 0.5 ) ):
    m = IceRayCpp.MaterialMediumConstant( value, deplete )
    return { 'this': m }
