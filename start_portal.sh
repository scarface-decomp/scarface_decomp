#!/bin/sh
# Scarface decomp portal for macOS and Linux:  sh start_portal.sh
# Keeps its Python packages in .venv inside this folder, so nothing is installed system-wide.
cd "$(dirname "$0")" || exit 1

if ! command -v python3 >/dev/null 2>&1; then
  echo "Python 3 is not installed. Get it from https://www.python.org/downloads/ or your package manager."
  exit 1
fi
if [ ! -f binaries/Scarface.exe ] && [ ! -f binaries/default.xbe ]; then
  echo "No game files yet: copy Scarface.exe (PC 1.00.2) and/or default.xbe (Xbox) into binaries/."
fi
if [ ! -x .venv/bin/python ]; then
  echo "Setting up the portal's Python packages (first run only)..."
  python3 -m venv .venv || { echo "Could not create .venv. On Debian/Ubuntu: sudo apt install python3-venv"; exit 1; }
fi
.venv/bin/python -m pip install --quiet --disable-pip-version-check -r requirements.txt || exit 1
echo "Starting the portal at http://localhost:${SCARFACE_PORT:-8085} (Ctrl+C stops it)."
echo "The first start takes a few minutes while it lists every function in your game files."
exec .venv/bin/python decomp_portal_server.py
