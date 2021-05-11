#ifndef _68a061264ac04a16a22399b2d61ff8a8
#define _68a061264ac04a16a22399b2d61ff8a8

#include "../../../../system/system.h"
#include "../../../../type/size.h"
#include "./handle.h"

#define F(D_P) IceRayC_Material_Pigment_Surface_Instruction_Convert_##D_P
#define P(D_P) IceRayC_##D_P
#define S(D_P) IceRayC_Type_Size P_##D_P
#define H IceRayC_Material_Pigment_Surfcace_Instruction_Handle
#define E IceRayC__EXPORT
#define D IceRayC__DECLSPEC

E D H F( Bool2Bool0         )( S( result ), S( left ) );
E D H F( Bool2Integer0      )( S( result ), S( left ) );
E D H F( Bool2Size0         )( S( result ), S( left ) );
E D H F( Bool2Scalar0       )( S( result ), S( left ) );
E D H F( Bool2Color0        )( S( result ), S( left ) );
E D H F( Bool2Coord2D0      )( S( result ), S( left ) );
E D H F( Bool2Coord3D0      )( S( result ), S( left ) );

E D H F( Integer2Bool0         )( S( result ), S( left ) );
E D H F( Integer2Integer0      )( S( result ), S( left ) );
E D H F( Integer2Size0         )( S( result ), S( left ) );
E D H F( Integer2Scalar0       )( S( result ), S( left ) );
E D H F( Integer2Color0        )( S( result ), S( left ) );
E D H F( Integer2Coord2D0      )( S( result ), S( left ) );
E D H F( Integer2Coord3D0      )( S( result ), S( left ) );

E D H F( Size2Bool0         )( S( result ), S( left ) );
E D H F( Size2Integer0      )( S( result ), S( left ) );
E D H F( Size2Size0         )( S( result ), S( left ) );
E D H F( Size2Scalar0       )( S( result ), S( left ) );
E D H F( Size2Color0        )( S( result ), S( left ) );
E D H F( Size2Coord2D0      )( S( result ), S( left ) );
E D H F( Size2Coord3D0      )( S( result ), S( left ) );

E D H F( Scalar2Bool0         )( S( result ), S( left ) );
E D H F( Scalar2Integer0      )( S( result ), S( left ) );
E D H F( Scalar2Size0         )( S( result ), S( left ) );
E D H F( Scalar2Scalar0       )( S( result ), S( left ) );
E D H F( Scalar2Color0        )( S( result ), S( left ) );
E D H F( Scalar2Coord2D0      )( S( result ), S( left ) );
E D H F( Scalar2Coord3D0      )( S( result ), S( left ) );

E D H F( Color2Bool0         )( S( result ), S( left ) );
E D H F( Color2Integer0      )( S( result ), S( left ) );
E D H F( Color2Size0         )( S( result ), S( left ) );
E D H F( Color2Scalar0       )( S( result ), S( left ) );
E D H F( Color2Color0        )( S( result ), S( left ) );
E D H F( Color2Coord2D0      )( S( result ), S( left ) );
E D H F( Color2Coord3D0      )( S( result ), S( left ) );

E D H F( Coord2D2Bool0         )( S( result ), S( left ) );
E D H F( Coord2D2Integer0      )( S( result ), S( left ) );
E D H F( Coord2D2Size0         )( S( result ), S( left ) );
E D H F( Coord2D2Scalar0       )( S( result ), S( left ) );
E D H F( Coord2D2Color0        )( S( result ), S( left ) );
E D H F( Coord2D2Coord2D0      )( S( result ), S( left ) );
E D H F( Coord2D2Coord3D0      )( S( result ), S( left ) );

E D H F( Coord3D2Bool0         )( S( result ), S( left ) );
E D H F( Coord3D2Integer0      )( S( result ), S( left ) );
E D H F( Coord3D2Size0         )( S( result ), S( left ) );
E D H F( Coord3D2Scalar0       )( S( result ), S( left ) );
E D H F( Coord3D2Color0        )( S( result ), S( left ) );
E D H F( Coord3D2Coord2D0      )( S( result ), S( left ) );
E D H F( Coord3D2Coord3D0      )( S( result ), S( left ) );

// affine3d2affine3d

#undef D
#undef E
#undef H
#undef S
#undef P
#undef F

#endif
