

#include "../../def_submodule.hpp"
#include <boost/python.hpp>
#include <fstream>


#include "pnm/pnm.hpp"

#include "../../../../../type/picture/memory.hpp"


namespace
 {
  typedef GS_DDMRM::S_IceRay::S_type::S_picture::GC__pure GTs_picture;

  bool GFs_storePNG( std::string const& P_name, GTs_picture const& P_image )
   {
    return false; //S_DDMRM::S_graph::S_picture::S_file::GF_save( P_name, P_image );
   }

  bool GFs_storePNM( std::string const& P_name, GTs_picture const& P_image )
   {
    std::ofstream ofs( P_name.c_str(), std::ios_base::binary );

     ofs<< PNM::save( (const uint8_t *)P_image.Fv_data(), P_image.F_size()[0], P_image.F_size()[1], PNM::P6 );
    return true;
   }

 }

void expose_graph_picture_save_image()
 {
  //MAKE_SUBMODULE( IceRay );
  MAKE_SUBMODULE( library  );
  MAKE_SUBMODULE( graph  );
  MAKE_SUBMODULE( picture );

//boost::python::def( "GraphPictureStorePNG",  &GFs_storePNG );
  boost::python::def( "GraphPictureStorePNM",  &GFs_storePNM );
 }
