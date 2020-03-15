import IceRayCpp

def name( ):
    return "cone"

def make( ):

    geometry = IceRayCpp.GeometrySimpleCone()

    return { 'this': geometry }
