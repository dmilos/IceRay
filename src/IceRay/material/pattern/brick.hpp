#ifndef Dh_IceRay_material_pattern_brick_hpp_
 #define Dh_IceRay_material_pattern_brick_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::S_typeN::GC__pure<N_number>

#include "./_pure.hpp"

#include "../../type/basic/scalar.hpp"
#include "../../type/color.hpp"
#include "../../type/math/coord.hpp"



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         class GC_brick
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size
          {
           public:
             explicit GC_brick( T_scalar const& P_mortar = T_scalar(0.1) ): M2_mortar( P_mortar )
              {
              }

           public:
            void  Fv_process( T_result &P_result, T_coord const& P_coord )const
             {
              T_coord I_position = P_coord;

              I_position[0] += 0.25*floor( I_position[1] );

              I_position[0] += 0.5*floor( I_position[2] );
              I_position[1] += 0.5*floor( I_position[2] );

              I_position[0] = ::math::function::saw( I_position[0] );
              I_position[1] = ::math::function::saw( I_position[1] );
              I_position[2] = ::math::function::saw( I_position[2] );

              if(    ( I_position[0] < M2_mortar )
                  || ( I_position[1] < M2_mortar )
                  || ( I_position[2] < M2_mortar )
                  )
                  { P_result = 0; return; }
              P_result = 1; return;
             }

           private:
             T_scalar M2_mortar;
          };

        }
      }
    }
  }

#endif
