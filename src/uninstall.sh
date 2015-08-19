#!/bin/bash

sudo make uninstall
cd SDK/
sudo make uninstall
cd ../
rm -rf SDK/
rm -rf CPP-SMS-Toolkit-1.0.0.zip
rm -rf GTKWIN32/
rm -rf gtk+-dev_2.24.10-1_win32.zip
rm -rf GTKLINUX/
rm -rf gtk+-2.24.28.tar.xz
