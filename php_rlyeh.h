#define PHP_RLYEH_EXTNAME "rlyeh"
#define PHP_RLYEH_VERSION "0.01"

PHP_FUNCTION(cthulhu);
PHP_FUNCTION(getYig);

PHP_MINIT_FUNCTION(rlyeh);
void rlyeh_old_one_pefree(zend_rsrc_list_entry *rsrc TSRMLS_DC);

typedef struct _old_one {
  char *name;
  int worshippers;
} old_one;


