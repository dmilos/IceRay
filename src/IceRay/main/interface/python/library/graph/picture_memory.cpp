#include <fstream>
#include "../../def_submodule.hpp"

#include "IceRay/type/picture/picture.hpp"
#include "pnm/pnm.hpp"

#include <boost/python.hpp>

typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_memory GTs_picture;
typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D GTs_coord;
typedef  GS_DDMRM::S_IceRay::S_type::GT_size   GTs_size;

namespace
 {
  bool GFs_size( GTs_picture &P_picture, GTs_coord const& P_size  )
   {
    return  P_picture.Fv_size( P_size );
   }
 }

namespace {
namespace Ss_wrap
{

class GCs_wrap
 : public GS_DDMRM::S_IceRay::S_type::S_picture::GC_type::GT_memory
 {
  public:
    typedef GS_DDMRM::S_IceRay::S_type::GT_report          T_report;

    typedef  GS_DDMRM::S_IceRay::S_type::GT_size   T_size;
    typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D T_size2D;
    typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_type::GT_memory T_memory;

    GCs_wrap(){}
    GCs_wrap(std::string const& P_filename){ F_load( P_filename ); }
    GCs_wrap( T_size const& P_width, T_size const& P_height):T_memory( P_width, P_height ){}
    GCs_wrap( T_size2D const& P_size ):T_memory( P_size ){ }

    bool F_load( std::string const& P_filename)
     {
      PNM::Info info;
      { std::ifstream ifs( P_filename.c_str(), std::ios_base::binary ); ifs >> PNM::probe( info ); }

      if( false == info.valid() )
       {
        return false;
       }

      if( PNM::P6 != info.type() )
       {
        return false;
       }

      this->Fv_size( { info.width(), info.height()} );
      std::uint8_t * data = const_cast<  uint8_t * >( ( uint8_t const* )Fv_data() );
      { std::ifstream ifs( P_filename.c_str(), std::ios_base::binary ); ifs >> PNM::load( data, info ); }

      return true;
     }

    bool F_store(std::string const& P_filename )
     {
      std::ofstream ofs( P_filename.c_str(), std::ios_base::binary );

      ofs << PNM::save( (const uint8_t *)Fv_data(), F_size()[0], F_size()[1], PNM::P6 );
      return true;
     }

 };
}
}


void expose_graph_picture__pure()
{
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( graph  );
  MAKE_SUBMODULE( picture );

  typedef GS_DDMRM::S_IceRay::S_type::GT_report          Tf_report;

  typedef  GS_DDMRM::S_IceRay::S_type::GT_size   Tf_size;
  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D Tf_coord;

  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_type::GT__pure Tf__pure;

   boost::python::class_< Tf__pure, boost::noncopyable >( "GraphTypePicture_Pure", boost::python::no_init )
  //  .def( boost::python::init<>() )
  //  .def( boost::python::init<std::string>() )
  //  .def( boost::python::init<GT_size, GT_size>() )
  //  .def( boost::python::init<Tf_coord>() )
  //
  //   //.def("size",    &GFs_size  )
  //  //.def("size",    &GTs_picture::Fv_size  )
  //  //.def("height",  &GFs_height  )
  //  //.def("width",   &GFs_width  )
  //  //.def("set",  &GFs_set )
  //  //.def("get",   &GFs_get )
   ;

}

void expose_graph_picture_memory()
 {
  expose_graph_picture__pure();

  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library   );
  MAKE_SUBMODULE( graph  );
  MAKE_SUBMODULE( picture );

  typedef GS_DDMRM::S_IceRay::S_type::GT_report          Tf_report;

  typedef  GS_DDMRM::S_IceRay::S_type::GT_size           Tf_size;
  typedef GS_DDMRM::S_IceRay::S_type::S_coord::GT_size2D Tf_coord;

  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC_type::GT__pure Tf__pure;

  typedef Ss_wrap::GCs_wrap Tf_wrap;

  //typedef Tf_coord        (Tf_wrap::*Tf_size0D)( )const;
  typedef Tf_report       (Tf_wrap::*Tf_size1D)( Tf_size const& , Tf_size const& );
  typedef Tf_report       (Tf_wrap::*Tf_size2D)( Tf_coord const& );

  //Tf_size0D I_size0d = &Tf_wrap::F_size;
  //Tf_size1D I_size1d = &Tf_wrap::Fv_size;
  Tf_size2D I_size2d = &Tf_wrap::Fv_size;

  boost::python::class_<Tf_wrap, boost::python::bases<Tf__pure>   >( "GraphTypePicture" )
     .def( boost::python::init<>() )
     .def( boost::python::init<std::string>() )
     .def( boost::python::init<Tf_size, Tf_size>() )
     .def( boost::python::init<Tf_coord>() )

      //.def( "size",  I_size0d )
   //.def( "size",  I_size1d )
     .def( "size",  I_size2d )
     .def( "load",     &Tf_wrap::F_load )
     .def( "store",    &Tf_wrap::F_store )
  ;
 }
