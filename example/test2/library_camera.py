#!/usr/bin/env python3

print( '<' + __name__ + ' file=\'' +   __file__ + '\'>' )

import IceRayPy

list = {
    'F-persp'        : IceRayPy.core.camera.flat.Perspective,
    'F-orth'         : IceRayPy.core.camera.flat.Orthogonal,
    'F-super'        : IceRayPy.core.camera.flat.Super,
    'S-horizontal'   : IceRayPy.core.camera.sphere.Horizontal,
    'S-vertical'     : IceRayPy.core.camera.sphere.Vertical,
    'S-fisheye'      : IceRayPy.core.camera.sphere.Fisheye,
    'C-vertical'     : IceRayPy.core.camera.cylinder.Vertical,
    'C-horizontal'   : IceRayPy.core.camera.cylinder.Horizontal,
    'I-C-vertical'   : IceRayPy.utility.camera.invert.CylinderVertical,
    'P-C-vertical'   : IceRayPy.utility.camera.pin.PinCylinderVertical,
    'DOF-persp'      : IceRayPy.core.camera.dof.Focus,
    'DOF-cone'       : IceRayPy.core.camera.dof.Cone,
    'DOF-cylinder'   : IceRayPy.core.camera.dof.Cylinder,
    }

print( '</' + __name__ + ' file=\'' +   __file__ + '\'>' )