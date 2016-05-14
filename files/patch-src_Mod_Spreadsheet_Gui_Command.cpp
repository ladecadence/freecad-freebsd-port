--- src/Mod/Spreadsheet/Gui/Command.cpp.orig	2016-05-14 13:24:05.363804000 +0200
+++ src/Mod/Spreadsheet/Gui/Command.cpp	2016-05-14 13:24:34.177737000 +0200
@@ -21,7 +21,9 @@
 #endif
 
 #include <time.h>
+#if defined(FC_OS_WIN32)
 #include <sys/timeb.h>
+#endif
 
 #include <Base/Exception.h>
 #include <Base/Interpreter.h>
