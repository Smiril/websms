#!/bin/bash
if [ -f GTKWIN32/ ]; then
    continue
fi


sudo zypper install mingw32-cross-gcc mingw32-cross-g++ mingw32-cross-gcc-bootstrap mingw32-runtime mingw32-winpthreads


make websms-exe-x64 websms-console-exe-x64 websms-exe-W32 websms-console-exe-W32

