@ECHO OFF

REM if DEBUG mode: SET CommonCompilerFlags=-EHa -Zi

SET CommonCompilerFlags=-EHa
SET CommonLinkerFlags=user32.lib /link moncontroller_x64.res

pushd z:\build

cl %CommonCompilerFlags% moncontroller_x64.cpp %CommonLinkerFlags%

popd
