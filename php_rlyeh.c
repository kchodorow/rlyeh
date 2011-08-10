// include PHP API
#include <php.h>

// header file we'll create below
#include "php_rlyeh.h"

int le_old_one;

// define the function(s) we want to add
zend_function_entry rlyeh_functions[] = {
  PHP_FE(cthulhu, NULL)
  PHP_FE(getYig, NULL)
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
  le_old_one = zend_register_list_destructors_ex(NULL, rlyeh_old_one_pefree, "Great Old One", module_number);
}

void rlyeh_old_one_pefree(zend_rsrc_list_entry *rsrc TSRMLS_DC) {
  old_one *god = rsrc->ptr;

  // free the char* field, if set
  if (god->name) {
    pefree(god->name, 1);
  }

  pefree(god, 1);
}

// install module
ZEND_GET_MODULE(rlyeh)

// actual non-template code!
PHP_FUNCTION(cthulhu) {
  // php_printf is PHP's version of printf, it's essentially "echo" from C
  php_printf("In his house at R'lyeh dead Cthulhu waits dreaming.\n");
}

PHP_FUNCTION(getYig) {
  zend_rsrc_list_entry *le;
  char *key = "yig";

  if (zend_hash_find(&EG(persistent_list), key, strlen(key)+1, (void**)&le) == FAILURE) {
    // need to create a new god
    zend_rsrc_list_entry nle;
    old_one *yig;

    yig = (old_one*)pemalloc(sizeof(old_one), 1);
    yig->name = pestrdup("Yig", 1);
    yig->worshippers = 4;

    php_printf("creating a new god\n");

    nle.ptr = yig;
    nle.type = le_old_one;
    nle.refcount = 1;
    
    zend_hash_update(&EG(persistent_list), key, strlen(key)+1, (void*)&nle, sizeof(zend_rsrc_list_entry), NULL);
  }
  else {
    old_one *god = le->ptr;

    php_printf("fetched %s: %d worshippers\n", god->name, god->worshippers);
  }
}
