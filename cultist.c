#include <php.h>

#include "cultist.h"

zend_class_entry *rlyeh_ce_cultist;

static function_entry cultist_methods[] = {
  PHP_ME(Cultist, sacrifice, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

void rlyeh_init_cultist(TSRMLS_D) {
  zend_class_entry ce;

  INIT_CLASS_ENTRY(ce, "Cultist", cultist_methods);
  rlyeh_ce_cultist = zend_register_internal_class(&ce TSRMLS_CC);

  /* fields */
  zend_declare_property_bool(rlyeh_ce_cultist, "alive", strlen("alive"), 1, ZEND_ACC_PUBLIC TSRMLS_CC);
}

PHP_METHOD(Cultist, sacrifice) {
  // TODO
}
