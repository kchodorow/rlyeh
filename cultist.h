#ifndef CULTIST_H
#define CULTIST_H

typedef struct _cult_secrets {
  // required
  zend_object std;

  // actual struct contents
  int end_of_world;
  char *prayer;
} cult_secrets;

zend_object_value create_cult_secrets(zend_class_entry *class_type TSRMLS_DC);
void free_cult_secrets(void *object TSRMLS_DC);
void rlyeh_init_cultist(TSRMLS_D);

PHP_METHOD(Cultist, sacrifice);
PHP_METHOD(Cultist, getDoomsday);

#endif
