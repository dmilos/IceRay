#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import math
import IceRayPy
import IceRayPy.utility.geometry.simple.hyperboloid

class Torus:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll, P_config = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        I_minor = 0.2

        self.m_cargo['torus']  =  IceRayPy.core.geometry.simple.Torus( self.m_cargo['dll'], I_minor )
        self.m_cargo['affine'] = IceRayPy.core.geometry.transform.Affine( self.m_cargo['dll'] )
        self.m_cargo['this'] = self.m_cargo['affine'].m_cargo['this']

        self.m_cargo['affine'].child( self.m_cargo['torus'] )

        self.m_cargo['center'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
        self.m_cargo['mayor']  = 1
        self.m_cargo['minor-original'] = I_minor
        self.m_cargo['minor-scale'] = I_minor

        self.m_cargo['normal'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
        self._recalc()

        self.center( IceRayPy.type.math.coord.Scalar3D( 0, 0, I_minor - 1 ) ) #< debug
        self.normal( IceRayPy.type.math.coord.Scalar3D( 0.5, 0.5, 0.5 ) ) #< debug

    def __del__( self ):
        self.m_cargo = {}

    def minor( self, P_minor ):
        if( None != P_minor ):
            self.m_cargo['minor-original'] = P_minor
            self.m_cargo['minor-scale'] = self.m_cargo['minor-original'] / self.m_cargo['mayor']
            self.m_cargo['torus'].minor( self.m_cargo['minor-scale'] )

        return self.m_cargo['minor-original']

    def mayor( self, P_mayor ):
        if( None != P_mayor ):
            self.m_cargo['mayor'] = P_mayor 
            self.minor( self.m_cargo['minor-original'] )
        return self.m_cargo['mayor'];

    def center( self, P_center = None ):
        if( None != P_center ):
            self.m_cargo['center'] = P_center
            self._recalc( )
        return self.m_cargo['center']

    def normal( self, P_normal ):
        I_len = IceRayPy.type.math.coord.length3D( self.m_cargo['dll'], P_normal )
        self.m_cargo['normal'] = IceRayPy.type.math.coord.scale3D( self.m_cargo['dll'], 1.0/I_len, P_normal )
        return self._recalc( )

    def _recalc( self ):
        I_scale   = IceRayPy.type.math.affine.scaleS( self.m_cargo['dll'], self.m_cargo['mayor'] )
        I_decline = IceRayPy.type.math.affine.system3D_Z( self.m_cargo['dll'], self.m_cargo['center'], self.m_cargo['normal'] )

        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_decline, I_scale )
        self.m_cargo['affine'].toWorld( I_result )
        return True


class CylinderG:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll, P_config = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        self.m_cargo['cylinder']  =  IceRayPy.core.geometry.simple.CylinderU( self.m_cargo['dll'] )
        self.m_cargo['affine'] = IceRayPy.core.geometry.transform.Affine( self.m_cargo['dll'] )
        self.m_cargo['this'] = self.m_cargo['affine'].m_cargo['this']

        self.m_cargo['affine'].child( self.m_cargo['cylinder'] )

        self.m_cargo['bottom'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
        self.m_cargo['top'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
        self.m_cargo['radius']  = 1
        self.m_cargo['direction'] = IceRayPy.type.math.coord.subtraction3D( self.m_cargo['dll'], self.m_cargo['top'], self.m_cargo['bottom'] )

        self._recalc()

        #self.bottom( IceRayPy.type.math.coord.Scalar3D( -1.0, -1.0, -1.0 ) )#!< debug
        #self.top(    IceRayPy.type.math.coord.Scalar3D( +0.0, +0.0, +0.0 ) )#!< debug
        self.bottom( IceRayPy.type.math.coord.Scalar3D( -0.5, +0.5, 0.0 ) )#!< debug
        self.top(    IceRayPy.type.math.coord.Scalar3D( +0.5, -0.5, 0.0 ) )#!< debug
        self.radius( 0.33 )#!< debug

        if( None != P_config ):
            if( 'top' in P_config ):
                self.top( P_config['top'] )
            if( 'bottom' in P_config ):
                self.bottom( P_config['bottom'] )
            if( 'radius' in P_config ):
                self.radius( P_config['radius'] )

        return

    def top( self, P_top = None ):
        if( None != P_top ):
            self.m_cargo['top'] = P_top
            self._recalc()
        return self.m_cargo['top']

    def bottom( self, P_bottom = None ):
        if( None != P_bottom ):
            self.m_cargo['bottom'] = P_bottom
            self._recalc()
        return self.m_cargo['bottom']

    def radius( self, P_radius = None  ):
        if( None != P_radius ):
            self.m_cargo['radius'] = P_radius
            self._recalc()
        return self.m_cargo['radius']

    def _recalc( self ):
        self.m_cargo['direction'] = IceRayPy.type.math.coord.subtraction3D( self.m_cargo['dll'], self.m_cargo['top'], self.m_cargo['bottom'] )
        I_height = IceRayPy.type.math.coord.distance3D(   self.m_cargo['dll'], self.m_cargo['bottom'], self.m_cargo['top'] )
        self.m_cargo['direction'] = IceRayPy.type.math.coord.scale3D( self.m_cargo['dll'], 1.0/I_height, self.m_cargo['direction'] )

        I_decline = IceRayPy.type.math.affine.system3D_Z( self.m_cargo['dll'], self.m_cargo['bottom'], self.m_cargo['direction'] )
        I_scale   = IceRayPy.type.math.affine.scaleV(     self.m_cargo['dll'], IceRayPy.type.math.coord.Scalar3D( self.m_cargo['radius'], self.m_cargo['radius'], I_height ) )

        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_decline, I_scale )
        self.m_cargo['affine'].toWorld( I_result )
        return True


class ConeG:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        self.m_cargo['cone']  =  IceRayPy.core.geometry.simple.Cone( self.m_cargo['dll'] )
        self.m_cargo['affine'] = IceRayPy.core.geometry.transform.Affine( self.m_cargo['dll'] )
        self.m_cargo['this'] = self.m_cargo['affine'].m_cargo['this']

        self.m_cargo['affine'].child( self.m_cargo['cone'] )

        self.m_cargo['bottom'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
        self.m_cargo['top'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
        self.m_cargo['radius']  = 1
        self.m_cargo['direction'] = IceRayPy.type.math.coord.subtraction3D( self.m_cargo['dll'], self.m_cargo['top'], self.m_cargo['bottom'] )

        self._recalc()

        #self.bottom( IceRayPy.type.math.coord.Scalar3D( -1.0, -1.0, -1.0 ) )#!< debug
        #self.top(    IceRayPy.type.math.coord.Scalar3D( +0.0, +0.0, +0.0 ) )#!< debug
        self.bottom( IceRayPy.type.math.coord.Scalar3D( -0.5, -0.5, -1.0 ) )#!< debug
        self.top(    IceRayPy.type.math.coord.Scalar3D( +0.5, +0.5, +1.0 ) )#!< debug
        self.radius(  0.1 )#!< debug

        return


    def top( self, P_top ):
        self.m_cargo['top'] = P_top
        return self._recalc()

    def bottom( self, P_bottom ):
        self.m_cargo['bottom'] = P_bottom
        return self._recalc()

    def radius( self, P_radius ):
        self.m_cargo['radius'] = P_radius
        return self._recalc()

    def _recalc( self ):
        self.m_cargo['direction'] = IceRayPy.type.math.coord.subtraction3D( self.m_cargo['dll'], self.m_cargo['top'], self.m_cargo['bottom'] )
        I_height = IceRayPy.type.math.coord.distance3D(   self.m_cargo['dll'], self.m_cargo['bottom'], self.m_cargo['top'] )
        self.m_cargo['direction'] = IceRayPy.type.math.coord.scale3D( self.m_cargo['dll'], 1.0/I_height, self.m_cargo['direction'] )

        I_decline = IceRayPy.type.math.affine.system3D_Z( self.m_cargo['dll'], self.m_cargo['bottom'], self.m_cargo['direction'] )
        I_scale   = IceRayPy.type.math.affine.scaleV(     self.m_cargo['dll'], IceRayPy.type.math.coord.Scalar3D( self.m_cargo['radius'], self.m_cargo['radius'], I_height ) )

        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_decline, I_scale )
        self.m_cargo['affine'].toWorld( I_result )
        return True


class ParaboloidG:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        self.m_cargo['paraboloid']  =  IceRayPy.core.geometry.simple.Paraboloid( self.m_cargo['dll'] )
        self.m_cargo['affine'] = IceRayPy.core.geometry.transform.Affine( self.m_cargo['dll'] )
        self.m_cargo['this'] = self.m_cargo['affine'].m_cargo['this']

        self.m_cargo['affine'].child( self.m_cargo['paraboloid'] )

        self.m_cargo['bottom'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
        self.m_cargo['top'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
        self.m_cargo['radius']  = 1
        self.m_cargo['direction'] = IceRayPy.type.math.coord.subtraction3D( self.m_cargo['dll'], self.m_cargo['top'], self.m_cargo['bottom'] )

        self._recalc()

        #self.bottom( IceRayPy.type.math.coord.Scalar3D( -1.0, -1.0, -1.0 ) )#!< debug
        #self.top(    IceRayPy.type.math.coord.Scalar3D( +0.0, +0.0, +0.0 ) )#!< debug
        self.bottom( IceRayPy.type.math.coord.Scalar3D( -0.5, -0.5, -1.0 ) )#!< debug
        self.top(    IceRayPy.type.math.coord.Scalar3D( +0.5, +0.5, +1.0 ) )#!< debug
        self.radius(  0.1 )#!< debug
        return


    def top( self, P_top ):
        self.m_cargo['top'] = P_top
        return self._recalc()

    def bottom( self, P_bottom ):
        self.m_cargo['bottom'] = P_bottom
        return self._recalc()

    def radius( self, P_radius ):
        self.m_cargo['radius'] = P_radius
        return self._recalc()

    def _recalc( self ):
        self.m_cargo['direction'] = IceRayPy.type.math.coord.subtraction3D( self.m_cargo['dll'], self.m_cargo['top'], self.m_cargo['bottom'] )
        I_height = IceRayPy.type.math.coord.distance3D(   self.m_cargo['dll'], self.m_cargo['bottom'], self.m_cargo['top'] )
        self.m_cargo['direction'] = IceRayPy.type.math.coord.scale3D( self.m_cargo['dll'], 1.0/I_height, self.m_cargo['direction'] )

        I_decline = IceRayPy.type.math.affine.system3D_Z( self.m_cargo['dll'], self.m_cargo['bottom'], self.m_cargo['direction'] )
        I_scale   = IceRayPy.type.math.affine.scaleV(     self.m_cargo['dll'], IceRayPy.type.math.coord.Scalar3D( self.m_cargo['radius'], self.m_cargo['radius'], I_height ) )

        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_decline, I_scale )
        self.m_cargo['affine'].toWorld( I_result )
        return True


class HyperboloidG:  #( IceRayPy.core.geometry.Generic ): # TODO have bug !!!
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        self.m_cargo['hyperboloid']  =  IceRayPy.core.geometry.simple.Hyperboloid( self.m_cargo['dll'] )
        self.m_cargo['affine'] = IceRayPy.core.geometry.transform.Affine( self.m_cargo['dll'] )
        self.m_cargo['this'] = self.m_cargo['affine'].m_cargo['this']

        self.m_cargo['affine'].child( self.m_cargo['hyperboloid'] )

        self.m_cargo['bottom'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
        self.m_cargo['top'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
        self.m_cargo['center'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0.5 )
        self.m_cargo['radius']  = 1
        self.m_cargo['direction'] = IceRayPy.type.math.coord.subtraction3D( self.m_cargo['dll'], self.m_cargo['top'], self.m_cargo['bottom'] )

        self._recalc()

        #self.bottom( IceRayPy.type.math.coord.Scalar3D( -1.0, -1.0, -1.0 ) )#!< debug
        #self.top(    IceRayPy.type.math.coord.Scalar3D( +0.0, +0.0, +0.0 ) )#!< debug
        self.bottom( IceRayPy.type.math.coord.Scalar3D( -0.5, -0.5, 0.0 ) )#!< debug
        self.top(    IceRayPy.type.math.coord.Scalar3D( +0.5, +0.5, 0.0 ) )#!< debug
        self.radius( 0.33 )#!< debug
        self.core(   1 )#!< debug
        return

    def core( self, P_core ):
        self.m_cargo['core'] = P_core
        self.m_cargo['hyperboloid'].core( self.m_cargo['core'] )
        return

    def top( self, P_top ):
        self.m_cargo['top'] = P_top
        return self._recalc()

    def bottom( self, P_bottom ):
        self.m_cargo['bottom'] = P_bottom
        return self._recalc()

    def radius( self, P_radius ):
        self.m_cargo['radius'] = P_radius
        return self._recalc()

    def _recalc( self ):
        self.m_cargo['center'] = IceRayPy.type.math.coord.subtraction3D( self.m_cargo['dll'], self.m_cargo['top'], self.m_cargo['bottom'] )
        self.m_cargo['center'] =  IceRayPy.type.math.coord.scale3D( self.m_cargo['dll'], 0.5, self.m_cargo['center'] )
        self.m_cargo['center'] =  IceRayPy.type.math.coord.addition3D( self.m_cargo['dll'], self.m_cargo['bottom'], self.m_cargo['center'] )

        self.m_cargo['direction'] = IceRayPy.type.math.coord.subtraction3D( self.m_cargo['dll'], self.m_cargo['top'], self.m_cargo['center'] )
        I_height = IceRayPy.type.math.coord.distance3D(   self.m_cargo['dll'], self.m_cargo['bottom'], self.m_cargo['center'] )
        self.m_cargo['direction'] = IceRayPy.type.math.coord.scale3D( self.m_cargo['dll'], 1.0/I_height, self.m_cargo['direction'] )

        I_decline = IceRayPy.type.math.affine.system3D_Z( self.m_cargo['dll'], self.m_cargo['center'], self.m_cargo['direction'] )
        I_scale   = IceRayPy.type.math.affine.scaleV(     self.m_cargo['dll'], IceRayPy.type.math.coord.Scalar3D( self.m_cargo['radius'], self.m_cargo['radius'], I_height ) )

        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_decline, I_scale )
        self.m_cargo['affine'].toWorld( I_result )
        return True


class Parallelepiped:
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        self.m_cargo['box']  =  IceRayPy.core.geometry.flat.Box( self.m_cargo['dll'] )
        self.m_cargo['box'].lo(  IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 ) )
        self.m_cargo['box'].hi(  IceRayPy.type.math.coord.Scalar3D( 1, 1, 1 ) )
        self.m_cargo['affine'] = IceRayPy.core.geometry.transform.Affine( self.m_cargo['dll'] )
        self.m_cargo['this'] = self.m_cargo['affine'].m_cargo['this']

        self.m_cargo['affine'].child( self.m_cargo['box'] )

        self.m_cargo['origin'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, -1 )

        self.m_cargo['X'] = IceRayPy.type.math.coord.Scalar3D( +1.0,  0.0,   math.sqrt( 0.5 ) )
        self.m_cargo['Y'] = IceRayPy.type.math.coord.Scalar3D( -0.5, +math.sqrt( 0.75 ), math.sqrt( 0.5 ) )
        self.m_cargo['Z'] = IceRayPy.type.math.coord.Scalar3D( -0.5, -math.sqrt( 0.75 ), math.sqrt( 0.5 ) )

        scale = 2 / math.sqrt(3.0) / math.sqrt(1.5);

        self.m_cargo['X'] = IceRayPy.type.math.coord.scale3D( self.m_cargo['dll'], scale, self.m_cargo['X'] )
        self.m_cargo['Y'] = IceRayPy.type.math.coord.scale3D( self.m_cargo['dll'], scale, self.m_cargo['Y'] )
        self.m_cargo['Z'] = IceRayPy.type.math.coord.scale3D( self.m_cargo['dll'], scale, self.m_cargo['Z'] )
        self._recalc()

        return

    def origin( self, P_origin ):
        self.m_cargo['origin'] = P_origin
        return self._recalc()

    def X( self, P_X ):
        self.m_cargo['X'] = P_X
        return self._recalc()

    def Y( self, P_Y ):
        self.m_cargo['Y'] = P_Y
        return self._recalc()

    def Z( self, P_Z ):
        self.m_cargo['Z'] = P_Z
        return self._recalc()

    def _recalc( self ):
        O = self.m_cargo['origin']
        X = self.m_cargo['X']
        Y = self.m_cargo['Y']
        Z = self.m_cargo['Z']

        I_affine = IceRayPy.type.math.affine.system3D( self.m_cargo['dll'], O, X, Y, Z )

        self.m_cargo['affine'].toWorld( I_affine )
        return True


class Cube:  #( IceRayPy.core.geometry.Generic ): # TODO have bug !!!
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        self.m_cargo['box']  =  IceRayPy.core.geometry.flat.Box( self.m_cargo['dll'] )

        self.center( IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 ) )
        self.size(   IceRayPy.type.math.coord.Scalar3D( 1, 1, 1 ) )

        return

    def center( self, P_center ):
        I_size = self.m_cargo['size']

        self.m_cargo['box'].lo( IceRayPy.type.math.coord.Scalar3D( P_center[0] - I_size[0], P_center[1] - I_size[1], P_center[2] - I_size[2] ) )
        self.m_cargo['box'].hi( IceRayPy.type.math.coord.Scalar3D( P_center[0] + I_size[0], P_center[1] + I_size[1], P_center[2] + I_size[2] ) )

        self.m_cargo['center'] = P_center
        return

    def size( self, P_size ):
        I_center = self.m_cargo['center']

        self.m_cargo['box'].lo( IceRayPy.type.math.coord.Scalar3D( I_center[0] - P_size[0], I_center[1] - P_size[1], I_center[2] - P_size[2] ) )
        self.m_cargo['box'].hi( IceRayPy.type.math.coord.Scalar3D( I_center[0] + P_size[0], I_center[1] + P_size[1], I_center[2] + P_size[2] ) )

        self.m_cargo['size'] = P_size
        return self._recalc()


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )