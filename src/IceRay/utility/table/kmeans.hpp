#ifndef Dh_DDMRM_Iceray_utility_table_kmeans_HPP_
 #define Dh_DDMRM_Iceray_utility_table_kmeans_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_table::GC_kmeans

#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/math/coord.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_table
        {

         class GC_kmeans
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_int                T_int;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;

             typedef std::vector< T_coord2D > T_table;
             
           public:
             GC_kmeans()
              {
              }
              
           public:
             T_table const& F_table( T_size const& P_count )const;
           private:
             typedef std::vector< T_table > T_vectorS;

             static T_vectorS M2_vectorS;
          };

        }
      }
    }
  }
#endif
