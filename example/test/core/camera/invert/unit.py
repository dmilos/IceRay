import math
import IceRayCpp

def name( ):
    return "invert-cylinder"

def cylinder( P_phi = math.radians(360), P_height = 2, P_radius = 1.5 ):

    cylinder = IceRayCpp.CameraCylinderVertical( P_phi , P_height , P_radius)
    cylinder.height( P_height )
    cylinder.phi( P_phi )
    cylinder.radius( P_radius )
    invert = IceRayCpp.CameraTransformInvert()
    invert.child( cylinder )

    return { 'this': invert, 'cylinder': cylinder }
    #return { 'this': cylinder }
