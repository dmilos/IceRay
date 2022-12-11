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
                En_color,
                En_cell2D   ,  En_cell3D   ,  En_cell       = En_cell3D,       En_cell4D    ,
                En_coord2D  ,  En_coord3D  ,  En_coord      = En_coord3D,      En_coord4D   ,
                En_affine2D ,  En_affine3D ,  En_affine     = En_affine3D,     En_affine4D  ,
              //TODO En_homography2D,  En_homography3D,  En_homography = En_homography3D, En_homography4D,
              //TODO En_spline2D    ,  En_spline3D    ,  En_spline     = En_spline3D,     En_spline4D    ,
              //TODO En_polynom2D   ,  En_polynom3D   ,  En_polynom    = En_polynom3D,    En_polynom4D   ,

                En_ray  ,
                En_spot ,
                En_light,

                En_chunk            ,
                En_geometry_Base    ,
                En_geometryNormal   ,
                En_geometryIntersect,
                En_geometryUVW      ,
                En_geometryDistance ,

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
               En_Bool__End = 100
              };

             enum Ee_constantSize
              {
               En_Size__Begin = 0,
               En_Size_ConstantBegin,
               En_Size_ConstZero=0,
               En_Size_ConstOne=1,
               En_Size_ConstantEnd = 10,

               En_Size_DynamicBegin = En_Size_ConstantEnd +1,

               En_Size_DynamicLightCount,
               En_Size_DynamicLightBegin,
               En_Size_DynamicLightEnd,

               En_Size_DynamicSpotCount,
               En_Size_DynamicSpotBegin,
               En_Size_DynamicSpotEnd,

               En_Size_DynamicRaysReflectedCount,
               En_Size_DynamicRaysRefractedCount,

               En_Size_DynamicEnd,

               En_Size_TemporalBegin = En_Size_DynamicEnd,
               En_Size__End = 100
             };

             enum Ee_constantScalar
              {
               En_Scalar__Begin = 0,
               En_Scalar_Const__Begin,
               En_Scalar_ConstZero    = En_Scalar_Const__Begin,
               En_Scalar_ConstOne     = 1,
               En_Scalar_ConstPi      = 2,
               En_Scalar_ConstGold    = 3,
               En_Scalar_ConstE       = 4,
               En_Scalar_Const__End,
               En_Scalar_Dynamic__Begin = En_Scalar_Const__End + 10,
               En_Scalar_DynamicLambda = En_Scalar_Dynamic__Begin,
               En_Scalar_Dynamic__End,
               En_Scalar_Temporal__Begin = En_Scalar_Dynamic__End,
               En_Scalar_Temporal__End = En_Scalar_Temporal__Begin,
               En_Scalar__End = 100
              };

             enum Ee_constantColor
              {
               En_Color__Begin = 0,

               En_Color_Const__Begin = En_Color__Begin,
               En_Color_ConstBlack = En_Color_Const__Begin,
               En_Color_ConstWhite,
               En_Color_ConstGray,
               En_Color_Const__End = En_Color_ConstGray + 1,
               En_Color_Dynamic__Begin = En_Color_Const__End,
               En_Color_DynamicResult,
               En_Color_Dynamic__End = En_Color_DynamicResult +1,
               En_Color_Temporal__Begin = En_Color_Dynamic__End,
               En_Color_Temporal__End = En_Color_Temporal__Begin + 100,
               En_Color__End = En_Color_Temporal__End
              };

             enum Ee_constantCoord2D
              {
               En_Coord2D__Begin = 0,
               En_inCoord2D_Const__Begin = En_Coord2D__Begin,
               En_inCoord2D_ConstZero = En_inCoord2D_Const__Begin,
               En_inCoord2D_Const__End = En_inCoord2D_ConstZero + 1,
               En_inCoord2D_Dynamic__Begin = En_inCoord2D_Const__End + 10,
               En_inCoord2D_Temporal__Begin = En_inCoord2D_Dynamic__Begin + 10,
               En_inCoord2D_Temporal__End = En_inCoord2D_Temporal__Begin + 50,
               En_Coord2D__End = En_inCoord2D_Temporal__End
              };

             enum Ee_constantCoord3D
              {
               En_Coord3D__Begin = 0,
               En_inCoord3D_Const__Begin,
               En_inCoord3D_ConstZero = 0,
               En_inCoord3D_Const__End = En_inCoord3D_Const__Begin + 10,
               En_inCoord3D_Dynamic__Begin = En_inCoord3D_Const__End,
               En_inCoord3D_DynamicPoint,
               En_inCoord3D_DynamicNormal,
               En_inCoord3D_DynamicBump,
               En_inCoord3D_DynamicUVW,
               En_inCoord3D_Dynamic__End = En_inCoord3D_DynamicUVW + 1,
               En_inCoord3D_Temporal__Begin = En_inCoord3D_Dynamic__End + 1,
               En_inCoord3D_Temporal__End = En_inCoord3D_Temporal__Begin + 100,
               En_Coord3D__End = En_inCoord3D_Temporal__End
              };

             enum Ee_constantCoord4D
              {
               En_Coord4D__Begin = 0,
               En_inCoord4D_Const__Begin,
               En_inCoord4D_ConstZero = En_inCoord4D_Const__Begin,
               En_inCoord4D_Const__End = En_inCoord4D_ConstZero + 1,
               En_inCoord4D_Dynamic__Begin = En_inCoord4D_Const__End,
               En_inCoord4D_Dynamic__End = En_inCoord4D_Dynamic__Begin + 50,
               En_inCoord4D_Temporal__Begin = En_inCoord4D_Dynamic__End,
               En_inCoord4D_Temporal__End = En_inCoord4D_Temporal__Begin + 100,
               En_Coord4D__End = En_inCoord4D_Temporal__End
              };

             enum Ee_constantSpot
              {
               En_Spot__Begin = 0,
               En_Spot_Const__Begin = En_Spot__Begin,
               En_Spot_Const__End = En_Spot_Const__Begin + 10,
               En_Spot_Dynamic__Begin = En_Spot_Const__End,
               En_Spot_Dynamic_Front = En_Spot_Dynamic__Begin, //!< First spot in input array
               En_Spot_Dynamic__End = En_Spot_Dynamic__Begin + 100,
               En_Spot_Temporal__Begin = En_Spot_Dynamic__End,
               En_Spot_Temporal__End = En_Spot_Temporal__Begin + 50,
               En_Spot__End = En_Spot_Temporal__End
              };

             enum Ee_constantLight
              {
               En_Light__Begin = 0,
               En_inLight_Const__Begin = En_Light__Begin,
               En_inLight_Const__End   = En_inLight_Const__Begin + 10,
               En_inLight_Dynamic__Begin = En_inLight_Const__End,
               En_inLight_Dynamic_Front = En_inLight_Dynamic__Begin,//!< First light in input array
               En_inLight_Dynamic__End = En_inLight_Dynamic__Begin + 50,
               En_inLight_Temporal__Begin = En_inLight_Dynamic__End,
               En_inLight_Temporal__End = En_inLight_Temporal__Begin + 50,
               En_Light__End = En_inLight_Temporal__End
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
              GC_memory()
               {
                M2_memory.resize( En__size, nullptr );
                M2_memory[ En__begin     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fake;

                M2_memory[ En_bool     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_bool   , En_Bool__End >();

                M2_memory[ En_int8     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_int8   , 10 >();
                M2_memory[ En_uint8    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_uint8  , 10 >();
                M2_memory[ En_integer  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_integer, 10 >();
                M2_memory[ En_size     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_size   , En_Size__End >();
                M2_memory[ En_scalar   ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_scalar , En_Scalar__End >();

                M2_memory[ En_color    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_color  , En_Color__End >();

                M2_memory[ En_coord2D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_coord2D, En_Coord2D__End >();
                M2_memory[ En_coord3D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_coord3D, En_Coord3D__End >();
                M2_memory[ En_coord4D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_coord4D, En_Coord4D__End >();

                M2_memory[ En_cell2D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_cell2D, 10 >();
                M2_memory[ En_cell3D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_cell3D, 10 >();
                M2_memory[ En_cell4D  ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_cell4D, 10 >();

                M2_memory[ En_affine2D ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_affine2D, 10 >();
                M2_memory[ En_affine3D ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_affine3D, 10 >();
                M2_memory[ En_affine4D ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_affine4D, 10 >();

                M2_memory[ En_ray      ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_dynamic< T_ray >();
                M2_memory[ En_spot     ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_dynamic< T_spot >( En_Spot__End );
                M2_memory[ En_light    ] = new GS_DDMRM::S_IceRay::S_material::S_compute::S_data::GC_fixed< T_light*,   En_Light__End >();

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
         IceRay_material_compute_memory_type2component( S_affine::GT_scalar4D , En_affine4D );

         IceRay_material_compute_memory_type2component( S_ray::GC_line,         En_ray      );
         IceRay_material_compute_memory_type2componentEx( T_spot ,              En_spot     );
         IceRay_material_compute_memory_type2componentEx( T_light,              En_light    );

        }
      }
    }
  }

#endif
