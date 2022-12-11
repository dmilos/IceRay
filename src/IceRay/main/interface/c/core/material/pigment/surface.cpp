
#include "./surface.h"
#include "./pigment.hpp"

IceRayC_Material_PigmentHandle IceRayC_Material_Pigment_Surface0()
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface  Tf_surface;
  auto Ir_result = new Tf_surface{};
  return cpp2c( Ir_result );
 }

IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Append( IceRayC_Material_PigmentHandle P_this, IceRayC_Material_Pigment_Surfcace_Instruction_Handle P_instruction )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_append( c2cpp( P_instruction ) );
  return 1;
 }
IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Result( IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_result )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_result( P_result  );
  return 1;
 }
IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Lambda( IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_lambda )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_lambda( P_lambda );
  return 1;
 }
IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Point(  IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_point  )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_point( P_point  );
  return 1;
 }
IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Normal( IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_normal )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_normal( P_normal  );
  return 1;
 }


IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Incident( IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_incident )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_incident( P_incident  );
  return 1;
 }

IceRayC_Type_Bool                  IceRayC_Material_Pigment_Surface_Origin(   IceRayC_Material_PigmentHandle P_this, IceRayC_Type_Size P_origin   )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::GC_surface        Tf_surface;

  auto I_this = dynamic_cast< Tf_surface *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_origin( P_origin  );
  return 1;
 }

