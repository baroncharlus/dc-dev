#!/bin/bash

echo "enter the name of the bin (w/ extension):"
read binimage
make
sh-elf-objcopy -R .stack -O binary main.elf $binimage
dc-tool -x $binimage -t 192.168.1.210
