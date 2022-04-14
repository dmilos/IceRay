#ifndef Dh_DDMRM_Iceray_utility_convert_HPP_
 #define Dh_DDMRM_Iceray_utility_convert_HPP_

//  GS_DDMRM::S_IceRay::S_utility::S_convert::GC_color2scalar
//  GS_DDMRM::S_IceRay::S_utility::S_convert::GC_scalar2color
//  GS_DDMRM::S_IceRay::S_utility::S_convert::GC_scalar2coord<dimension>
//  GS_DDMRM::S_IceRay::S_utility::S_convert::GC_color2coord<dimension>
//  GS_DDMRM::S_IceRay::S_utility::S_convert::GC_coord2color<dimension>

 #include "IceRay/type/basic/basic.hpp"
 #include "IceRay/type/color.hpp"
 #include "IceRay/type/math/coord.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_utility
      {
       namespace S_convert
        {

         template < typename N_result, typename N_input >
          struct GC_direct
           {
            typedef N_result  T_result;
            typedef N_input T_input, T_first;

            T_result operator()(  T_input const& P_input )const
             {
              return static_cast<T_result>( P_input );
             }
           };

         struct GC_color2bool
          {
           typedef GS_DDMRM::S_IceRay::S_type::GT_bool  T_result;
           typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar T_input, T_first;

           T_result operator()( T_input const& P_input )const
            {
             typedef GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar T_gray;

             return P_input != ::color::constant::black_t{};
            }
          };

         struct GC_bool2color
          {
           typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar  T_result; 
           typedef GS_DDMRM::S_IceRay::S_type::GT_bool  T_input, T_first;

           T_result operator()( T_input const& P_input )const
            {
             return P_input ? T_result( ::color::constant::white_t{} ) : T_result( ::color::constant::black_t{} );
            }
          };

         struct GC_color2scalar
          {
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar  T_result;
           typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar T_input, T_first;

           T_result operator()(  T_input const& P_input )const
            {
             typedef GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar T_gray;
             T_gray I_gray { P_input };
             T_result I_result = I_gray.get<0>();
             return I_result;
            }
          };

         struct GC_scalar2color
          {
           typedef GS_DDMRM::S_IceRay::S_type::GT_scalar  T_input;
           typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar T_result , T_first;

           T_result operator()(  T_input const& P_input )const
            {
             typedef GS_DDMRM::S_IceRay::S_type::S_color::S_gray::GT_scalar T_gray;
             T_gray I_gray{{P_input}};
             T_result I_result{ I_gray };
             return I_result;
            }
          };

        //template< unsigned dimension_number >
        // struct GC_scalar2coord
        //  {
        //   typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar  T_input;
        //   // typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalarND<dimension_number> T_result , T_first;
        //
        //   T_result operator()(  T_input const& P_input )const
        //    {
        //     T_result I_result;// = ::math::linear::vector::fill( I_result, P_input );
        //     return I_result;
        //    }
        //  };

         struct GC_color2coord
          {
           typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar  T_input;
           typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar  T_result , T_first;

           T_result operator()(  T_input const& P_input )const
            {
             T_result I_result;
             I_result[0] = P_input[0];
             I_result[1] = P_input[1];
             I_result[2] = P_input[2];
             return I_result;
            }
          };

        struct GC_coord2color
         {
          typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar  T_input;
          typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar T_result , T_first;

          T_result operator()(  T_input const& P_input )const
           {
             T_result I_result;
             I_result[0] = fabs( P_input[0] );
             I_result[1] = fabs( P_input[1] );
             I_result[2] = fabs( P_input[2] );
             return I_result;
           }
         };

        }
      }
    }
  }

#endif
