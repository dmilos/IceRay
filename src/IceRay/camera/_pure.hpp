#ifndef _DDMRM_IceRAY_camera__pure_HPP_
 #define _DDMRM_IceRAY_camera__pure_HPP_

  #include "./type/ray.hpp"
  #include "./type/beam.hpp"
  #include "./type/coord.hpp"
  #include "./type/matrix.hpp"
  #include "./type/affine.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {

        class GC__pure
         {
          public:
            typedef GS_DDMRM::S_IceRay::S_type::GT_size                 T_size;
            typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar2D    T_coord2D;
            typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar3D   T_matrix3D;
            typedef GS_DDMRM::S_IceRay::S_type::S_matrix::GT_scalar4D   T_matrix4D;

            typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_affine     T_affine;


            typedef GS_DDMRM::S_IceRay::S_type::GT_scalar               T_scalar;
            typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_scalar3D    T_coord;

            typedef GS_DDMRM::S_IceRay::S_camera::S_type::GT_ray        T_ray;
            typedef GS_DDMRM::S_IceRay::S_camera::S_type::GT_beam       T_beam;

          public:
                     GC__pure();
            explicit GC__pure( T_size const& P_size );
            virtual ~GC__pure();

          public:
            //! @param  P_beam must be pre allocated
            //! @param  P_uv e [-1,1]x[-1,1]
            //! @note Directions are not unit.
            virtual T_size Fv_beam( T_beam &P_beam, T_coord2D const& P_uv )const=0;

          public:
            //! @param  P_uv e [-1,1]x[-1,1]
            //! @desc Each point of camera has their own transformation system, Later it will be used to split the ray in to beam
            //! @desc Zero is origin of direction. You no need to produce unit vectors
            virtual void Fv_system( T_affine &, T_coord2D const& P_uv )const=0;

          public:// maximum number of rays per beam;
            T_size const& F_size( )const
             {
              return M2_size;
             }
            virtual bool Fv_size( T_size const& P_size )
             {
              M2_size = P_size;
              return true;
             }

          protected:
            T_size   & F1_size( ){ return M2_size; }
          private:
            T_size M2_size;

         };

       }
     }
   }

#endif

