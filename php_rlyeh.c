// include PHP API
#include <php.h>

// header file we'll create below
#include "php_rlyeh.h"

// define the function(s) we want to add
zend_function_entry rlyeh_functions[] = {
  PHP_FE(cthulhu, NULL)
  { NULL, NULL, NULL }
};

// "rlyeh_functions" refers to the struct defined above
// we'll be filling in more of this later: you can use this to specify
// globals, php.ini info, startup and teardown functions, etc.
zend_module_entry rlyeh_module_entry = {
  STANDARD_MODULE_HEADER,
  PHP_RLYEH_EXTNAME,
  rlyeh_functions,
  NULL,
  NULL,
  NULL,
  NULL,
  NULL,
  PHP_RLYEH_VERSION,
  STANDARD_MODULE_PROPERTIES
};

// install module
ZEND_GET_MODULE(rlyeh)

// actual non-template code!
PHP_FUNCTION(cthulhu) {
  // boolean type
  zend_bool english = 0;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "b", &english) == FAILURE) {
    return;
  }

  if (english) {
    php_printf("In his house at R'lyeh dead Cthulhu waits dreaming\n");
  }
  else {
    php_printf("Ph'nglui mglw'nafh Cthulhu R'lyeh wgah'nagl fhtagn.\n");
  }
}
