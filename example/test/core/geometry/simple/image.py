import IceRayCpp

def make( P_width, P_height ):
    image = IceRayCpp.GraphTypePicture( )
    image.size( IceRayCpp.MathTypeSize2D().load( P_width, P_height ) );
    return { 'this' : image }
