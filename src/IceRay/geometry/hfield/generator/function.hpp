#ifndef _DDMM_IceRAY_geometry_hfield_generator_func_H_
 #define _DDMM_IceRAY_geometry_hfield_generator_func_H_

#include "./_pure.hpp"
#include <functional>

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_geometry
      {
       namespace S_hfield
        {
         namespace S_generator
          {

           class GC_function
            : public GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure T__pure;

             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;

             public:
               typedef std::function< T_scalar( T_scalar const&, T_scalar const& )  > T_function;

             public:
               GC_function( );
               GC_function( T_function const& P_function, T_size const& P_x, T_size const& P_y );

             public:
               T_scalar Fv_value( T_size const& P_y, T_size const& P_x )const;
               T_scalar Fv_value( T_coord const& P_position )const;

             public:  // property function  function
                       T_function    const& F_function()const{ return M2_function; }
               virtual bool                 F_function( T_function const& P_function ){ M2_function = P_function; return bool( true ); }
             protected:
               T_function        & F1_function(){ return M2_function; }
             private:
               T_function M2_function;
               static T_function Fs_one();
            };

          }
        }
      }
    }
  }

#endif