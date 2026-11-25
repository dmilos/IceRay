#include "IceRay/material/compute/operation/expression.hpp"

#include "./handle.hpp"


#define P(D_P) IceRayC_##D_P
#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Operation_##D_P
#define S IceRayC_Type_Size
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle


H F(Expression0)( S P_output, S P_input )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_expression   Tf_this;
  auto Ir_result = new Tf_this{ P_output, P_input };
  return cpp2c( Ir_result );
 }

int F(Expression_Expression)( H P_this, char *P_expression  )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_expression Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_expression( P_expression );
  return 1;
 }

int F(Expression_String2Index)( H P_this, S P_target, char *P_source )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_expression Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_mapper( P_target, P_source );
  return 1;
 }

int F(Expression_Index2Index)( H P_this, S P_target,  S P_source )
 {
  typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_operation::GC_expression Tf_this;

  auto I_this = dynamic_cast< Tf_this *>( c2cpp( P_this ) );
  if( nullptr == I_this )
   {
    return 0;
   }
  I_this->F_mapper( P_target, P_source );
  return 1;
 }
