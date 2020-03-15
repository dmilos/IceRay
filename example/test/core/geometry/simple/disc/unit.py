import IceRayCpp

def name( ):
    return "disc"

def make( ): # P_lo, P_hi 
    geometry = IceRayCpp.GeometrySimpleDisc()

    return { 'this': geometry }
