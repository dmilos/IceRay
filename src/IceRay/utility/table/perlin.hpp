#ifndef Dh_DDMRM_Iceray_utility_table_perlin_HPP_
 #define Dh_DDMRM_Iceray_utility_table_perlin_HPP_

 // GS_DDMRM::S_IceRay::S_utility::S_table::GC_perlin

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

         class GC_perlin
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar    T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;

             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D    T_value;

             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size3D      T_cell;


           public:
             T_value const& operator[]( T_cell const& P_index )const
              {
               return M2_container[ ::math::algorithm::index( F_size(), P_index ) ];
              }
             T_value & operator[]( T_cell const& P_index )
              {
               return M2_container[ ::math::algorithm::index( F_size(), P_index ) ];
              }

           public:
             T_cell const& F_size()const{ return M2_size; }
             bool F_size( T_cell const& P_size )
              {
               std::srand(0);
               M2_size = P_size;
               T_cell I_position{0};
               I_position[ N_dimensionTable-1] = P_size[ N_dimensionTable-1];
               M2_container.resize( ::math::algorithm::index( P_size, I_position ) );
               for( auto & value: M2_container )
                {
                 for( auto & abscissa : value )
                  {
                   abscissa = rand() /(T_scalar)RAND_MAX;
                  }
                }
               return true;
              }
           private:
             T_cell    M2_size;

           public:
             T_structure const& F_structure()const{ return M2_structure; }
             T_structure      & F_structure()     { return M2_structure; }
           private:
             T_container    M2_container;
          };

        }
      }
    }
  }
#endif
