import IceRayCpp

def name( ):
    return "usphere"

def make( ):
    usphere = IceRayCpp.GeometrySimpleUSphere()
    return { 'this': usphere }