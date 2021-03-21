#ifndef Dh_DDMRM_Iceray_medium__pure_HPP_
 #define Dh_DDMRM_Iceray_medium__pure_HPP_

 // GS_DDMRM::S_IceRay::S_material::S_medium::GC__pure

 #include "IceRay/type/color.hpp"
 #include "IceRay/type/math/coord.hpp"
 #include "IceRay/type/container/jurisdiction.hpp"
 #include "IceRay/geometry/_type/state.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_medium
        {

         class GC__pure
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_type::GT_size                   T_size;
             typedef GS_DDMRM::S_IceRay::S_type::GT_scalar                 T_scalar;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar        T_color;
             typedef GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar    T_gray;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar        T_coord,T_coord3D;
             typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D      T_coord4D;
             typedef GS_DDMRM::S_IceRay::S_geometry::S__type::GC_state      T_state;
             typedef GS_DDMRM::S_IceRay::S_type::S_container::GT_jurisdiction< T_scalar > T_jurisdiction;

           public:
             GC__pure(){ ; }
             virtual ~GC__pure(){ ; }

             /*! Calculate Absorption. Result always exists
              @param P_result,  - result color
              @param P_deplete  - result depletion; black: total deplete, white : no deplete
              @param P_start    - begin point
              @param P_end      - end point
              @param P_state    - state is in start point
             */
             virtual bool Fv_attenuate( T_color & P_result, T_color & P_deplete, T_coord const& P_start, T_coord const& P_end, T_state const& P_state )const
              {
               return false;
               // static T_color Is_black( ::color::constant::black_t{} );
               // static T_color Is_white( ::color::constant::white_t{} );
               //
               // P_result  = Is_black; //!< fog does not exists
               // P_deplete = Is_white; //!< No depletion at all
              }

             virtual void Fv_IOR( T_jurisdiction & P_jurisdiction, T_coord const& P_point )
              {
              }
          };

        }
      }
    }
  }

#endif