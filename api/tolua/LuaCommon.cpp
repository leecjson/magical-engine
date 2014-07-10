/*
** Lua binding: common
** Generated automatically by tolua++-1.0.92 on 07/08/14 22:51:30.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_common_open (lua_State* tolua_S);

#include "PlatformMacros.h"
#include "tolua_ext.h"
#include "magical-engine.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"A");
}

/* function: go1 */
#ifndef TOLUA_DISABLE_tolua_common_go100
static int tolua_common_go100(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   go1();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'go1'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: go2 */
#ifndef TOLUA_DISABLE_tolua_common_go200
static int tolua_common_go200(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int s = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   go2(s);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'go2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: go3 */
#ifndef TOLUA_DISABLE_tolua_common_go300
static int tolua_common_go300(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,1,0));
  {
   go3(x);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'go3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: go4 */
#ifndef TOLUA_DISABLE_tolua_common_go400
static int tolua_common_go400(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* str = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   go4(str);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'go4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: go4 */
#ifndef TOLUA_DISABLE_tolua_common_go401
static int tolua_common_go401(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_iscppstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const std::string str = ((const std::string)  tolua_tocppstring(tolua_S,1,0));
  {
   go4(str);
   tolua_pushcppstring(tolua_S,(const char*)str);
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_go400(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: go4 */
#ifndef TOLUA_DISABLE_tolua_common_go402
static int tolua_common_go402(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isnumber(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  int a = ((int)  tolua_tonumber(tolua_S,1,0));
  {
   std::string tolua_ret = (std::string)  go4(a);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_go401(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* function: go5 */
#ifndef TOLUA_DISABLE_tolua_common_go500
static int tolua_common_go500(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object* obj = ((Object*)  tolua_tousertype(tolua_S,1,0));
  {
   go5(obj);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'go5'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: go6 */
#ifndef TOLUA_DISABLE_tolua_common_go600
static int tolua_common_go600(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Object* obj = ((const Object*)  tolua_tousertype(tolua_S,1,0));
  {
   go6(obj);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'go6'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: go7 */
#ifndef TOLUA_DISABLE_tolua_common_go700
static int tolua_common_go700(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"Object",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Object obj = *((Object*)  tolua_tousertype(tolua_S,1,0));
  {
   go7(obj);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'go7'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: go8 */
#ifndef TOLUA_DISABLE_tolua_common_go800
static int tolua_common_go800(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Object obj = *((const Object*)  tolua_tousertype(tolua_S,1,0));
  {
   go8(obj);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'go8'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: go9 */
#ifndef TOLUA_DISABLE_tolua_common_go900
static int tolua_common_go900(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     (tolua_isvaluenil(tolua_S,1,&tolua_err) || !tolua_isusertype(tolua_S,1,"const Object",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Object* obj = ((const Object*)  tolua_tousertype(tolua_S,1,0));
  {
   go9(*obj);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'go9'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: go10 */
#ifndef TOLUA_DISABLE_tolua_common_go1000
static int tolua_common_go1000(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   A* tolua_ret = (A*)  go10();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"A");
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'go10'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_common_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_function(tolua_S,"go1",tolua_common_go100);
  tolua_function(tolua_S,"go2",tolua_common_go200);
  tolua_function(tolua_S,"go3",tolua_common_go300);
  tolua_function(tolua_S,"go4",tolua_common_go400);
  tolua_function(tolua_S,"go4",tolua_common_go401);
  tolua_function(tolua_S,"go4",tolua_common_go402);
  tolua_function(tolua_S,"go5",tolua_common_go500);
  tolua_function(tolua_S,"go6",tolua_common_go600);
  tolua_function(tolua_S,"go7",tolua_common_go700);
  tolua_function(tolua_S,"go8",tolua_common_go800);
  tolua_function(tolua_S,"go9",tolua_common_go900);
  tolua_function(tolua_S,"go10",tolua_common_go1000);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_common (lua_State* tolua_S) {
 return tolua_common_open(tolua_S);
};
#endif

