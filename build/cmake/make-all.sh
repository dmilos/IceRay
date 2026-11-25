#!/bin/bash

reset

source make-make.sh
cmake --build   . --parallel 16 -j 16
cmake --install .
