#!/bin/bash

wget https://websms.at/images/websms/developer/sdks/CPP-SMS-Toolkit-1.0.0.zip
unzip -d SDK CPP-SMS-Toolkit-1.0.0.zip
cd SDK/
make && sudo make install
cd ../
rm -rf SDK CPP-SMS-Toolkit-1.0.0.zip
sudo make
