--- src/Mod/Robot/App/kdl_cp/tree.hpp.orig	2016-05-14 13:30:26.064967000 +0200
+++ src/Mod/Robot/App/kdl_cp/tree.hpp	2016-05-12 01:24:54.500154000 +0200
@@ -30,10 +30,13 @@
 #include <string>
 #include <map>
 
+#define KDL_USE_NEW_TREE_INTERFACE
+
 #ifdef KDL_USE_NEW_TREE_INTERFACE
 #include <boost/shared_ptr.hpp>
 #endif //#ifdef KDL_USE_NEW_TREE_INTERFACE
 
+
 namespace KDL
 {
     class TreeElement;
