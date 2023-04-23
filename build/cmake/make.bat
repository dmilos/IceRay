@rem mkdir _makeVS
@rem cd _makeVS
@rem 
@rem %prg_cmake% .. -A Win32
@rem 
@rem cd ..

mkdir _makeVS64
cd _makeVS64

%prg_cmake% .. -A x64

pause