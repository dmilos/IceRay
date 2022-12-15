print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy
import IceRayPy.utility.geometry.simple.hyperboloid

class Torus:  #( IceRayPy.core.geometry.Generic ):
    def __init__( self, P_dll ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        self.m_cargo['torus']  =  IceRayPy.core.geometry.simple.Torus( self.m_cargo['dll'], 0.1 )
        self.m_cargo['affine'] = IceRayPy.core.geometry.transform.Affine( self.m_cargo['dll'] )
        self.m_cargo['this'] = self.m_cargo['affine'].m_cargo['this']

        self.m_cargo['affine'].child( self.m_cargo['torus'] )

        self.m_cargo['center'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 0 )
        self.m_cargo['mayor']  = 1
        self.m_cargo['minor-original'] = 0.1
        self.m_cargo['minor-scale'] = 0.1

        self.m_cargo['normal'] = IceRayPy.type.math.coord.Scalar3D( 0, 0, 1 )
        self._recalc()

        self.center( IceRayPy.type.math.coord.Scalar3D( 0, 0, -0.9 ) ) #< debug

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
        self.m_cargo['normal'] = P_normal
        return self._recalc( )

    def _recalc( self ):
        I_move    = IceRayPy.type.math.affine.move3D( self.m_cargo['dll'], self.m_cargo['center'] )
        I_scale   = IceRayPy.type.math.affine.scaleS( self.m_cargo['dll'], self.m_cargo['mayor'] )
        I_decline = IceRayPy.type.math.affine.id3D( self.m_cargo['dll']) # IceRayPy.type.math.affine.decline( self.m_cargo['dll'], self.m_cargo['normal'] )

        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_decline, I_scale )
        I_result = IceRayPy.type.math.affine.compose3D( self.m_cargo['dll'], I_move, I_result )
        self.m_cargo['affine'].toWorldSet( I_result )
        return True


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )