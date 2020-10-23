#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include "utils.h"

void dp (const char * format, ...){
#ifdef DEBUG
  va_list args;
  va_start (args, format);
  vfprintf(stderr, format, args);
  va_end(args);
#endif
}
