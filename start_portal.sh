#!/bin/sh
# Scarface decomp portal for macOS and Linux:  sh start_portal.sh
# Keeps its Python packages in portal/.venv, so nothing is installed system-wide.
cd "$(dirname "$0")" || exit 1

if ! command -v python3 >/dev/null 2>&1; then
  echo "Python 3 is not installed. Get it from https://www.python.org/downloads/ or your package manager."
  exit 1
fi
if [ -z "$(ls binaries 2>/dev/null | grep -v -x -e README.md -e scripts_and_data)" ]; then
  echo "No game files yet: put the game, or the downloads it came in (the Xbox disc's .7z, .zip or .iso,"
  echo "and optionally the PC 1.00.2 patch), in binaries/ and start again. The portal unpacks them itself."
fi
export PYTHONDONTWRITEBYTECODE=1
if [ ! -x portal/.venv/bin/python ]; then
  echo "Setting up the portal's Python packages (first run only)..."
  python3 -m venv portal/.venv || { echo "Could not create portal/.venv. On Debian/Ubuntu: sudo apt install python3-venv"; exit 1; }
fi
portal/.venv/bin/python -m pip install --quiet --disable-pip-version-check -r portal/requirements.txt || exit 1
echo "Starting the portal at http://localhost:${SCARFACE_PORT:-8085} (Ctrl+C stops it)."
echo "The first start takes a few minutes while it unpacks your files and lists every function."
exec portal/.venv/bin/python portal/decomp_portal_server.py
