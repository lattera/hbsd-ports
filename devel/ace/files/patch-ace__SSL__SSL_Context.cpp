<<<<<<< HEAD
--- ace/SSL/SSL_Context.cpp.orig	2016-05-02 07:59:38 UTC
+++ ace/SSL/SSL_Context.cpp
@@ -352,7 +352,7 @@ ACE_SSL_Context::filter_versions (const 
 bool
 ACE_SSL_Context::check_host (const ACE_INET_Addr &host, SSL *peerssl)
 {
-#if defined (OPENSSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x10002001L)
+#if defined (OPENSSL_VERSION_NUMBER) && (OPENSSL_VERSION_NUMBER >= 0x10002001L) && !defined(LIBRE_VERSION_NUMBER)
 
   this->check_context ();
 
@@ -629,7 +629,7 @@ ACE_SSL_Context::random_seed (const char
 int
 ACE_SSL_Context::egd_file (const char * socket_file)
 {
-#if OPENSSL_VERSION_NUMBER < 0x00905100L
=======
--- ace/SSL/SSL_Context.cpp.orig	2018-09-18 07:26:56 UTC
+++ ace/SSL/SSL_Context.cpp
@@ -179,7 +179,7 @@ ACE_SSL_Context::ssl_library_init (void)
 # endif  /* OPENSSL_VERSION_NUMBER < 0x10100000L */
 #endif  /* WIN32 */
 
-#if OPENSSL_VERSION_NUMBER >= 0x00905100L
>>>>>>> freebsd/master
+#if OPENSSL_VERSION_NUMBER < 0x00905100L || defined(LIBRESSL_VERSION_NUMBER)
       // OpenSSL < 0.9.5 doesn't have EGD support.
 
       const char *egd_socket_file =
