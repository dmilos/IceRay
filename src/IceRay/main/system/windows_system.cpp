#include <windows.h>
#include <commctrl.h>
#include <gdiplus.h>

#pragma comment( lib, "Msimg32.lib" )
#pragma comment( lib, "gdiplus.lib" )

#pragma comment( lib, "comctl32.lib" )
#pragma comment( lib, "Ole32.lib" )

// Dbghelp.lib

using namespace Gdiplus;

// system
namespace{
ULONG_PTR            GIs_GdiplusToken;
GdiplusStartupInput  GIs_GdiplusStartupInput;
GdiplusStartupOutput GIs_GdiplusStartupOutput;
}

void InitSystemWindows( void )
 {
  HMODULE I_com = LoadLibrary( "comctl32.dll" );
  GdiplusStartup( &GIs_GdiplusToken, &GIs_GdiplusStartupInput, &GIs_GdiplusStartupOutput );

  INITCOMMONCONTROLSEX I_icc;
  I_icc.dwSize=sizeof(INITCOMMONCONTROLSEX);
  I_icc.dwICC = ICC_TREEVIEW_CLASSES | 0x00008000 | ICC_BAR_CLASSES;
  OleInitialize( NULL );
  CoInitialize( NULL );
  InitCommonControlsEx( &I_icc );
//SetCurrentDirectory( GI_system.F_root().c_str() );
 }


void ShutDownSystemWindows( void )
 {
  GdiplusShutdown( GIs_GdiplusToken );
 }

BOOL APIENTRY DllMain(HMODULE module_handle, DWORD ul_reason_for_call, LPVOID /*lp_reserved*/)
 {
  switch (ul_reason_for_call)
   {
    case DLL_PROCESS_ATTACH:
     {
      extern void InitSystem( void );
      InitSystem();
     }break;

    case DLL_PROCESS_DETACH:
     {
      extern void ShutDownSystem( void );
      ShutDownSystem();
     }break;
   }
  return TRUE;
 }