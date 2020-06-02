#ifndef _DDMRM_type_general_prototype_hpp_
 #define _DDMRM_type_general_prototype_hpp_

// GS_DDMRM::S_type::S_general::GC_prototype





 namespace GS_DDMRM
  {
   namespace S_type
    {
     namespace S_general
      {

       template < typename N__base >
       class GC_prototype
        : public virtual N__base
        {
         public:

           typedef N__base           T__base;

         public:
                    GC_prototype(){}
           virtual ~GC_prototype(){}

         public:

           virtual T__base*        Fv_blank()const=0; //! make blank instance
           virtual T__base*        Fv_clone()const=0; //!< exact clone
           virtual void            Fv_release( T__base* P_this )const=0; //! release
        };

      }
    }
  }

#endif
