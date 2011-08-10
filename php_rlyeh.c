// include PHP API
#include <php.h>
#include <zend_exceptions.h>

// header file we'll create below
#include "php_rlyeh.h"

zend_class_entry *rlyeh_ce_exception;

// define the function(s) we want to add
zend_function_entry rlyeh_functions[] = {
  PHP_FE(cthulhu, NULL)
  PHP_FE(lookAtMonster, NULL)
  { NULL, NULL, NULL }
};

// "rlyeh_functions" refers to the struct defined above
// we'll be filling in more of this later: you can use this to specify
// globals, php.ini info, startup and teardown functions, etc.
zend_module_entry rlyeh_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_RLYEH_EXTNAME,
  rlyeh_functions,
  PHP_MINIT(rlyeh),
  NULL,
  NULL,
  NULL,
  NULL,
  PHP_RLYEH_VERSION,
  STANDARD_MODULE_PROPERTIES
};

PHP_MINIT_FUNCTION(rlyeh) {
  rlyeh_init_exception(TSRMLS_C);
}

// install module
ZEND_GET_MODULE(rlyeh)

// actual non-template code!
PHP_FUNCTION(cthulhu) {
  // php_printf is PHP's version of printf, it's essentially "echo" from C
  php_printf("In his house at R'lyeh dead Cthulhu waits dreaming.\n");
}

void rlyeh_init_exception(TSRMLS_D) {
  zend_class_entry e;

  INIT_CLASS_ENTRY(e, "MadnessException", NULL);
  rlyeh_ce_exception = zend_register_internal_class_ex(&e, (zend_class_entry*)zend_exception_get_default(TSRMLS_C), NULL TSRMLS_CC);
}

PHP_FUNCTION(lookAtMonster) {
  zend_throw_exception(rlyeh_ce_exception, "looked at the monster too long", 1000 TSRMLS_CC);
}
