import math
import IceRayCpp

def name( ):
    return "sphere-vertical"

def make( horizont_view = math.radians(180), vertical_view = math.radians(120) ):
    camera = IceRayCpp.CameraSpherePackage( horizont_view, vertical_view )
    #todo camera.phi( phi_view )
    #todo camera.theta( theta )
    return { 'this': camera }
