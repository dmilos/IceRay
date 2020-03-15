import math
import IceRayCpp

def name( ):
    return "hyperboloid"

def cone( P_core = 0 ):
    geometry = IceRayCpp.GeometrySimpleHyperboloid( P_core )
    return{ 'this' : geometry }

def cylinder( P_core = 1 ):
    geometry = IceRayCpp.GeometrySimpleHyperboloid( P_core )
    return{ 'this' : geometry }

def sphere( P_core = math.sqrt(2) ):
    geometry = IceRayCpp.GeometrySimpleHyperboloid( P_core )
    return{ 'this' : geometry }

def negative( P_core = -0.5 ): # double side
    geometry = IceRayCpp.GeometrySimpleHyperboloid( P_core )
    return{ 'this' : geometry }

def nuke( P_core = 0.5 ): # single side.
    geometry = IceRayCpp.GeometrySimpleHyperboloid( P_core )
    return{ 'this' : geometry }

