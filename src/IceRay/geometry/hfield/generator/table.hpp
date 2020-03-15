#ifndef _DDMM_IceRAY_geometry_hfield_generator_table_H_
 #define _DDMM_IceRAY_geometry_hfield_generator_table_H_

// GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC_table


#include <vector>

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

           class GC_table
            : public GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure
            {
             public:
               typedef GS_DDMRM::S_IceRay::S_geometry::S_hfield::S_generator::GC__pure T__pure;

             public:
               typedef GS_DDMRM::S_IceRay::S_type::GT_scalar T_scalar;
               typedef GS_DDMRM::S_IceRay::S_type::GT_size   T_size;

             public:
               typedef std::vector< T_scalar> T_raw;
               typedef std::vector< T_raw> T_field;

             public:
                        GC_table( );
               explicit GC_table( T_field const& P_field );
             public:
               T_scalar Fv_value( T_size const& P_y, T_size const& P_x )const;
               T_scalar Fv_value( T_coord const& P_position )const;

             public:  // property field  field
                       T_field    const& F_field()const{ return M2_field; }
                       bool              F_field( T_field const& P_field ){ M2_field = P_field; return bool( true ); }
             protected:
               T_field        & F1_field(){ return M2_field; }
             private:
               T_field M2_field;
            };

          }
        }
      }
    }
  }

#endif