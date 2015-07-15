@ECHO OFF

REM This bat file help to create the C++ develop environment on your Windows machine

REM Change HOME variable for alternative .emacs.d location
REM If you need to create the separated emacs configuration files
SET HOME=%~dp0

REM This is specific for Windows 7 Pro SP1 setup environment file location
REM x64 for 64 bit architecture
CALL "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x64

REM Add the PATH to shell.bat and emacs.bat location
SET PATH=z:\myworkingdir\misc;%PATH%
