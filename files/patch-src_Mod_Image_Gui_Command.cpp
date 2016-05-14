--- src/Mod/Image/Gui/Command.cpp.orig	2016-05-14 12:53:20.903372000 +0200
+++ src/Mod/Image/Gui/Command.cpp	2016-05-14 12:53:52.465212000 +0200
@@ -20,7 +20,9 @@
 #endif
 
 #include <time.h>
+#if defined(FC_OS_WIN32)
 #include <sys/timeb.h>
+#endif
 
 #include <Base/Exception.h>
 #include <Base/Interpreter.h>
