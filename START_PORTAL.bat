@echo off
rem Scarface decomp portal: double-click to start. Installs what it needs the first time.
title Scarface decomp portal
cd /d "%~dp0"

set "PY="
where py >nul 2>&1 && set "PY=py -3"
if not defined PY where python >nul 2>&1 && set "PY=python"
if not defined PY (
  echo.
  echo  Python 3 is not installed.
  echo  Get it from https://www.python.org/downloads/ and, on the installer's first screen,
  echo  tick "Add python.exe to PATH". Then double-click START_PORTAL.bat again.
  echo.
  pause
  exit /b 1
)

if not exist "binaries\Scarface.exe" if not exist "binaries\default.xbe" (
  echo.
  echo  No game files yet. Copy Scarface.exe ^(PC 1.00.2^) and/or default.xbe ^(Xbox^)
  echo  into the "binaries" folder next to this file, then start the portal again.
  echo  The portal will still open, but it has nothing to show without them.
  echo.
)

rem The portal's packages live in .venv inside this folder, so nothing is installed system-wide
rem and no administrator rights are needed.
if not exist ".venv\Scripts\python.exe" (
  echo  Setting up the portal's Python packages ^(first run only^)...
  %PY% -m venv .venv
  if errorlevel 1 (
    echo.
    echo  Could not create the .venv folder. Reinstall Python from https://www.python.org/downloads/
    echo  with the default options, then try again.
    pause
    exit /b 1
  )
)
echo  Checking the Python packages the portal needs...
".venv\Scripts\python.exe" -m pip install --quiet --disable-pip-version-check -r requirements.txt
if errorlevel 1 (
  echo.
  echo  Installing packages failed. Check your internet connection and try again.
  pause
  exit /b 1
)

if not defined SCARFACE_PORT set "SCARFACE_PORT=8085"
echo  Starting the portal. Your browser will open http://localhost:%SCARFACE_PORT%
echo  The first start takes a few minutes while it lists every function in your game files.
echo  Keep this window open while you work; close it to stop the portal.
echo.
".venv\Scripts\python.exe" decomp_portal_server.py
pause
