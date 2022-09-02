#ifndef _a20d15465299425a97f981c5aae1daed
#define _a20d15465299425a97f981c5aae1daed


template < typename N_handle, typename N_class >
 inline void IceRayC__Internal_Release( N_handle P_this )
  {
   typedef N_class Tf_class;
   auto I_this = reinterpret_cast<Tf_class*> ( P_this );
   delete I_this;
  }

template < typename N_handle, typename N_base, typename N_derive >
 inline N_handle IceRayC__Internal_Construct0()
  {
   typedef N_handle   Tf_handle;
   typedef N_base     Tf_base;
   typedef N_derive   Tf_derive;

   auto Ir_result = new Tf_derive{};
   return reinterpret_cast<Tf_handle>( dynamic_cast< N_base *> ( Ir_result ) );
  }

template < typename N_handle, typename N_base, typename N_derive, typename N_parameter0 >
 inline N_handle IceRayC__Internal_Construct1( N_parameter0 P_0 )
  {
   typedef N_handle   Tf_handle;
   typedef N_base     Tf_base;
   typedef N_derive   Tf_derive;

   auto Ir_result = new Tf_derive{ P_0 };
   return reinterpret_cast<Tf_handle>( dynamic_cast< N_base *> ( Ir_result ) );
  }

template < typename N_handle, typename N_base, typename N_derive >
 inline N_derive* IceRayC__Internal_Extract( N_handle P_this )
  {
   typedef N_handle   Tf_handle;
   typedef N_base     Tf_base;
   typedef N_derive   Tf_derive;

   auto Ir_this = dynamic_cast< Tf_derive*>( reinterpret_cast<Tf_base*> ( P_this ) );

   return Ir_this;
  }

#endif
