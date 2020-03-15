import IceRayCpp


import IceRayCpp

def name(  ):
    return "exponential"

def make( value =  IceRayCpp.GraphTypeColorRGB().fill( 0.9 ) ):
    m = IceRayCpp.MaterialMediumExponential( value, 3.5 )
    return { 'this': m }


make(  )