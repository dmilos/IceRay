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
              enum Ee_component
               {
                En__error = 100,
                En__begin = 0,

                En_bool=1, En_int8=2, En_uint8=3, En_integer=4, En_size=5, En_scalar=6,
                En_color=7,
                En_coord2D = 8,  En_coord3D =  9, En_coord = En_coord3D, En_coord4D = 10,
                En_cell2D  =11,  En_cell3D  = 12, En_cell  = En_cell3D,  En_cell4D  = 13,
                En_affine2D=14, En_affine3D=15,
                En_ray = 16,
                En_spot =17,
                En_light =18,

                En_chunk             =19,
                En_geometry_Base     =20,
                En_geometryNormal    =21,
                En_geometryIntersect =22,
                En_geometryUVW       =23,
                En_geometryDistance  =24,

                En__size, En__end = En__size
               };
              typedef Ee_component T_component;

              template < typename type_type > struct C_type2component{ enum{ En_component = En__error }; };


             enum Ee_constantBool
              {
               En_Bool__Begin = 0,
               En_inBool_ConstFALSE   = 0,
               En_inBool_ConstTRUE    = 1,
               En_inBool_DynamicValid = 2,
               En_Bool__End = 32
              };

             enum Ee_constantSize
              {
               En_Size__Begin = 0,
               En_inSize_ConstantBegin,
               En_inSize_ConstZero=0,
               En_inSize_ConstOne=1,
               En_inSize_ConstantEnd = 10,

               En_inSize_DynamicBegin = En_inSize_ConstantEnd +1,

               En_inSize_DynamicLightCount,

               En_inSize_DynamicSpotCount,
               En_inSize_DynamicSpotBegin,

               En_inSize_DynamicRaysReflectedCount,
               En_inSize_DynamicRaysRefractedCount,

               En_inSize_DynamicEnd,

               En_inSize_TemporalBegin = En_inSize_DynamicEnd,
               En_Size__End = 100
             };

             enum Ee_constantScalar
              {
               En_Scalar__Begin = 0,
               En_inScalar_Const__Begin,
               En_inScalar_ConstZero    = En_inScalar_Const__Begin,
               En_inScalar_ConstOne     = 1,
               En_inScalar_ConstPi      = 2,
               En_inScalar_ConstGold    = 3,
               En_inScalar_ConstE       = 4,
               En_inScalar_Const__End,
               En_inScalar_Dynamic__Begin = En_inScalar_Const__End + 10,
               En_inScalar_DynamicLambda = En_inScalar_Dynamic__Begin,
               En_inScalar_Dynamic__End,
               En_inScalar_Temporal__Begin = En_inScalar_Dynamic__End,
               En_inScalar_Temporal__End = En_inScalar_Temporal__Begin,
               En_Scalar__End = 100
              };

             enum Ee_constantColor
              {
               En_Color__Begin = 0,
               En_outColor__Begin = 0,
               En_outColor_Result = 0,

               En_inColor__Begin = 1,

               En_inColor_Const__Begin = En_inColor__Begin,
               En_inColor_ConstBlack = En_inColor_Const__Begin,
               En_inColor_ConstWhite,
               En_inColor_ConstGray,
               En_inColor_Const__End,
               En_inColor_Dynamic__Begin,

               En_inColor_Dynamic__End = En_inColor_Dynamic__Begin +10,
               En_inColor_Temporal__Begin = En_inColor_Dynamic__End +1,
               En_Color__End = 100
              };

             enum Ee_constantCoord3D
              {
               En_Coord3D__Begin = 0,
               En_inCoord3D_Const__Begin,
               En_inCoord3D_ConstZero = 0,
               En_inCoord3D_Const__End,
               En_inCoord3D_Dynamic__Begin = En_inCoord3D_Const__End + 10,
               En_inCoord3D_DynamicPoint,
               En_inCoord3D_DynamicNormal,
               En_inCoord3D_DynamicBump,
               En_inCoord3D_DynamicUVW,
               En_inCoord3D_Dynamic__End,
               En_inCoord3D_Temporal__Begin,
             //En_inCoord3D_Temporal__End,
               En_Coord3D__End = 100
              };

             enum Ee_constantSpot
              {
               En_Spot__Begin = 0,
               En_inSpot_Const__Begin,
               En_inSpot_Const__End,
               En_inSpot_Dynamic__Begin = En_inSpot_Const__End + 10,
               En_inSpot_Dynamic_Front = En_inSpot_Dynamic__Begin, //!< First spot in input array
               En_inSpot_Dynamic__End,
               En_inSpot_Temporal__Begin,
             //En_inSpot_Temporal__End
               En_Spot__End = 100
              };

             enum Ee_constantLight
              {
               En_Light__Begin = 0,
               En_inLight_Const__Begin = En_Light__Begin,
               En_inLight_Const__End,
               En_inLight_Dynamic__Begin = En_inLight_Const__End + 10,//!< First spot in input array
               En_inLight_Dynamic_Front,
               En_inLight_Dynamic__End,
               En_inLight_Temporal__Begin,
             //En_inLight_Temporal__End,
               En_Light__End = 100
              };

             enum Ee_constantRay
              {
               En_Ray_ConstZero = 0,
               En_inRay_DynamicIncident,
               En_inRay_DynamicReflected,
               En_inRay_Temporal__Begin,
               En_inRay_Temporal__End,
               En_Ray__End = 100
              };



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

              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D    T_affine2D;
              typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar4D    T_affine3D;


              typedef GS_DDMRM::S_IceRay::S_light::S_type::GC_spot      T_spot;
              typedef GS_DDMRM::S_IceRay::S_type::S_ray::GC_line        T_ray;
              typedef GS_DDMRM::S_IceRay::S_light::GC__pure             T_light;

              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometry_Base    ;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometryNormal   ;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometryIntersect;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometryUVW      ;
              typedef GS_DDMRM::S_IceRay::S_geometry::S__pure::GC__base   T_geometryDistance ;

            public:
              GC_memory()
               {
                M2_memory.resize( En__size, nullptr );
                M2_memory[ En__begin     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fake;

                M2_memory[ En_bool     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_bool   , En_Bool__End >();

                M2_memory[ En_int8     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_int8   , 10 >();
                M2_memory[ En_uint8    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_uint8  , 10 >();
                M2_memory[ En_integer  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_integer, 10 >();
                M2_memory[ En_size     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_size   , 10 >();
                M2_memory[ En_scalar   ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_scalar , En_Scalar__End >();

                M2_memory[ En_color    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_color  , En_Color__End >();

                M2_memory[ En_coord2D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_coord2D, 10 >();
                M2_memory[ En_coord3D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_coord3D, En_Coord3D__End >();
                M2_memory[ En_coord4D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_coord4D, 10 >();

                M2_memory[ En_cell2D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_cell2D, 10 >();
                M2_memory[ En_cell3D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_cell3D, 10 >();
                M2_memory[ En_cell4D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_cell4D, 10 >();

                M2_memory[ En_affine2D ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_affine2D, 10 >();
                M2_memory[ En_affine3D ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_affine3D, 10 >();

                M2_memory[ En_ray      ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_dynamic< T_ray >();
                M2_memory[ En_spot     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_dynamic< T_spot >( En_Spot__End );
                M2_memory[ En_light    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_light*,  En_Light__End >();

                M2_memory[ En_chunk             ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometry_Base::T_state, 10 >();
                M2_memory[ En_geometry_Base     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometry_Base    *, 10 >();
                M2_memory[ En_geometryNormal    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometryNormal   *, 10 >();
                M2_memory[ En_geometryIntersect ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometryIntersect*, 10 >();
                M2_memory[ En_geometryUVW       ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometryUVW      *, 10 >();
                M2_memory[ En_geometryDistance  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_geometryDistance *, 10 >();
               }

              T_size const&  F_size( T_component const& P_component )const
               {
                return M2_memory[ P_component ]->Fv_size();
               }

              void  F_size( T_component const& P_component, T_size const& P_size )
               {
                M2_memory[ P_component ]->Fv_size( P_size );
               }

              template< typename N_type >
               T_raw   const* F_get()const
                {
                 static const T_component I_component = (T_component) C_type2component< N_type >::En_component;
                 return M2_memory[ I_component ];
                }

              template< typename N_type >
               T_raw   * F_get()
                {
                 static const T_component I_component = (T_component) C_type2component< N_type >::En_component;
                 return M2_memory[ I_component ];
                }

              T_raw const* F_get( Ee_component const& P_component )const
               {
                return M2_memory[ P_component ];
               }

              T_raw   * F_get( Ee_component const& P_component )
               {
                return M2_memory[ P_component ];
               }

              void F_reset( T_component const& P_component )
               {
                M2_memory[ P_component ]->Fv_reset();
               }

              void F_reset( )
               {
                for( auto & I_raw : M2_memory )
                 {
                  I_raw->Fv_reset();
                 }
               }

            private:
              std::vector< T_raw * > M2_memory;
           };

#define IceRay_material_compute_memory_type2component(DP_type, DP_enum) \
           template <  >           \
              struct GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::C_type2component< GS_DDMRM::S_IceRay::S_type::DP_type >  \
              { enum{ En_component = GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::DP_enum }; }

#define IceRay_material_compute_memory_type2componentEx(DP_type, DP_enum) \
           template <  >           \
              struct GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::C_type2component< GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::DP_type >  \
              { enum{ En_component = GS_DDMRM::S_IceRay::S_material::S_compute::GC_memory::DP_enum }; }

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
         IceRay_material_compute_memory_type2component( S_ray::GC_line,         En_ray      );

         IceRay_material_compute_memory_type2componentEx( T_spot ,              En_spot  );
         IceRay_material_compute_memory_type2componentEx( T_light,              En_light );

        }
      }
    }
  }

#endif
