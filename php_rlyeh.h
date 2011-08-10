#define PHP_RLYEH_EXTNAME "rlyeh"
#define PHP_RLYEH_VERSION "0.01"

PHP_FUNCTION(cthulhu);

PHP_MINIT_FUNCTION(rlyeh);

void rlyeh_init_exception(TSRMLS_D);

PHP_FUNCTION(lookAtMonster);
