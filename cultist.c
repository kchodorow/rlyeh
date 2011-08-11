#include <php.h>

#include "cultist.h"

zend_class_entry *rlyeh_ce_cultist;

static function_entry cultist_methods[] = {
  PHP_ME(Cultist, sacrifice, NULL, ZEND_ACC_PUBLIC)
  PHP_ME(Cultist, getDoomsday, NULL, ZEND_ACC_PUBLIC)
  {NULL, NULL, NULL}
};

void rlyeh_init_cultist(TSRMLS_D) {
  zend_class_entry ce;

  INIT_CLASS_ENTRY(ce, "Cultist", cultist_methods);
  ce.create_object = create_cult_secrets;
  rlyeh_ce_cultist = zend_register_internal_class(&ce TSRMLS_CC);

  /* fields */
  zend_declare_property_bool(rlyeh_ce_cultist, "alive", strlen("alive"), 1, ZEND_ACC_PUBLIC TSRMLS_CC);
}

zend_object_value create_cult_secrets(zend_class_entry *class_type TSRMLS_DC) {
  zend_object_value retval;
  cult_secrets *intern;
  zval *tmp;

  // allocate the struct we're going to use
  intern = (cult_secrets*)emalloc(sizeof(cult_secrets));
  memset(intern, 0, sizeof(cult_secrets));

  // create a table for class properties
  zend_object_std_init(&intern->std, class_type TSRMLS_CC);
  zend_hash_copy(intern->std.properties,
                 &class_type->default_properties,
                 (copy_ctor_func_t) zval_add_ref,
                 (void *) &tmp,
                 sizeof(zval *));

  // create a destructor for this struct
  retval.handle = zend_objects_store_put(intern, (zend_objects_store_dtor_t) zend_objects_destroy_object, free_cult_secrets, NULL TSRMLS_CC);
  retval.handlers = zend_get_std_object_handlers();
  return retval;
}

// this will be called when a Cultist goes out of scope
void free_cult_secrets(void *object TSRMLS_DC) {
  cult_secrets *secrets = (cult_secrets*)object;
  if (secrets->prayer) {
    efree(secrets->prayer);
  }
  efree(secrets);
}

PHP_METHOD(Cultist, sacrifice) {
  // TODO
}

PHP_METHOD(Cultist, getDoomsday) {
  cult_secrets *secrets;

  secrets = (cult_secrets*)zend_object_store_get_object(getThis() TSRMLS_CC);

  RETURN_LONG(secrets->end_of_world);
}
