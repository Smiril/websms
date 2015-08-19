#!/bin/bash
if [ -f CPP-SMS-Toolkit-1.0.0.zip ]; then
    continue
fi

if [ ! -f libmpc2-0.8.2-12.1.6.x86_64.rpm ]; then
wget ftp://mirror.switch.ch/pool/4/mirror/opensuse/opensuse/distribution/12.1/repo/oss/suse/x86_64/libmpc2-0.8.2-12.1.6.x86_64.rpm
fi
if [ ! -f mingw32-cross-gcc-5.1.0-10.10.x86_64.rpm ]; then
wget http://download.opensuse.org/repositories/windows:/mingw:/win32/openSUSE_13.2/x86_64/mingw32-cross-gcc-5.1.0-10.10.x86_64.rpm
fi

if [ -f libmpc2-0.8.2-12.1.6.x86_64.rpm ]; then
sudo rpm -iv libmpc2-0.8.2-12.1.6.x86_64.rpm
fi
if [ -f mingw32-cross-gcc-5.1.0-10.10.x86_64.rpm ]; then
sudo rpm -iv mingw32-cross-gcc-5.1.0-10.10.x86_64.rpm
fi

make websms-exe-x64 websms-console-exe-x64 websms-exe-W32 websms-console-exe-W32

