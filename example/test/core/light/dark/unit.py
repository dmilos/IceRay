import IceRayCpp

def name( ):
    return "dark"

def make(  ):

    light = IceRayCpp.LightDark()

    return { 'this': light }
