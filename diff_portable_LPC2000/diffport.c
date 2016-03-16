--- port.c	2012-08-12 12:41:56.000000000 +0200
+++ /comptes/E129986P/TER/FreeRTOSV8.2.3/FreeRTOS/Source/portable/GCC/ARM7_LPC2000/port.c	2016-03-16 11:23:38.003846857 +0100
@@ -1,76 +0,0 @@
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
- * Implementation of functions defined in portable.h for the ARM7 port.
- *
- * Components that can be compiled to either ARM or THUMB mode are
- * contained in this file.  The ISR routines, which can only be compiled
- * to ARM mode are contained in portISR.c.
- *----------------------------------------------------------*/
-
-
@@ -85,4 +9,4 @@
-#define portINITIAL_SPSR				( ( portSTACK_TYPE ) 0x1f ) /* System mode, ARM mode, interrupts enabled. */
-#define portTHUMB_MODE_BIT				( ( portSTACK_TYPE ) 0x20 )
-#define portINSTRUCTION_SIZE			( ( portSTACK_TYPE ) 4 )
-#define portNO_CRITICAL_SECTION_NESTING	( ( portSTACK_TYPE ) 0 )
+#define portINITIAL_SPSR				( ( StackType_t ) 0x1f ) /* System mode, ARM mode, interrupts enabled. */
+#define portTHUMB_MODE_BIT				( ( StackType_t ) 0x20 )
+#define portINSTRUCTION_SIZE			( ( StackType_t ) 4 )
+#define portNO_CRITICAL_SECTION_NESTING	( ( StackType_t ) 0 )
@@ -91 +15 @@
-#define portENABLE_TIMER			( ( unsigned char ) 0x01 )
+#define portENABLE_TIMER			( ( uint8_t ) 0x01 )
@@ -93,2 +17,2 @@
-#define portINTERRUPT_ON_MATCH		( ( unsigned long ) 0x01 )
-#define portRESET_COUNT_ON_MATCH	( ( unsigned long ) 0x02 )
+#define portINTERRUPT_ON_MATCH		( ( uint32_t ) 0x01 )
+#define portRESET_COUNT_ON_MATCH	( ( uint32_t ) 0x02 )
@@ -97,3 +21,3 @@
-#define portTIMER_VIC_CHANNEL		( ( unsigned long ) 0x0004 )
-#define portTIMER_VIC_CHANNEL_BIT	( ( unsigned long ) 0x0010 )
-#define portTIMER_VIC_ENABLE		( ( unsigned long ) 0x0020 )
+#define portTIMER_VIC_CHANNEL		( ( uint32_t ) 0x0004 )
+#define portTIMER_VIC_CHANNEL_BIT	( ( uint32_t ) 0x0010 )
+#define portTIMER_VIC_ENABLE		( ( uint32_t ) 0x0020 )
@@ -120 +44 @@
-portSTACK_TYPE *pxPortInitialiseStack( portSTACK_TYPE *pxTopOfStack, pdTASK_CODE pxCode, void *pvParameters )
+StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters )
@@ -122 +46 @@
-portSTACK_TYPE *pxOriginalTOS;
+StackType_t *pxOriginalTOS;
@@ -136 +60 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) pxCode + portINSTRUCTION_SIZE;		
+	*pxTopOfStack = ( StackType_t ) pxCode + portINSTRUCTION_SIZE;		
@@ -139 +63 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0xaaaaaaaa;	/* R14 */
+	*pxTopOfStack = ( StackType_t ) 0xaaaaaaaa;	/* R14 */
@@ -141 +65 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) pxOriginalTOS; /* Stack used when task starts goes in R13. */
+	*pxTopOfStack = ( StackType_t ) pxOriginalTOS; /* Stack used when task starts goes in R13. */
@@ -143 +67 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x12121212;	/* R12 */
+	*pxTopOfStack = ( StackType_t ) 0x12121212;	/* R12 */
@@ -145 +69 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x11111111;	/* R11 */
+	*pxTopOfStack = ( StackType_t ) 0x11111111;	/* R11 */
@@ -147 +71 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x10101010;	/* R10 */
+	*pxTopOfStack = ( StackType_t ) 0x10101010;	/* R10 */
@@ -149 +73 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x09090909;	/* R9 */
+	*pxTopOfStack = ( StackType_t ) 0x09090909;	/* R9 */
@@ -151 +75 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x08080808;	/* R8 */
+	*pxTopOfStack = ( StackType_t ) 0x08080808;	/* R8 */
@@ -153 +77 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x07070707;	/* R7 */
+	*pxTopOfStack = ( StackType_t ) 0x07070707;	/* R7 */
@@ -155 +79 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x06060606;	/* R6 */
+	*pxTopOfStack = ( StackType_t ) 0x06060606;	/* R6 */
@@ -157 +81 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x05050505;	/* R5 */
+	*pxTopOfStack = ( StackType_t ) 0x05050505;	/* R5 */
@@ -159 +83 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x04040404;	/* R4 */
+	*pxTopOfStack = ( StackType_t ) 0x04040404;	/* R4 */
@@ -161 +85 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x03030303;	/* R3 */
+	*pxTopOfStack = ( StackType_t ) 0x03030303;	/* R3 */
@@ -163 +87 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x02020202;	/* R2 */
+	*pxTopOfStack = ( StackType_t ) 0x02020202;	/* R2 */
@@ -165 +89 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x01010101;	/* R1 */
+	*pxTopOfStack = ( StackType_t ) 0x01010101;	/* R1 */
@@ -170 +94 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) pvParameters; /* R0 */
+	*pxTopOfStack = ( StackType_t ) pvParameters; /* R0 */
@@ -175 +99 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) portINITIAL_SPSR;
+	*pxTopOfStack = ( StackType_t ) portINITIAL_SPSR;
@@ -177 +101 @@
-	if( ( ( unsigned long ) pxCode & 0x01UL ) != 0x00 )
+	if( ( ( uint32_t ) pxCode & 0x01UL ) != 0x00 )
@@ -195 +119 @@
-portBASE_TYPE xPortStartScheduler( void )
+BaseType_t xPortStartScheduler( void )
@@ -221 +145 @@
-unsigned long ulCompareMatch;
+uint32_t ulCompareMatch;
@@ -250 +174 @@
-	VICVectAddr0 = ( long ) vTickISR;
+	VICVectAddr0 = ( int32_t ) vTickISR;
