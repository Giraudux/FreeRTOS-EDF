--- portISR.c	2012-08-12 12:41:56.000000000 +0200
+++ /comptes/E129986P/TER/FreeRTOSV8.2.3/FreeRTOS/Source/portable/GCC/ARM7_LPC2000/portISR.c	2016-03-16 11:23:45.452090721 +0100
@@ -1,92 +0,0 @@
-/*
-    FreeRTOS V7.2.0 - Copyright (C) 2012 Real Time Engineers Ltd.
-	
-
-    ***************************************************************************
-     *                                                                       *
-     *    FreeRTOS tutorial books are available in pdf and paperback.        *
-     *    Complete, revised, and edited pdf reference manuals are also       *
-     *    available.                                                         *
-     *                                                                       *
-     *    Purchasing FreeRTOS documentation will not only help you, by       *
-     *    ensuring you get running as quickly as possible and with an        *
-     *    in-depth knowledge of how to use FreeRTOS, it will also help       *
-     *    the FreeRTOS project to continue with its mission of providing     *
-     *    professional grade, cross platform, de facto standard solutions    *
-     *    for microcontrollers - completely free of charge!                  *
-     *                                                                       *
-     *    >>> See http://www.FreeRTOS.org/Documentation for details. <<<     *
-     *                                                                       *
-     *    Thank you for using FreeRTOS, and thank you for your support!      *
-     *                                                                       *
-    ***************************************************************************
-
-
-    This file is part of the FreeRTOS distribution.
-
-    FreeRTOS is free software; you can redistribute it and/or modify it under
-    the terms of the GNU General Public License (version 2) as published by the
-    Free Software Foundation AND MODIFIED BY the FreeRTOS exception.
-    >>>NOTE<<< The modification to the GPL is included to allow you to
-    distribute a combined work that includes FreeRTOS without being obliged to
-    provide the source code for proprietary components outside of the FreeRTOS
-    kernel.  FreeRTOS is distributed in the hope that it will be useful, but
-    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
-    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
-    more details. You should have received a copy of the GNU General Public
-    License and the FreeRTOS license exception along with FreeRTOS; if not it
-    can be viewed here: http://www.freertos.org/a00114.html and also obtained
-    by writing to Richard Barry, contact details for whom are available on the
-    FreeRTOS WEB site.
-
-    1 tab == 4 spaces!
-    
-    ***************************************************************************
-     *                                                                       *
-     *    Having a problem?  Start by reading the FAQ "My application does   *
-     *    not run, what could be wrong?                                      *
-     *                                                                       *
-     *    http://www.FreeRTOS.org/FAQHelp.html                               *
-     *                                                                       *
-    ***************************************************************************
-
-    
-    http://www.FreeRTOS.org - Documentation, training, latest information, 
-    license and contact details.
-    
-    http://www.FreeRTOS.org/plus - A selection of FreeRTOS ecosystem products,
-    including FreeRTOS+Trace - an indispensable productivity tool.
-
-    Real Time Engineers ltd license FreeRTOS to High Integrity Systems, who sell 
-    the code with commercial support, indemnification, and middleware, under 
-    the OpenRTOS brand: http://www.OpenRTOS.com.  High Integrity Systems also
-    provide a safety engineered and independently SIL3 certified version under 
-    the SafeRTOS brand: http://www.SafeRTOS.com.
-*/
-
-
-/*-----------------------------------------------------------
- * Components that can be compiled to either ARM or THUMB mode are
- * contained in port.c  The ISR routines, which can only be compiled
- * to ARM mode, are contained in this file.
- *----------------------------------------------------------*/
-
-/*
-	Changes from V2.5.2
-		
-	+ The critical section management functions have been changed.  These no
-	  longer modify the stack and are safe to use at all optimisation levels.
-	  The functions are now also the same for both ARM and THUMB modes.
-
-	Changes from V2.6.0
-
-	+ Removed the 'static' from the definition of vNonPreemptiveTick() to 
-	  allow the demo to link when using the cooperative scheduler.
-
-	Changes from V3.2.4
-
-	+ The assembler statements are now included in a single asm block rather
-	  than each line having its own asm block.
-*/
-
-
@@ -97,2 +5,2 @@
-#define portTIMER_MATCH_ISR_BIT		( ( unsigned char ) 0x01 )
-#define portCLEAR_VIC_INTERRUPT		( ( unsigned long ) 0 )
+#define portTIMER_MATCH_ISR_BIT		( ( uint8_t ) 0x01 )
+#define portCLEAR_VIC_INTERRUPT		( ( uint32_t ) 0 )
@@ -101,2 +9,2 @@
-#define portNO_CRITICAL_NESTING		( ( unsigned long ) 0 )
-volatile unsigned long ulCriticalNesting = 9999UL;
+#define portNO_CRITICAL_NESTING		( ( uint32_t ) 0 )
+volatile uint32_t ulCriticalNesting = 9999UL;
@@ -109 +17 @@
-/* 
+/*
@@ -127 +35 @@
- * When a context switch is performed from the task level the saved task 
+ * When a context switch is performed from the task level the saved task
@@ -134,2 +42,2 @@
-	/* Within an IRQ ISR the link register has an offset from the true return 
-	address, but an SWI ISR does not.  Add the offset manually so the same 
+	/* Within an IRQ ISR the link register has an offset from the true return
+	address, but an SWI ISR does not.  Add the offset manually so the same
@@ -146 +54 @@
-	portRESTORE_CONTEXT();	
+	portRESTORE_CONTEXT();
@@ -150 +58 @@
-/* 
+/*
@@ -157 +65 @@
-	portSAVE_CONTEXT();	
+	portSAVE_CONTEXT();
@@ -159 +67 @@
-	/* Increment the RTOS tick count, then look for the highest priority 
+	/* Increment the RTOS tick count, then look for the highest priority
@@ -161,5 +69,8 @@
-	__asm volatile( "bl vTaskIncrementTick" );
-
-	#if configUSE_PREEMPTION == 1
-		__asm volatile( "bl vTaskSwitchContext" );
-	#endif
+	__asm volatile
+	(
+		"	bl xTaskIncrementTick	\t\n" \
+		"	cmp r0, #0				\t\n" \
+		"	beq SkipContextSwitch	\t\n" \
+		"	bl vTaskSwitchContext	\t\n" \
+		"SkipContextSwitch:			\t\n"
+	);
@@ -170 +81 @@
-	
+
@@ -189 +100 @@
-		__asm volatile ( 
+		__asm volatile (
@@ -197 +108 @@
-			
+
@@ -200,5 +111,5 @@
-		__asm volatile ( 
-			"STMDB	SP!, {R0}		\n\t"	/* Push R0.									*/	
-			"MRS	R0, CPSR		\n\t"	/* Get CPSR.								*/	
-			"BIC	R0, R0, #0xC0	\n\t"	/* Enable IRQ, FIQ.							*/	
-			"MSR	CPSR, R0		\n\t"	/* Write back modified value.				*/	
+		__asm volatile (
+			"STMDB	SP!, {R0}		\n\t"	/* Push R0.									*/
+			"MRS	R0, CPSR		\n\t"	/* Get CPSR.								*/
+			"BIC	R0, R0, #0xC0	\n\t"	/* Enable IRQ, FIQ.							*/
+			"MSR	CPSR, R0		\n\t"	/* Write back modified value.				*/
@@ -218 +129 @@
-	__asm volatile ( 
+	__asm volatile (
@@ -225 +136 @@
-	/* Now interrupts are disabled ulCriticalNesting can be accessed 
+	/* Now interrupts are disabled ulCriticalNesting can be accessed
@@ -243,5 +154,5 @@
-			__asm volatile ( 
-				"STMDB	SP!, {R0}		\n\t"	/* Push R0.						*/	
-				"MRS	R0, CPSR		\n\t"	/* Get CPSR.					*/	
-				"BIC	R0, R0, #0xC0	\n\t"	/* Enable IRQ, FIQ.				*/	
-				"MSR	CPSR, R0		\n\t"	/* Write back modified value.	*/	
+			__asm volatile (
+				"STMDB	SP!, {R0}		\n\t"	/* Push R0.						*/
+				"MRS	R0, CPSR		\n\t"	/* Get CPSR.					*/
+				"BIC	R0, R0, #0xC0	\n\t"	/* Enable IRQ, FIQ.				*/
+				"MSR	CPSR, R0		\n\t"	/* Write back modified value.	*/
