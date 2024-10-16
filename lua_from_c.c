#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int main()
{
  lua_State *L = luaL_newstate();
  luaopen_base(L);
  luaopen_io(L);
  luaopen_string(L);
  luaopen_math(L);

  if (luaL_loadfile(L, "moon.lua") || lua_pcall(L, 0, 0, 0))
    error(L, "cannot run configuration file: %s",
          lua_tostring(L, -1));

  lua_getglobal(L, "f");
  lua_pushnumber(L, 12983);
  lua_pushnumber(L, 2);
  if (lua_pcall(L, 2, 1, 0) != 0)
    error(L, "error running function `f': %s",
          lua_tostring(L, -1));
  if (!lua_isnumber(L, -1))
    error(L, "function `f' must return a number");
  int z = lua_tonumber(L, -1);
  lua_pop(L, 1);

  printf("%d\n", z);

  lua_getglobal(L, "width");
  lua_getglobal(L, "height");

  if (!lua_isnumber(L, -2))
    error(L, "`width' should be a number\n");
  if (!lua_isnumber(L, -1))
    error(L, "`height' should be a number\n");
  int width = (int)lua_tonumber(L, -2);
  int height = (int)lua_tonumber(L, -1);

  printf("%d\n", width);
  printf("%d\n", height);

  lua_close(L);

  return 0;
}
