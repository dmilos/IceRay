import ctypes

import IceRayPy.type.basic
import IceRayPy.type.math

ScalarType = IceRayPy.type.basic.Scalar
UnsignedType = IceRayPy.type.basic.Unsigned
SizeType = IceRayPy.type.basic.Size
AddressOf = ctypes.addressof

G_sample =1
class Focus:
    def __init__( self, P_dll, P_config = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_DOF_Focus0()

        self.aperture( IceRayPy.type.math.interval.Scalar1D( IceRayPy.type.math.coord.Scalar1D(0.2), IceRayPy.type.math.coord.Scalar1D(0.0) ) )
        self.focus(    IceRayPy.type.math.interval.Scalar1D( IceRayPy.type.math.coord.Scalar1D(2.9), IceRayPy.type.math.coord.Scalar1D(3.1) ) )

        if( None != P_config ):
            if( 'sample' in P_config ):
                self.sample( P_config['sample'] )
            if( 'aperture' in P_config ):
                self.aperture( P_config['aperture'] )
            if( 'focus' in P_config ):
                self.focus( P_config['focus'] )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def child( self, P_child ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Focus_Child( self.m_cargo['this'], P_child.m_cargo['this'] )
        self.m_cargo['child'] = P_child

    def sample( self, P_sample ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Focus_Sample( self.m_cargo['this'], SizeType( P_sample ) )

    def aperture( self, P_aperture : IceRayPy.type.math.interval.Scalar1D ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Focus_Aperture( self.m_cargo['this'], AddressOf( P_aperture ) )

    def focus( self, P_focus       : IceRayPy.type.math.interval.Scalar1D ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Focus_Focus( self.m_cargo['this'], AddressOf( P_focus ) )

    def gauss( self, P_gauss ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Focus_Gauss( self.m_cargo['this'], ScalarType( P_gauss ) )

class Cone:
    def __init__( self, P_dll, P_config = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_DOF_Cone0()
        self.aperture( 0.225 )

        if( None != P_config ):
            if( 'sample' in P_config ):
                self.sample( P_config['sample'] )
            if( 'aperture' in P_config ):
                self.aperture( P_config['aperture'] )


    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Camera_DOF_Cone_Child( self.m_cargo['this'], P_child.m_cargo['this'] )

    def sample( self, P_sample ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Cone_Sample( self.m_cargo['this'], SizeType( P_sample ) )

    def aperture( self, P_aperture : ScalarType ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Cone_Aperture( self.m_cargo['this'], ScalarType( P_aperture ) )

    def gauss( self, P_gauss ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Cone_Gauss( self.m_cargo['this'], ScalarType( P_gauss ) )


class Cylinder:
    def __init__( self, P_dll, P_config = None ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Camera_DOF_Cylinder0()

        self.aperture( 0.1 )

        if( None != P_config ):
            if( 'sample' in P_config ):
                self.sample( P_config['sample'] )
            if( 'aperture' in P_config ):
                self.aperture( P_config['aperture'] )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Camera_Release( self.m_cargo['this'] )

    def child( self, P_child ):
        self.m_cargo['child'] = P_child
        self.m_cargo['dll'].IceRayC_Camera_DOF_Cylinder_Child( self.m_cargo['this'], P_child.m_cargo['this'] )

    def sample( self, P_sample ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Cylinder_Sample( self.m_cargo['this'], SizeType( P_sample ) )

    def aperture( self, P_aperture : ScalarType ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Cylinder_Aperture( self.m_cargo['this'], ScalarType( P_aperture ) )

    def gauss( self, P_gauss : ScalarType ):
        self.m_cargo['dll'].IceRayC_Camera_DOF_Cylinder_Gauss( self.m_cargo['this'], ScalarType( P_gauss ) )
