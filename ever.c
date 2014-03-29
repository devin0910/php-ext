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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_ever.h"

/* If you declare any globals in php_ever.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(ever)
*/

/* True global resources - no need for thread safety here */
static int le_ever;

/* {{{ ever_functions[]
 *
 * Every user visible function must have an entry in ever_functions[].
 */
const zend_function_entry ever_functions[] = {
	PHP_FE(confirm_ever_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(calcpi,	NULL)
	PHP_FE(reverse,	NULL)
	PHP_FE(uniquechars,	NULL)
	PHP_FE_END	/* Must be the last line in ever_functions[] */
};
/* }}} */

/* {{{ ever_module_entry
 */
zend_module_entry ever_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"ever",
	ever_functions,
	PHP_MINIT(ever),
	PHP_MSHUTDOWN(ever),
	PHP_RINIT(ever),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(ever),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(ever),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_EVER_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_EVER
ZEND_GET_MODULE(ever)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("ever.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_ever_globals, ever_globals)
    STD_PHP_INI_ENTRY("ever.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_ever_globals, ever_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_ever_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_ever_init_globals(zend_ever_globals *ever_globals)
{
	ever_globals->global_value = 0;
	ever_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(ever)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(ever)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(ever)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(ever)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(ever)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "ever support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_ever_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_ever_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "ever", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/* {{{ proto double calcpi(int iterations)
   Calculate Pi */
PHP_FUNCTION(calcpi)
{
	int argc = ZEND_NUM_ARGS();
	long iterations;

	if (zend_parse_parameters(argc TSRMLS_CC, "l", &iterations) == FAILURE) 
		return;

	php_error(E_WARNING, "calcpi: not yet implemented");
}
/* }}} */

/* {{{ proto string reverse(string input)
   Reverse the input string */
PHP_FUNCTION(reverse)
{
	char *input = NULL;
	int argc = ZEND_NUM_ARGS();
	int input_len;

	if (zend_parse_parameters(argc TSRMLS_CC, "s", &input, &input_len) == FAILURE) 
		return;

	php_error(E_WARNING, "reverse: not yet implemented");
}
/* }}} */

/* {{{ proto array uniquechars(string input [, bool case_sensitive])
   Return the unique characters in the input string */
PHP_FUNCTION(uniquechars)
{
	char *input = NULL;
	int argc = ZEND_NUM_ARGS();
	int input_len;
	zend_bool case_sensitive;

	if (zend_parse_parameters(argc TSRMLS_CC, "s|b", &input, &input_len, &case_sensitive) == FAILURE) 
		return;

	php_error(E_WARNING, "uniquechars: not yet implemented");
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
