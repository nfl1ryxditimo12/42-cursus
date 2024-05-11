#!/bin/bash

PYTHON_PATH="/usr/bin/python3"
PATH_URL="https://github.com/jaraco/path.git"

$PYTHON_PATH -m venv local_lib
source local_lib/bin/activate

python3 -m pip --version

python3 -m pip install --log pip_install.log --force-reinstall git+$PATH_URL

python3 my_program.py