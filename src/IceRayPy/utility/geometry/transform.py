#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )


import IceRayPy

def Translate(
     P_dll
    ,P_child : IceRayPy.core.object.Wrapper
    ,P_move
  ):

    pretender = core.geometry.Pretender( P_dll, P_child.cast2Geometry(), P_child )
    translator = core.geometry.transform.Translate( P_dll, pretender )
    translator.move( P_move )

    result = IceRayPy.core.object.Wrapper( P_dll )
    result.geometrySet( translator )

    return result

#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
