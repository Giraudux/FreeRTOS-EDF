--- portmacro.h	2012-08-12 12:41:56.000000000 +0200
+++ /comptes/E129986P/TER/FreeRTOSV8.2.3/FreeRTOS/Source/portable/GCC/ARM7_LPC2000/portmacro.h	2016-03-16 11:23:53.424351759 +0100
@@ -1,66 +0,0 @@
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
@@ -75 +9 @@
- * Port specific definitions.  
+ * Port specific definitions.
@@ -90 +24 @@
-#define portSTACK_TYPE	unsigned portLONG
+#define portSTACK_TYPE	uint32_t
@@ -92,0 +27,4 @@
+typedef portSTACK_TYPE StackType_t;
+typedef long BaseType_t;
+typedef unsigned long UBaseType_t;
+
@@ -94,2 +32,2 @@
-	typedef unsigned portSHORT portTickType;
-	#define portMAX_DELAY ( portTickType ) 0xffff
+	typedef uint16_t TickType_t;
+	#define portMAX_DELAY ( TickType_t ) 0xffff
@@ -97,2 +35,2 @@
-	typedef unsigned portLONG portTickType;
-	#define portMAX_DELAY ( portTickType ) 0xffffffff
+	typedef uint32_t TickType_t;
+	#define portMAX_DELAY ( TickType_t ) 0xffffffffUL
@@ -100 +38 @@
-/*-----------------------------------------------------------*/	
+/*-----------------------------------------------------------*/
@@ -104 +42 @@
-#define portTICK_RATE_MS			( ( portTickType ) 1000 / configTICK_RATE_HZ )		
+#define portTICK_PERIOD_MS			( ( TickType_t ) 1000 / configTICK_RATE_HZ )
@@ -107 +45 @@
-/*-----------------------------------------------------------*/	
+/*-----------------------------------------------------------*/
@@ -122 +60 @@
-extern volatile unsigned portLONG ulCriticalNesting;					\
+extern volatile uint32_t ulCriticalNesting;					\
@@ -159 +97 @@
-extern volatile unsigned portLONG ulCriticalNesting;					\
+extern volatile uint32_t ulCriticalNesting;					\
@@ -212,2 +150,2 @@
- * THUMB_INTERWORK is defined the utilities are defined as functions in 
- * portISR.c to ensure a switch to ARM mode.  When THUMB_INTERWORK is not 
+ * THUMB_INTERWORK is defined the utilities are defined as functions in
+ * portISR.c to ensure a switch to ARM mode.  When THUMB_INTERWORK is not
@@ -224 +162 @@
-	
+
@@ -234 +172 @@
-			
+
