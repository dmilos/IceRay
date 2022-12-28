#!/bin/bash

reset

[ -e _makeGcc ] || mkdir _makeGcc
cd _makeGcc

#cmake -DCMAKE_BUILD_TYPE=Debug ..

#cmake -DCMAKE_BUILD_TYPE=Debug -DICERAY_SWITCH_DEBUG=1 ..
cmake  ..

make
