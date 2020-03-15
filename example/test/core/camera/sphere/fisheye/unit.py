import math
import IceRayCpp

def name( ):
    return "sphere-fisheye"

def make( P_horisontal  = math.sin( math.radians(90) ), P_vertical = math.sin( math.radians(90) ) ):
    camera = IceRayCpp.CameraSphereFisheye( P_horisontal, P_vertical )
    #todo camera.phi( phi_view )
    #todo camera.theta( theta )
    return { 'this': camera }
