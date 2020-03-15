#!/usr/bin/python

import IceRayCpp

class Sphere:
    M_native= None

    def __init__( self,  P_center = None , P_radius = None  ):
        if None == P_center:
            self.M_native = IceRayCpp.GeometryBlobbySphere()
            return

        if None == P_radius:
            self.M_native = IceRayCpp.GeometryBlobbySphere(P_center)
            return

        self.M_native = IceRayCpp.GeometryBlobbySphere(P_center)

    def __del( self ):
        self.M_native = None
        

