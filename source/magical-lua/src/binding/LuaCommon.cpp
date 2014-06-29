/*
** Lua binding: common
** Generated automatically by tolua++-1.0.92 on 06/29/14 20:28:59.
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

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Object (lua_State* tolua_S)
{
 Object* self = (Object*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Node (lua_State* tolua_S)
{
 Node* self = (Node*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_vec2 (lua_State* tolua_S)
{
 vec2* self = (vec2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"mat3");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"Node");
 tolua_usertype(tolua_S,"vec2");
}

/* method: new of class  Object */
#ifndef TOLUA_DISABLE_tolua_common_Object_new00
static int tolua_common_Object_new00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Object* tolua_ret = (Object*)  newObject_LuaGC();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Object */
#ifndef TOLUA_DISABLE_tolua_common_Object_new00_local
static int tolua_common_Object_new00_local(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Object",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Object* tolua_ret = (Object*)  newObject_LuaGC();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Object");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Object */
#ifndef TOLUA_DISABLE_tolua_common_Object_delete00
static int tolua_common_Object_delete00(lua_State* tolua_S)
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
  Object* self = (Object*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get()->toString of class  Object */
#ifndef TOLUA_DISABLE_tolua_common_Object_toString00
static int tolua_common_Object_toString00(lua_State* tolua_S)
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
  const Object* self = (const Object*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get()->toString'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->get()->toString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Node */
#ifndef TOLUA_DISABLE_tolua_common_Node_new00
static int tolua_common_Node_new00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Node* tolua_ret = (Node*)  newNode_LuaGC();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Node */
#ifndef TOLUA_DISABLE_tolua_common_Node_new00_local
static int tolua_common_Node_new00_local(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Node* tolua_ret = (Node*)  newNode_LuaGC();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Node");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Node */
#ifndef TOLUA_DISABLE_tolua_common_Node_delete00
static int tolua_common_Node_delete00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Node* self = (Node*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get()->toString of class  Node */
#ifndef TOLUA_DISABLE_tolua_common_Node_toString00
static int tolua_common_Node_toString00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Node",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Node* self = (const Node*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get()->toString'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->get()->toString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_get_vec2_x
static int tolua_get_vec2_x(lua_State* tolua_S)
{
  vec2* self = (vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_set_vec2_x
static int tolua_set_vec2_x(lua_State* tolua_S)
{
  vec2* self = (vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->x = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: y of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_get_vec2_y
static int tolua_get_vec2_y(lua_State* tolua_S)
{
  vec2* self = (vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_set_vec2_y
static int tolua_set_vec2_y(lua_State* tolua_S)
{
  vec2* self = (vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->y = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_new00
static int tolua_common_vec2_new00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float rx = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float ry = ((const float)  tolua_tonumber(tolua_S,3,0));
  {
   vec2* tolua_ret = (vec2*)  Mtolua_new((vec2)(rx,ry));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec2");
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_new00_local
static int tolua_common_vec2_new00_local(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float rx = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float ry = ((const float)  tolua_tonumber(tolua_S,3,0));
  {
   vec2* tolua_ret = (vec2*)  Mtolua_new((vec2)(rx,ry));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_new01
static int tolua_common_vec2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   vec2* tolua_ret = (vec2*)  Mtolua_new((vec2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec2");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_vec2_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_new01_local
static int tolua_common_vec2_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   vec2* tolua_ret = (vec2*)  Mtolua_new((vec2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_vec2_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2__add00
static int tolua_common_vec2__add00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* self = (const vec2*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   vec2 tolua_ret = (vec2)  self->operator+(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2__add01
static int tolua_common_vec2__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const vec2* self = (const vec2*)  tolua_tousertype(tolua_S,1,0);
  const vec2* rhs = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   vec2 tolua_ret = (vec2)  self->operator+(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_vec2__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2__sub00
static int tolua_common_vec2__sub00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* self = (const vec2*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   vec2 tolua_ret = (vec2)  self->operator-(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2__sub01
static int tolua_common_vec2__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const vec2* self = (const vec2*)  tolua_tousertype(tolua_S,1,0);
  const vec2* rhs = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   vec2 tolua_ret = (vec2)  self->operator-(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_vec2__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2__mul00
static int tolua_common_vec2__mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* self = (const vec2*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   vec2 tolua_ret = (vec2)  self->operator*(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2__mul01
static int tolua_common_vec2__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const vec2* self = (const vec2*)  tolua_tousertype(tolua_S,1,0);
  const vec2* rhs = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   vec2 tolua_ret = (vec2)  self->operator*(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_vec2__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2__div00
static int tolua_common_vec2__div00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* self = (const vec2*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   vec2 tolua_ret = (vec2)  self->operator/(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2__div01
static int tolua_common_vec2__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const vec2* self = (const vec2*)  tolua_tousertype(tolua_S,1,0);
  const vec2* rhs = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   vec2 tolua_ret = (vec2)  self->operator/(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_vec2__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2__eq00
static int tolua_common_vec2__eq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* self = (const vec2*)  tolua_tousertype(tolua_S,1,0);
  const vec2* rhs = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*rhs);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_fill00
static int tolua_common_vec2_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float x = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float y = ((const float)  tolua_tonumber(tolua_S,3,0));
  {
   vec2 tolua_ret = (vec2)  vec2::fill(x,y);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_length00
static int tolua_common_vec2_length00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  vec2::length(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lengthSq of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_lengthSq00
static int tolua_common_vec2_lengthSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  vec2::lengthSq(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lengthSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_normalize00
static int tolua_common_vec2_normalize00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   vec2 tolua_ret = (vec2)  vec2::normalize(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lerp of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_lerp00
static int tolua_common_vec2_lerp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const vec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v1 = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  const vec2* v2 = ((const vec2*)  tolua_tousertype(tolua_S,3,0));
  float t = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   vec2 tolua_ret = (vec2)  vec2::lerp(*v1,*v2,t);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_dot00
static int tolua_common_vec2_dot00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v1 = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  const vec2* v2 = ((const vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  vec2::dot(*v1,*v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cross of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_cross00
static int tolua_common_vec2_cross00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v1 = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  const vec2* v2 = ((const vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  vec2::cross(*v1,*v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cross'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: transform of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_transform00
static int tolua_common_vec2_transform00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const mat3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  const mat3* m = ((const mat3*)  tolua_tousertype(tolua_S,3,0));
  {
   vec2 tolua_ret = (vec2)  vec2::transform(*v,*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: transformCoord of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_transformCoord00
static int tolua_common_vec2_transformCoord00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const mat3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  const mat3* m = ((const mat3*)  tolua_tousertype(tolua_S,3,0));
  {
   vec2 tolua_ret = (vec2)  vec2::transformCoord(*v,*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transformCoord'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_scale00
static int tolua_common_vec2_scale00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  const float s = ((const float)  tolua_tonumber(tolua_S,3,0));
  {
   vec2 tolua_ret = (vec2)  vec2::scale(*v,s);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateBy of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_rotateBy00
static int tolua_common_vec2_rotateBy00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  const float degrees = ((const float)  tolua_tonumber(tolua_S,3,0));
  const vec2* center = ((const vec2*)  tolua_tousertype(tolua_S,4,0));
  {
   vec2 tolua_ret = (vec2)  vec2::rotateBy(*v,degrees,*center);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateBy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: degreesBetween of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_degreesBetween00
static int tolua_common_vec2_degreesBetween00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v1 = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  const vec2* v2 = ((const vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  vec2::degreesBetween(*v1,*v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'degreesBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceBetween of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_distanceBetween00
static int tolua_common_vec2_distanceBetween00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v1 = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  const vec2* v2 = ((const vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  vec2::distanceBetween(*v1,*v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: midPointBetween of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_common_vec2_midPointBetween00
static int tolua_common_vec2_midPointBetween00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const vec2* v1 = ((const vec2*)  tolua_tousertype(tolua_S,2,0));
  const vec2* v2 = ((const vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   vec2 tolua_ret = (vec2)  vec2::midPointBetween(*v1,*v2);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'midPointBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  vec2 */
#ifndef TOLUA_DISABLE_tolua_get_vec2_ZERO
static int tolua_get_vec2_ZERO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&vec2::ZERO,"const vec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_common_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Object","Object","",tolua_collect_Object);
  #else
  tolua_cclass(tolua_S,"Object","Object","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Object");
   tolua_function(tolua_S,"new",tolua_common_Object_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Object_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Object_new00_local);
   tolua_function(tolua_S,"delete",tolua_common_Object_delete00);
   tolua_function(tolua_S,"toString",tolua_common_Object_toString00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Node","Node","Object",tolua_collect_Node);
  #else
  tolua_cclass(tolua_S,"Node","Node","Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Node");
   tolua_function(tolua_S,"new",tolua_common_Node_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Node_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Node_new00_local);
   tolua_function(tolua_S,"delete",tolua_common_Node_delete00);
   tolua_function(tolua_S,"toString",tolua_common_Node_toString00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"vec2","vec2","",tolua_collect_vec2);
  #else
  tolua_cclass(tolua_S,"vec2","vec2","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"vec2");
   tolua_variable(tolua_S,"x",tolua_get_vec2_x,tolua_set_vec2_x);
   tolua_variable(tolua_S,"y",tolua_get_vec2_y,tolua_set_vec2_y);
   tolua_function(tolua_S,"new",tolua_common_vec2_new00);
   tolua_function(tolua_S,"new_local",tolua_common_vec2_new00_local);
   tolua_function(tolua_S,".call",tolua_common_vec2_new00_local);
   tolua_function(tolua_S,"new",tolua_common_vec2_new01);
   tolua_function(tolua_S,"new_local",tolua_common_vec2_new01_local);
   tolua_function(tolua_S,".call",tolua_common_vec2_new01_local);
   tolua_function(tolua_S,".add",tolua_common_vec2__add00);
   tolua_function(tolua_S,".add",tolua_common_vec2__add01);
   tolua_function(tolua_S,".sub",tolua_common_vec2__sub00);
   tolua_function(tolua_S,".sub",tolua_common_vec2__sub01);
   tolua_function(tolua_S,".mul",tolua_common_vec2__mul00);
   tolua_function(tolua_S,".mul",tolua_common_vec2__mul01);
   tolua_function(tolua_S,".div",tolua_common_vec2__div00);
   tolua_function(tolua_S,".div",tolua_common_vec2__div01);
   tolua_function(tolua_S,".eq",tolua_common_vec2__eq00);
   tolua_function(tolua_S,"fill",tolua_common_vec2_fill00);
   tolua_function(tolua_S,"length",tolua_common_vec2_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_vec2_lengthSq00);
   tolua_function(tolua_S,"normalize",tolua_common_vec2_normalize00);
   tolua_function(tolua_S,"lerp",tolua_common_vec2_lerp00);
   tolua_function(tolua_S,"dot",tolua_common_vec2_dot00);
   tolua_function(tolua_S,"cross",tolua_common_vec2_cross00);
   tolua_function(tolua_S,"transform",tolua_common_vec2_transform00);
   tolua_function(tolua_S,"transformCoord",tolua_common_vec2_transformCoord00);
   tolua_function(tolua_S,"scale",tolua_common_vec2_scale00);
   tolua_function(tolua_S,"rotateBy",tolua_common_vec2_rotateBy00);
   tolua_function(tolua_S,"degreesBetween",tolua_common_vec2_degreesBetween00);
   tolua_function(tolua_S,"distanceBetween",tolua_common_vec2_distanceBetween00);
   tolua_function(tolua_S,"midPointBetween",tolua_common_vec2_midPointBetween00);
   tolua_variable(tolua_S,"ZERO",tolua_get_vec2_ZERO,NULL);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_common (lua_State* tolua_S) {
 return tolua_common_open(tolua_S);
};
#endif

