#!/bin/bash

reset

[ -e _makeGcc ] || mkdir _makeGcc
cd _makeGcc

cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build   . --parallel 8
cmake --install .
