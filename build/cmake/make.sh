#!/bin/bash

reset

[ -e _makeGcc ] || mkdir _makeGcc
cd _makeGcc

#cmake -DCMAKE_BUILD_TYPE=Debug ..
# ??? cmake --build debug ..

#cmake -DCMAKE_C_FLAGS="-g -g2 -Og -D_DEBUG -DDEBUG -ggdb -finstrument-functions"  -DCMAKE_CXX_FLAGS="-g -g2 -Og -D_DEBUG -DDEBUG -ggdb -finstrument-functions"  ..

#cmake -DCMAKE_BUILD_TYPE=Debug -DICERAY_SWITCH_DEBUG=1 ..
cmake  ..

make
