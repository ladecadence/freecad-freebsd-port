--- src/App/Application.cpp.orig	2016-05-13 14:08:16 UTC
+++ src/App/Application.cpp
@@ -47,7 +47,10 @@
 # include <Shlobj.h>
 #endif
 
-
+#if defined(FC_OS_BSD)
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
 
 #include "Application.h"
 #include "Document.h"
@@ -2075,7 +2078,18 @@ std::string Application::FindHomePath(co
         // path. In the worst case we simply get q wrong path and FreeCAD is not
         // able to load its modules.
         char resolved[PATH_MAX];
+#if defined(FC_OS_BSD) 
+        int mib[4];
+        mib[0] = CTL_KERN;
+        mib[1] = KERN_PROC;
+        mib[2] = KERN_PROC_PATHNAME;
+        mib[3] = -1;
+        size_t cb = sizeof(resolved);
+        sysctl(mib, 4, resolved, &cb, NULL, 0);
+        int nchars = strlen(resolved);
+#else
         int nchars = readlink("/proc/self/exe", resolved, PATH_MAX);
+#endif
         if (nchars < 0 || nchars >= PATH_MAX)
             throw Base::Exception("Cannot determine the absolute path of the executable");
         resolved[nchars] = '\0'; // enfore null termination
