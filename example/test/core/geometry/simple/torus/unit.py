import IceRayCpp

def name( ):
    return "torus"

def make( ):
    torus = IceRayCpp.GeometrySimpleTorus()
    torus.minor( 0.2 )
    
    return { 'this': torus }