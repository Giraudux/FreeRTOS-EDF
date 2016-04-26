#!/bin/bash
set -x

wget https://launchpad.net/gcc-arm-embedded/4.9/4.9-2015-q3-update/+download/gcc-arm-none-eabi-4_9-2015q3-20150921-linux.tar.bz2

tar -xf gcc-arm-none-eabi-4_9-2015q3-20150921-linux.tar.bz2

rm gcc-arm-none-eabi-4_9-2015q3-20150921-linux.tar.bz2

mv gcc-arm-none-eabi-4_9-2015q3 gcc-arm-none-eabi

cat << "EOF" > Makefile
#
#	Makefile for FreeRTOS demo on Raspberry Pi
#

BASE=$(shell pwd)/
BUILD_DIR=$(shell pwd)/build/
PATH:=$(PATH):$(BASE)gcc-arm-none-eabi/arm-none-eabi/bin:$(BASE)gcc-arm-none-eabi/bin

MODULE_NAME="RaspberryPi BSP"

TARGETS=kernel.img kernel.list kernel.syms kernel.elf
LINKER_SCRIPT=raspberrypi.ld

-include .dbuild/dbuild.mk


all: kernel.list kernel.img kernel.syms
	@$(SIZE) kernel.elf

kernel.img: kernel.elf
	$(Q)$(PRETTY) IMAGE $(MODULE_NAME) $@
	$(Q)$(OBJCOPY) kernel.elf -O binary $@

kernel.list: kernel.elf
	$(Q)$(PRETTY) LIST $(MODULE_NAME) $@
	$(Q)$(OBJDUMP) -D -S  kernel.elf > $@

kernel.syms: kernel.elf
	$(Q)$(PRETTY) SYMS $(MODULE_NAME) $@
	$(Q)$(OBJDUMP) -t kernel.elf > $@

kernel.elf: LDFLAGS += -L "./gcc-arm-none-eabi/lib/gcc/arm-none-eabi/4.9.3"
kernel.elf: LDFLAGS += -L "./gcc-arm-none-eabi/arm-none-eabi/lib"
kernel.elf: LDFLAGS += -lgcc -lc
kernel.elf: $(OBJECTS)
	$(Q)$(LD) $(OBJECTS) -Map kernel.map -o $@ -T $(LINKER_SCRIPT) $(LDFLAGS)
EOF

make clean
make
