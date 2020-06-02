#ifndef _DDMRM_type_general_config_hpp_
 #define _DDMRM_type_general_config_hpp_

// GS_DDMRM::S_type::S_general::GC_config





 namespace GS_DDMRM
  {
   namespace S_type
    {
     namespace S_general
      {

         class GC_config
          {
           public:
           public:
                      GC_config(){}
             virtual ~GC_config(){}

           public:
             virtual bool        Fv_reset()=0;//! put instance in default state
          };

      }
    }
  }

#endif
