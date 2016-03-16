--- port.c	2016-03-16 10:31:27.152284334 +0100
+++ /comptes/E129986P/TER/FreeRTOSV8.2.3/FreeRTOS/Source/portable/GCC/ARM7_AT91FR40008/port.c	2016-03-16 10:31:27.680303986 +0100
@@ -15,4 +15,4 @@
-#define portINITIAL_SPSR				( ( portSTACK_TYPE ) 0x1f ) /* System mode, ARM mode, interrupts enabled. */
-#define portTHUMB_MODE_BIT				( ( portSTACK_TYPE ) 0x20 )
-#define portINSTRUCTION_SIZE			( ( portSTACK_TYPE ) 4 )
-#define portNO_CRITICAL_SECTION_NESTING	( ( portSTACK_TYPE ) 0 )
+#define portINITIAL_SPSR				( ( StackType_t ) 0x1f ) /* System mode, ARM mode, interrupts enabled. */
+#define portTHUMB_MODE_BIT				( ( StackType_t ) 0x20 )
+#define portINSTRUCTION_SIZE			( ( StackType_t ) 4 )
+#define portNO_CRITICAL_SECTION_NESTING	( ( StackType_t ) 0 )
@@ -39 +39 @@
-portSTACK_TYPE *pxPortInitialiseStack( portSTACK_TYPE *pxTopOfStack, pdTASK_CODE pxCode, void *pvParameters )
+StackType_t *pxPortInitialiseStack( StackType_t *pxTopOfStack, TaskFunction_t pxCode, void *pvParameters )
@@ -41 +41 @@
-portSTACK_TYPE *pxOriginalTOS;
+StackType_t *pxOriginalTOS;
@@ -55 +55 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) pxCode + portINSTRUCTION_SIZE;		
+	*pxTopOfStack = ( StackType_t ) pxCode + portINSTRUCTION_SIZE;		
@@ -58 +58 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0xaaaaaaaa;	/* R14 */
+	*pxTopOfStack = ( StackType_t ) 0xaaaaaaaa;	/* R14 */
@@ -60 +60 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) pxOriginalTOS; /* Stack used when task starts goes in R13. */
+	*pxTopOfStack = ( StackType_t ) pxOriginalTOS; /* Stack used when task starts goes in R13. */
@@ -62 +62 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x12121212;	/* R12 */
+	*pxTopOfStack = ( StackType_t ) 0x12121212;	/* R12 */
@@ -64 +64 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x11111111;	/* R11 */
+	*pxTopOfStack = ( StackType_t ) 0x11111111;	/* R11 */
@@ -66 +66 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x10101010;	/* R10 */
+	*pxTopOfStack = ( StackType_t ) 0x10101010;	/* R10 */
@@ -68 +68 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x09090909;	/* R9 */
+	*pxTopOfStack = ( StackType_t ) 0x09090909;	/* R9 */
@@ -70 +70 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x08080808;	/* R8 */
+	*pxTopOfStack = ( StackType_t ) 0x08080808;	/* R8 */
@@ -72 +72 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x07070707;	/* R7 */
+	*pxTopOfStack = ( StackType_t ) 0x07070707;	/* R7 */
@@ -74 +74 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x06060606;	/* R6 */
+	*pxTopOfStack = ( StackType_t ) 0x06060606;	/* R6 */
@@ -76 +76 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x05050505;	/* R5 */
+	*pxTopOfStack = ( StackType_t ) 0x05050505;	/* R5 */
@@ -78 +78 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x04040404;	/* R4 */
+	*pxTopOfStack = ( StackType_t ) 0x04040404;	/* R4 */
@@ -80 +80 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x03030303;	/* R3 */
+	*pxTopOfStack = ( StackType_t ) 0x03030303;	/* R3 */
@@ -82 +82 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x02020202;	/* R2 */
+	*pxTopOfStack = ( StackType_t ) 0x02020202;	/* R2 */
@@ -84 +84 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) 0x01010101;	/* R1 */
+	*pxTopOfStack = ( StackType_t ) 0x01010101;	/* R1 */
@@ -89 +89 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) pvParameters; /* R0 */
+	*pxTopOfStack = ( StackType_t ) pvParameters; /* R0 */
@@ -94 +94 @@
-	*pxTopOfStack = ( portSTACK_TYPE ) portINITIAL_SPSR;
+	*pxTopOfStack = ( StackType_t ) portINITIAL_SPSR;
@@ -115 +115 @@
-portBASE_TYPE xPortStartScheduler( void )
+BaseType_t xPortStartScheduler( void )
@@ -141 +141 @@
-volatile unsigned long ulDummy;
+volatile uint32_t ulDummy;
@@ -161 +161 @@
-		AT91C_BASE_AIC->AIC_SVR[portTIMER_AIC_CHANNEL] = ( unsigned long ) vPreemptiveTick;
+		AT91C_BASE_AIC->AIC_SVR[portTIMER_AIC_CHANNEL] = ( uint32_t ) vPreemptiveTick;
@@ -166 +166 @@
-		AT91C_BASE_AIC->AIC_SVR[portTIMER_AIC_CHANNEL] = ( unsigned long ) vNonPreemptiveTick;
+		AT91C_BASE_AIC->AIC_SVR[portTIMER_AIC_CHANNEL] = ( uint32_t ) vNonPreemptiveTick;
