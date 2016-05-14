--- src/Base/TimeInfo.cpp.orig	2016-05-14 10:54:20.010837000 +0200
+++ src/Base/TimeInfo.cpp	2016-05-14 11:23:09.995007000 +0200
@@ -57,10 +57,14 @@
 
 void TimeInfo::setCurrent(void)
 {
-#if defined (_MSC_VER)
+#if defined (WIN32)
     _ftime( &timebuffer );
-#elif defined(__GNUC__)
-    ftime( &timebuffer );
+#else
+    //ftime( &timebuffer );
+    struct timeval t;
+    gettimeofday(&t, NULL);
+    timebuffer.time = t.tv_sec;
+    timebuffer.millitm = t.tv_usec / 1000;
 #endif
 }
 
