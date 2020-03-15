import math
import IceRayCpp

def name( ):
    return "ellipsoid"

def make( P_center = IceRayCpp.MathTypeCoord3D().load(0,0,0),
          P_radius = IceRayCpp.MathTypeCoord3D().load( 1, (math.sqrt(5)-1)/2, 1 - (math.sqrt(5)-1)/2 )
         ): # P_center, P_radius
    I_center = P_center
    I_radius = P_radius
    ellipsoid = IceRayCpp.GeometrySimpleEllipsoid( I_center, I_radius )
    ellipsoid.center( P_center )
    return{ 'this' : ellipsoid }
