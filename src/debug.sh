#!/bin/bash
if [ -f CPP-SMS-Toolkit-1.0.0.zip ]; then
    continue
fi
if [ ! -f CPP-SMS-Toolkit-1.0.0.zip ]; then
wget https://websms.at/images/websms/developer/sdks/CPP-SMS-Toolkit-1.0.0.zip
if [ ! -f SDK ]; then
unzip -d SDK CPP-SMS-Toolkit-1.0.0.zip
fi
fi
cd SDK/
if [ -f /usr/local/lib/libwebsms.so.1.0 ]; then
    make clean
    sudo make uninstall
fi
make && sudo make install
cd ../
make debug-websms
make debug-websms-console
