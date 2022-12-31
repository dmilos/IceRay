#ifndef Dh_DDMRM_Iceray_utility_table_structure_HPP_
 #define Dh_DDMRM_Iceray_utility_table_structure_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_table::GC_structure

#include "IceRay/type/basic/size.hpp"
#include "IceRay/type/math/coord.hpp"
#include <fstream>
#include <string>
#include <algorithm>

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_table
        {

         class GC_structure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;

           public:
             typedef std::vector<T_size>  T_sizeContainer;
             typedef std::vector<T_scalar>  T_radiusContainer;
             typedef std::vector<T_coord2D>  T_pointContainer;

           public:
             void F_compile();
             void F_clear();

           public:
             T_sizeContainer const& F_size()const{ return M2_size; }
           private:
             T_sizeContainer    M2_size;
           public:
             T_radiusContainer const& F_radius()const{ return M2_radius; }
           private:
             T_radiusContainer  M2_radius;
           public:
             T_pointContainer const& F_spot()const{ return M2_point; }
             T_pointContainer      & F_spot()     { return M2_point; }
           private:
             T_pointContainer M2_point;
          };

        }
      }
    }
  }

#endif
