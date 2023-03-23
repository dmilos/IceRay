#ifndef Dh_DDMRM_Iceray_material_compute_memory_constant__HPP_
 #define Dh_DDMRM_Iceray_material_compute_memory_constant__HPP_

// GS_DDMRM::S_IceRay::S_material::S_compute::S_memory



 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_compute
        {
         namespace S_memory
          {

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

           enum Ee_constantBool
            {
             En_Bool__Begin         = 0,
             En_Bool_Const__Begin  =  0,
             En_Bool_ConstFALSE   =  0,
             En_Bool_ConstTRUE    =  1,
             En_Bool_ConstRand    =  2,
             En_Bool_Const__End    = En_Bool_Const__Begin + 10,

             En_Bool_Dynamic__Begin = En_Bool_Const__End,
             En_Bool_DynamicValid = 3,
             En_Bool_Dynamic__End = En_Bool_Dynamic__Begin + 20,

             En_Bool_Temporal__Begin = En_Bool_Dynamic__End,
             En_Bool_Temporal__End = 100,

             En_Bool__End           = En_Bool_Temporal__End
            };

           enum Ee_constantSize
            {
             En_Size__Begin      = 0,
             En_Size_Constant__Begin,
             En_Size_ConstZero  =0,
             En_Size_ConstOne   =1,
             En_Size_ConstRand  =2,
             En_Size_Constant__End = 10,

             En_Size_Dynamic__Begin = En_Size_Constant__End +1,
             En_Size_DynamicLightCount,
             En_Size_DynamicLight__Begin,
             En_Size_DynamicLight__End,

             En_Size_DynamicSpotCount,
             En_Size_DynamicSpot__Begin,
             En_Size_DynamicSpot__End,

             En_Size_DynamicRaysReflectedCount,
             En_Size_DynamicRaysRefractedCount,

             En_Size_Dynamic__End,

             En_Size_Temporal__Begin = En_Size_Dynamic__End,
             En_Size__End = 100
            };

           enum Ee_constantScalar
            {
             En_Scalar__Begin = 0,

             En_Scalar_Const__Begin = En_Scalar__Begin,
             En_Scalar_ConstZero    = En_Scalar_Const__Begin,
             En_Scalar_ConstOne     = 1,
             En_Scalar_ConstRand    = 2,
             En_Scalar_ConstPi      = 3,
             En_Scalar_ConstE       = 4,
             En_Scalar_ConstGold    = 5,
             En_Scalar_ConstSQRT2   = 6,
             En_Scalar_ConstSQRT3   = 7,
             En_Scalar_Const__End   = En_Scalar_Const__Begin + 10,

             En_Scalar_Dynamic__Begin = En_Scalar_Const__End,
             En_Scalar_DynamicLambda = En_Scalar_Dynamic__Begin,
             En_Scalar_Dynamic__End = En_Scalar_Dynamic__Begin+10,

             En_Scalar_Temporal__Begin = En_Scalar_Dynamic__End,
             En_Scalar_Temporal__End = En_Scalar_Temporal__Begin+100,
             En_Scalar__End = 100
            };

           enum Ee_constantColor
            {
             En_Color__Begin = 0,

             En_Color_Const__Begin = En_Color__Begin,
             En_Color_ConstBlack = En_Color_Const__Begin,
             En_Color_ConstWhite,
             En_Color_ConstGray,
             En_Color_ConstRed,
             En_Color_ConstGreen,
             En_Color_ConstBlue,
             En_Color_ConstCyan,
             En_Color_ConstMagenta,
             En_Color_ConstYellow,
             En_Color_Const__End = En_Color_Const__Begin + 20,

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
             En_inCoord2D_ConstRand,
             En_inCoord2D_Const__End = En_inCoord2D_Const__Begin + 10,

             En_inCoord2D_Dynamic__Begin = En_inCoord2D_Const__End,
             En_inCoord2D_Dynamic__End   = En_inCoord2D_Dynamic__Begin + 10,

             En_inCoord2D_Temporal__Begin = En_inCoord2D_Dynamic__End + 10,
             En_inCoord2D_Temporal__End = En_inCoord2D_Temporal__Begin + 50,
             En_Coord2D__End = En_inCoord2D_Temporal__End
            };

           enum Ee_constantCoord3D
            {
             En_Coord3D__Begin = 0,
             En_inCoord3D_Const__Begin,
             En_inCoord3D_ConstZero = 0,
             En_inCoord3D_ConstRand = 1,
             En_inCoord3D_Const__End = En_inCoord3D_Const__Begin + 10,

             En_inCoord3D_Dynamic__Begin = En_inCoord3D_Const__End,

             En_inCoord3D_Dynamic_Origin,
             En_inCoord3D_Dynamic_Incident,
             En_inCoord3D_Dynamic_Point,
             En_inCoord3D_Dynamic_Normal,
             En_inCoord3D_Dynamic_Reflected,
             En_inCoord3D_Dynamic_Bump,
             En_inCoord3D_Dynamic_UVW,
             En_inCoord3D_Dynamic_2Viewer,

             En_inCoord3D_Dynamic_Surface_X, //!Local coordinate system at point with normal as Z, Y = NxV, x = Nx(NxV)
             En_inCoord3D_Dynamic_Surface_Y, //!Local coordinate system at point with normal as Z, Y = NxV, x = Nx(NxV)

             En_inCoord3D_Dynamic_Incident_X, //!Local coordinate system at point with incident as Z, Y = NxV, x = Nx(NxV)
             En_inCoord3D_Dynamic_Incident_Y, //!Local coordinate system at point with incident as Z, Y = NxV, x = Nx(NxV)

             En_inCoord3D_Dynamic_Reflect_X, //!Local coordinate system at point with reflected as Z, Y = NxV, x = Nx(NxV)
             En_inCoord3D_Dynamic_Reflect_Y, //!Local coordinate system at point with reflected as Z, Y = NxV, x = Nx(NxV)

             En_inCoord3D_Dynamic__End = En_inCoord3D_Dynamic__Begin + 10,

             En_inCoord3D_Temporal__Begin = En_inCoord3D_Dynamic__End + 1,
             En_inCoord3D_Temporal__End = En_inCoord3D_Temporal__Begin + 100,
             En_Coord3D__End = En_inCoord3D_Temporal__End
            };

           enum Ee_constantCoord4D
            {
             En_Coord4D__Begin = 0,
             En_inCoord4D_Const__Begin,
             En_inCoord4D_ConstZero = En_inCoord4D_Const__Begin,
             En_inCoord4D_ConstRand,
             En_inCoord4D_Const__End = En_inCoord4D_Const__Begin + 10,

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

          }
        }
      }
    }
  }

#endif
