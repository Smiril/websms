#!/bin/bash
if [ -f CPP-SMS-Toolkit-1.0.0.zip ]; then
    continue
fi

if [ ! -f libmpc2-0.8.2-12.1.6.x86_64.rpm ]; then
wget ftp://mirror.switch.ch/pool/4/mirror/opensuse/opensuse/distribution/12.1/repo/oss/suse/x86_64/libmpc2-0.8.2-12.1.6.x86_64.rpm
fi
if [ ! -f gtk+-3.14.15.tar.xz ]; then
wget ftp://ftp.pbone.net/mirror/ftp5.gwdg.de/pub/opensuse/repositories/GNOME:/Apps:/Evince:/Windows:/3.6/openSUSE_12.2/x86_64/mingw32-cross-gcc-c++-4.8.1-11.3.x86_64.rpm
fi

sudo rpm -iv libmpc2-0.8.2-12.1.6.x86_64.rpm
sudo rpm -iv mingw32-cross-gcc-c++-4.8.1-11.3.x86_64.rpm

make websms-exe websms-console-exe

