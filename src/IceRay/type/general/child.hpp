#ifndef _DDMRM_type_general_child_hpp_
 #define _DDMRM_type_general_child_hpp_

// GS_DDMRM::S_type::S_general::GC_child





 namespace GS_DDMRM
  {
   namespace S_type
    {
     namespace S_general
      {

       class GC_parent;

       class GC_child
        {
         public:

           typedef GS_DDMRM::S_type::S_general::GC_parent            T_parent;
         public:
           explicit GC_child( T_parent *P_parent = nullptr );
           virtual ~GC_child();

         public:
           virtual void        Fv_parent( T_parent *P_parent );
         protected:
         private:
           T_parent * M2_parent;
        };

      }
    }
  }

#endif
