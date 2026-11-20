@echo off
rem Builds the campaign's C tools into build\ (git-ignored):
rem   build\symcov_import.exe   tools\symcov_import.c   symcov report -> reports/ lists
rem (a rule checker and a gate are planned; add their names to TOOLS below when their sources exist)
rem
rem Compiler: Visual Studio 2022's cl (vcvars64.bat), else the 2003 Toolkit's cl in portal\tools\msvc71\bin.
rem The sources are plain C (C89 declarations, no dependencies), so either compiler builds them.
rem Run it from anywhere: it works from the repository root.
setlocal
cd /d "%~dp0.."
if not exist build mkdir build

set "VCVARS=C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
set "TOOLS=symcov_import shar_bridge"

if exist "%VCVARS%" (
    call "%VCVARS%" >nul 2>nul
    if errorlevel 1 goto toolkit
    for %%T in (%TOOLS%) do (
        cl /nologo /O2 /W3 /D_CRT_SECURE_NO_WARNINGS /Fo"build\%%T.obj" /Fe"build\%%T.exe" "tools\%%T.c" >"build\%%T.log"
        if errorlevel 1 (type "build\%%T.log" & echo build failed: %%T & exit /b 1)
        echo built build\%%T.exe
    )
    del /q build\*.obj build\*.log 2>nul
    exit /b 0
)

:toolkit
set "MSVC71=%CD%\portal\tools\msvc71"
if not exist "%MSVC71%\bin\cl.exe" (
    echo No compiler: Visual Studio 2022 is not at the usual place and portal\tools\msvc71 is not set up.
    exit /b 1
)
set "PATH=%MSVC71%\bin;%PATH%"
set "INCLUDE=%MSVC71%\include"
set "LIB=%MSVC71%\lib"
for %%T in (%TOOLS%) do (
    cl /nologo /O2 /D_CRT_SECURE_NO_WARNINGS /Fo"build\%%T.obj" /Fe"build\%%T.exe" "tools\%%T.c" >"build\%%T.log"
    if errorlevel 1 (type "build\%%T.log" & echo build failed: %%T & exit /b 1)
    echo built build\%%T.exe
)
del /q build\*.obj build\*.log 2>nul
exit /b 0
