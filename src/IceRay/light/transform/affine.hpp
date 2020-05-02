#ifndef Dh_DDMM_IceRay_light_transform_affine
 #define Dh_DDMM_IceRay_light_transform_affine

 // GS_DDMRM::S_IceRay::S_light::S_transform::GC_affine

 #include "../_parent.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {
       namespace S_transform
        {

         class GC_affine
          : public GS_DDMRM::S_IceRay::S_light::GC__parent
          {
           public:
             typedef GS_DDMRM::S_IceRay::S_light::GC__pure  T_pure;
             typedef GS_DDMRM::S_IceRay::S_type::S_affine::GT_affine    T_affine;

           public:
                      GC_affine( );
             explicit GC_affine( T_pure * P_child );
                     ~GC_affine();

           public:
             T_size  Fv_swarm( T_swarm &P_spot,  T_coord const& P_point )const;

           public:
             T_affine   const& F_function()const{ return M2_function; }
             bool              F_function( T_affine const& P_function ){ M2_function = P_function; return bool( true ); }
           protected:
             T_affine        & F1_function(){ return M2_function; }
           private:
             T_affine M2_function;
          };

        }
       }
     }
   }

#endif
