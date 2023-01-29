#print( '<' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )
import math
import IceRayPy

G_albedo = IceRayPy.type.color.RGB( 1, 1, 1 )
G_angle = math.radians(15)
G_gauss =  1

G_sizeGrid      = 13 #1,   1     3    7  13
G_countHex      =  2 #1,   1,    3,   7, 13
G_countPinwheel =  0 #0,   0,    0,   0,  0,
G_countRandom   = 74 #1,   2,   12,  33, 74
G_countTriangle =  9 #1,   1,    2,   5,  9,  17
G_countVDC      = 74 #1,   2,   12,  33, 74

def Grid(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_side   = G_sizeGrid
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

    I_side   = tempSize + 0
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
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_side,   I_side   ) )
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

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Grid( P_dll, normal, I_side, I_leader, I_angle, I_gauss, I_total, I_start ) )

    if( 'jitter-type' in P_config ):
        if( 'random' == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'sobol'  == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'vdc'    == P_config['jitter-type'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_total, I_start, I_jitter ) )
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction-claim' in P_config ):
        if( True == P_config['correction-claim'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

    if( 'correction-trim' in P_config ):
        if( True == P_config['correction-trim'] ):
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

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_count  = tempSize + 0
    I_leader = tempSize + 1
    I_total  = tempSize + 2
    I_start  = tempSize + 3
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2
    I_albedo = tempColor + 0

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
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction-claim' in P_config ):
        if( True == P_config['correction-claim'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

    if( 'correction-trim' in P_config ):
        if( True == P_config['correction-trim'] ):
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
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction-claim' in P_config ):
        if( True == P_config['correction-claim'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

    if( 'correction-trim' in P_config ):
        if( True == P_config['correction-trim'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )

    return I_surface

def Sobol(
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
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction-claim' in P_config ):
        if( True == P_config['correction-claim'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

    if( 'correction-trim' in P_config ):
        if( True == P_config['correction-trim'] ):
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
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction-claim' in P_config ):
        if( True == P_config['correction-claim'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

    if( 'correction-trim' in P_config ):
        if( True == P_config['correction-trim'] ):
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
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction-claim' in P_config ):
        if( True == P_config['correction-claim'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

    if( 'correction-trim' in P_config ):
        if( True == P_config['correction-trim'] ):
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

    print( "VDC::config:" + str( P_config ), flush = True  )

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
        if( 'none'    == P_config['jitter-type'] ):
            pass

    if( 'correction-claim' in P_config ):
        if( True == P_config['correction-claim'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )

    if( 'correction-trim' in P_config ):
        if( True == P_config['correction-trim'] ):
            I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )

    return I_surface


#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )