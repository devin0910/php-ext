/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2013 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_HELLO_H
#define PHP_HELLO_H

extern zend_module_entry hello_module_entry;
void hello_old_one_pefree(zend_rsrc_list_entry *rsrc TSRMLS_DC);
#define phpext_hello_ptr &hello_module_entry

#ifdef PHP_WIN32
#	define PHP_HELLO_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_HELLO_API __attribute__ ((visibility("default")))
#else
#	define PHP_HELLO_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(hello);
PHP_MSHUTDOWN_FUNCTION(hello);
PHP_RINIT_FUNCTION(hello);
PHP_RSHUTDOWN_FUNCTION(hello);
PHP_MINFO_FUNCTION(hello);

PHP_FUNCTION(cthulhu);	/* For testing, remove later. */
PHP_FUNCTION(makeBool);	/* For testing, remove later. */
PHP_FUNCTION(makeLong);	/* For testing, remove later. */
PHP_FUNCTION(leak);	/* For testing, remove later. */
PHP_FUNCTION(getYig);	/* For testing, remove later. */
PHP_FUNCTION(chant);	/* For testing, remove later. */
PHP_FUNCTION(findMonster);	/* For testing, remove later. */

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(hello)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(hello)
*/

/* In every utility function you add that needs to use variables 
   in php_hello_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as HELLO_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

typedef struct _old_one {
    char *name;
    int worshippers;
} old_one;

#ifdef ZTS
#define HELLO_G(v) TSRMG(hello_globals_id, zend_hello_globals *, v)
#else
#define HELLO_G(v) (hello_globals.v)
#endif

#endif	/* PHP_HELLO_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
