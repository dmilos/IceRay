#print( '<' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )
import math
import IceRayPy

G_albedo = IceRayPy.type.color.RGB( 1, 1, 1 )
G_angle = math.radians(30)
G_gauss =  1


# todo def _ApplyJitter( P_surface, P_config ):
# todo     if( 'jitter-angle' in P_config ):
# todo         I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )
# todo
# todo     if( 'jitter-type' in P_config ):
# todo         if( 'random' == P_config['jitter-type'] ):
# todo             P_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
# todo         if( 'sobol'  == P_config['jitter-type'] ):
# todo             P_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
# todo         if( 'vdc'    == P_config['jitter-type'] ):
# todo             P_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
# todo         if( 'congruent'    == P_config['jitter-type'] ):
# todo             P_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(    P_dll, normal, I_total, I_start, I_jitter ) )
# todo         if( 'none'    == P_config['jitter-type'] ):
# todo             pass
# todo     return True
# todo
# todo  def _ApplyCorrectionPre( P_surface, P_config ):
# todo     if( 'correction-leader' in P_config ):
# todo         if( True == P_config['correction-leader'] ):
# todo             P_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_leader ) )
# todo     if( 'correction-cone' in P_config ):
# todo         if( True == P_config['correction-cone'] ):
# todo             P_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )
# todo
# todo     return True
# todo
# todo   def _ApplyCorrectionPost( P_surface, P_config ):
# todo     if( 'correction-claim' in P_config ):
# todo         if( True == P_config['correction-claim'] ):
# todo             P_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
# todo
# todo     if( 'correction-trim' in P_config ):
# todo         if( True == P_config['correction-trim'] ):
# todo             P_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )
# todo
# todo     return True




G_sizeGrid      =  6 #1,   1     3    7  13
G_countHex      =  7 #1,   1,    3,   7, 13
G_countPinwheel =  0 #0,   0,    0,   0,  0,
G_countLD       =  0 #0,   0,    0,   0,  0,
G_countRandom   = 33 #1,   2,   12,  33, 74
G_countCongruent= 33 #1,   2,   12,  33, 74
G_countSobol    = 33 #1,   2,   12,  33, 74
G_countTriangle =  8 #1,   1,    2,   5,  9,  17
G_countVDC      = 33 #1,   2,   12,  33, 74

def Grid(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count   = G_sizeGrid
    ,P_leader = 0
    ,P_angle  = G_angle
    ,P_gauss  = G_gauss
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_count  = tempSize + 0
    I_leader = tempSize + 1
    I_total  = tempSize + 2
    I_start  = tempSize + 3
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count , I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_leader ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Grid( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )

    return I_surface


def Hexagon(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count = G_countHex
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_count  = tempSize + 0
    I_leader = tempSize + 1
    I_total  = tempSize + 2
    I_start  = tempSize + 3
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_leader ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Hexagon( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )

    return I_surface


def Pinwheel(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count = G_countPinwheel
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 1
    I_total = tempSize + 2
    I_count = tempSize + 2
    I_angle = tempScalar + 0
    I_gauss = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 2

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_angle ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Pinwheel( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )


    return I_surface



def Sunflower(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count = G_countHex
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_count  = tempSize + 0
    I_leader = tempSize + 1
    I_total  = tempSize + 2
    I_start  = tempSize + 3
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_leader ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Sunflower( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )

    return I_surface



def Poisson(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count = G_countHex
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_count  = tempSize + 0
    I_leader = tempSize + 1
    I_total  = tempSize + 2
    I_start  = tempSize + 3
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_leader ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Poisson( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_total, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )

    return I_surface



def LD(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count = G_countLD
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0
    I_count  = tempSize + 1
    I_total  = tempSize + 1
    I_start  = tempSize + 2
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_angle ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.LD(        P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )


    return I_surface



def Sobol(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count = G_countSobol
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0
    I_count  = tempSize + 1 # total and count are the same for random
    I_total  = tempSize + 1 # total and count are the same for random
    I_start  = tempSize + 2
    I_angle = tempScalar + 0
    I_gauss = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_angle ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Sobol( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )


    return I_surface



def Random(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count = G_countRandom
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0
    I_count  = tempSize + 1 # total and count are the same for random
    I_total  = tempSize + 1 # total and count are the same for random
    I_start  = tempSize + 2
    I_angle = tempScalar + 0
    I_gauss = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_angle ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Random( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )


    return I_surface



def Random(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count = G_countRandom
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0
    I_count  = tempSize + 1 # total and count are the same for random
    I_total  = tempSize + 1 # total and count are the same for random
    I_start  = tempSize + 2
    I_angle = tempScalar + 0
    I_gauss = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_angle ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Random( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )


    return I_surface


def Triangle(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_radius = G_countTriangle
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0
    I_radius = tempSize + 1
    I_total  = tempSize + 2
    I_start  = tempSize + 3
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_radius, I_radius ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_angle ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Triangle( P_dll, normal, I_radius, I_leader, I_angle, I_gauss, I_total, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )


    return I_surface


def VDC(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count = G_countVDC
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0
    I_count  = tempSize + 1 # total and count are the same for VDC
    I_total  = tempSize + 1 # total and count are the same for VDC
    I_start  = tempSize + 2
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_angle ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.VDC( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )


    return I_surface


def Congruent(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_count = G_countCongruent
    ,P_leader = 0
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):
    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    incident   = IceRayPy.core.material.instruction.label.coord3d.dynamic.INCIDENT
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_leader = tempSize + 0
    I_count  = tempSize + 1 # total and count are the same for random
    I_total  = tempSize + 1 # total and count are the same for random
    I_start  = tempSize + 2
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    if( 'jitter-angle' in P_config ):
        I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_config['jitter-angle'], I_jitter ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( 'correction-leader' in P_config ):
        if( True == P_config['correction-leader'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Leader( P_dll, normal, I_angle, I_angle ) )
    if( 'correction-cone' in P_config ):
        if( True == P_config['correction-cone'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Congruent( P_dll, normal, I_count, I_leader, I_angle, I_gauss, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'congruent'== P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Congruent(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction' in P_config ):
        if( 'claim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
        if( 'trim' == P_config['correction'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )


    return I_surface



#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )