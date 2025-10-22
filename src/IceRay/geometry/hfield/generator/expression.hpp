#ifndef _DDMM_IceRAY_geometry_hfield_generator_expression_H_
 #define _DDMM_IceRAY_geometry_hfield_generator_expression_H_

#include "./_pure.hpp"
#include "IceRay/type/basic/string.hpp"
#include "IceRay/type/math/interval.hpp"
#include "IceRay/utility/expression/expression.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_hfield
        {
         namespace S_generator
          {

           class GC_expression
            : public GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure T__pure;
               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_program   T_program;
               typedef GS_DDMRM::S_IceRay::S_utility::S_expression::GC_memory    T_memory;

             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_size     T_size;
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar   T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::GT_string   T_string;
               typedef GS_DDMRM::S_IceRay::S_type::S_interval::GT_scalar3D         T_box, T_interval;

             public:
               explicit GC_expression( T_string const& P_expression = "z-0.5");

             public:
               T_scalar Fv_value( T_size const& P_x, T_size const& P_y )const;
               T_scalar Fv_value( T_size2D const& P_position )const;

              public:  // property expression  expression
                       T_box    const& F_box()const{ return M2_box; }
               virtual bool            F_box( T_box const& P_box ){ M2_box = P_box; return bool( true ); }
             protected:
               T_box        & F1_box(){ return M2_box; }
             private:
               T_box M2_box;

             public:  // property expression  expression
                       T_string    const& F_expression()const{ return M2_expression; }
               virtual bool               F_expression( T_string const& P_expression ){ M2_expression = P_expression; return bool( true ); }
             protected:
               T_string        & F1_expression(){ return M2_expression; }
             private:
               T_string M2_expression;
               static T_string Fs_one();
             private:
               T_program M2_program;
               T_memory  M2_memory;
            };

          }
        }
      }
    }
  }

#endif