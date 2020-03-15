import IceRayCpp

def name( ):
    return "plane"

def make( ): # P_center, P_radius
    point = IceRayCpp.MathTypeCoord3D().load(0,0,0.0001)
    normal = IceRayCpp.MathTypeCoord3D().load(0,0,1)
    plane = IceRayCpp.GeometrySimplePlane( point, normal )
    return{ 'this' : plane }
