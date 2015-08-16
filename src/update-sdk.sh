#!/bin/bash

cd SDK/
sudo make uninstall
make && sudo make install
cd ../
sudo make
