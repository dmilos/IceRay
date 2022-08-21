reset

[ -e _makeGcc ] || mkdir _makeGcc
cd _makeGcc

cmake ..

make
