#!/usr/bin/env python3

print( '<' + __name__ + ' file=\'' +   __file__ + '\'>' )

import IceRayPy

list = {
        'dark'            : IceRayPy.core.light.Dark, # No light at all
        'point'           : IceRayPy.core.light.Point,
        'reflector'       : IceRayPy.core.light.Reflector,
        'line'            : IceRayPy.core.light.Line,
        'spline'         : IceRayPy.core.light.Spline, # TODO crash on Ubuntu
        'circle'          : IceRayPy.core.light.Circle,
        'area'            : IceRayPy.core.light.Area,
        'disc'            : IceRayPy.core.light.Disc,
        #'confine'        : IceRayPy.core.light.Confine, # TODO it is dark
        #'T-id'           : IceRayPy.core.light.transform.Identity,     # TODO NYI
        #'T-translate'    : IceRayPy.core.light.transform.Translate,    # TODO NYI
        #'T-affine'       : IceRayPy.core.light.transform.Affine,       # TODO NYI
        #'T-homography'   : IceRayPy.core.light.transform.Homography,   # TODO NYI

        'sun-Point'       : IceRayPy.utility.light.sun.Point, # TODO it is dark
        'sun-Area'        : IceRayPy.utility.light.sun.Area,
        'sun-Line'        : IceRayPy.utility.light.sun.Line,
        'sun-Circle'      : IceRayPy.utility.light.sun.Circle,
        #'sun-Disc'       : IceRayPy.utility.light.sun.Disc
        #'sphere'         : IceRayPy.utility.light.sphere.unit.make,    # TODO NYI
        #'chandelier-H'   : IceRayPy.utility.light.chandelier.Hexa   # TODO NYI
        #'chandelier-T'   : IceRayPy.utility.light.chandelier.Tetra, # TODO NYI
        #'chandelier-O'   : IceRayPy.utility.light.chandelier.Octa   # TODO NYI
        'chand-studio'    : IceRayPy.utility.light.chandelier.Studio,   # TODO NYI
        'chand-nine'      : IceRayPy.utility.light.chandelier.Nine    
    }

print( '</' + __name__ + ' file=\'' +   __file__ + '\'>' )
