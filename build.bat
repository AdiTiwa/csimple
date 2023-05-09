@ECHO OFF

cd ./build
cmake --build .
cd Debug
csimple.exe