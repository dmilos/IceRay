import IceRayCpp
from IceRayCpp import *


import object
import surface

def light():

    point = IceRayCpp.LightPoint()
    point.spot( IceRayCpp.LightTypeSpot() )
    point.center( IceRayCpp.MathTypeCoord3D().load(0,0,0.9) )
    return { 'this': point }

explode = 0.2


def push( parent, name, child ):
    parent['this'].push( child['this'] )
    parent[name] = child


def make( ):

    objectCeil_cargo  = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load(0.5,0.5,0.5) ), GeometrySimpleBox( MathTypeCoord3D().load( -(1 - explode), -(1 - explode),  1   ), MathTypeCoord3D().load( 1 - explode, (1 - explode),  1.1 ) ) )
    objectFloor_cargo = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load(0.25,0.25,0.25) ), GeometrySimpleBox( MathTypeCoord3D().load( -(1 - explode), -(1 - explode), -1.1 ), MathTypeCoord3D().load( 1 - explode, (1 - explode), -1   ) ) )
    objectEast_cargo  = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load(0.5,1,0.5) ), GeometrySimpleBox( MathTypeCoord3D().load( -(1 - explode),  1  , -(1 - explode) ), MathTypeCoord3D().load(  1 - explode,  1.1 , (1 - explode) ) ) )
    objectWest_cargo  = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load(0,1,0) ), GeometrySimpleBox( MathTypeCoord3D().load( -(1 - explode), -1.1, -(1 - explode) ), MathTypeCoord3D().load(  1 - explode, -1   , (1 - explode) ) ) )
    objectNorth_cargo = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load(0.5,0.5,1) ), GeometrySimpleBox( MathTypeCoord3D().load(  1  , -(1 - explode)  , -(1 - explode) ), MathTypeCoord3D().load(  1.1, (1 - explode), (1 - explode) ) ) )
    objectSouth_cargo = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load(0,0,1) ), GeometrySimpleBox( MathTypeCoord3D().load( -1.1, -(1 - explode)  , -(1 - explode) ), MathTypeCoord3D().load( -1  , (1 - explode), (1 - explode) ) ) )

    objectMarkpZ_cargo = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load( 0, 0, 1 ) ), GeometrySimpleSphere( MathTypeCoord3D().load( 0, 0, 1 ), 0.1 ) )
    objectMarkmZ_cargo = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load( 0, 0, 1 ) ), GeometrySimpleSphere( MathTypeCoord3D().load( 0, 0,-1 ), 0.1 ) )
    objectMarkpY_cargo = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load( 0, 1, 0 ) ), GeometrySimpleSphere( MathTypeCoord3D().load( 0, 1, 0 ), 0.1 ) )
    objectMarkmY_cargo = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load( 0, 1, 0 ) ), GeometrySimpleSphere( MathTypeCoord3D().load( 0,-1, 0 ), 0.1 ) )
    objectMarkpX_cargo = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load( 1, 0, 0 ) ), GeometrySimpleSphere( MathTypeCoord3D().load( 1, 0, 0 ), 0.1 ) )
    objectMarkmX_cargo = object.make( surface.make_lambert( light(), GraphTypeColorRGB().load( 1, 0, 0 ) ), GeometrySimpleSphere( MathTypeCoord3D().load(-1, 0, 0 ), 0.1 ) )

    geometry_cargo={}
    geometry_cargo['this'] = GeometryRTSSGeometry( )
    geometry_cargo['list'] = GeometryRTSSList()
    geometry_cargo['this'].rtss( geometry_cargo['list'] )

    push( geometry_cargo, 'ceil',  objectCeil_cargo  )
    push( geometry_cargo, 'floor', objectFloor_cargo )
    push( geometry_cargo, 'east',  objectEast_cargo  )
    push( geometry_cargo, 'west',  objectWest_cargo  )
    push( geometry_cargo, 'north', objectNorth_cargo )
    push( geometry_cargo, 'south', objectSouth_cargo )

    push( geometry_cargo, 'sph-pZ', objectMarkpZ_cargo )
    push( geometry_cargo, 'sph-mZ', objectMarkmZ_cargo )
    push( geometry_cargo, 'sph-pY', objectMarkpY_cargo )
    push( geometry_cargo, 'sph-mY', objectMarkmY_cargo )
    push( geometry_cargo, 'sph-pX', objectMarkpX_cargo )
    push( geometry_cargo, 'sph-mX', objectMarkmX_cargo )


    object_cargo = IceRayCpp.CoreObject()
    object_cargo.geometry( geometry_cargo['this'] )

    return { 'this': object_cargo, 'geometry': geometry_cargo }


