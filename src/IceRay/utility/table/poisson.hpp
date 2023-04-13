#ifndef Dh_DDMRM_Iceray_utility_table_poisson_HPP_
 #define Dh_DDMRM_Iceray_utility_table_poisson_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_table::GC_poisson

#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/math/coord.hpp"

#include "./structure.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_table
        {

         class GC_poisson
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_int                T_int;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;

             typedef GS_DDMRM::S_IceRay::S_utility::S_table::GC_structure  T_structure;
           public:
             explicit GC_poisson( T_size const& P_size = 15 )
              {
               F_init( P_size );
              }
           public:
             bool F_init( T_size const& P_size );

           public:
             T_structure const& F_structure()const{ return M2_structure; }
             T_structure      & F_structure()     { return M2_structure; }
           private:
             T_structure    M2_structure;
          };

        }
      }
    }
  }
#endif
