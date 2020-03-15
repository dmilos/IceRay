import IceRayCpp

def name( ):
    return "vacuum"

def make( ):
    lo = IceRayCpp.MathTypeCoord3D()
    lo[0] = -1
    lo[1] = -1
    lo[2] = -1

    hi = IceRayCpp.MathTypeCoord3D()
    hi[0] = 1
    hi[1] = 1
    hi[2] = 1

    box3 = IceRayCpp.GeometryVolumetricVacuum( lo, hi )

    return { 'this': box3 }
