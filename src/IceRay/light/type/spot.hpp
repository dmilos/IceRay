#ifndef Dh_DDMRM_IceRay_LIGHT_spot_H_
 #define Dh_DDMRM_IceRay_LIGHT_spot_H_
// GS_DDMRM::S_IceRay::S_light::S_type::GC_spot

 #include "../../type/basic/report.hpp"
 #include "../../type/math/coord.hpp"
 #include "../../type/color.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {
       namespace S_type
        {

         class GC_spot
          {
           public:


             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar               T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar      T_coord;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar      T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar  T_gray;

             GC_spot( )
              :M2_shadow( true )
              ,M2_center( ::math::linear::vector::fill( T_coord{}, 0 ) )
              ,M2_0( T_gray( { T_scalar(1) } ) )
              ,M2_1( T_gray( { T_scalar(0) } ) )
              ,M2_2( T_gray( { T_scalar(0) } ) )
              {
              }

             explicit GC_spot( T_coord const & P_center )
              :M2_shadow( true )
              ,M2_center( P_center )
              ,M2_0( T_gray( { T_scalar(1) } ) )
              ,M2_1( T_gray( { T_scalar(0) } ) )
              ,M2_2( T_gray( { T_scalar(0) } ) )
              {
              }

             GC_spot( T_coord const & P_center, T_color const& P_0, T_color const& P_1, T_color const& P_2 )
              :M2_shadow( true )
              ,M2_center( P_center )
              ,M2_0( P_0 )
              ,M2_1( P_1 )
              ,M2_2( P_2 )
              {
              }

           public:
              void F_energy( T_color & P_color, T_coord const& P_point )const
               {

                T_scalar I_distance = ::math::linear::vector::distance( P_point, F_center() );
              //P_color = M2_0 + ( M2_1 + M2_2 / I_distance ) / I_distance;
                P_color = M2_2 / I_distance;
                P_color += M2_1;
                P_color /= I_distance;
                P_color += M2_0;
               }

           public:
             bool const& F_shadow()const{ return M2_shadow; }
             bool        F_shadow( bool const&  P_shadow ){ M2_shadow = P_shadow; return bool( true ); }
           private:
             bool M2_shadow;

           public:
             T_coord const& F_center()const{ return M2_center; }
             T_coord      & F_center(){ return M2_center; }
             bool           F_center( T_coord const& P_center ){ M2_center = P_center; return bool( true ); }
           private:
             T_coord  M2_center;

           public:
             T_color const& F_0()const{ return M2_0; }
             T_color      & F_0()     { return M2_0; }
             bool           F_0( T_color const& P_0 ){ M2_0 = P_0; return bool( true ); }
           private:
             T_color  M2_0;

           public:
             T_color const& F_1()const{ return M2_1; }
             T_color      & F_1()     { return M2_1; }
             bool           F_1( T_color const& P_1 ){ M2_1 = P_1; return bool( true ); }
           private:
             T_color  M2_1;

           public:
             T_color const& F_2()const{ return M2_2; }
             T_color      & F_2()     { return M2_2; }
             bool           F_2( T_color const& P_2 ){ M2_2 = P_2; return bool( true ); }
           private:
             T_color  M2_2;
          };

        }
      }
    }
  }

#endif
