#!/bin/bash
if [ -f GTKWIN32/ ]; then
    continue
fi

if [ ! -f libmpc2-0.8.2-12.1.6.x86_64.rpm ]; then
wget ftp://mirror.switch.ch/pool/4/mirror/opensuse/opensuse/distribution/12.1/repo/oss/suse/x86_64/libmpc2-0.8.2-12.1.6.x86_64.rpm
fi
if [ ! -f mingw32-cross-gcc-5.1.0-10.10.x86_64.rpm ]; then
wget http://download.opensuse.org/repositories/windows:/mingw:/win32/openSUSE_13.2/x86_64/mingw32-cross-gcc-5.1.0-10.10.x86_64.rpm
fi
if [ ! -f mingw32-cross-breakpad-tools.ymp?base=openSUSE%3A13.2 ]; then
wget https://software.opensuse.org/ymp/windows:mingw:win32/openSUSE_13.2/mingw32-cross-breakpad-tools.ymp?base=openSUSE%3A13.2&query=mingw32-cross-breakpad-tools
fi
if [ ! -f mingw32-cross-binutils-2.25-3.1.x86_64.rpm ]; then
wget http://download.opensuse.org/repositories/windows:/mingw:/win32/openSUSE_13.2/x86_64/mingw32-cross-binutils-2.25-3.1.x86_64.rpm
fi
if [ ! -f mingw32-filesystem-20150401-2.1.noarch.rpm ]; then
wget http://download.opensuse.org/repositories/windows:/mingw:/win32/openSUSE_13.2/noarch/mingw32-filesystem-20150401-2.1.noarch.rpm
fi
if [ ! -f mingw32-cross-cpp-5.1.0-10.10.x86_64.rpm ]; then
wget http://download.opensuse.org/repositories/windows:/mingw:/win32/openSUSE_13.2/x86_64/mingw32-cross-cpp-5.1.0-10.10.x86_64.rpm
fi
if [ ! -f mingw32-headers-4.0.2-2.2.noarch.rpm ]; then
wget http://download.opensuse.org/repositories/windows:/mingw:/win32/openSUSE_13.2/noarch/mingw32-headers-4.0.2-2.2.noarch.rpm
fi
if [ ! -f mingw32-runtime-4.0.2-1.17.noarch.rpm ]; then
wget http://download.opensuse.org/repositories/windows:/mingw:/win32/openSUSE_13.2/noarch/mingw32-runtime-4.0.2-1.17.noarch.rpm
fi

if [ -f mingw32-cross-breakpad-tools.ymp?base=openSUSE%3A13.2 ]; then
sudo sh mingw32-cross-breakpad-tools.ymp?base=openSUSE%3A13.2
fi
if [ -f mingw32-cross-cpp-5.1.0-10.10.x86_64.rpm ]; then
sudo rpm -iv mingw32-cross-cpp-5.1.0-10.10.x86_64.rpm
fi
if [ -f mingw32-headers-4.0.2-2.2.noarch.rpm ]; then
sudo rpm -iv mingw32-headers-4.0.2-2.2.noarch.rpm
fi
if [ -f mingw32-runtime-4.0.2-1.17.noarch.rpm ]; then
sudo rpm -iv mingw32-runtime-4.0.2-1.17.noarch.rpm 
fi
if [ -f mingw32-cross-binutils-2.25-3.1.x86_64.rpm ]; then
sudo rpm -iv mingw32-cross-binutils-2.25-3.1.x86_64.rpm
fi
if [ -f mingw32-filesystem-20150401-2.1.noarch.rpm ]; then
sudo rpm -iv mingw32-filesystem-20150401-2.1.noarch.rpm
fi
if [ -f libmpc2-0.8.2-12.1.6.x86_64.rpm ]; then
sudo rpm -iv libmpc2-0.8.2-12.1.6.x86_64.rpm
fi
if [ -f mingw32-cross-gcc-5.1.0-10.10.x86_64.rpm ]; then
sudo rpm -iv mingw32-cross-gcc-5.1.0-10.10.x86_64.rpm
fi

make websms-exe-x64 websms-console-exe-x64 websms-exe-W32 websms-console-exe-W32

