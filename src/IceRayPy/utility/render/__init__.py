#print( '<' + __name__ + ' name=\'' +   __file__ + '\'>' )

import IceRayPy

class Manager:
    def __init__( self, P_dll, P_config = None ):

        self.m_cargo = {}
        self.m_cargo['dll'] = P_dll

        self.m_cargo['pierce'] = IceRayPy.core.render.pierce.Projector( P_dll )
        self.m_cargo['pierce'].camera( IceRayPy.core.camera.flat.Perspective( P_dll ) )

        self.m_cargo['tracer'] = IceRayPy.core.render.ray.Trace( P_dll )
        self.m_cargo['tracer'].depth( 20 )
        self.m_cargo['tracer'].trash( 0.001 )
        self.m_cargo['tracer'].next( 18 )

        self.m_cargo['manager'] = IceRayPy.core.render.manager.TheOne(  P_dll  )

        self.m_cargo['manager'].scanner( IceRayPy.core.render.scanner.Block( P_dll ) )

        self.m_cargo['manager'].pixel( IceRayPy.core.render.pixel.Basic( P_dll ) )
        if( None != P_config ) and ( 'pixel' in P_config )and ( 'type' in P_config['pixel'] ):
            strategy = None
            if( 'random' == P_config['pixel']['type'] ):
                strategy =  IceRayPy.core.render.pixel.strategy.Random( P_dll );
            if( 'sobol' == P_config['pixel']['type'] ):
                strategy =  IceRayPy.core.render.pixel.strategy.Sobol( P_dll );
            if( 'center' == P_config['pixel']['type'] ):
                strategy =  IceRayPy.core.render.pixel.strategy.Center( P_dll );
            if( 'grid' == P_config['pixel']['type'] ):
                strategy =  IceRayPy.core.render.pixel.strategy.Grid( P_dll );

            if( 'size' in  P_config['pixel'] ) and hasattr( strategy, 'size' ):
                strategy.size( P_config['pixel']['size'] )

            if( None != strategy ):
                self.m_cargo['manager'].pixelGet().strategy( strategy )

        self.m_cargo['manager'].pierce( self.m_cargo['pierce'] )
        self.m_cargo['manager'].sheaf( IceRayPy.core.render.sheaf.ALL( P_dll ) )
        self.m_cargo['manager'].ray( self.m_cargo['tracer'] )

    def __del__( self ):
        self.m_cargo = {}

    def default( self ):
        pass

    def camera( self, P_camera ):
        self.m_cargo['projector'].camera( P_camera )

    def window( self, P_o, P_hi ):
        self.m_cargo['manager'].scannerGet().window( P_o, P_hi )

    def hot( self, P_hot ):
        self.m_cargo['manager'].scannerGet().hot( P_hot )

    def tracer( self ): #tracer get
        return self.m_cargo['tracer']

    def camera( self, P_camera ):
        self.m_cargo['pierce'].camera( P_camera )

    def object( self, P_object ):
        self.m_cargo['tracer'].object( P_object )

    def start( self, P_image ):
        self.m_cargo['manager'].start( P_image )



#print( '</' + __name__ + ' name=\'' +   __file__ + '>' )
