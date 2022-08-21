#ifndef Dh_DDMM_IceRay_light_transform_generic
 #define Dh_DDMM_IceRay_light_transform_generic

 // GS_DDMRM::S_IceRay::S_light::S_transform::GC__model

 #include "../_parent.hpp"
 #include "../../utility/mapping.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {
       namespace S_transform
        {

         template< typename N_mapping >
          class GC__model
           : public GS_DDMRM::S_IceRay::S_light::GC__parent
           {
            public:
              typedef GS_DDMRM::S_IceRay::S_light::GC__pure  T_pure;
              typedef N_mapping  T_mapping;

            public:
                       GC__model( );
              explicit GC__model( T_mapping const& P_mapping, T_pure * P_child );
                      ~GC__model();

            public:
              T_size  Fv_swarm( T_swarm &P_swarm, T_coord const& P_point )const
               {
                M2_swarm.F_clear();
                F_child().Fv_swarm( M2_swarm, P_point );

                for( auto & I_spot: M2_swarm )
                 {
                  auto I_center = I_spot.F_center();
                  I_spot.F_center() = M2_mapping( I_center );
                  P_swarm.F_push( I_spot );
                 }
                return M2_swarm.F_size();
               }

           public:
             T_mapping    const& F_mapping()const{ return M2_mapping; }
             bool                F_mapping( T_mapping const& P_mapping ){ M2_mapping = P_mapping; return bool( true ); }
           protected:
             T_mapping        & F1_mapping(){ return M2_mapping; }
           private:
             T_mapping M2_mapping;
           private:
              mutable T_swarm M2_swarm;
           };

           typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC__model< GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_identity>  GT_identity;
           typedef GS_DDMRM::S_IceRay::S_light::S_transform::GC__model< GS_DDMRM::S_IceRay::S_utility::S_mapping::GC_translate> GT_translate;
         }
       }
     }
   }

#endif
