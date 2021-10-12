#ifndef _DDMM_IceRAY_geometry_complex_blobby_type_heap_H_
 #define _DDMM_IceRAY_geometry_complex_blobby_type_heap_H_

#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/basic/scalar.hpp"

#include "./coefficient.hpp"


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

           class GC_heap
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar            T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size              T_size;
               typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar     T_coord;

               typedef GS_DDMRM::S_IceRay::S_geometry::S_blobby::S_type::GC_coefficient::T_typedef T_coefficient;

               void                 F_push( T_scalar const& P_lambda, T_coefficient const& P_coefficient ){}
               T_size               F_size( ){ return 0; }
               void                 F_pop( ){}
               T_scalar      const& F_topLambda( )const{ return 0; }
               T_coefficient const& F_topCoefficient( )const{ return T_coefficient(); }
            };

          }
        }
      }
    }
  }

#endif

