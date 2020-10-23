#include <string.h>
#include "test.h"
#include "utils.h"

struct name * new_name(const char * text){
  struct name * nn;
  dp("New name\n");
  size_t len;
  len = strlen(text);
  dp("Text:%s Length:%ld\n", text, len);
  nn = (struct name *) malloc(sizeof(struct name));
  dp("Name allocated\n");
  nn->text = (char *) malloc(sizeof(char)*( 1 + len));
  dp("Text allocated\n");
  strcpy(nn->text, text);
  dp("Text coppied\n");
  nn->length = len;
  return nn;
}

int new_obj(struct obj * ret_obj, const char * text, int height, int strength){
  dp("New obj\n");
  // ret_obj = (struct obj *) malloc(sizeof(struct obj));
  dp("Obj Allocated\n");
  ret_obj->text = new_name(text);
  dp("Name Set\n");
  ret_obj->height = height;
  ret_obj->strength = strength;
  return 0;
}

void print_obj(struct obj * in_obj){
  dp("NAME=%s\nHeight=%dunits\nStrength=%dunits\n", in_obj->text->text, in_obj->height, in_obj->strength);
}

void print_name(struct name * text){
  dp("NAME=%s\nLength=%ld\n", text->text, text->length);
}

void free_name(struct name * text){
  dp("In Free name\n");
  free(text->text);
  free(text);
}

void free_obj(struct obj * in_obj){
  dp("In Free obj\n");
  free_name(in_obj->text);
  free(in_obj);
}
