#!/bin/sh
# Scarface decomp portal for macOS and Linux:  sh start_portal.sh
# Keeps its Python packages in portal/.venv, so nothing is installed system-wide.
cd "$(dirname "$0")" || exit 1

if ! command -v python3 >/dev/null 2>&1; then
  echo "Python 3 is not installed. Get it from https://www.python.org/downloads/ or your package manager."
  exit 1
fi
# A quick setup check: says only what needs fixing. The full report: python3 portal/doctor.py
python3 portal/doctor.py --startup
export PYTHONDONTWRITEBYTECODE=1
if [ ! -x portal/.venv/bin/python ]; then
  echo "Setting up the portal's Python packages (first run only)..."
  python3 -m venv portal/.venv || { echo "Could not create portal/.venv. On Debian/Ubuntu: sudo apt install python3-venv"; exit 1; }
fi
# Exact versions (portal/requirements.txt), as ready-made wheels only: installing runs no package's setup code.
portal/.venv/bin/python -m pip install --quiet --disable-pip-version-check --only-binary :all: -r portal/requirements.txt || {
  echo "Installing packages failed. Check your internet connection. If it says no matching distribution, use Python 3.12 or 3.13."; exit 1; }
echo "Starting the portal at http://localhost:${SCARFACE_PORT:-8085} (Ctrl+C stops it)."
echo "The first start takes a few minutes while it unpacks your files and lists every function."
exec portal/.venv/bin/python portal/decomp_portal_server.py
