
CFLAGS += -march=armv6z -g -Wall -Wextra
CFLAGS += -I $(BASE)/Source/include
CFLAGS += -I $(BASE)/Source/portable/GCC/RaspberryPi
CFLAGS += -I $(BASE)/Demo/RaspberryPi
CFLAGS += -I $(BASE)/Demo/RaspberryPi/Drivers

TOOLCHAIN=arm-none-eabi-

