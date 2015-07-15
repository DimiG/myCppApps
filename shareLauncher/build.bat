@ECHO OFF

REM if DEBUG mode: SET CommonCompilerFlags=-EHa -Zi
REM To convert .rc into .res file use Microsoft (R) Windows (R) Resource Compiler rc.exe
SET CommonCompilerFlags=-EHa
SET CommonLinkerFlags=/link shareLauncher.res

REM The z:\build is a build directory.
pushd z:\build

cl %CommonCompilerFlags% shareLauncher_x64.cpp %CommonLinkerFlags%

popd
