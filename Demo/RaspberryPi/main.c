#include <FreeRTOS.h>
#include <task.h>

#include "Drivers/interrupts.h"
#include "Drivers/gpio.h"

/**
 *
 */
void task0_aperiodic(void *pParam) {
    /* unused parameter */
    (void) pParam;

	for(;;) {
		vTaskDelay(100);
		SetGpio(16, 0);
		vTaskDelay(100);
	}
}

/**
 *
 */
void task1_aperiodic(void *pParam) {
    /* unused parameter */
    (void) pParam;

	for(;;) {
		SetGpio(16, 1);
		vTaskDelay(200);
	}
}

/**
 *
 */
void task0_periodic(void *pParam) {
    /* unused parameter */
    (void) pParam;

	vTaskDelay(100);
	SetGpio(16, 0);
	vTaskDelay(100);
}

/**
 *
 */
void task1_periodic(void *pParam) {
    /* unused parameter */
    (void) pParam;

	SetGpio(16, 1);
	vTaskDelay(200);
}

/**
 *	This is the systems main entry, some call it a boot thread.
 *
 *	-- Absolutely nothing wrong with this being called main(), just it doesn't have
 *	-- the same prototype as you'd see in a linux program.
 **/
int main(void) {

	DisableInterrupts();
	InitInterruptController();

	SetGpioFunction(16, 1);			// RDY led

	xTaskCreate(task0_aperiodic, "LED_0", 128, NULL, 0, NULL);
	xTaskCreate(task1_aperiodic, "LED_1", 128, NULL, 0, NULL);

	vTaskStartScheduler();

	/*
	 *	We should never get here, but just in case something goes wrong,
	 *	we'll place the CPU into a safe loop.
	 */
	for(;;) {
		;
	}

	return 0;
}
