import IceRayCpp

def name( ):
    return "ucylinder"

def make( ):
    usphere = IceRayCpp.GeometrySimpleUCylinder()
    return { 'this': usphere }