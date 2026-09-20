#!/bin/bash

reset

source make-make.sh
cmake --build   . --parallel 8
cmake --install .
