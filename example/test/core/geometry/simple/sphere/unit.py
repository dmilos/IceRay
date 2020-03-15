import math
import IceRayCpp

def name( ):
    return "sphere"

def make( P_center = IceRayCpp.MathTypeCoord3D().load(0,0,0), 
          P_radius = 0.75 #(math.sqrt(5)-1)/2
         ): # P_center, P_radius
    I_center = P_center
    I_radius = P_radius
    sphere = IceRayCpp.GeometrySimpleSphere( I_center.load(0,0,0), I_radius )
    return{ 'this' : sphere }
