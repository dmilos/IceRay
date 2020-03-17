#ifndef _DDMRM_IceRAY_camera__parent_HPP_
 #define _DDMRM_IceRAY_camera__parent_HPP_

  #include "./type/report.hpp"

  #include "./_pure.hpp"

  namespace GS_DDMRM
   {
    namespace S_IceRay
     {
      namespace S_camera
       {

        class GC__parent
         : public GS_DDMRM::S_IceRay::S_camera::GC__pure
         {
          public:

            typedef GS_DDMRM::S_IceRay::S_camera::GC__pure        T__pure;

            GC__parent();
            GC__parent( T__pure * P_child, T_size const& P_size = 1 );
           ~GC__parent();

          public:
            T_size Fv_beam( T_beam &P_beam, T_coord2D const& P_uv )const;
          public:
            void   Fv_system( T_affine &P_matrix, T_coord2D const& P_uv )const;

          public:
            bool Fv_size( T_size const& P_size )
             {
              M2_child->Fv_size( P_size );
              F1_size() = P_size;
              return true;
             }
          public:
            T__pure const& F_child()const{ return *M2_child; }
            T__pure      & F_child()     { return *M2_child; }

            bool           F_child( T__pure * P_child );

          protected:
            T__pure & F1_child(){ return *M2_child; }
          private:
            T__pure *M2_child;  //!< dumb_ptr<>???

          public:
            static T__pure & Fs_child();

         };

       }
     }
   }


#endif

