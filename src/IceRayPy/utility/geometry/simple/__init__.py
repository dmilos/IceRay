print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import IceRayPy.utility.geometry.simple.hyperboloid

class Torus:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
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
        self.m_cargo['minor-original'] = P_minor
        self.m_cargo['minor-scale'] = self.m_cargo['minor-original'] / self.m_cargo['mayor']
        self.m_cargo['torus'].minor( self.m_cargo['minor-scale'] )
        return

    def mayor( self, P_mayor ):
        self.m_cargo['mayor'] = P_mayor
        return this.minor( self.m_cargo['minor-original'] );

    def center( self, P_center ):
        self.m_cargo['center'] = P_center
        return self._recalc( )

    def normal( self, P_normal ):
        I_len = IceRayPy.type.math.coord.length3D( self.m_cargo['dll'], P_normal )
        self.m_cargo['normal'] = IceRayPy.type.math.coord.scale3D( self.m_cargo['dll'], 1.0/I_len, P_normal )
        return self._recalc( )

    def _recalc( self ):
        I_scale   = IceRayPy.type.math.affine.scaleS( self.m_cargo['dll'], self.m_cargo['mayor'] )
        I_decline = IceRayPy.type.math.affine.system3D_Z( self.m_cargo['dll'], self.m_cargo['center'], self.m_cargo['normal'] )

        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_decline, I_scale )
        self.m_cargo['affine'].toWorldSet( I_result )
        return True

class Cylinder:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        self.m_cargo['cylinder']  =  IceRayPy.core.geometry.simple.UCylinder( self.m_cargo['dll'] )
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
        self.m_cargo['affine'].toWorldSet( I_result )
        return True

class Cone:  #( IceRayPy.core.geometry.Generic ):
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
        self.m_cargo['affine'].toWorldSet( I_result )
        return True


class Paraboloid:  #( IceRayPy.core.geometry.Generic ):
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
        self.m_cargo['affine'].toWorldSet( I_result )
        return True



class Hyperboloid:  #( IceRayPy.core.geometry.Generic ): # TODO have bug !!!
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
        self.m_cargo['affine'].toWorldSet( I_result )
        return True


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )