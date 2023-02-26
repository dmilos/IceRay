#ifndef Dh_DDMRM_Iceray_utility_table_LD_HPP_
 #define Dh_DDMRM_Iceray_utility_table_LD_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_table::GC_LD

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

         class GC_LD
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_int                T_int;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;

             typedef std::vector< T_coord2D > T_container; 
             typedef std::vector< T_scalar > T_number; 
           public:
             GC_LD(  );

           public:
             bool F_init( T_size const& P_size ) ;

           public:
             T_container const& F_container()const{ return M2_container; }
             T_container      & F_container()     { return M2_container; }
           private:
             T_container    M2_container;
           private:
             T_number    M2_number;
          };

        }
      }
    }
  }
#endif
