--- src/Mod/Mesh/App/WildMagic4/Wm4System.cpp.orig	2016-05-14 11:25:12.774776000 +0200
+++ src/Mod/Mesh/App/WildMagic4/Wm4System.cpp	2016-05-14 11:26:15.947469000 +0200
@@ -22,7 +22,7 @@
 #include <sys/stat.h>
 
 // support for GetTime
-#ifdef __APPLE__
+#if !defined(WIN32)
 #include <sys/time.h>
 static timeval gs_kInitial;
 static bool gs_bInitializedTime = false;
@@ -103,7 +103,7 @@
 //----------------------------------------------------------------------------
 double System::GetTime ()
 {
-#ifdef __APPLE__
+#if !defined(WIN32)
     if (!gs_bInitializedTime)
     {
         gs_bInitializedTime = true;
