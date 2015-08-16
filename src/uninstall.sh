#!/bin/bash

sudo make uninstall
cd SDK/
sudo make uninstall
cd ../
rm -rf SDK/
rm -rf CPP-SMS-Toolkit-1.0.0.zip
