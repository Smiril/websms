#!/bin/bash
if [ -f CPP-SMS-Toolkit-1.0.0.zip ]; then
    continue
fi

if [ ! -f CPP-SMS-Toolkit-1.0.0.zip ]; then
wget https://websms.at/images/websms/developer/sdks/CPP-SMS-Toolkit-1.0.0.zip
fi
if [ ! -f SDK ]; then
unzip -d SDK CPP-SMS-Toolkit-1.0.0.zip
fi
if [ ! -f glib-dev_2.34.3-1_win32.zip ]; then
wget http://win32builder.gnome.org/packages/3.6/glib-dev_2.34.3-1_win32.zip
fi
if [ ! -f glib-dev_2.34.3-1_win64.zip ]; then
wget http://win32builder.gnome.org/packages/3.6/glib-dev_2.34.3-1_win64.zip
fi
if [ ! -f gtk+-2.24.28.tar.xz ]; then
wget http://ftp.gnome.org/pub/gnome/sources/gtk+/2.24/gtk+-2.24.28.tar.xz
fi
if [ ! -f GTKLINUX ]; then
tar -xvf -J --directory=GTKLINUX gtk+-2.24.28.tar.xz
fi
if [ ! -f gtk+-dev_2.24.10-1_win32.zip ]; then
wget http://ftp.gnome.org/pub/gnome/binaries/win32/gtk+/2.24/gtk+-dev_2.24.10-1_win32.zip
fi
if [ ! -f gtk+-dev_3.6.4-1_win64.zip ]; then
wget http://win32builder.gnome.org/packages/3.6/gtk+-dev_3.6.4-1_win64.zip
fi
if [ ! -f glib-2.44.0.tar.xz ]; then
wget http://ftp.gnome.org/pub/gnome/sources/glib/2.44/glib-2.44.0.tar.xz
fi
if [ ! -f GTKWIN32 ]; then
unzip -d GTKWIN32 gtk+-dev_2.24.10-1_win32.zip
fi
if [ ! -f GLIBWIN32 ]; then
unzip -d GLIBWIN32 glib-dev_2.34.3-1_win32.zip
fi
if [ ! -f GTKWIN64 ]; then
unzip -d GTKWIN64 gtk+-dev_3.6.4-1_win64.zip
fi
if [ ! -f GLIBWIN64 ]; then
unzip -d GLIBWIN64 glib-dev_2.34.3-1_win64.zip
fi
if [ ! -f GLIBLINUX ]; then
tar -xvf -J --directory=GLIBLINUX glib-2.44.0.tar.xz
fi
cd SDK/
if [ -f /usr/local/lib/libwebsms.so.1.0 ]; then
    make clean
    sudo make uninstall
fi
make && sudo make install
cd ../
if [ -f GTKLINUX ]; then
cd GTKLINUX/
fi
if [ -f gtk+-2.24.28 ]; then
    cd gtk+-2.24.28
    sh ./configure
    make && sudo make install
    cd ../
fi
if [ -f gtk+-2.24.28 ]; then
cd ../
fi
make && sudo make websms 
sudo make websms-console


