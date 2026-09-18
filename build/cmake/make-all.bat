@rem mkdir _makeVS32
@rem cd _makeVS32
@rem 
@rem %prg_cmake% .. -A Win32
@rem %prg_cmake% --build . --config Release
@rem cd ..

mkdir _makeVS64
cd _makeVS64

%prg_cmake% .. -A x64

%prg_cmake% --build . --config Release
%prg_cmake% --install . --config Release

%prg_cmake% --build . --config Debug
%prg_cmake% --install . --config Debug

pause