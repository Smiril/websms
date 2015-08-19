#!/bin/bash
if [ -f GTKWIN32/ ]; then
    continue
fi

sudo apt-get install mingw-w64 mingw-w64-tools mingw-w64-common mingw-w64-i686-dev mingw-w64-x86-64-dev g++-mingw-w64-i686

make websms-exe-x64 websms-console-exe-x64 websms-exe-W32 websms-console-exe-W32

