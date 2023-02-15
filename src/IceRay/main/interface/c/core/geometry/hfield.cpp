

#include "../../type/coord.hpp"
#include "../../type/interval.hpp"
#include "../../type/picture.hpp"

#include "IceRay/geometry/hfield/hfield.hpp"


#include "./handle.h"
#include "./handle.hpp"
#include "./hfield.hpp"

IceRayC_Geometry_HField_Generator_Handle cpp2c( GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Geometry_HField_Generator_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure * c2cpp( IceRayC_Geometry_HField_Generator_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure*> ( P_that );
 }

IceRayC_Geometry_HField_Object_Handle cpp2c( GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure* P_this )
 {
  return reinterpret_cast< IceRayC_Geometry_HField_Object_Handle >( P_this );
 }
GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure * c2cpp( IceRayC_Geometry_HField_Object_Handle P_that )
 {
  return  reinterpret_cast<GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC__pure*> ( P_that );
 }


IceRayC_Geometry_Handle IceRayC_Geometry_HField_System0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::GC_system Tf_hfield;
  auto Ir_result = new Tf_hfield{};
  return cpp2c( Ir_result );
 }

IceRayC_Type_Bool       IceRayC_Geometry_HField_System_Lo( IceRayC_Geometry_Handle P_this, IceRayC_Type_Math_Coord_Scalar3D* P_lo )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::GC_system Tf_hfield;

  auto I_this = dynamic_cast< Tf_hfield *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_box( { c2cpp( *P_lo ), I_this->F_box()[1] } );
  return 1;
 }

IceRayC_Type_Bool       IceRayC_Geometry_HField_System_Hi( IceRayC_Geometry_Handle P_this, IceRayC_Type_Math_Coord_Scalar3D* P_hi )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::GC_system Tf_hfield;

  auto I_this = dynamic_cast< Tf_hfield *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->Fv_box( { I_this->F_box()[0], c2cpp( *P_hi ) } );
  return 1;
 }


IceRayC_Type_Bool       IceRayC_Geometry_HField_System_Generator( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_HField_Generator_Handle P_generator )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::GC_system Tf_hfield;

  auto I_this = dynamic_cast< Tf_hfield *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_generator( c2cpp( P_generator ) );
  return 1;
 }


IceRayC_Type_Bool       IceRayC_Geometry_HField_System_Object(   IceRayC_Geometry_Handle P_this, IceRayC_Geometry_HField_Object_Handle   P_object )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::GC_system Tf_hfield;

  auto I_this = dynamic_cast< Tf_hfield *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_object( c2cpp(P_object) );
  return 1;
 }


int                                      IceRayC_Geometry_HField_Generator_Release( IceRayC_Geometry_HField_Generator_Handle P_this )
 {
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
 }

IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Image0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_image Tf_image;
  auto Ir_result = new Tf_image{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Image1( IceRayC_Type_Picture_Handle P_picture )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_image Tf_image;
  auto Ir_result = new Tf_image{ *c2cpp(P_picture) };
  return cpp2c( Ir_result );
 }

IceRayC_Type_Bool IceRayC_Geometry_HField_Generator_Image_Picture( IceRayC_Geometry_HField_Generator_Handle P_this, IceRayC_Type_Picture_Handle P_picture )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_image Tf_image;

  auto I_this = dynamic_cast< Tf_image *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_picture( *c2cpp(P_picture) );
  return 1;
 }


IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Expression0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_expression Tf_expression;
  auto Ir_result = new Tf_expression{};
  return cpp2c( Ir_result );
 }
IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Expression1( char *P_expression )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_expression Tf_expression;
  auto Ir_result = new Tf_expression{ P_expression };
  return cpp2c( Ir_result );
 }

IceRayC_Type_Bool                        IceRayC_Geometry_HField_Generator_Expression_Pattern( IceRayC_Geometry_HField_Generator_Handle P_this, char *P_expression )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_expression Tf_expression;

  auto I_this = dynamic_cast< Tf_expression *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->F_expression( P_expression )?1:0;
 }

IceRayC_Type_Bool                        IceRayC_Geometry_HField_Generator_Expression_Box( IceRayC_Geometry_HField_Generator_Handle P_this, IceRayC_TypeInterval3D* P_box )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_expression Tf_expression;

  auto I_this = dynamic_cast< Tf_expression *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_box( c2cpp( *P_box ) );
  return 1;
 }

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Table0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_table Tf_table;
  auto Ir_result = new Tf_table{};
  return cpp2c( Ir_result );
 }
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Table1( IceRayC_TypeCoordSize2D* P_size )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_table Tf_table;
  auto Ir_result = new Tf_table{ c2cpp( *P_size ) };
  return cpp2c( Ir_result );
 }
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                        IceRayC_Geometry_HField_Generator_Table_Size( IceRayC_Geometry_HField_Generator_Handle P_this, IceRayC_TypeCoordSize2D* P_size  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_table Tf_table;

  auto I_this = dynamic_cast< Tf_table *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return I_this->Fv_size( c2cpp( *P_size ) )?1:0;
 }
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                        IceRayC_Geometry_HField_Generator_Table_Value( IceRayC_Geometry_HField_Generator_Handle P_this, IceRayC_TypeCoordSize2D* P_size, IceRayC_TypeScalar P_value  )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_table Tf_table;

  auto I_this = dynamic_cast< Tf_table *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  return  I_this->F_set( c2cpp( *P_size ), P_value )? 1 : 0;
 }

int                                    IceRayC_Geometry_HField_Object_Release( IceRayC_Geometry_HField_Object_Handle P_this )
 {
  auto I_this = c2cpp( P_this );
  delete I_this;
  return 1;
 }

IceRayC_Geometry_HField_Object_Handle  IceRayC_Geometry_HField_Object_Flat0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_flat Tf_flat;
  auto Ir_result = new Tf_flat{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_HField_Object_Handle  IceRayC_Geometry_HField_Object_Quad0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_quad Tf_quad;
  auto Ir_result = new Tf_quad{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_HField_Object_Handle  IceRayC_Geometry_HField_Object_Triangle0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_triangle Tf_triangle;
  auto Ir_result = new Tf_triangle{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_HField_Object_Handle  IceRayC_Geometry_HField_Object_Vacuuum0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_vacuum Tf_vacuum;
  auto Ir_result = new Tf_vacuum{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_HField_Object_Handle  IceRayC_Geometry_HField_Object_Geometry0()
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_geometry Tf_geometry;
  auto Ir_result = new Tf_geometry{};
  return cpp2c( Ir_result );
 }

IceRayC_Geometry_HField_Object_Handle    IceRayC_Geometry_HField_Object_Geometry1( IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_geometry Tf_geometry;
  auto Ir_result = new Tf_geometry{ c2cpp(P_child) };
  return cpp2c( Ir_result );
 }

IceRayC_Type_Bool    IceRayC_Geometry_HField_Object_Geometry_Set( IceRayC_Geometry_HField_Object_Handle P_this, IceRayC_Geometry_Handle P_child )
 {
  typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base Tf__base;
  typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_object::GC_geometry Tf_geometry;

  auto I_this = dynamic_cast< Tf_geometry *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_child( c2cpp( P_child ) );
  return 1;
 }



