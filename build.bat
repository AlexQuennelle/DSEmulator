@echo off
echo Generating CMake files
for %%a in ("%~dp0\.") do set "parent=%%~nxa"
if not exist "Build" mkdir Build
cd Build
cmake ../ -G "Unix Makefiles"

echo Building Executable
make
start %parent%
exit
