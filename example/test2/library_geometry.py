#!/usr/bin/env python3

import IceRayPy


list = {
     'S-sphere'           : IceRayPy.core.geometry.simple.Sphere,
     'S-usphere'          : IceRayPy.core.geometry.simple.SphereU,
     'S-cylinder'         : IceRayPy.core.geometry.simple.Cylinder,
     'S-util-cylinder'    : IceRayPy.utility.geometry.simple.CylinderG,
     'S-box'              : IceRayPy.core.geometry.simple.Box,
     'S-torus'            : IceRayPy.core.geometry.simple.Torus,
     'S-util-torus'       : IceRayPy.utility.geometry.simple.Torus,
     'S-cone'             : IceRayPy.core.geometry.simple.Cone,
     'S-util-cone'        : IceRayPy.utility.geometry.simple.ConeG,
     'S-disc'             : IceRayPy.core.geometry.simple.Disc,
     'S-udisc'            : IceRayPy.core.geometry.simple.UDisc,
     'S-ellipsoid'        : IceRayPy.core.geometry.simple.Ellipsoid,
     'S-paraboloid'       : IceRayPy.core.geometry.simple.Paraboloid,
     'S-util-paraboloid'  : IceRayPy.utility.geometry.simple.ParaboloidG,
     'S-quadric'          : IceRayPy.core.geometry.simple.Quadric,
     'S-triangle'         : IceRayPy.core.geometry.simple.Triangle,
     'S-triangleU'        : IceRayPy.core.geometry.simple.TriangleU, #!< TODO
     'S-plane'            : IceRayPy.core.geometry.simple.Plane,
     'S-saddle'           : IceRayPy.core.geometry.simple.Saddle,
     'S-cylinderu'        : IceRayPy.core.geometry.simple.CylinderU,

     'hyper-nuke'           : IceRayPy.utility.geometry.simple.hyperboloid.Nuke,
     'hyper-sphere'         : IceRayPy.utility.geometry.simple.hyperboloid.Sphere,
     'hyper-cone'           : IceRayPy.utility.geometry.simple.hyperboloid.Cone,
     'hyper-cylinder'       : IceRayPy.utility.geometry.simple.hyperboloid.Cylinder,
     'hyper-negative'       : IceRayPy.utility.geometry.simple.hyperboloid.Negative,

     'C-I-i-i'    : IceRayPy.library.geometry.example.Intersect_IN_IN,
     'C-I-i-o'    : IceRayPy.library.geometry.example.Intersect_IN_OUT,
     'C-I-i-s'    : IceRayPy.library.geometry.example.Intersect_IN_SURFACE,
     'C-I-o-i'    : IceRayPy.library.geometry.example.Intersect_OUT_IN,
     'C-I-o-o'    : IceRayPy.library.geometry.example.Intersect_OUT_OUT,
     'C-I-o-s'    : IceRayPy.library.geometry.example.Intersect_OUT_SURFACE,
     'C-I-s-i'    : IceRayPy.library.geometry.example.Intersect_SURFACE_IN,
     'C-I-s-o'    : IceRayPy.library.geometry.example.Intersect_SURFACE_OUT,
     'C-I-s-s'    : IceRayPy.library.geometry.example.Intersect_SURFACE_SURFACE,

    #'C-Enclose'      : IceRayPy.core.geometry.complex.Enclose, #NYI

     'C-hfieldI'       : IceRayPy.library.geometry.hfield.Image,
    #'C-hfieldLE'      : IceRayPy.library.geometry.hfield.Expression, #NYI
     'C-hfieldT2x2'    : IceRayPy.library.geometry.hfield.Table2x2,
     'C-hfieldT3x3'    : IceRayPy.library.geometry.hfield.Table3x3,
     'C-hfieldT4x4'    : IceRayPy.library.geometry.hfield.Table4x4,
     'C-hfieldT30x30'  : IceRayPy.library.geometry.hfield.Table5x5,

     'T-identity'   : IceRayPy.core.geometry.transform.Identity,
     'T-translate'  : IceRayPy.core.geometry.transform.Translate,
     'T-affine'     : IceRayPy.core.geometry.transform.Affine,
     'T-hgraphy'    : IceRayPy.core.geometry.transform.Homography,
     'T-mblur'      : IceRayPy.library.geometry.MotionBlur,

     'T-lensCS'      : IceRayPy.library.geometry.lens.concave.Symetric,
     'T-lensCP'      : IceRayPy.library.geometry.lens.concave.Plano,
     'T-lensVS'      : IceRayPy.library.geometry.lens.convex.Symetric,
     'T-lensVP'      : IceRayPy.library.geometry.lens.convex.Plano,

     'T-lensPCvA'    : IceRayPy.library.geometry.example.IntersectGeneral,

     'V-Vacuum'      : IceRayPy.core.geometry.volumetric.Vacuum,
     'V-Mist'        : IceRayPy.core.geometry.volumetric.Mist,
     'V-Smoke'       : IceRayPy.core.geometry.volumetric.Smoke,
     'library-1m'    : IceRayPy.library.geometry.OneM,
     'L-Bpair'       : IceRayPy.library.geometry.blobby.Pair
     }
