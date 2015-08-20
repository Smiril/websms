#!/bin/bash
if [ -f GTKWIN32/ ]; then
    continue
fi


sudo zypper install mingw32-cross-gcc mingw32-cross-gcc-bootstrap mingw32-runtime


make websms-exe-W32
make websms-console-exe-W32
make websms-exe-x64
make websms-console-exe-x64 

