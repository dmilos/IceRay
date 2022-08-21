#ifndef Dh_DDMM_IceRay_light__parent
 #define Dh_DDMM_IceRay_light__parent

 // GS_DDMRM::S_IceRay::S_light::GC__parent

 #include "./_pure.hpp"


 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_light
      {

       class GC__parent
        : public GS_DDMRM::S_IceRay::S_light::GC__pure
        {
         public:
           typedef GS_DDMRM::S_IceRay::S_light::GC__pure  T_pure;

         public:
                    GC__parent( );
           explicit GC__parent( T_pure * P_child );
                   ~GC__parent();

         public:
           using T_pure::Fv_swarm;

         public:  // property child  child
           T__pure    const& F_child()const{ return *M2_child; }
           bool             Fv_child( T__pure * P_child )
            {
             M2_child = P_child; 
             if( nullptr == M2_child )
              {
               M2_child = &Fs_point();
              }
             return bool( true ); 
            }
         protected:
        //T__pure        & F1_child(){ return M2_child; }
         private:
           T__pure * M2_child;

         private:
           static T__pure & Fs_point();

        };

       }
     }
   }

#endif
