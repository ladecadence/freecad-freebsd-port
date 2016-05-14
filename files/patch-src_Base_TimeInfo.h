--- src/Base/TimeInfo.h.orig	2016-05-14 10:52:57.312066000 +0200
+++ src/Base/TimeInfo.h	2016-05-14 12:41:29.455067000 +0200
@@ -28,13 +28,25 @@
 
 
 #include <stdio.h>
+#if defined(FC_OS_WIN32)
 #include <sys/timeb.h>
-#include <time.h>
+#else
+#include <sys/time.h>
+#endif
+//#include <time.h>
 
 #ifdef __GNUC__
 # include <stdint.h>
 #endif
 
+#if !defined(FC_OS_WIN32)
+struct timeb
+{
+	int64_t time;
+	unsigned short millitm;
+};
+#endif
+
 namespace Base
 {
 /// BaseClass class and root of the type system
