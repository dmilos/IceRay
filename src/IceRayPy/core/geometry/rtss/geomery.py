#!/usr/bin/python

import IceRayCpp

class Geometry:
    M_native = None
    M_rtss = None
    M_child = []

    def __init__( self, P_rtss = None , P_radius = None  ):
        self.M_native = IceRayCpp.GeometryRTSSGeometry()
        if( None != P_rtss ):
            self.M_native.rtss( P_rtss.get_native() )
        self.M_rtss = P_rtss

    def __del__(self):
        self.M_native = None
        self.M_rtss = None
        self.M_child = []

    def push( P_geometry ):
        self.M_native.push( P_geometry.get_native() )
        M_child += [ P_geometry ]



