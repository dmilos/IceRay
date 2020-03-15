import math
import IceRayCpp

def name( ):
    return "sphere-vertical"

def make( phi_view = math.radians(180), theta = math.radians(120) ):
    camera = IceRayCpp.CameraSpherePolarVertical()
    #todo camera.phi( phi_view )
    #todo camera.theta( theta )
    return { 'this': camera }
