#include <php.h>

#include "php_rlyeh.h"
#include "cultist.h"

zend_class_entry *rlyeh_ce_cultist;

static function_entry cultist_methods[] = {
  PHP_ME(Cultist, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_ME(Cultist, sacrifice, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Cultist, createCultist, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  {NULL, NULL, NULL}
};

void rlyeh_init_cultist(TSRMLS_D) {
  zend_class_entry ce;

  INIT_CLASS_ENTRY(ce, "Cultist", cultist_methods);
  rlyeh_ce_cultist = zend_register_internal_class(&ce TSRMLS_CC);

  /* fields */
  zend_declare_property_bool(rlyeh_ce_cultist, "alive", strlen("alive"), 1, ZEND_ACC_PUBLIC TSRMLS_CC);
}

PHP_METHOD(Cultist, __construct) {
  char *name;
  int name_len;
  // defaults
  long health = 10, sanity = 4;
  
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|ll", &name, &name_len, &health, &sanity) == FAILURE) {
    return;
  }  
  
  zend_update_property_stringl(rlyeh_ce_cultist, getThis(), "name", strlen("name"), name, name_len TSRMLS_CC);
  zend_update_property_long(rlyeh_ce_cultist, getThis(), "health", strlen("health"), health TSRMLS_CC);
  zend_update_property_long(rlyeh_ce_cultist, getThis(), "sanity", strlen("sanity"), sanity TSRMLS_CC);
}

PHP_METHOD(Cultist, sacrifice) {
  // TODO
}

PHP_METHOD(Cultist, createCultist) {
  object_init_ex(return_value, rlyeh_ce_cultist);
  CALL_METHOD(Cultist, __construct, return_value, return_value);
}
