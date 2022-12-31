#ifndef Dh_DDMRM_Iceray_material_compute_data_memory__pure__HPP_
 #define Dh_DDMRM_Iceray_material_compute_data_memory__pure__HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory

 #include <vector>
 #include "IceRay/type/basic/basic.hpp"
 #include "../../type/basic/scalar.hpp"
 #include "../../type/color.hpp"
 #include "../../type/math/coord.hpp"
 #include "../../type/math/affine.hpp"
 #include "../../type/basic/integer.hpp"
 #include "../../light/type/spot.hpp"
 #include "../../light/_pure.hpp"
 #include "../../geometry/_pure/_pure.hpp"

 #include "./raw.hpp"

 #include "./memory/constant.hpp"

 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {

         class GC_memory
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__pure T_raw;

              typedef GS_DDMRM::S_IceRay::S_material::S_compute::S_memory::Ee_component T_component;

              template < typename type_type > struct C_type2component{ enum{ En_component = T_component::En__error }; };

              template< typename N_type >
               using T__base = GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC__base<N_type>;

              typedef GS_DDMRM::S_IceRay::S_type::GT_bool               T_bool;
              typedef GS_DDMRM::S_IceRay::S_type::GT_int8               T_int8;
              typedef GS_DDMRM::S_IceRay::S_type::GT_uint8              T_uint8;
              typedef GS_DDMRM::S_IceRay::S_type::GT_integer            T_integer;
              typedef GS_DDMRM::S_IceRay::S_type::GT_size               T_size;
              typedef GS_DDMRM::S_IceRay::S_type::GT_scalar             T_scalar;

              typedef GS_DDMRM::S_IceRay::S_type::S_color::GT_scalar    T_color;

              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D  T_coord2D;
              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D  T_coord3D;
              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D  T_coord4D;

              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_int2D  T_cell2D;
              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_int3D  T_cell3D;
              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_int4D  T_cell4D;

              typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar2D    T_affine2D;
              typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar3D    T_affine3D;
              typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_scalar4D    T_affine4D;


              typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;
              typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_line        T_ray;
              typedef GS_DDMRM::S_IceRay::S_light::GC__pure             T_light;

              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometry_Base    ;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometryNormal   ;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometryIntersect;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometryUVW      ;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometryDistance ;

            public:
              GC_memory();

            public:
              T_size const&  F_size( T_component const& P_component )const
               {
                return M2_memory[ static_cast<T_size>( P_component ) ]->Fv_size();
               }

              void  F_size( T_component const& P_component, T_size const& P_size )
               {
                M2_memory[ static_cast<T_size>( P_component ) ]->Fv_size( P_size );
               }

              template< typename N_type >
               T__base<N_type>   const* F_get()const
                {
                 static const T_component I_component = (T_component) C_type2component< N_type >::En_component;
                 return dynamic_cast< T__base<N_type> const* >( M2_memory[ I_component ] );
                }

              template< typename N_type >
               T__base<N_type>   * F_get()
                {
                 static const T_component I_component = (T_component) C_type2component< N_type >::En_component;
                 return dynamic_cast<T__base<N_type>*> ( M2_memory[ I_component ] );
                }

              T_raw const* F_get( T_component const& P_component )const
               {
                return M2_memory[ static_cast<T_size>( P_component ) ];
               }

              T_raw   * F_get( T_component const& P_component )
               {
                return M2_memory[ static_cast<T_size>( P_component ) ];
               }

              void F_reset( T_component const& P_component )
               {
                M2_memory[ static_cast<T_size>( P_component ) ]->Fv_reset();
               }

              void F_reset( )
               {
                for( auto & I_raw : M2_memory )
                 {
                  I_raw->Fv_reset();
                 }
               }

            private:
              std::vector< T_raw * > M2_memory; //!< unique_ptr<T_raw>
           };

#define IceRay_material_compute_memory_type2component(DP_type, DP_enum) \
           template <  >           \
              struct GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::C_type2component< GS_DDMRM::S_IceRay::S_type::DP_type >  \
              { enum{ En_component = GS_DDMRM::S_IceRay::S_material::S_compute::S_memory::Ee_component::DP_enum }; }

#define IceRay_material_compute_memory_type2componentEx(DP_type, DP_enum) \
           template <  >           \
              struct GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::C_type2component< GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::DP_type >  \
              { enum{ En_component = GS_DDMRM::S_IceRay::S_material::S_compute::S_memory::Ee_component::DP_enum }; }

         IceRay_material_compute_memory_type2component( GT_bool,                En_bool     );
         IceRay_material_compute_memory_type2component( GT_int8,                En_int8     );
         IceRay_material_compute_memory_type2component( GT_uint8,               En_uint8    );
         IceRay_material_compute_memory_type2component( GT_integer,             En_integer  );
         IceRay_material_compute_memory_type2component( GT_size,                En_size     );
         IceRay_material_compute_memory_type2component( GT_scalar,              En_scalar   );
         IceRay_material_compute_memory_type2component( S_color::GT_scalar ,    En_color    );
         IceRay_material_compute_memory_type2component( S_coord::GT_scalar2D ,  En_coord2D  );
         IceRay_material_compute_memory_type2component( S_coord::GT_scalar3D ,  En_coord3D  );
         IceRay_material_compute_memory_type2component( S_coord::GT_scalar4D ,  En_coord4D  );
         IceRay_material_compute_memory_type2component( S_coord::GT_int2D ,     En_cell2D   );
         IceRay_material_compute_memory_type2component( S_coord::GT_int3D ,     En_cell3D   );
         IceRay_material_compute_memory_type2component( S_coord::GT_int4D ,     En_cell4D   );
         IceRay_material_compute_memory_type2component( S_affine::GT_scalar2D , En_affine2D );
         IceRay_material_compute_memory_type2component( S_affine::GT_scalar3D , En_affine3D );
         IceRay_material_compute_memory_type2component( S_affine::GT_scalar4D , En_affine4D );

         IceRay_material_compute_memory_type2component( S_ray::GC_line,         En_ray      );
         IceRay_material_compute_memory_type2componentEx( T_spot ,              En_spot     );
         IceRay_material_compute_memory_type2componentEx( T_light,              En_light    );

        }
      }
    }
  }

#endif
