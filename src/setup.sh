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
if [ ! -f gtk+-3.14.15.tar.xz ]; then
wget http://ftp.gnome.org/pub/gnome/sources/gtk+/3.14/gtk+-3.14.15.tar.xz
fi
if [ ! -f GTKLINUX ]; then
tar -xvf -J --directory=GTKLINUX gtk+-3.14.15.tar.xz
fi
if [ ! -f gtk+-dev_3.6.4-1_win32.zip ]; then
wget http://win32builder.gnome.org/packages/3.6/gtk+-dev_3.6.4-1_win32.zip
fi
if [ ! -f GTKWIN32 ]; then
unzip -d GTKWIN32 gtk+-dev_3.6.4-1_win32.zip
fi

cd SDK/
if [ -f /usr/local/lib/libwebsms.so.1.0 ]; then
    make clean
    sudo make uninstall
fi
make && sudo make install
cd ../
make && sudo make install
echo "Make Windows Binary?(only Opensuse x64) Do that? [Y,n]"
read input
if [[ $input == "Y" || $input == "y" ]]; then
        echo "doing that ..."
        sh W32_x64_opensuse_build.sh
else
        echo "don't doing that ..."
fi

