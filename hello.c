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
#include "php_hello.h"

/* If you declare any globals in php_hello.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(hello)
*/

/* True global resources - no need for thread safety here */
static int le_hello;
static int le_old_one;

/* {{{ hello_functions[]
 *
 * Every user visible function must have an entry in hello_functions[].
 */
const zend_function_entry hello_functions[] = {
	PHP_FE(cthulhu,	NULL)		/* For testing, remove later. */
	PHP_FE(makeBool,	NULL)		/* For testing, remove later. */
	PHP_FE(makeLong,	NULL)		/* For testing, remove later. */
	PHP_FE(leak,	NULL)		/* For testing, remove later. */
	PHP_FE(getYig,	NULL)		/* For testing, remove later. */
	PHP_FE(chant,	NULL)		/* For testing, remove later. */
	PHP_FE(findMonster,	NULL)		/* For testing, remove later. */
	PHP_FE_END	/* Must be the last line in hello_functions[] */
};
/* }}} */

/* {{{ hello_module_entry
 */
zend_module_entry hello_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"hello",
	hello_functions,
	PHP_MINIT(hello),
	PHP_MSHUTDOWN(hello),
	PHP_RINIT(hello),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(hello),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(hello),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_HELLO
ZEND_GET_MODULE(hello)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("hello.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_hello_globals, hello_globals)
    STD_PHP_INI_ENTRY("hello.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_hello_globals, hello_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_hello_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_hello_init_globals(zend_hello_globals *hello_globals)
{
	hello_globals->global_value = 0;
	hello_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(hello)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
    le_old_one = zend_register_list_destructors_ex(NULL, hello_old_one_pefree, "Great Old One", module_number);
	return SUCCESS;
}

void hello_old_one_pefree(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    old_one *god = rsrc->ptr;

    if (god->name)
        pefree(god->name, 1);

    pefree(god, 1);
}

/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(hello)
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
PHP_RINIT_FUNCTION(hello)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(hello)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(hello)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "hello support", "enabled");
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
/* {{{ proto string confirm_hello_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(cthulhu)
{
    zend_bool english = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &english) == FAILURE) {
        return;
    }
    

    if (english) {
        php_printf("saying in english");
    } else {
        php_printf("说中文");
    }
}

PHP_FUNCTION(makeBool)
{
    Z_TYPE_P(return_value) = IS_BOOL;
    Z_LVAL_P(return_value) = 1;
}

PHP_FUNCTION(makeLong)
{
 //   Z_TYPE_P(return_value) = IS_LONG;
 //   Z_LVAL_P(return_value) = 1;
    ZVAL_BOOL(return_value, 0);
}

PHP_FUNCTION(getYig)
{
    zend_rsrc_list_entry *le;
    char *key = "yig";

    if (zend_hash_find(&EG(persistent_list), key, strlen(key)+1, (void**)&le) == FAILURE) {
        zend_rsrc_list_entry nle;
        old_one *yig;

        yig = (old_one*) pemalloc(sizeof(old_one), 1);
        yig->name = pestrdup("Yig", 1);
        yig->worshippers = 4;

        php_printf("creating a new god\n");

        nle.ptr = yig;
        nle.type = le_old_one;
        nle.refcount = 1;

        zend_hash_update(&EG(persistent_list), key, strlen(key)+1, (void*)&nle, sizeof(zend_rsrc_list_entry), NULL);
    } else {
        old_one *god = le->ptr;
        php_printf("fetched %s: %d worshippers\n", god->name, god->worshippers);
    }
}

PHP_FUNCTION(chant)
{
    int str_len, i;
    long num;
    char *str;
    zval *arr;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "lsa", &num, &str, &str_len, &arr) == FAILURE) {
        return;
    }

    if (num < 0 || num > 100) {
        return;
    }

    for (i = 0; i < num; i++) {
        add_next_index_string(arr, str, 1);
    }
}

PHP_FUNCTION(findMonster)
{
    int monster_len;
    char *monster; 
    zval *list, **desc;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sa", &monster, &monster_len, &list) == FAILURE) {
        return;
    }
 
    if (zend_hash_find(Z_ARRVAL_P(list), monster, monster_len+1, (void**)&desc) == FAILURE) {
        RETURN_NULL();
    }

    RETURN_STRINGL(Z_STRVAL_PP(desc), Z_STRLEN_PP(desc), 1);
}

PHP_FUNCTION(leak)
{
 //   Z_TYPE_P(return_value) = IS_LONG;
 //   Z_LVAL_P(return_value) = 1;
    emalloc(20);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
