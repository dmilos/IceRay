print( '<' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )

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

G_correctCone  = False
G_correctClaim = True
G_correctTrim  = False

#G_correctVDCCone = True

def Grid(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_leader = 0
    ,P_side   = G_sizeGrid
    ,P_angle  = G_angle
    ,P_gauss  = G_gauss
    ):

    #global G_sizeGrid
    #P_side = G_sizeGrid # TEST only
    ##print( "******************* G: " + str( math.degrees(G_sizeGrid)  ) )
    #G_sizeGrid = G_sizeGrid + 1

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
    I_side   = tempSize + 1
    I_total  = tempSize + 2
    I_start  = tempSize + 3
    I_angle   = tempScalar + 0
    I_gauss   = tempScalar + 1

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_side,   I_side   ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0, I_leader ) )

    if( True == G_correctCone ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Grid( P_dll, normal, I_leader, I_side, I_angle, I_gauss, I_total, I_start ) )

    if( True == G_correctClaim ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
    if( True == G_correctTrim  ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )



    return I_surface

def Hexagon(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_leader = 0
    ,P_count = G_countHex
    ,P_angle = G_angle
    ,P_jitter = math.radians( 15 )
    ,P_gauss = G_gauss
    ):
    #global G_angle
    #P_angle = G_angle # TODO test only
    #print( "******************* G: " + str( math.degrees(G_angle)  ) )
    #G_angle = G_angle + math.radians(1)

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

    I_leader = tempSize + 0
    I_count  = tempSize + 1
    I_total  = tempSize + 2
    I_start  = tempSize + 3
    I_angle  = tempScalar + 0
    I_gauss  = tempScalar + 1
    I_jitter = tempScalar + 2

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_jitter, I_jitter  ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0, I_leader ) )

    if( True == G_correctCone ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Hexagon( P_dll, normal, I_leader, I_count, I_angle, I_gauss, I_total, I_start ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Sobol(  P_dll, normal, I_start, I_total, I_jitter ) )
    #I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.Random( P_dll, normal, I_start, I_total, I_jitter ) )
    #I_surface.append( IceRayPy.core.material.instruction.transmission.jitter.VDC(    P_dll, normal, I_start, I_total, I_jitter ) )

    if( True == G_correctClaim ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
    if( True == G_correctTrim  ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )


    return I_surface

def Pinwheel(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_leader = 0
    ,P_count = G_countPinwheel
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

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0, I_leader ) )

    if( True == G_correctCone ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Pinwheel( P_dll, normal, I_leader, I_count, I_angle, I_gauss, I_total ) )

    if( True == G_correctClaim ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
    if( True == G_correctTrim  ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )



    return I_surface

def Sobol(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_leader = 0
    ,P_count = G_countRandom
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

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0, I_leader ) )

    if( True == G_correctCone ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Sobol( P_dll, normal, I_leader, I_count, I_angle, I_gauss, I_start ) )

    if( True == G_correctClaim ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
    if( True == G_correctTrim  ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )

    return I_surface


def Random(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_leader = 0
    ,P_count = G_countRandom
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

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0, I_leader ) )

    if( True == G_correctCone ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Random( P_dll, normal, I_leader, I_count, I_angle, I_gauss, I_start ) )

    if( True == G_correctClaim ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
    if( True == G_correctTrim  ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )



    return I_surface

def Triangle(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_leader = 0
    ,P_radius = G_countTriangle
    ,P_angle = G_angle
    ,P_gauss = G_gauss
    ):

    #global G_countTriangle
    #P_radius = G_countTriangle # TODO test only
    ##print( "******************* G: " + str( math.degrees(G_countTriangle)  ) )
    #G_countTriangle = G_countTriangle + 1

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
    
    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, tempColor + 0 ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_radius, I_radius ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0, I_leader ) )

    if( True == G_correctCone ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Triangle( P_dll, normal, I_leader, I_radius, I_angle, I_gauss, I_total, I_start ) )

    if( True == G_correctClaim ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
    if( True == G_correctTrim  ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )

    return I_surface


def VDC(
     P_dll
    ,P_config = None
    ,P_albedo : IceRayPy.type.color.RGB = G_albedo
    ,P_leader = 0
    ,P_count = G_countVDC
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
    I_angle = tempScalar + 0
    I_gauss = tempScalar + 1
    I_albedo = tempColor + 0

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, P_albedo, I_albedo ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader, I_leader ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count,  I_count  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle,  I_angle  ) )
    I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss,  I_gauss  ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, I_albedo, I_leader ) )

    if( True == G_correctCone ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Cone( P_dll, normal, incident, I_angle, I_angle ) )

    I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.VDC( P_dll, normal, I_leader, I_count, I_angle, I_gauss, I_start ) )

    if( True == G_correctClaim ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Claim( P_dll, normal, I_total, I_start ) )
    if( True == G_correctTrim  ):
        I_surface.append( IceRayPy.core.material.instruction.transmission.correct.Trim(  P_dll, normal, I_total, I_start ) )

    return I_surface


print( '</' + __name__ + ' name=\'' +   __file__ + '>' )