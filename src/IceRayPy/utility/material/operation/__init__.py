#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy.utility.material.operation.mapping

def Coord3D2Color(
    P_dll
    ,P_config = None
    ,P_function = None
    ,P_filename = None 
   ):


    result = IceRayPy.core.material.instruction.label.color.dynamic.RESULT
    normal = IceRayPy.core.material.instruction.label.coord3d.dynamic.NORMAL

    I_surface = IceRayPy.core.material.pigment.Surface( P_dll )
    I_surface.append( IceRayPy.core.material.instruction.convert.Coord3D2Color( P_dll, result, normal ) )

    return I_surface

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
