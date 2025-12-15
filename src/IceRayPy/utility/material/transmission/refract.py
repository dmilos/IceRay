#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


import IceRayPy

def Fresnel(
     P_dll
    ,P_config
    ,P_ior      = None
    ,P_albedo   = None
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_iorValue = 1.635
    if( 'ior' in P_config ):
        I_iorValue = P_config['ior']
    if( None != P_ior ):
        I_iorValue = P_ior

    I_albedoValue = IceRayPy.type.color.RGB( 0.9, 0.9, 0.9 )
    if( 'albedo' in P_config ):
        I_albedoValue = P_config['albedo']
    if( None != P_albedo ):
        I_albedoValue = P_albedo

    I_leader = tempSize + 0
    I_count = tempSize + 1
    I_ior    = tempScalar + 0
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_iorValue,      I_ior ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedoValue,   I_albedo ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Fresnel( P_dll, point, normal, I_ior, I_albedo, I_count, I_leader ) )

    return I_surface


def Snell(
     P_dll
    ,P_config
    ,P_ior          = None
    ,P_albedo       = None
    ,P_transparency = None
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_iorValue = 1.635
    if( 'ior' in P_config ):
        I_iorValue = P_config['ior']
    if( None != P_ior ):
        I_iorValue = P_ior

    I_albedoValue = IceRayPy.type.color.RGB( 0.9, 0.9, 0.9 )
    if( 'albedo' in P_config ):
        I_albedoValue = P_config['albedo']
    if( None != P_albedo ):
        I_albedoValue = P_albedo

    I_transparencyValue = IceRayPy.type.color.RGB( 0.9, 0.9, 0.9 )
    if( 'transparency' in P_config ):
        I_transparencyValue = P_config['transparency']
    if( None != P_transparency ):
        I_transparencyValue = P_transparency

    I_leader = tempSize + 1
    I_ior    = tempScalar + 0
    I_albedo = tempColor + 0
    I_transparency  = tempColor + 1

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_iorValue,          I_ior ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedoValue,       I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_transparencyValue, I_transparency ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Snell( P_dll, point, normal, I_ior, I_albedo, I_transparency, I_leader ) )

    return I_surface

def Schlick(
     P_dll
    ,P_config
    ,P_ior      = None # 1.16, 1.54, 2.51, 2.94
    ,P_albedo   = None
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_leader = tempSize + 0
    I_count  = tempSize + 1
    I_ior    = tempScalar + 0
    I_albedo = tempScalar + 1

    I_iorValue = 1.635
    if( 'ior' in P_config ):
        I_iorValue = P_config['ior']
    if( None != P_ior ):
        I_iorValue = P_ior

    I_albedoValue = IceRayPy.type.color.RGB( 0.99, 0.99, 0.99 )
    if( 'albedo' in P_config ):
        I_albedoValue = P_config['albedo']
    if( None != P_albedo ):
        I_albedoValue = P_albedo

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_iorValue,    I_ior    ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedoValue, I_albedo ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Schlick( P_dll, point, normal, I_ior, I_albedo, I_count, I_leader ) )

    return I_surface



def Birefringence(
     P_dll
    ,P_config
    ,P_ior1      = None  #!< n0
    ,P_albedo1   = None
    ,P_ior2      = None  #!< ne
    ,P_albedo2   = None
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_leader1 = tempSize + 0
    I_count1  = tempSize + 1
    I_leader2 = tempSize + 2
    I_count2  = tempSize + 3
    I_ior1    = tempScalar + 0
    I_albedo1 = tempScalar + 1
    I_ior2    = tempScalar + 2
    I_albedo2 = tempScalar + 3

    I_ior1Value = 1.658
    if( 'ior1' in P_config ):
        I_ior1Value = P_config['ior1']
    if( None != P_ior1 ):
        I_ior1Value = P_ior1

    I_albedo1Value = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    if( 'albedo1' in P_config ):
        I_albedo1Value = P_config['albedo1']
    if( None != P_albedo1 ):
        I_albedo1Value = P_albedo1

    I_ior2Value = 1.486
    if( 'ior2' in P_config ):
        I_ior2Value = P_config['ior2']
    if( None != P_ior2 ):
        I_ior2Value = P_ior2

    I_albedo2Value = IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 )
    if( 'albedo2' in P_config ):
        I_albedo2Value = P_config['albedo2']
    if( None != P_albedo2 ):
        I_albedo2Value = P_albedo2
        
    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_ior1Value,    I_ior1    ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedo1Value, I_albedo1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_ior2Value,    I_ior2    ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedo2Value, I_albedo2 ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Schlick( P_dll, point, normal, I_ior1, I_albedo1, I_count1, I_leader1 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Schlick( P_dll, point, normal, I_ior2, I_albedo2, I_count2, I_leader2 ) )

    return I_surface
    
def BaB2O4         ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.6776, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 1.5534, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def Be3Al2_SiO3_6  ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.602 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 1.557 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def CaCO3          ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.658 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 1.486 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def H2O            ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.3090, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 1.3104, IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def LiNbO3         ( P_dll, P_config ): return Birefringence( P_dll, P_config, 2.272 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 2.187 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def MgF2           ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.380 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 1.385 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def SiO2           ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.544 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 1.553 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def Al2O3          ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.770 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 1.762 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def TiO2           ( P_dll, P_config ): return Birefringence( P_dll, P_config, 2.616 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 2.903 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def Al2O3          ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.768 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 1.760 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def SiC            ( P_dll, P_config ): return Birefringence( P_dll, P_config, 2.647 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 2.693 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def Tourmaline     ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.669 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 1.638 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def ZrSiO4_hight   ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.960 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 2.015 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )
def ZrSiO4_low     ( P_dll, P_config ): return Birefringence( P_dll, P_config, 1.920 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ), 1.967 , IceRayPy.type.color.RGB( 0.5, 0.5, 0.5 ) )

def Biaxial(
     P_dll
    ,P_config
    ,P_ior1      = None  #!< nα
    ,P_albedo1   = None
    ,P_ior2      = None  #!< nβ
    ,P_albedo2   = None
    ,P_ior3      = None  #!< nγ
    ,P_albedo3   = None
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN

    I_leader1 = tempSize + 0
    I_count1  = tempSize + 1
    I_leader2 = tempSize + 2
    I_count2  = tempSize + 3
    I_leader3 = tempSize + 4
    I_count3  = tempSize + 5
    I_ior1    = tempScalar + 0
    I_albedo1 = tempScalar + 1
    I_ior2    = tempScalar + 2
    I_albedo2 = tempScalar + 3
    I_ior3    = tempScalar + 4
    I_albedo3 = tempScalar + 5

    I_ior1Value = 1.595
    if( 'ior1' in P_config ):
        I_ior1Value = P_config['ior1']
    if( None != P_ior1 ):
        I_ior1Value = P_ior1

    I_albedo1Value = IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 )
    if( 'albedo1' in P_config ):
        I_albedo1Value = P_config['albedo1']
    if( None != P_albedo1 ):
        I_albedo1Value = P_albedo1

    I_ior2Value = 1.640
    if( 'ior2' in P_config ):
        I_ior2Value = P_config['ior2']
    if( None != P_ior2 ):
        I_ior2Value = P_ior2
    I_albedo2Value = IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 )
    if( 'albedo2' in P_config ):
        I_albedo2Value = P_config['albedo2']
    if( None != P_albedo2 ):
        I_albedo2Value = P_albedo2
        
    I_ior2Value = 1.640
    if( 'ior3' in P_config ):
        I_ior3Value = P_config['ior3']
    if( None != P_ior3 ):
        I_ior3Value = P_ior3
    I_albedo3Value = IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 )
    if( 'albedo3' in P_config ):
        I_albedo3Value = P_config['albedo3']
    if( None != P_albedo3 ):
        I_albedo3Value = P_albedo3
        
    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_ior1Value,    I_ior1    ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedo1Value, I_albedo1 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_ior2Value,    I_ior2    ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedo2Value, I_albedo2 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar(          P_dll, I_ior3Value,    I_ior3    ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(           P_dll, I_albedo3Value, I_albedo3 ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Schlick( P_dll, point, normal, I_ior1, I_albedo1, I_count1, I_leader1 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Schlick( P_dll, point, normal, I_ior2, I_albedo2, I_count2, I_leader2 ) )
    I_surface.append( IceRayPy.core.material.instruction.transmission.refract.Schlick( P_dll, point, normal, I_ior3, I_albedo3, I_count3, I_leader3 ) )

    return I_surface


def MgSO4_7H2O( P_dll, P_config ):                 return Biaxial( P_dll, P_config, 1.433, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.455, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.461, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ) )
def B4O5__OH_4_8H2O( P_dll, P_config ):            return Biaxial( P_dll, P_config, 1.447, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.469, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.472, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ) )
def NaCaB5O6_OH_6_5H2O( P_dll, P_config ):         return Biaxial( P_dll, P_config, 1.490, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.510, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.520, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ) )
def KAl2_AlSi3O10__F_OH_2( P_dll, P_config ):      return Biaxial( P_dll, P_config, 1.563, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.596, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.601, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ) )
def K_Mg_Fe_3_AlSi3O10__F_OH_2( P_dll, P_config ): return Biaxial( P_dll, P_config, 1.595, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.640, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.640, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ) )
def Al2SiO4_F_OH_2( P_dll, P_config ):             return Biaxial( P_dll, P_config, 1.618, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.620, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.627, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ) )
def Mg_Fe_2SiO4( P_dll, P_config ):                return Biaxial( P_dll, P_config, 1.640, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.660, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 1.680, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ) )
def CaTiO3( P_dll, P_config ):                     return Biaxial( P_dll, P_config, 2.300, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 2.340, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ), 2.380, IceRayPy.type.color.RGB( 0.3333, 0.3333, 0.3333 ) )

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
