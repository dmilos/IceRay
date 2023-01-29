#print( '<' + __name__ + ' name=\'' +   __file__ + '\''+ '>' )

import math
import IceRayPy


def Random(
     P_dll
    ,P_config = None
    ,P_total 
    ,P_start 
    ,P_angle
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 0 ) )
    # TODO I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0, I_leader ) )
    # TODO 
    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader,tempSize + 0 ) )
    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count, tempSize + 1 ) )
    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle, tempScalar + 0 ) )
    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss, tempScalar + 1 ) )
    # TODO 
    # TODO I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Grid( P_dll, normal, tempSize+0, tempSize+1, tempScalar+0, tempScalar+1 ) )
    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    return I_surface

def VDC(
     P_dll
    ,P_config = None
    ,P_total 
    ,P_start 
    ,P_angle
    ):

    result     = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    point      = IceRayPy.core.material.instruction.label.coord3d.dynamic.POINT
    normal     = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempSize   = IceRayPy.core.material.instruction.label.size.temp._BEGIN
    tempScalar = IceRayPy.core.material.instruction.label.scalar.temp._BEGIN
    tempColor  = IceRayPy.core.material.instruction.label.color.temp._BEGIN
    lightThe   = IceRayPy.core.material.instruction.label.light.temp._BEGIN
    spotBegin  = IceRayPy.core.material.instruction.label.size.dynamic.SpotBegin
    spotEnd    = IceRayPy.core.material.instruction.label.size.dynamic.SpotEnd

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )

    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Color( P_dll, P_albedo,  tempColor + 0 ) )
    # TODO I_surface.append( IceRayPy.core.material.instruction.transmission.reflect.One( P_dll, point, normal, tempColor + 0, I_leader ) )
    # TODO 
    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_leader,tempSize + 0 ) )
    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Size(   P_dll, P_count, tempSize + 1 ) )
    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_angle, tempScalar + 0 ) )
    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Scalar( P_dll, P_gauss, tempScalar + 1 ) )
    # TODO 
    # TODO I_surface.append( IceRayPy.core.material.instruction.transmission.blossom.Hexagon( P_dll, normal, tempSize+0, tempSize+1, tempScalar+0, tempScalar+1 ) )
    # TODO I_surface.append( IceRayPy.core.material.instruction.constant.Color(  P_dll, IceRayPy.type.color.RGB( 0, 0, 0 ), result ) )

    return I_surface

def Sobol(
     P_dll
    ,P_config = None
    ,P_total 
    ,P_start 
    ,P_angle
    ):
    pass

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )