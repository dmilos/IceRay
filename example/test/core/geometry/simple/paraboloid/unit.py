import IceRayCpp

def name( ):
    return "paraboloid"

def make( ): # P_center, P_radius
    geometry = IceRayCpp.GeometrySimpleParaboloid()
    return{ 'this' : geometry }

