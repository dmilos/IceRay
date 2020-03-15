import math
import IceRayCpp

def name( ):
    return "cylinder-vertical"

def make( height = 2, phi = math.radians(120) ):
    camera = IceRayCpp.CameraCylinderVertical(  )
    camera.height( height )
    camera.phi( phi )
    return { 'this': camera }
