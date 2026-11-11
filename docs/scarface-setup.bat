@echo off
rem Scarface decomp: one file that sets everything up on Windows. Double-click it.
rem It installs Python and Git if you don't have them (with winget, Windows' own installer), puts the project
rem on your Desktop (or updates it if it is already there), and starts the portal.
rem Nothing here needs administrator rights. Read it first if you like: it is plain text.
title Scarface decomp setup
setlocal EnableExtensions

echo.
echo  Scarface decomp setup
echo  =====================
echo.

rem ---- Python
set "HAVE_PY="
py -3 --version >nul 2>&1 && set "HAVE_PY=1"
if not defined HAVE_PY python --version >nul 2>&1 && set "HAVE_PY=1"
if defined HAVE_PY goto :python_ok
call :need_winget || goto :fail
echo  Installing Python 3.13 ...
winget install -e --id Python.Python.3.13 --source winget
set "PATH=%LocalAppData%\Programs\Python\Launcher;%LocalAppData%\Programs\Python\Python313;%LocalAppData%\Programs\Python\Python313\Scripts;%PATH%"
py -3 --version >nul 2>&1 && goto :python_ok
python --version >nul 2>&1 && goto :python_ok
echo.
echo  Python did not install. Get it from https://www.python.org/downloads/ and tick
echo  "Add python.exe to PATH" on its first screen, then run this file again.
goto :fail
:python_ok
echo  Python: ready.

rem ---- Git
git --version >nul 2>&1 && goto :git_ok
call :need_winget || goto :fail
echo  Installing Git ...
winget install -e --id Git.Git --source winget
set "PATH=%ProgramFiles%\Git\cmd;%LocalAppData%\Programs\Git\cmd;%PATH%"
git --version >nul 2>&1 && goto :git_ok
echo.
echo  Git did not install. Get it from https://git-scm.com/downloads (the default options are fine),
echo  then run this file again.
goto :fail
:git_ok
echo  Git: ready.

rem ---- The project, on the Desktop
set "DESK=%USERPROFILE%\Desktop"
for /f "usebackq delims=" %%D in (`powershell -NoProfile -Command "[Environment]::GetFolderPath('Desktop')"`) do set "DESK=%%D"
set "PROJ=%DESK%\scarface_decomp"
if exist "%PROJ%\.git" goto :update
if exist "%PROJ%\START_PORTAL.bat" goto :have_folder
echo  Getting the project into %PROJ% ...
git clone https://github.com/scarface-decomp/scarface_decomp.git "%PROJ%"
if errorlevel 1 goto :clone_failed
goto :have_folder
:update
echo  The project is already in %PROJ%: getting the latest version ...
git -C "%PROJ%" pull --ff-only
:have_folder

echo.
echo  Almost there. Two files are yours to add (the project can't give you them):
echo.
echo    1. Your game: put the US Xbox disc image (.iso, .zip or .7z) in
echo       %PROJ%\binaries
echo    2. The compiler's installer, VCToolkitSetup.exe: put it in
echo       %PROJ%
echo       (or just leave it in your Downloads folder: it is found there too)
echo.
echo  The folder is opening now. Add them, then come back to this window.
start "" explorer "%PROJ%\binaries"
echo.
pause
echo.
call "%PROJ%\START_PORTAL.bat"
exit /b 0

:need_winget
winget --version >nul 2>&1 && exit /b 0
echo.
echo  This computer doesn't have winget, Windows' installer tool. Get "App Installer" from the
echo  Microsoft Store and run this file again, or install Python and Git yourself:
echo    https://www.python.org/downloads/   and   https://git-scm.com/downloads
exit /b 1

:clone_failed
echo.
echo  Couldn't get the project. Check your internet connection and run this file again.
echo  If a folder named scarface_decomp is already on your Desktop, rename it first.
:fail
echo.
pause
exit /b 1
