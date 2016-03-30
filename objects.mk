#
#	FreeRTOS portable layer for RaspberryPi
#
OBJECTS += $(BUILD_DIR)/Source/portable/GCC/RaspberryPi/port.o
OBJECTS += $(BUILD_DIR)/Source/portable/GCC/RaspberryPi/portisr.o

#
#	FreeRTOS Core
#
OBJECTS += $(BUILD_DIR)/Source/croutine.o
#OBJECTS += $(BUILD_DIR)/Source/event_groups.o
OBJECTS += $(BUILD_DIR)/Source/list.o
OBJECTS += $(BUILD_DIR)/Source/queue.o
OBJECTS += $(BUILD_DIR)/Source/tasks.o
#OBJECTS += $(BUILD_DIR)/Source/timers.o

#
#	Interrupt Manager & GPIO Drivers
#
OBJECTS += $(BUILD_DIR)/Demo/RaspberryPi/Drivers/interrupts.o
OBJECTS += $(BUILD_DIR)/Demo/RaspberryPi/Drivers/gpio.o

$(BUILD_DIR)/Source/portable/GCC/RaspberryPi/port.o: CFLAGS += -I $(BASE)/Demo/RaspberryPi/

#
#	Selected HEAP implementation for FreeRTOS.
#
OBJECTS += $(BUILD_DIR)/Source/portable/MemMang/heap_4.o

#
#	Startup and platform initialisation code.
#
OBJECTS += $(BUILD_DIR)/Demo/RaspberryPi/startup.o


#
#	Main Test Program
#
OBJECTS += $(BUILD_DIR)/Demo/RaspberryPi/main.o

