import IceRayCpp

__all__ = []

class Engine:
    M__cargo  = {}

    def __init__( self ):
        self.M__cargo['cargo']={}

        self.M__cargo['engine']  = IceRayCpp.RenderEngine()
        self.M__cargo['scanner'] = IceRayCpp.RenderScannerBlock()
        self.M__cargo['engine'].scanner( self.M__cargo['scanner'] );

        #self.M__cargo['this'] = IceRayCpp.RenderEngine()
        #self.M__cargo['cargo']['scanner'] = IceRayCpp.RenderScannerBlock()
        #self.M__cargo['cargo']['pixel'  ] = IceRayCpp.RenderPixelBasic()
        #self.M__cargo['cargo']['piercer'] = IceRayCpp.RenderPierceBasic()
        #self.M__cargo['cargo']['ray'    ] = IceRayCpp.CoreRenderRayC2A()
        #self.M__cargo['cargo']['camera' ] = IceRayCpp.CameraFlatPerspective()

        self.M__cargo['cargo']['pixel' ] = {}
        #self.M__cargo['cargo']['pixel' ]['strategy'] = IceRayCpp.RenderPixelStrategyCenter()
        self.M__cargo['cargo']['pixel' ]['strategy'] = IceRayCpp.RenderPixelStrategyGrid()
        self.M__cargo['cargo']['pixel' ]['strategy'].size( 12 )
        #self.M__cargo['scanner'].threads(2)

        self.M__cargo['pixel']   = IceRayCpp.RenderPixelBasic()
        self.M__cargo['pixel'].strategy( self.M__cargo['cargo']['pixel' ]['strategy'] )
        self.M__cargo['engine'].pixel( self.M__cargo['pixel'] );

        self.M__cargo['piercer'] = IceRayCpp.RenderPierceBasic()
        self.M__cargo['engine'].pierce( self.M__cargo['piercer'] );

        self.M__cargo['ray']    = IceRayCpp.CoreRenderRayC2A()
        self.M__cargo['ray'].trash( 0.0001 )
        self.M__cargo['ray'].depth( 2 )
        self.M__cargo['piercer'].ray( self.M__cargo['ray'] )
        #self.M__cargo['camera'] = IceRayCpp.CameraFlatPerspective( 1 )
        #self.M__cargo['piercer'].camera( self.M__cargo['camera'] )

    def scannerGet( self ):
        return self.M__cargo['scanner']

    def scanner( self, P_scanner ):
        self.M__cargo['scanner'] = P_scanner
        self.M__cargo['engine'].scanner( self.M__cargo['scanner'] );

    def pixel( self, P_pixel ):
        #self.M__cargo['cargo']['pixel']['this']  = P_pixel['this'];
        #self.M__cargo['cargo']['pixel']['cargo'] = P_pixel['cargo'];

        self.M__cargo['pixel'] = P_pixel
        self.M__cargo['engine'].pixel( self.M__cargo['pixel'] );

    def pixelStrategy( self ):
        return self.M__cargo['cargo']['pixel' ]['strategy']

    def camera( self, P_camera ):
        self.M__cargo['camera'] = P_camera
        self.M__cargo['piercer'].camera( self.M__cargo['camera'] )

    def object( self, P_object ):
        self.M__cargo['ray'].object( P_object )

    def piercer( self ):
        self.M__cargo['engine'].pierce( self.M__cargo['piercer'] );
        self.M__cargo['piercer'].ray( self.M__cargo['ray'] )
        self.M__cargo['piercer'].camera( self.M__cargo['camera'] )

    def start( self,  P_image ):
        self.M__cargo['engine'].start( P_image )

    def work( self ):
        self.M__cargo['engine'].work()

    def progress( self ):
        self.M__cargo['engine'].progress()

    def depth( self, d ):
        self.M__cargo['ray'].depth( d )


