#!/usr/bin/env python3

import IceRayPy

Coord3D = IceRayPy.type.math.coord.Scalar3D
Matrix3D = IceRayPy.type.math.matrix.Scalar3D




list = {

     'F-box'              : IceRayPy.core.geometry.flat.Box,
     'F-disc'             : IceRayPy.core.geometry.flat.Disc,
     'F-udisc'            : IceRayPy.core.geometry.flat.UDisc,
     'F-triangle'         : IceRayPy.core.geometry.flat.Triangle,
     'F-triangleU'        : IceRayPy.core.geometry.flat.TriangleU, #!< TODO
     'F-plane'            : IceRayPy.core.geometry.flat.Plane,
     'F-piped'            : IceRayPy.utility.geometry.simple.Parallelepiped,

     'Q-sphere'           : IceRayPy.core.geometry.simple.Sphere,
     'Q-sphereu'          : IceRayPy.core.geometry.simple.SphereU,
     'Q-cylinder'         : IceRayPy.core.geometry.simple.Cylinder,
     'Q-cylinderu'        : IceRayPy.core.geometry.simple.CylinderU,
     'Q-util-cylinder'    : IceRayPy.utility.geometry.simple.CylinderG,
     'Q-cone'             : IceRayPy.core.geometry.simple.Cone,
     'Q-util-cone'        : IceRayPy.utility.geometry.simple.ConeG,
     'Q-ellipsoid'        : IceRayPy.core.geometry.simple.Ellipsoid,
     'Q-paraboloid'       : IceRayPy.core.geometry.simple.Paraboloid,
     'Q-util-paraboloid'  : IceRayPy.utility.geometry.simple.ParaboloidG,
     
     'Q-Q-default'        : IceRayPy.core.geometry.simple.Quadric,
     'Q-Q-sphere'         : IceRayPy.utility.geometry.simple.quadric.Sphere,
     'Q-Q-cylinder'       : IceRayPy.utility.geometry.simple.quadric.Cylinder,
     'Q-Q-para'           : IceRayPy.utility.geometry.simple.quadric.Paraboloid,
     'Q-Q-saddle'         : IceRayPy.utility.geometry.simple.quadric.Saddle,
     'Q-Q-nuke'           : IceRayPy.utility.geometry.simple.quadric.Nuke,
     'Q-Q-cone'           : IceRayPy.utility.geometry.simple.quadric.Cone,

     'Q-saddle'           : IceRayPy.core.geometry.simple.Saddle,
     'Q-hyper-nuke'       : IceRayPy.utility.geometry.simple.hyperboloid.Nuke,
     'Q-hyper-sphere'     : IceRayPy.utility.geometry.simple.hyperboloid.Sphere,
     'Q-hyper-cone'       : IceRayPy.utility.geometry.simple.hyperboloid.Cone,
     'Q-hyper-cylinder'   : IceRayPy.utility.geometry.simple.hyperboloid.Cylinder,
     'Q-hyper-negative'   : IceRayPy.utility.geometry.simple.hyperboloid.Negative,

     'S-torus'            : IceRayPy.core.geometry.simple.Torus,
     'S-util-torus'       : IceRayPy.utility.geometry.simple.Torus,

     'C-I-i-i'    : IceRayPy.library.geometry.example.Intersect_IN_IN,
     'C-I-i-o'    : IceRayPy.library.geometry.example.Intersect_IN_OUT,
     'C-I-i-s'    : IceRayPy.library.geometry.example.Intersect_IN_SURFACE,
     'C-I-o-i'    : IceRayPy.library.geometry.example.Intersect_OUT_IN,
     'C-I-o-o'    : IceRayPy.library.geometry.example.Intersect_OUT_OUT,
     'C-I-o-s'    : IceRayPy.library.geometry.example.Intersect_OUT_SURFACE,
     'C-I-s-i'    : IceRayPy.library.geometry.example.Intersect_SURFACE_IN,
     'C-I-s-o'    : IceRayPy.library.geometry.example.Intersect_SURFACE_OUT,
     'C-I-s-s'    : IceRayPy.library.geometry.example.Intersect_SURFACE_SURFACE,
     'C-cookie'   : IceRayPy.library.geometry.example.Cookie,

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

     'V-vacuum'      : IceRayPy.core.geometry.volumetric.Vacuum,
     'V-Mist'        : IceRayPy.core.geometry.volumetric.Mist,
     'V-Smoke'       : IceRayPy.core.geometry.volumetric.Smoke,
     'library-1m'    : IceRayPy.library.geometry.OneM,
     'L-Bpair'       : IceRayPy.library.geometry.blobby.Pair
     }
