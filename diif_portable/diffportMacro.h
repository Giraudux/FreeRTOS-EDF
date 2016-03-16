--- portmacro.h	2016-03-16 10:32:26.278483235 +0100
+++ /comptes/E129986P/TER/FreeRTOSV8.2.3/FreeRTOS/Source/portable/GCC/ARM7_AT91FR40008/portmacro.h	2016-03-16 10:32:15.690089705 +0100
@@ -0,0 +1,17 @@
+#ifndef PORTMACRO_H
+#define PORTMACRO_H
+
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+/*-----------------------------------------------------------
+ * Port specific definitions.
+ *
+ * The settings in this file configure FreeRTOS correctly for the
+ * given hardware and compiler.
+ *
+ * These settings should not be altered.
+ *-----------------------------------------------------------
+ */
+
@@ -7 +24 @@
-#define portSTACK_TYPE	unsigned portLONG
+#define portSTACK_TYPE	uint32_t
@@ -9,0 +27,4 @@
+typedef portSTACK_TYPE StackType_t;
+typedef long BaseType_t;
+typedef unsigned long UBaseType_t;
+
@@ -11,2 +32,2 @@
-	typedef unsigned portSHORT portTickType;
-	#define portMAX_DELAY ( portTickType ) 0xffff
+	typedef uint16_t TickType_t;
+	#define portMAX_DELAY ( TickType_t ) 0xffff
@@ -14,2 +35,2 @@
-	typedef unsigned portLONG portTickType;
-	#define portMAX_DELAY ( portTickType ) 0xffffffff
+	typedef uint32_t TickType_t;
+	#define portMAX_DELAY ( TickType_t ) 0xffffffffUL
@@ -17 +38 @@
-/*-----------------------------------------------------------*/	
+/*-----------------------------------------------------------*/
@@ -21 +42 @@
-#define portTICK_RATE_MS			( ( portTickType ) 1000 / configTICK_RATE_HZ )		
+#define portTICK_PERIOD_MS			( ( TickType_t ) 1000 / configTICK_RATE_HZ )
@@ -33,2 +54,2 @@
-#define portTIMER_AIC_CHANNEL		( ( unsigned portLONG ) 4 )
-/*-----------------------------------------------------------*/	
+#define portTIMER_AIC_CHANNEL		( ( uint32_t ) 4 )
+/*-----------------------------------------------------------*/
@@ -48 +69 @@
-extern volatile unsigned portLONG ulCriticalNesting;					\
+extern volatile uint32_t ulCriticalNesting;					\
@@ -85 +106 @@
-extern volatile unsigned portLONG ulCriticalNesting;					\
+extern volatile uint32_t ulCriticalNesting;					\
@@ -134,2 +155,2 @@
- * THUMB_INTERWORK is defined the utilities are defined as functions in 
- * portISR.c to ensure a switch to ARM mode.  When THUMB_INTERWORK is not 
+ * THUMB_INTERWORK is defined the utilities are defined as functions in
+ * portISR.c to ensure a switch to ARM mode.  When THUMB_INTERWORK is not
@@ -146 +167 @@
-	
+
@@ -156 +177 @@
-			
+
@@ -173 +194 @@
-/*-----------------------------------------------------------*/	
+/*-----------------------------------------------------------*/
