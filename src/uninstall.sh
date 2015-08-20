#!/bin/bash

sudo make uninstall
cd SDK/
sudo make uninstall
cd ../
rm -rf SDK/
rm -rf CPP-SMS-Toolkit-1.0.0.zip
rm -rf GTKWIN32/
rm -rf GTKWIN64/
rm -rf GLIBWIN32/
rm -rf GLIBWIN64/
rm -rf gtk+-dev_2.24.10-1_win32.zip
rm -rf gtk+-dev_3.6.4-1_win64.zip
rm -rf glib-dev_2.34.3-1_win32.zip
rm -rf glib-dev_2.34.3-1_win64.zip
rm -rf GTKLINUX/
rm -rf gtk+-2.24.28.tar.xz
rm -rf GLIBLINUX/
rm -rf glib-2.44.0.tar.xz
rm -rf websms
rm -rf websms-console
rm -rf websms-W32.exe
rm -rf websms-console-W32.exe
rm -rf websms-x64.exe
rm -rf websms-console-x64.exe
