#!/bin/bash

sudo apt-get install build-essential libcurl4-openssl-dev libjansson-dev libgtk2.0-0 libglib2.0-0 libgdk-pixbuf2.0-0 libcairo2 libc6 git
cd src/
sh setup.sh
cd ../
echo "Make Windows Binary?(only Unbuntu x64) Do that? [Y,n]"
read input
if [[ $input == "Y" || $input == "y" ]]; then
        echo "doing that ..."
        cd src/
        sh W32_x64_unbuntu_build.sh
        cd ../
else
        echo "don't doing that ..."
fi
