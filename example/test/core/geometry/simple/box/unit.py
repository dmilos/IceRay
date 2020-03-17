import math
import IceRayCpp

def name( ):
    return "box"

def make(
    #P_len = (math.sqrt(5)-1)/2 
    P_len = 1
    ): # P_lo, P_hi
    lo = IceRayCpp.MathTypeCoord3D()
    lo[0] = -P_len
    lo[1] = -P_len
    lo[2] = -P_len

    hi = IceRayCpp.MathTypeCoord3D()
    hi[0] = P_len
    hi[1] = P_len
    hi[2] = P_len

    box3 = IceRayCpp.GeometrySimpleBox( lo, hi )

    return { 'this': box3 }
