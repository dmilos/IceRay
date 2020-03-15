import IceRayCpp

def name( ):
    return "saddle"

def make( ):
    geometry = IceRayCpp.GeometrySimpleSaddle()
    return{ 'this' : geometry }

