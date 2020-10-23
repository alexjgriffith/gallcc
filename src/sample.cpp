#include "test.h"
#include "utils.h"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

static struct obj * to_obj(lua_State *l, int index){
  struct obj * in_obj = (struct obj *)luaL_checkudata(l, index, "obj");
  return in_obj;
}

static int from_name (lua_State *l, struct name * text){
  lua_createtable(l, 0, 2);
  lua_pushstring(l, text->text);
  lua_setfield(l, -2, "text");
  lua_pushinteger(l, text->length);
  lua_setfield(l, -2, "length");
  return 1;
}

static int from_obj (lua_State *l, struct obj * out_obj){
  lua_createtable(l, 0, 3);
  lua_pushstring(l, out_obj->text->text);
  lua_setfield(l, -2, "text");
  lua_pushinteger(l, out_obj->height);
  lua_setfield(l, -2, "height");
  lua_pushinteger(l, out_obj->strength);
  lua_setfield(l, -2, "strength");
  return 1;
}

static struct name * check_name(lua_State *l, int index){
  luaL_checktype(l, index, LUA_TUSERDATA);
  struct name * text = (struct name *)luaL_checkudata(l, index, "name");
  if(text == NULL) luaL_typerror(l, index, "name");
  return text;
}


static struct obj * check_obj(lua_State *l, int index){
  luaL_checktype(l, index, LUA_TUSERDATA);
  struct obj * in_obj = (struct obj *)luaL_checkudata(l, index, "obj");
  if(in_obj == NULL) luaL_typerror(l, index, "obj");
  return in_obj;
}

static int sample_new_name(lua_State *l){
  size_t size;
  int argc = lua_gettop(l);
  const char *data = luaL_checklstring(l, 1, &size);
  struct name * text;
  text = new_name(data);
  *(name **) lua_newuserdata(l, sizeof(name)) = text;
  luaL_getmetatable(l, "name");
  lua_setmetatable(l, -2);
  print_name(text);
  return 1;
}

static int sample_new_obj(lua_State *l){
  size_t size;
  int argc = lua_gettop(l);
  const char *text = luaL_checklstring(l, 1, &size);
  int height = luaL_checkint(l, 2);
  int strength = luaL_checkint(l, 2);
  struct obj * out_obj = (struct obj*) lua_newuserdata(l, sizeof(struct obj));
  new_obj(out_obj, text, height, strength);
  luaL_getmetatable(l, "obj");
  lua_setmetatable(l, -2);
  print_obj(out_obj);
  return 1;
}

static int sample_get_name_data(lua_State *l){
  size_t size;
  int argc = lua_gettop(l);
  struct name *text = check_name(l, 1);
  print_name(text);
  static int ret = from_name(l, text);
  return ret;
}

static int sample_get_obj_data(lua_State *l){
  size_t size;
  int argc = lua_gettop(l);
  struct obj *in_obj = check_obj(l, 1);
  print_obj(in_obj);
  static int ret = from_obj(l, in_obj);
  return ret;
}

static const struct luaL_Reg sample_lib [] = {
  {"new_obj", sample_new_obj},
  {"get_obj_data",sample_get_obj_data},
  {"new_name", sample_new_name},
  {"get_name_data",sample_get_name_data},
  {NULL,NULL}
};

extern "C" {
  int luaopen_sample (lua_State *l){
    luaL_newmetatable(l, "obj");
    luaL_newmetatable(l, "name");
    luaL_register(l, "sample", sample_lib);
    return 1;
  }
}
