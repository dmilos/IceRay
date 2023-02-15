#ifndef _ce6d99fa547743dd91e9bcda19214485
#define _ce6d99fa547743dd91e9bcda19214485

#include "../../system/system.h"
#include "../../type/type.h"
#include "../../type/picture.h"

#include "./handle.h"

struct  IceRayC_Geometry_HField_Generator_Struct {};
typedef IceRayC_Geometry_HField_Generator_Struct* IceRayC_Geometry_HField_Generator_Handle;
struct  IceRayC_Geometry_HField_Object_Struct {};
typedef IceRayC_Geometry_HField_Object_Struct* IceRayC_Geometry_HField_Object_Handle;


IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Geometry_Handle IceRayC_Geometry_HField_System0();

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_HField_System_Lo( IceRayC_Geometry_Handle P_this, IceRayC_Type_Math_Coord_Scalar3D* P_lo );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_HField_System_Hi( IceRayC_Geometry_Handle P_this, IceRayC_Type_Math_Coord_Scalar3D* P_hi );

IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_HField_System_Generator( IceRayC_Geometry_Handle P_this, IceRayC_Geometry_HField_Generator_Handle P_function );
IceRayC__EXPORT IceRayC__DECLSPEC  IceRayC_Type_Bool       IceRayC_Geometry_HField_System_Object(   IceRayC_Geometry_Handle P_this, IceRayC_Geometry_HField_Object_Handle   P_function );



IceRayC__EXPORT IceRayC__DECLSPEC int                                      IceRayC_Geometry_HField_Generator_Release( IceRayC_Geometry_HField_Generator_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Image0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Image1( IceRayC_Type_Picture_Handle P_picture );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                        IceRayC_Geometry_HField_Generator_Image_Picture( IceRayC_Geometry_HField_Generator_Handle P_this, IceRayC_Type_Picture_Handle P_picture );


IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Expression0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Expression1( char *P_expression );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                        IceRayC_Geometry_HField_Generator_Expression_Pattern( IceRayC_Geometry_HField_Generator_Handle P_this, char *P_expression );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                        IceRayC_Geometry_HField_Generator_Expression_Box( IceRayC_Geometry_HField_Generator_Handle P_this, IceRayC_TypeInterval3D* P_box );


IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Table0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Generator_Handle IceRayC_Geometry_HField_Generator_Table1( IceRayC_TypeCoordSize2D* P_size );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                        IceRayC_Geometry_HField_Generator_Table_Size( IceRayC_Geometry_HField_Generator_Handle P_this, IceRayC_TypeCoordSize2D* P_size  );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                        IceRayC_Geometry_HField_Generator_Table_Value( IceRayC_Geometry_HField_Generator_Handle P_this, IceRayC_TypeCoordSize2D* P_size, IceRayC_TypeScalar P_value  );


IceRayC__EXPORT IceRayC__DECLSPEC int                                      IceRayC_Geometry_HField_Object_Release( IceRayC_Geometry_HField_Object_Handle P_this );

IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Object_Handle    IceRayC_Geometry_HField_Object_Flat0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Object_Handle    IceRayC_Geometry_HField_Object_Quad0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Object_Handle    IceRayC_Geometry_HField_Object_Triangle0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Object_Handle    IceRayC_Geometry_HField_Object_Vacuuum0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Object_Handle    IceRayC_Geometry_HField_Object_Geometry0();
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Geometry_HField_Object_Handle    IceRayC_Geometry_HField_Object_Geometry1( IceRayC_Geometry_Handle P_child );
IceRayC__EXPORT IceRayC__DECLSPEC IceRayC_Type_Bool                        IceRayC_Geometry_HField_Object_Geometry_Set( IceRayC_Geometry_HField_Object_Handle P_this, IceRayC_Geometry_Handle P_child );

#endif
