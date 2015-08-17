#!/bin/bash
if [  -f CPP-SMS-Toolkit-1.0.0.zip ]; then
    continue
fi
if [ ! -f CPP-SMS-Toolkit-1.0.0.zip ]; then
wget https://websms.at/images/websms/developer/sdks/CPP-SMS-Toolkit-1.0.0.zip
unzip -d SDK CPP-SMS-Toolkit-1.0.0.zip
fi
cd SDK/
make && sudo make install
cd ../
sudo make
