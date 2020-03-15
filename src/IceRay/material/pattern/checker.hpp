#ifndef Dh_IceRay_material_pattern_checker_hpp_
 #define Dh_IceRay_material_pattern_checker_hpp_

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

         class GC_checker
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__size
          { // DONE
           public:
             GC_checker()
              {
              }

           public:
            void  Fv_process( T_result &P_result, T_coord const& P_coord )const
             {
              bool who = true;

              T_scalar I_value;

              I_value = P_coord[0]; if( I_value < 0.0 ){ I_value = 1.0-I_value; } if( ( (int)I_value ) % 2) who = ! who;
              I_value = P_coord[1]; if( I_value < 0.0 ){ I_value = 1.0-I_value; } if( ( (int)I_value ) % 2) who = ! who;
              I_value = P_coord[2]; if( I_value < 0.0 ){ I_value = 1.0-I_value; } if( ( (int)I_value ) % 2) who = ! who;

              switch( who )
               {
                case( false ):  P_result = 0;  break;
                case(  true ):  P_result = 1;  break;
               }

             }

          };

        }
      }
    }
  }

#endif
