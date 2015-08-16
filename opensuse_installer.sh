#!/bin/bash

sudo zypper install libjansson4 libjansson4-32bit libjansson-devel curl libcurl4 libcurl4-32bit libcurl-devel at-spi2-atk-common at-spi2-atk-gtk2 glib glib-32bit gtk gtk2-branding-SLED gtk2-data gtk2-devel gtk2-immodule-amharic gtk2-immodule-inuktitut gtk2-metatheme-adwaita gtk2-tools gtk2-tools-32bit patterns-openSUSE-base patterns-openSUSE-devel_basis patterns-openSUSE-devel_C_C++ git
cd src/
sh setup.sh
cd ../
