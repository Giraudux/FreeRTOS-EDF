#!/bin/bash

wget https://launchpad.net/gcc-arm-embedded/4.9/4.9-2015-q3-update/+download/gcc-arm-none-eabi-4_9-2015q3-20150921-linux.tar.bz2

tar -xf gcc-arm-none-eabi-4_9-2015q3-20150921-linux.tar.bz2

rm gcc-arm-none-eabi-4_9-2015q3-20150921-linux.tar.bz2

export PATH=$PATH:./gcc-arm-none-eabi-4_9-2015q3/arm-none-eabi/bin:./gcc-arm-none-eabi-4_9-2015q3/bin
