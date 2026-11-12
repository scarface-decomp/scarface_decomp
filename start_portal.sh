#!/bin/sh
# Scarface decomp portal for macOS and Linux:  sh start_portal.sh
# Keeps its Python packages in portal/.venv, so nothing is installed system-wide.
cd "$(dirname "$0")" || exit 1

if ! command -v python3 >/dev/null 2>&1; then
  echo "Python 3 is not installed. Get it from https://www.python.org/downloads/ or your package manager."
  exit 1
fi
# The compiler: set up by itself the first time, when VCToolkitSetup.exe is in this folder, binaries/,
# source_archives/ or Downloads (needs msitools). Says nothing otherwise.
python3 portal/scripts/setup_msvc71.py --auto
# A quick setup check: says only what needs fixing. The full report: python3 portal/doctor.py
python3 portal/doctor.py --startup
export PYTHONDONTWRITEBYTECODE=1
if [ ! -x portal/.venv/bin/python ]; then
  echo "Setting up the portal's Python packages (first run only)..."
  python3 -m venv portal/.venv || { echo "Could not create portal/.venv. On Debian/Ubuntu: sudo apt install python3-venv"; exit 1; }
fi
# Exact versions (portal/requirements.txt), as ready-made wheels only: installing runs no package's setup code.
# A set-up that was cut short leaves portal/.venv without pip: put it back, or make the folder again.
portal/.venv/bin/python -m pip --version >/dev/null 2>&1 || portal/.venv/bin/python -m ensurepip --upgrade >/dev/null 2>&1 \
  || python3 -m venv --clear portal/.venv
portal/.venv/bin/python -m pip install --quiet --disable-pip-version-check --only-binary :all: -r portal/requirements.txt || {
  echo "Installing packages failed. Check your internet connection. If it says no matching distribution, use Python 3.12 or 3.13."; exit 1; }
echo "Starting the portal at http://localhost:${SCARFACE_PORT:-8085} (Ctrl+C stops it)."
echo "The first start takes a few minutes while it unpacks your files and lists every function."
exec portal/.venv/bin/python portal/decomp_portal_server.py
