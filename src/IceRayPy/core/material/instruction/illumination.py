print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import ctypes

SizeType   = ctypes.c_uint
ScalarType = ctypes.c_uint
AddresOf   = ctypes.addressof

class ALP:
    def __init__(self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_emission, P_diffuse, P_specular, P_shininess ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_ALP0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_emission  ), SizeType( P_diffuse ), SizeType( P_specular ), SizeType( P_shininess )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Ambient:
    def __init__(self, P_dll, P_result, P_emission ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Ambient0(
             SizeType( P_result )
            ,SizeType( P_emission  )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class AsDiffuse: #( AsDiffuse0   )( S( result ), S( point     ), S( normal    ), S( spotCount ), S( spotBegin ), S( diffuse    ), S( specular   )  );
    def __init__(self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_diffuse, P_specular  ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_AsDiffuse0(
              SizeType( P_result )
             ,SizeType( P_point     ), SizeType( P_normal    )
             ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
             ,SizeType( P_diffuse   ), SizeType( P_specular  )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class AsSpecular: #( S( result ), S( point     ), S( normal    ), S( spotCount ), S( spotBegin ), S( specular   ), S( nu         ), S( nv        ) );

    def __init__(self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_diffuse, P_specular, P_nu, P_nv ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_AsDiffuse0(
              SizeType( P_result )
             ,SizeType( P_point     ), SizeType( P_normal    )
             ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
             ,SizeType( P_specular  ), SizeType( P_nu  ), SizeType( P_nv  )
        )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Beckmann:
    def __init__( self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_specular, P_roughness ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Beckmann0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_specular ), SizeType( P_roughness )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Blinn: # S( result ), S( point     ), S( normal    ), S( spotCount ), S( spotBegin ), S( specular   ), S( shininess  )
    def __init__(self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_specular, P_shininess ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Blinn0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_specular ), SizeType( P_shininess )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Gaussian: # S( result ), S( point     ), S( normal    ), S( spotCount ), S( spotBegin ), S( specular   ), S( smoothness )
    def __init__(self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_specular, P_smoothness ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Gaussian0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_specular ), SizeType( P_smoothness )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Lambert: # S( result ), S( point     ), S( normal    ), S( spotCount ), S( spotBegin ), S( diffuse    )
    def __init__(self, P_dll, P_result, P_point, P_normal , P_spotBegin, P_spotEnd, P_diffuse ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Lambert0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_diffuse )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )


class Phong: # S( result ),                                 S( spotCount ), S( spotBegin ), S( specular   ), S( shininess  )
    def __init__(self, P_dll, P_result, P_spotBegin, P_spotEnd, P_specular, P_shininess ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Phong0(
             SizeType( P_result )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_specular ), SizeType( P_shininess )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class HsLambert:    # S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( groove ), S( P_diffuse ) );
    def __init__( self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_groove, P_diffuse ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_HsLambert0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_groove ), SizeType( P_diffuse )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class HsNormal:    # S( result ),                 S( normal    ),                                S( groove ) );
    def __init__( self, P_dll, P_normal, P_groove ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_HsNormal0(
             SizeType( P_result )
            ,SizeType( P_normal )
            ,SizeType( P_groove )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class HsPhong:     # S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( groove ), S( specular   ), S( shininess  ) );
    def __init__( self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_groove, P_specular, P_shininess ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Beckmann0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_groove )
            ,SizeType( P_specular ), SizeType( P_shininess )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class OnF29:       # S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( rho ), S( sigma ) );
    def __init__( self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_rho, P_sigma ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Beckmann0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_rho ), SizeType( P_sigma )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class OnP44:        # S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( A ), S( B ) );
    def __init__( self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_A, P_B ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Beckmann0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_A ), SizeType( P_B )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class OnYF:          # S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( A ), S( B ) );
    def __init__( self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_A, P_B ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Beckmann0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_A ), SizeType( P_B )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class WardApprox: # S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( specular ), S( alphaX  ), S( alphaY ), S( direction ) );
    def __init__( self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_specular, P_alphaX, P_alphaY, P_direction ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Beckmann0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_specular )
            ,SizeType( P_alphaX ), SizeType( P_alphaY ), SizeType( P_direction )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class WardIsotropic: # S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( specular ), S( alpha   ) );
    def __init__( self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_specular, P_alpha ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Beckmann0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_specular ), SizeType( P_alpha )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )

class WardReal: # S( result ), S( point     ), S( normal    ), S( spotBegin  ), S( spotEnd ), S( specular ), S( alphaX  ), S( alphaY ), S( direction ) );
    def __init__( self, P_dll, P_result, P_point, P_normal, P_spotBegin, P_spotEnd, P_specular, P_alphaX, P_alphaY, P_direction ):
        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll
        self.m_cargo['this'] = self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Illumination_Beckmann0(
             SizeType( P_result )
            ,SizeType( P_point ) , SizeType( P_normal )
            ,SizeType( P_spotBegin ), SizeType( P_spotEnd )
            ,SizeType( P_specular )
            ,SizeType( P_alphaX ), SizeType( P_alphaY ), SizeType( P_direction )
            )

    def __del__(self):
        self.m_cargo['dll'].IceRayC_Material_Pigment_Surface_Instruction_Release( self.m_cargo['this'] )




print( '</' + __name__ + ' name=\'' +   __file__ + '>' )