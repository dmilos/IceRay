print( '<' + __name__ + ' file=\'' +   __file__ + '\'>' )
#__all__       = [ "constant", "core", "extension", "library", "system", "type", "utility" ]
#__name__      = "IceRayPy"
__author__    = "I"
__developer__ = "I"
__status__    = "production"
__version__   = "0.0.0.0"
__date__      = "14:58 Sunday, 27 September, 2015"
__revision__  = ""
__build__     = ""
__buildsys__  = ""


# phase One
import IceRayPy.constant

# phase One
import IceRayPy.type

# phase Two
import IceRayPy.type.math.coord
import IceRayPy.type.math.interval
import IceRayPy.type.math.matrix
import IceRayPy.type.math.affine
import IceRayPy.type.math.homography
import IceRayPy.type.color
import IceRayPy.type.graph

# phase One
import IceRayPy.core

# phase Two
import IceRayPy.core.camera.dof

# phase Three
import IceRayPy.utility

print( '</' + __name__ + ' file=\'' +   __file__ + '\'>' )
