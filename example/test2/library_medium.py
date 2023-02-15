#!/usr/bin/env python3

print( '<' + __name__ + ' file=\'' +   __file__ + '\'>' )

import IceRayPy


list = {
       'trans'      : IceRayPy.core.material.medium.Transparent,
       'solid'     : IceRayPy.core.material.medium.Solid,
       'const'     : IceRayPy.core.material.medium.Constant,
       'exp'       : IceRayPy.core.material.medium.Exponential,
       'linear'    : IceRayPy.core.material.medium.Linear,
       'quadratic' : IceRayPy.core.material.medium.Quadratic,
    }


print( '</' + __name__ + ' file=\'' +   __file__ + '\'>' )
