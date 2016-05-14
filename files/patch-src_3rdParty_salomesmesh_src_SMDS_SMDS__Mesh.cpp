--- src/3rdParty/salomesmesh/src/SMDS/SMDS_Mesh.cpp.orig	2016-05-13 14:07:30 UTC
+++ src/3rdParty/salomesmesh/src/SMDS/SMDS_Mesh.cpp
@@ -43,6 +43,7 @@
 using namespace std;
 
 #ifndef WIN32
+#include <sys/wait.h>
 #if !(defined(__MACH__) && defined(__APPLE__))
 #include <sys/sysinfo.h>
 #endif
