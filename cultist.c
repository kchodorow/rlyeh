#include <php.h>

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
  php_printf("in the constructor\n");
}

PHP_METHOD(Cultist, sacrifice) {
  // TODO
}

PHP_METHOD(Cultist, createCultist) {
  object_init_ex(return_value, rlyeh_ce_cultist);
}
