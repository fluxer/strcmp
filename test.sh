#!/bin/sh

cmake . -DCMAKE_BUILD_TYPE=Release
make
./strcmp_test

git clean -f -d -x

cmake . -DCMAKE_BUILD_TYPE=Debug
make
./strcmp_test
