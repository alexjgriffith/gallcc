#include "test.h"
#include "utils.h"

struct obj * some_fun(){
  dp("In SomeFun\n");
  struct obj * in_obj = (struct obj *) malloc(sizeof(struct obj));
  dp("Obj Allocated\n");
  new_obj(in_obj,"hello?",21,22);
  dp("obj created\n");
  print_obj(in_obj);
  return in_obj;
}

int main(int argc, char** argv)
{
  dp("In main\n");
  obj * in_obj = some_fun();
  print_obj(in_obj);
  // lua_State* L = luaL_newstate();

  // luaL_dostring(L, "a = 10 + 5");
  // lua_getglobal(L, "a");
  // int i = lua_tointeger(L, -1);
  // dp("%d\n", i);

  // lua_close(L);

  return 0;
}
