#include <FreeRTOS.h>
#include <task.h>

#include "Drivers/interrupts.h"
#include "Drivers/gpio.h"

/**
 *
 */
 
void wait(UBaseType_t durationMS){
	UBaseType_t tickPeriodMS_start = xTaskGetTickCount()*portTICK_PERIOD_MS;
	UBaseType_t tickPeriodMS_current;
	for(
		tickPeriodMS_current = tickPeriodMS_start;
	 	tickPeriodMS_current<tickPeriodMS_start+durationMS;
	  	tickPeriodMS_current = xTaskGetTickCount()*portTICK_PERIOD_MS
	  );
}

/**
 *
 */
void task16(void *pParam) {
    /* unused parameter */
    (void) pParam;

	for(;;) {
		SetGpio(16, 1);
		wait(1000);
		SetGpio(16, 0);
		wait(1000);
	}
}

/**
 *
 */
void task18(void *pParam) {
    /* unused parameter */
    (void) pParam;

	for(;;) {
		SetGpio(18, 1);
		wait(750);
		SetGpio(18, 0);
		wait(750);
	}
}
void taskblue(void *pParam) {
    /* unused parameter */
    (void) pParam;

	TickType_t lastWakeTime;
	int i;
    /*
     * This variable must be initialized once.
     * Then it will be updated automatically by vTaskDelayUntil().
     */
     
    lastWakeTime = xTaskGetTickCount();
    for(;;){
    SetGpioFunction(24, 1);
		for(i=0;i<3;i++) {
			SetGpio(24, 1);
			wait(500);
			SetGpio(24, 0);
			wait(500);
		}
		SetGpioFunction(24, 0);
		vTaskDelayUntil( &lastWakeTime, 9000 / portTICK_RATE_MS );
	}
	/*
     * If the task implementation ever manages to break out of the
     * infinite loop above, it must be deleted before reaching the
     * end of the function!
     */
    vTaskDelete(NULL);
}
void taskgreen(void *pParam) {
    /* unused parameter */
    SetGpioFunction(23, 1);
    
    (void) pParam;

	TickType_t lastWakeTime;
	int i;
    /*
     * This variable must be initialized once.
     * Then it will be updated automatically by vTaskDelayUntil().
     */
     
    lastWakeTime = xTaskGetTickCount();
    for(;;){
		for(i=0;i<5;i++) {
			SetGpio(23, 1);
			wait(500);
			SetGpio(23, 0);
			wait(500);
		}
		vTaskDelayUntil( &lastWakeTime, 18000 / portTICK_RATE_MS );
	}
	/*
     * If the task implementation ever manages to break out of the
     * infinite loop above, it must be deleted before reaching the
     * end of the function!
     */
    vTaskDelete(NULL);
}
void taskred(void *pParam) {
	SetGpioFunction(18, 1);			// RDY led

	(void) pParam;
	TickType_t lastWakeTime;
	int i;
    /*
     * This variable must be initialized once.
     * Then it will be updated automatically by vTaskDelayUntil().
     */
    lastWakeTime = xTaskGetTickCount();
    for(;;){
    	for(i=0;i<4;i++) {
		SetGpio(18, 1);
		wait(500);
		SetGpio(18, 0);
		wait(500);
		}
		vTaskDelayUntil( &lastWakeTime, 18000 / portTICK_RATE_MS );
    }
    /*
     * If the task implementation ever manages to break out of the
     * infinite loop above, it must be deleted before reaching the
     * end of the function!
     */
    vTaskDelete(NULL);
}
void taskgauche(void *pParam) {
    /* unused parameter */
    (void) pParam;

	for(;;) {
		SetGpio(8, 1);
		vTaskDelay(500);
		SetGpio(8, 0);
		vTaskDelay(500);
	}
}
void taskdroite(void *pParam) {
    /* unused parameter */
    (void) pParam;

	for(;;) {
		vTaskDelay(250);
		SetGpio(7, 1);
		vTaskDelay(250);
		SetGpio(7, 0);
		
	}
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


	
			// RDY led
	SetGpioFunction(16, 1);
	SetGpioFunction(8, 1);
/*
	xTaskCreate(task16, "LED_16", 128, NULL, 0, NULL);
	xTaskCreate(task18, "LED_18", 128, NULL, 0, NULL);
	xTaskCreate(task23, "LED_23", 128, NULL, 0, NULL);
	*/
	//SetGpioFunction(24, 1);
	xTaskCreate(taskgauche, "LED_8", 128, NULL, 4, NULL);
	xTaskCreate(taskred, "LED_18", 128, NULL, 1, NULL);
	xTaskCreate(taskgreen, "LED_23", 128, NULL, 2, NULL);
	xTaskCreate(taskblue, "LED_24", 128, NULL,3, NULL);
	
	

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
