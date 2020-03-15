#ifndef _DDMM_IceRAY_geometry_hfield_generator_theone_H_
 #define _DDMM_IceRAY_geometry_hfield_generator_theone_H_

//GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_theone

#include "./_pure.hpp"

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

           class GC_theone
            : public GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure T__pure;

               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;

               typedef std::function< T_scalar( T_scalar const&, T_scalar const& )  > T_function;

               GC_theone( )
                :GC_theone( 0.5 )
                {
                }

               GC_theone( T_scalar const& P_level )
                :T__pure( 2, 2 )
                , M2_level( P_level )
                {
                }

             public:
               T_scalar Fv_value( T_size const& P_y, T_size const& P_x )const
                {
                 return M2_level;
                }

               T_scalar Fv_value( T_coord const& P_position )const
                {
                 return M2_level;
                }

             public:  // property scalar  level
                       T_scalar    const& F_level()const{ return M2_level; }
               virtual bool                 F_level( T_scalar const& P_level ){ M2_level = P_level; return bool( true ); }
             protected:
               T_scalar        & F1_level(){ return M2_level; }
             private:
               T_scalar M2_level;
            };

          }
        }
      }
    }
  }

#endif