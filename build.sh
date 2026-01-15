#!/bin/bash

git submodule update --init 

cp /repo/good-working-config /repo/buildroot/.config
mkdir -p /repo/buildroot/output/build/linux-custom/
cp /repo/linux.config /repo/buildroot/output/build/linux-custom/.config

make -C buildroot BR2_EXTERNAL=/repo/ext-tree -j73 linux-menuconfig

make -C buildroot BR2_EXTERNAL=/repo/ext-tree -j73 menuconfig
make -C buildroot BR2_EXTERNAL=/repo/ext-tree -j73

cp -r /repo/buildroot/output/images/ /repo/

cp /repo/config.txt /repo/images/

scp -r /repo/images/* "btardio@192.168.1.126":/var/lib/tftpboot/

