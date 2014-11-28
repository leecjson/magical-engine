/*
** Lua binding: common
** Generated automatically by tolua++-1.0.92 on 11/28/14 15:39:52.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_common_open (lua_State* tolua_S);

#include "BindCommon.h"
#include "tolua_ext.h"
#include "magical-engine.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Vec2");
}

/* method: clamp of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_clamp00
static int tolua_common_Vec2_clamp00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* min = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* max = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clamp'", NULL);
#endif
  {
   self->clamp(*min,*max);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_clamp01
static int tolua_common_Vec2_clamp01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vec2* out = ((Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* v = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  const Vec2* min = ((const Vec2*)  tolua_tousertype(tolua_S,4,0));
  const Vec2* max = ((const Vec2*)  tolua_tousertype(tolua_S,5,0));
  {
   Vec2::clamp(*out,*v,*min,*max);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vec2_clamp00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_common_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Vec2","Vec2","",NULL);
  tolua_beginmodule(tolua_S,"Vec2");
   tolua_function(tolua_S,"clamp",tolua_common_Vec2_clamp00);
   tolua_function(tolua_S,"clamp",tolua_common_Vec2_clamp01);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_common (lua_State* tolua_S) {
 return tolua_common_open(tolua_S);
};
#endif

