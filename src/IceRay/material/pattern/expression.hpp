#ifndef Dh_IceRay_material_pattern_expression_hpp_
 #define Dh_IceRay_material_pattern_expression_hpp_

//! GS_DDMRM::S_IceRay::S_material::S_pattern::GC_expression

#include "./_pure.hpp"







 namespace GS_DDMRM
  {
   namespace S_IceRay
    {
     namespace S_material
      {
       namespace S_pattern
        {

         class GC_expression
          : public GS_DDMRM::S_IceRay::S_material::S_pattern::GT__scalar
          {
           public:
             // f(x,y,z) - no n for normal or similar things
             explicit GC_expression( std::string const& expression )
              {
                  // TODO
              }

           public:
             void  Fv_process( T_result &P_result, T_coord const& P_coord )const
              {
               // TODO
               //P_result = execute( );
              }

           private:
             std::string M2_expression;
          };

        }
      }
    }
  }

#endif
