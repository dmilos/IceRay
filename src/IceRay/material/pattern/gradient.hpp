#ifndef Dh_IceRay_material_pattern_gradient_hpp_
 #define Dh_IceRay_material_pattern_gradient_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_gradient

#include <map>
#include "./_pure.hpp"






 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         class GC_gradient
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__color
          {
           public:
             explicit GC_gradient( )
              {
               //M_map[0] = color::constant::black_t{};
               //M_map[1] = color::constant::white_t{};
               F_bottom( T_coord{ 0, 0, 0 } );
               F_top( T_coord{ 0, 0, 1 } );
              }

            bool F_set( T_scalar const P_position, T_color const& P_value )
              {
               T_scalar I_epsilon = 1e-5;
               for( auto & item : M_map )
                {
                 if( fabs( item.first - P_position ) < I_epsilon )
                  {
                   item.second = P_value;
                   return true;
                  }
                }
               M_map[P_position] = P_value;
               return true;
              }

            bool F_bottom( T_coord const P_bottom )
              {
               M_bottom = P_bottom;
               ::math::linear::vector::subtraction( M2_direction, M_top, M_bottom );
               T_scalar I_scale = ::math::linear::vector::dot( M2_direction, M2_direction );
               ::math::linear::vector::scale( M2_direction, T_scalar(1)/I_scale );
               return true;
              }
            bool F_top( T_coord const P_top )
              {
               M_top = P_top;
               ::math::linear::vector::subtraction( M2_direction, M_top, M_bottom );
               T_scalar I_scale = ::math::linear::vector::dot( M2_direction, M2_direction );
               ::math::linear::vector::scale( M2_direction, T_scalar(1)/I_scale );
               return true;
              }

           public:
             void  Fv_process( T_result &P_result, T_coord const& P_coord )const
              {
               T_coord I_point; ::math::linear::vector::subtraction( I_point, P_coord, M_bottom );
               T_scalar I_value = ::math::linear::vector::dot( I_point, M2_direction );

               if( I_value < M_map.begin()->first ) { P_result = M_map.begin()->second; return; }
               if( M_map.rbegin()->first < I_value ) { P_result = M_map.rbegin()->second; return; }
               auto upper = M_map.upper_bound( I_value );
               auto lower = std::prev( upper );

               auto t = math::function::to_one( I_value, lower->first, upper->first );
               P_result = lower->second + t*( upper->second - lower->second );
              }
           public:
             std::map<T_scalar,T_color> M_map;
             T_coord M_bottom, M_top;
           private:
             T_coord M2_direction;
          };

        }
      }
    }
  }

#endif
