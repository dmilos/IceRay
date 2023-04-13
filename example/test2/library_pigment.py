#!/usr/bin/env python3

print( '<' + __name__ + ' file=\'' +   __file__ + '\'>' )

import IceRayPy

list = {
      'constant'                 : IceRayPy.utility.material.pattern.Constant,
       #TODO NYI 'surface'       : core.material.pigment.Surface,

      'P-noise-cells'      : IceRayPy.utility.material.pattern.noise.Cells,
      'P-noise-crackle'    : IceRayPy.utility.material.pattern.noise.Crackle,
      'P-noise-perlin'     : IceRayPy.utility.material.pattern.noise.Perlin,
      'P-noise-congruent1d'  : IceRayPy.utility.material.pattern.noise.Congruent1D,
      'P-noise-congruent3d'  : IceRayPy.utility.material.pattern.noise.Congruent3D,
      'P-noise-random'     : IceRayPy.utility.material.pattern.noise.Random,
      'P-noise-value'      : IceRayPy.utility.material.pattern.noise.Value,
      'P-noise-vdc'        : IceRayPy.utility.material.pattern.noise.VDC,
      'P-image'            : IceRayPy.utility.material.pattern.Image,
      'P-brick'            : IceRayPy.utility.material.pattern.Brick,
      'P-checker'          : IceRayPy.utility.material.pattern.Checker,
      'P-hexagon'          : IceRayPy.utility.material.pattern.Hexagon,
      'P-onion'            : IceRayPy.utility.material.pattern.Onion, #TODO check
      'P-level'            : IceRayPy.utility.material.pattern.Level, #TODO check
      'P-gradientBW'       : IceRayPy.utility.material.pattern.Gradient,

      'I-ALP'           : IceRayPy.utility.material.illumination.Alp,       # OK OK
      'I-ambient'       : IceRayPy.utility.material.illumination.Ambient,   # OK OK TODO align with ALP
      'I-AsDiffuse'     : IceRayPy.utility.material.illumination.AsDiffuse, # OK OK TODO align with ALP
      'I-AsSpecular'    : IceRayPy.utility.material.illumination.AsSpecular,# OK OK TODO align with ALP
      'I-AS'            : IceRayPy.utility.material.illumination.AshikminShirley,# OK OK TODO align with ALP
      'I-beckmann-iso'  : IceRayPy.utility.material.illumination.Beckmann_Isotropic,  # OK Check again  TODO problem on terminator
      #'I-beckmann-ani'  : IceRayPy.utility.material.illumination.Beckmann_Anisotropic,  # OK Check again  TODO problem on terminator
      #'I-TR-iso'        : IceRayPy.utility.material.illumination.TrowbridgeReitz_Isotropic,  # TODO
      'I-TR-ani'        : IceRayPy.utility.material.illumination.TrowbridgeReitz_Anisotropic,  # TODO
      'I-Blinn'         : IceRayPy.utility.material.illumination.Blinn,     # OK OK TODO fix color TODO problem on terminator
      'I-Burley-diff'   : IceRayPy.utility.material.illumination.Burley_Diffuse,
      'I-Burley-spec'    : IceRayPy.utility.material.illumination.Burley_Specular,
      'I-gaussian'      : IceRayPy.utility.material.illumination.Gaussian,  # OK OK TODO problem on terminator
      'I-HsLambert'     : IceRayPy.utility.material.illumination.HsLambert, # OK OK TODO align with Alp
      'I-HsPhong'       : IceRayPy.utility.material.illumination.HsPhong,   # OK OK TODO align with Alp
      'I-Lambert'       : IceRayPy.utility.material.illumination.Lambert,   #OK OK  TODO align with ALP
      'I-ONf29'         : IceRayPy.utility.material.illumination.ON_f29,       # TODO in progress
      'I-ONf30'         : IceRayPy.utility.material.illumination.ON_f30,        # TODO in progress
      'I-ONYFP'         : IceRayPy.utility.material.illumination.ON_Fujii_Proposed,     # OK OK TODO align with Alp
      'I-ONYFQ'         : IceRayPy.utility.material.illumination.ON_Fujii_Qualitative,  # OK OK TODO align with ALP
      'I-ONJvO'         : IceRayPy.utility.material.illumination.ON_Ouwerkerk,  # OK OK TODO align with ???
      'I-Phong'         : IceRayPy.utility.material.illumination.Phong,         # OK OK TODO align with ALP
      'I-WardApprox'    : IceRayPy.utility.material.illumination.WardApprox,    # OK OK TODO align with ALP
      'I-WardIsotropic' : IceRayPy.utility.material.illumination.WardIsotropic, # OK OK TODO align with ALP
      'I-WardReal'      : IceRayPy.utility.material.illumination.WardReal,      # OK OK TODO align with ALP
      'I-CT'            : IceRayPy.utility.material.illumination.CookTorrance, # OK OK TODO align with ALP

      'M-o-ID'                     : IceRayPy.utility.material.operation.mapping.Identity3D,
      'M-o-translate'              : IceRayPy.utility.material.operation.mapping.Translate3D,
      'M-o-affine'                 : IceRayPy.utility.material.operation.mapping.Affine3D,
      'M-o-homography'             : IceRayPy.utility.material.operation.mapping.Homography3D,
      'M-o-Cartesian2Cylindric'    : IceRayPy.utility.material.operation.mapping.Cartesian2Cylindric,  #TODO check
      'M-o-Cartesian2Package'      : IceRayPy.utility.material.operation.mapping.Cartesian2Package,    #TODO check
      'M-o-Cartesian2Spherical'    : IceRayPy.utility.material.operation.mapping.Cartesian2Spherical,  #TODO check
      'M-o-Cartesian2Torus'        : IceRayPy.utility.material.operation.mapping.Cartesian2Torus,      #TODO check
      'M-o-Cartesian2Tablecloth'   : IceRayPy.utility.material.operation.mapping.Cartesian2Tablecloth, #TODO check
      'M-o-Cartesian2WoodX'        : IceRayPy.utility.material.operation.mapping.Cartesian2WoodX,      #TODO check
      'M-o-Cartesian2WoodY'        : IceRayPy.utility.material.operation.mapping.Cartesian2WoodY,      #TODO check
      'M-o-Cartesian2WoodZ'        : IceRayPy.utility.material.operation.mapping.Cartesian2WoodZ,      #TODO check
      'M-o-Cylindric2Cartesian'    : IceRayPy.utility.material.operation.mapping.Cylindric2Cartesian,  #TODO check
      'M-o-Cylindric2Spherical'    : IceRayPy.utility.material.operation.mapping.Cylindric2Spherical,  #TODO check
      'M-o-Spherical2Cartesian'    : IceRayPy.utility.material.operation.mapping.Spherical2Cartesian,  #TODO check
      'M-o-Spherical2Cylindric'    : IceRayPy.utility.material.operation.mapping.Spherical2Cylindric,  #TODO check
      'M-o-Euclid2Max'             : IceRayPy.utility.material.operation.mapping.Euclid2Max,           #TODO check
      'M-o-Max2Euclid'             : IceRayPy.utility.material.operation.mapping.Max2Euclid,           #TODO check
      'M-o-Cartesian2Fisheye'      : IceRayPy.utility.material.operation.mapping.Cartesian2Fisheye,    #TODO check

     'T-0-reflect-One'               : IceRayPy.utility.material.transmission.reflect.One,      #OK
     'T-0-reflect-mirror'            : IceRayPy.utility.material.transmission.reflect.Mirror,      #OK
     'T-1-reflect-schlick'           : IceRayPy.utility.material.transmission.reflect.Schlick,  #OK
     'T-2-reflect-blossom-Grid'      : IceRayPy.utility.material.transmission.blossom.Grid,     #TODO edge bug
     'T-3-reflect-blossom-Hexagon'   : IceRayPy.utility.material.transmission.blossom.Hexagon,  #CHECK
     'T-4-reflect-blossom-trg'       : IceRayPy.utility.material.transmission.blossom.Triangle, #OK
     'T-5-reflect-blossom-LD'        : IceRayPy.utility.material.transmission.blossom.LD,       #Experimental
    #'T-5-reflect-blossom-Pinwheel' : IceRayPy.utility.material.transmission.blossom.Pinwheel, #TODO
    #'T-5-reflect-blossom-penrose'  : IceRayPy.utility.material.transmission.blossom.Penrose, #TODO
     'T-6-reflect-blossom-Rand'      : IceRayPy.utility.material.transmission.blossom.Random,   #OK
     'T-7-reflect-blossom-sobol'     : IceRayPy.utility.material.transmission.blossom.Sobol, #OK
     'T-8-reflect-blossom-VDC'       : IceRayPy.utility.material.transmission.blossom.VDC,      #OK
     'T-8-reflect-blossom-congruent' : IceRayPy.utility.material.transmission.blossom.Congruent,      #OK
     'T-8-reflect-blossom-sunflower' : IceRayPy.utility.material.transmission.blossom.Sunflower,      #OK
     'T-9-refract-fresnel'           : IceRayPy.utility.material.transmission.refract.Fresnel,  #OK
     'T-A-refract-Snell'             : IceRayPy.utility.material.transmission.refract.Snell,    #OK
     'T-B-refract-schlick'           : IceRayPy.utility.material.transmission.refract.Schlick,  #OK

     'X-Coord3D2Color'               : IceRayPy.utility.material.operation.Coord3D2Color,  #OK
}

print( '</' + __name__ + ' file=\'' +   __file__ + '\'>' )
