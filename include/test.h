#include <stdlib.h>
struct name {
  char * text;
  size_t length;
};

struct obj {
  struct name * text;
  int height;
  int strength;
};

struct name * new_name(const char * text);

int new_obj(struct obj * ret_obj, const char * text, int height, int strength);

void print_obj(struct obj * in_obj);

void print_name(struct name * text);

void free_name(name * text);

void free_obj(obj * in_obj);
