#ifndef Dh_DDMRM_type_nothing_H_
 #define Dh_DDMRM_type_nothing_H_
 // GS_DDMRM::S_type::GC_nothing
 
 namespace S_DDMRM
  {
   namespace S_type
    {

     class GC_nothing
      {
       private:
         GC_nothing( void )/* = delete */{ ; }
         GC_nothing( GC_nothing const& P_original )/* = delete */{ ; }
         GC_nothing& operator=( GC_nothing const&P_original )/* = delete */{ return *this; }
        ~GC_nothing( void )/* = delete */{ ; }
      };

    }
  }

 namespace GS_DDMRM
  {
   namespace S_type
    {
  // namespace S_type 
  //  {
       class GC_nothing
        {
         private:
           GC_nothing( void )/* = delete */{ ; }
           GC_nothing( GC_nothing const& P_original )/* = delete */{ ; }
           GC_nothing& operator=( GC_nothing const&P_original )/* = delete */{ return *this; }
          ~GC_nothing( void )/* = delete */{ ; }
        };
    //} 
    }
  }


#endif
