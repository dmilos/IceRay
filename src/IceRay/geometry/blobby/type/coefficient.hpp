#ifndef _DDMM_IceRAY_geometry_complex_blobby_type_coefficient_H_
 #define _DDMM_IceRAY_geometry_complex_blobby_type_coefficient_H_

#include "../../../type/basic/scalar.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_blobby
        {
         namespace S_type
          {

           struct GC_coefficient
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar            T_scalar;

               typedef std::array<T_scalar,5>                           T_typedef;

               static void Fs_reset( T_typedef & P_result )
                {
                 P_result[0] = T_scalar( 0 );
                 P_result[1] = T_scalar( 0 );
                 P_result[2] = T_scalar( 0 );
                 P_result[3] = T_scalar( 0 );
                 P_result[4] = T_scalar( 0 );
                }

               static void Fs_invert( T_typedef & P_result )
                {
                 P_result[0] = -P_result[0];
                 P_result[1] = -P_result[1];
                 P_result[2] = -P_result[2];
                 P_result[3] = -P_result[3];
                 P_result[4] = -P_result[4];
                }

               static void Fs_accumulate( T_typedef & P_result, T_typedef const& P_left )
                {
                 P_result[0] += P_left[0];
                 P_result[1] += P_left[1];
                 P_result[2] += P_left[2];
                 P_result[3] += P_left[3];
                 P_result[4] += P_left[4];
                }
            };

          }
        }
      }
    }
  }

#endif

