import IceRayCpp
import IceRayPy

def make( P_center, P_radius ): # P_center, P_radius
    sphere = IceRayCpp.GeometrySimpleSphere( P_center, P_radius )
    return{ 'this' : sphere }

