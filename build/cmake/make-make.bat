mkdir _makeVS32
cd _makeVS32

%prg_cmake% .. -A Win32

cd ..

mkdir _makeVS64
cd _makeVS64

%prg_cmake% .. -A x64
 pause