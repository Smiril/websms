#!/bin/bash

cd SDK/
sudo make uninstall
make && sudo make install
cd ../
zip -r -9 -v -x *.o ./SDK/*
sudo make
