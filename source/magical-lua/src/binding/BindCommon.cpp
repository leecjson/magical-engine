/*
** Lua binding: common
** Generated automatically by tolua++-1.0.92 on 07/29/14 11:15:23.
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

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Vec4 (lua_State* tolua_S)
{
 Vec4* self = (Vec4*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Quaternion (lua_State* tolua_S)
{
 Quaternion* self = (Quaternion*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vec3 (lua_State* tolua_S)
{
 Vec3* self = (Vec3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Mat4 (lua_State* tolua_S)
{
 Mat4* self = (Mat4*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vec2 (lua_State* tolua_S)
{
 Vec2* self = (Vec2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Data (lua_State* tolua_S)
{
 Data* self = (Data*) tolua_tousertype(tolua_S,1,0);
	self->release();
	return 0;
}

static int tolua_collect_Reference (lua_State* tolua_S)
{
 Reference* self = (Reference*) tolua_tousertype(tolua_S,1,0);
	self->release();
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Vec4");
 tolua_usertype(tolua_S,"Assets");
 tolua_usertype(tolua_S,"Mathv3");
 tolua_usertype(tolua_S,"Vec2");
 tolua_usertype(tolua_S,"Mat4");
 tolua_usertype(tolua_S,"Data");
 tolua_usertype(tolua_S,"Mathq4");
 tolua_usertype(tolua_S,"Mathv4");
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"Vec3");
 tolua_usertype(tolua_S,"Mathm4");
 tolua_usertype(tolua_S,"MatrixStack");
 tolua_usertype(tolua_S,"Mathv2");
 tolua_usertype(tolua_S,"Reference");
}

/* function: magicalIsError */
#ifndef TOLUA_DISABLE_tolua_common_magicalIsError00
static int tolua_common_magicalIsError00(lua_State* tolua_S)
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
   bool tolua_ret = (bool)  magicalIsError();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalIsError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalIgnoreLastError */
#ifndef TOLUA_DISABLE_tolua_common_magicalIgnoreLastError00
static int tolua_common_magicalIgnoreLastError00(lua_State* tolua_S)
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
   magicalIgnoreLastError();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalIgnoreLastError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalSetLastErrorInfo */
#ifndef TOLUA_DISABLE_tolua_common_magicalSetLastErrorInfo00
static int tolua_common_magicalSetLastErrorInfo00(lua_State* tolua_S)
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
  const char* info = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   magicalSetLastErrorInfo(info);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalSetLastErrorInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalGetLastErrorInfo */
#ifndef TOLUA_DISABLE_tolua_common_magicalGetLastErrorInfo00
static int tolua_common_magicalGetLastErrorInfo00(lua_State* tolua_S)
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
   const char* tolua_ret = (const char*)  magicalGetLastErrorInfo();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalGetLastErrorInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalAssert */
#ifndef TOLUA_DISABLE_tolua_common_magicalAssert00
static int tolua_common_magicalAssert00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isboolean(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  bool __con = ((bool)  tolua_toboolean(tolua_S,1,0));
  const char* __msg = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   magicalAssert(__con,__msg);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalAssert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalBeginTicking */
#ifndef TOLUA_DISABLE_tolua_common_magicalBeginTicking00
static int tolua_common_magicalBeginTicking00(lua_State* tolua_S)
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
   magicalBeginTicking();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalBeginTicking'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalEndTicking */
#ifndef TOLUA_DISABLE_tolua_common_magicalEndTicking00
static int tolua_common_magicalEndTicking00(lua_State* tolua_S)
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
   magicalEndTicking();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalEndTicking'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalBeginObserve */
#ifndef TOLUA_DISABLE_tolua_common_magicalBeginObserve00
static int tolua_common_magicalBeginObserve00(lua_State* tolua_S)
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
   magicalBeginObserve();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalBeginObserve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalEndObserve */
#ifndef TOLUA_DISABLE_tolua_common_magicalEndObserve00
static int tolua_common_magicalEndObserve00(lua_State* tolua_S)
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
   magicalEndObserve();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalEndObserve'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Reference */
#ifndef TOLUA_DISABLE_tolua_common_Reference_delete00
static int tolua_common_Reference_delete00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Reference",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Reference* self = (Reference*)  tolua_tousertype(tolua_S,1,0);
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

/* method: retain of class  Reference */
#ifndef TOLUA_DISABLE_tolua_common_Reference_retain00
static int tolua_common_Reference_retain00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Reference",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Reference* self = (Reference*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'retain'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: release of class  Reference */
#ifndef TOLUA_DISABLE_tolua_common_Reference_release00
static int tolua_common_Reference_release00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Reference",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Reference* self = (Reference*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: referenceCount of class  Reference */
#ifndef TOLUA_DISABLE_tolua_common_Reference_referenceCount00
static int tolua_common_Reference_referenceCount00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Reference",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Reference* self = (const Reference*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'referenceCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->referenceCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'referenceCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Data */
#ifndef TOLUA_DISABLE_tolua_common_Data_delete00
static int tolua_common_Data_delete00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Data",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Data* self = (Data*)  tolua_tousertype(tolua_S,1,0);
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

/* method: create of class  Data */
#ifndef TOLUA_DISABLE_tolua_common_Data_create00
static int tolua_common_Data_create00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Data",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Shared<Data> tolua_ret = (Shared<Data>)  Data::create();
    tolua_ret->retain();
    tolua_pushusertype(tolua_S,(void*)(tolua_ret.get()),"Data");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: assign of class  Data */
#ifndef TOLUA_DISABLE_tolua_common_Data_assign00
static int tolua_common_Data_assign00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Data",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Data* self = (Data*)  tolua_tousertype(tolua_S,1,0);
  char* data = ((char*)  tolua_tostring(tolua_S,2,0));
  unsigned const int size = ((unsigned const int)  tolua_tonumber(tolua_S,3,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'assign'", NULL);
#endif
  {
   self->assign(data,size);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'assign'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: malloc of class  Data */
#ifndef TOLUA_DISABLE_tolua_common_Data_malloc00
static int tolua_common_Data_malloc00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Data",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Data* self = (Data*)  tolua_tousertype(tolua_S,1,0);
  unsigned const int size = ((unsigned const int)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'malloc'", NULL);
#endif
  {
   self->malloc(size);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'malloc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: realloc of class  Data */
#ifndef TOLUA_DISABLE_tolua_common_Data_realloc00
static int tolua_common_Data_realloc00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Data",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Data* self = (Data*)  tolua_tousertype(tolua_S,1,0);
  unsigned const int size = ((unsigned const int)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'realloc'", NULL);
#endif
  {
   self->realloc(size);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'realloc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: empty of class  Data */
#ifndef TOLUA_DISABLE_tolua_common_Data_empty00
static int tolua_common_Data_empty00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Data",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Data* self = (const Data*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'empty'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: size of class  Data */
#ifndef TOLUA_DISABLE_tolua_common_Data_size00
static int tolua_common_Data_size00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Data",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Data* self = (const Data*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'", NULL);
#endif
  {
   unsigned int tolua_ret = ( unsigned int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAbsolutePath of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_getAbsolutePath00
static int tolua_common_Assets_getAbsolutePath00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Assets",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  Assets::getAbsolutePath(path);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAbsolutePath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDefaultSearchPath of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_getDefaultSearchPath00
static int tolua_common_Assets_getDefaultSearchPath00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Assets",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::string tolua_ret = (std::string)  Assets::getDefaultSearchPath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDefaultSearchPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addSearchPath of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_addSearchPath00
static int tolua_common_Assets_addSearchPath00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Assets",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Assets::addSearchPath(path);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addSearchPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeSearchPath of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_removeSearchPath00
static int tolua_common_Assets_removeSearchPath00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Assets",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Assets::removeSearchPath(path);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeSearchPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearSearchPath of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_clearSearchPath00
static int tolua_common_Assets_clearSearchPath00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Assets",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Assets::clearSearchPath();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearSearchPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clearCachedAbsPath of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_clearCachedAbsPath00
static int tolua_common_Assets_clearCachedAbsPath00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Assets",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Assets::clearCachedAbsPath();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clearCachedAbsPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAssetsFileExist of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_isAssetsFileExist00
static int tolua_common_Assets_isAssetsFileExist00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Assets",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* file_name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  Assets::isAssetsFileExist(file_name);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAssetsFileExist'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: loadAssetsFile of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_loadAssetsFile00
static int tolua_common_Assets_loadAssetsFile00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Assets",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* file_name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Shared<Data> tolua_ret = (Shared<Data>)  Assets::loadAssetsFile(file_name);
    tolua_ret->retain();
    tolua_pushusertype(tolua_S,(void*)(tolua_ret.get()),"Data");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'loadAssetsFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalLog */
#ifndef TOLUA_DISABLE_tolua_common_magicalLog00
static int tolua_common_magicalLog00(lua_State* tolua_S)
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
  const char* __msg = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   magicalLog(__msg);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalLogD */
#ifndef TOLUA_DISABLE_tolua_common_magicalLogD00
static int tolua_common_magicalLogD00(lua_State* tolua_S)
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
  const char* __msg = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   magicalLogD(__msg);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalLogD'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalLogE */
#ifndef TOLUA_DISABLE_tolua_common_magicalLogE00
static int tolua_common_magicalLogE00(lua_State* tolua_S)
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
  const char* __msg = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   magicalLogE(__msg);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalLogE'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalLogLastError */
#ifndef TOLUA_DISABLE_tolua_common_magicalLogLastError00
static int tolua_common_magicalLogLastError00(lua_State* tolua_S)
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
   magicalLogLastError();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalLogLastError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mat of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_get_common_Mat4_mat
static int tolua_get_common_Mat4_mat(lua_State* tolua_S)
{
 int tolua_index;
  Mat4* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (Mat4*)  lua_touserdata(tolua_S,-1);
#ifdef MAG_DEBUG
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifdef MAG_DEBUG
 if (tolua_index<0 || tolua_index>=16)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->mat[tolua_index]);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mat of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_set_common_Mat4_mat
static int tolua_set_common_Mat4_mat(lua_State* tolua_S)
{
 int tolua_index;
  Mat4* self;
 lua_pushstring(tolua_S,".self");
 lua_rawget(tolua_S,1);
 self = (Mat4*)  lua_touserdata(tolua_S,-1);
#ifdef MAG_DEBUG
 {
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in array indexing.",&tolua_err);
 }
#endif
 tolua_index = (int)tolua_tonumber(tolua_S,2,0);
#ifdef MAG_DEBUG
 if (tolua_index<0 || tolua_index>=16)
  tolua_error(tolua_S,"array indexing out of range.",NULL);
#endif
  self->mat[tolua_index] = ((float)  tolua_tonumber(tolua_S,3,0));
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_new00
static int tolua_common_Mat4_new00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,17,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,18,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float m11 = ((float)  tolua_tonumber(tolua_S,2,0));
  float m12 = ((float)  tolua_tonumber(tolua_S,3,0));
  float m13 = ((float)  tolua_tonumber(tolua_S,4,0));
  float m14 = ((float)  tolua_tonumber(tolua_S,5,0));
  float m21 = ((float)  tolua_tonumber(tolua_S,6,0));
  float m22 = ((float)  tolua_tonumber(tolua_S,7,0));
  float m23 = ((float)  tolua_tonumber(tolua_S,8,0));
  float m24 = ((float)  tolua_tonumber(tolua_S,9,0));
  float m31 = ((float)  tolua_tonumber(tolua_S,10,0));
  float m32 = ((float)  tolua_tonumber(tolua_S,11,0));
  float m33 = ((float)  tolua_tonumber(tolua_S,12,0));
  float m34 = ((float)  tolua_tonumber(tolua_S,13,0));
  float m41 = ((float)  tolua_tonumber(tolua_S,14,0));
  float m42 = ((float)  tolua_tonumber(tolua_S,15,0));
  float m43 = ((float)  tolua_tonumber(tolua_S,16,0));
  float m44 = ((float)  tolua_tonumber(tolua_S,17,0));
  {
   Mat4* tolua_ret = (Mat4*)  Mtolua_new((Mat4)(m11,m12,m13,m14,m21,m22,m23,m24,m31,m32,m33,m34,m41,m42,m43,m44));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mat4");
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

/* method: new_local of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_new00_local
static int tolua_common_Mat4_new00_local(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,17,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,18,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float m11 = ((float)  tolua_tonumber(tolua_S,2,0));
  float m12 = ((float)  tolua_tonumber(tolua_S,3,0));
  float m13 = ((float)  tolua_tonumber(tolua_S,4,0));
  float m14 = ((float)  tolua_tonumber(tolua_S,5,0));
  float m21 = ((float)  tolua_tonumber(tolua_S,6,0));
  float m22 = ((float)  tolua_tonumber(tolua_S,7,0));
  float m23 = ((float)  tolua_tonumber(tolua_S,8,0));
  float m24 = ((float)  tolua_tonumber(tolua_S,9,0));
  float m31 = ((float)  tolua_tonumber(tolua_S,10,0));
  float m32 = ((float)  tolua_tonumber(tolua_S,11,0));
  float m33 = ((float)  tolua_tonumber(tolua_S,12,0));
  float m34 = ((float)  tolua_tonumber(tolua_S,13,0));
  float m41 = ((float)  tolua_tonumber(tolua_S,14,0));
  float m42 = ((float)  tolua_tonumber(tolua_S,15,0));
  float m43 = ((float)  tolua_tonumber(tolua_S,16,0));
  float m44 = ((float)  tolua_tonumber(tolua_S,17,0));
  {
   Mat4* tolua_ret = (Mat4*)  Mtolua_new((Mat4)(m11,m12,m13,m14,m21,m22,m23,m24,m31,m32,m33,m34,m41,m42,m43,m44));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mat4");
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

/* method: new of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_new01
static int tolua_common_Mat4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Mat4* tolua_ret = (Mat4*)  Mtolua_new((Mat4)(*m));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mat4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mat4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_new01_local
static int tolua_common_Mat4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Mat4* tolua_ret = (Mat4*)  Mtolua_new((Mat4)(*m));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mat4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_new02
static int tolua_common_Mat4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Mat4* tolua_ret = (Mat4*)  Mtolua_new((Mat4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mat4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mat4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_new02_local
static int tolua_common_Mat4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Mat4* tolua_ret = (Mat4*)  Mtolua_new((Mat4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mat4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_delete00
static int tolua_common_Mat4_delete00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
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

/* method: operator+ of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4__add00
static int tolua_common_Mat4__add00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
  float scalar = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Mat4 tolua_ret = (Mat4)  self->operator+(scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
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

/* method: operator+ of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4__add01
static int tolua_common_Mat4__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Mat4* rhs = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Mat4 tolua_ret = (Mat4)  self->operator+(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mat4__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4__sub00
static int tolua_common_Mat4__sub00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
  float scalar = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Mat4 tolua_ret = (Mat4)  self->operator-(scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
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

/* method: operator- of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4__sub01
static int tolua_common_Mat4__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Mat4* rhs = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Mat4 tolua_ret = (Mat4)  self->operator-(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mat4__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4__mul00
static int tolua_common_Mat4__mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
  float scalar = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Mat4 tolua_ret = (Mat4)  self->operator*(scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
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

/* method: operator* of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4__mul01
static int tolua_common_Mat4__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Mat4* rhs = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Mat4 tolua_ret = (Mat4)  self->operator*(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mat4__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_copy00
static int tolua_common_Mat4_copy00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   Mat4 tolua_ret = (Mat4)  self->copy();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fill00
static int tolua_common_Mat4_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,17,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,18,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float m11 = ((float)  tolua_tonumber(tolua_S,2,0));
  float m12 = ((float)  tolua_tonumber(tolua_S,3,0));
  float m13 = ((float)  tolua_tonumber(tolua_S,4,0));
  float m14 = ((float)  tolua_tonumber(tolua_S,5,0));
  float m21 = ((float)  tolua_tonumber(tolua_S,6,0));
  float m22 = ((float)  tolua_tonumber(tolua_S,7,0));
  float m23 = ((float)  tolua_tonumber(tolua_S,8,0));
  float m24 = ((float)  tolua_tonumber(tolua_S,9,0));
  float m31 = ((float)  tolua_tonumber(tolua_S,10,0));
  float m32 = ((float)  tolua_tonumber(tolua_S,11,0));
  float m33 = ((float)  tolua_tonumber(tolua_S,12,0));
  float m34 = ((float)  tolua_tonumber(tolua_S,13,0));
  float m41 = ((float)  tolua_tonumber(tolua_S,14,0));
  float m42 = ((float)  tolua_tonumber(tolua_S,15,0));
  float m43 = ((float)  tolua_tonumber(tolua_S,16,0));
  float m44 = ((float)  tolua_tonumber(tolua_S,17,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(m11,m12,m13,m14,m21,m22,m23,m24,m31,m32,m33,m34,m41,m42,m43,m44);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fill01
static int tolua_common_Mat4_fill01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(*m);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Mat4_fill00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillIdentity of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillIdentity00
static int tolua_common_Mat4_fillIdentity00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillIdentity'", NULL);
#endif
  {
   self->fillIdentity();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillZero of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillZero00
static int tolua_common_Mat4_fillZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillZero'", NULL);
#endif
  {
   self->fillZero();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillLookAt of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillLookAt00
static int tolua_common_Mat4_fillLookAt00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* eye = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* target = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  const Vec3* up = ((const Vec3*)  tolua_tousertype(tolua_S,4,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillLookAt'", NULL);
#endif
  {
   self->fillLookAt(*eye,*target,*up);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillLookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillPerspective of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillPerspective00
static int tolua_common_Mat4_fillPerspective00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float fov = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspect = ((float)  tolua_tonumber(tolua_S,3,0));
  float znear = ((float)  tolua_tonumber(tolua_S,4,0));
  float zfar = ((float)  tolua_tonumber(tolua_S,5,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillPerspective'", NULL);
#endif
  {
   self->fillPerspective(fov,aspect,znear,zfar);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillPerspective'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillOrthographic of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillOrthographic00
static int tolua_common_Mat4_fillOrthographic00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float right = ((float)  tolua_tonumber(tolua_S,3,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,4,0));
  float top = ((float)  tolua_tonumber(tolua_S,5,0));
  float near = ((float)  tolua_tonumber(tolua_S,6,0));
  float far = ((float)  tolua_tonumber(tolua_S,7,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillOrthographic'", NULL);
#endif
  {
   self->fillOrthographic(left,right,bottom,top,near,far);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillOrthographic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillScale of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillScale00
static int tolua_common_Mat4_fillScale00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* scale = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillScale'", NULL);
#endif
  {
   self->fillScale(*scale);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillScale of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillScale01
static int tolua_common_Mat4_fillScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillScale'", NULL);
#endif
  {
   self->fillScale(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Mat4_fillScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillRotation of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillRotation00
static int tolua_common_Mat4_fillRotation00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillRotation'", NULL);
#endif
  {
   self->fillRotation(*q);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillRotation of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillRotation01
static int tolua_common_Mat4_fillRotation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* axis = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillRotation'", NULL);
#endif
  {
   self->fillRotation(*axis,angle);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Mat4_fillRotation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillRotationX of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillRotationX00
static int tolua_common_Mat4_fillRotationX00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillRotationX'", NULL);
#endif
  {
   self->fillRotationX(angle);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillRotationX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillRotationY of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillRotationY00
static int tolua_common_Mat4_fillRotationY00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillRotationY'", NULL);
#endif
  {
   self->fillRotationY(angle);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillRotationY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillRotationZ of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillRotationZ00
static int tolua_common_Mat4_fillRotationZ00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillRotationZ'", NULL);
#endif
  {
   self->fillRotationZ(angle);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillRotationZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillTranslation of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillTranslation00
static int tolua_common_Mat4_fillTranslation00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* translation = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillTranslation'", NULL);
#endif
  {
   self->fillTranslation(*translation);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillTranslation of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_fillTranslation01
static int tolua_common_Mat4_fillTranslation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillTranslation'", NULL);
#endif
  {
   self->fillTranslation(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Mat4_fillTranslation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIdentity of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_isIdentity00
static int tolua_common_Mat4_isIdentity00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isIdentity'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isIdentity();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUpVector of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_getUpVector00
static int tolua_common_Mat4_getUpVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUpVector'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->getUpVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUpVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDownVector of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_getDownVector00
static int tolua_common_Mat4_getDownVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDownVector'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->getDownVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDownVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLeftVector of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_getLeftVector00
static int tolua_common_Mat4_getLeftVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLeftVector'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->getLeftVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLeftVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRightVector of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_getRightVector00
static int tolua_common_Mat4_getRightVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRightVector'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->getRightVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRightVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getForwardVector of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_getForwardVector00
static int tolua_common_Mat4_getForwardVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getForwardVector'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->getForwardVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getForwardVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBackVector of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_getBackVector00
static int tolua_common_Mat4_getBackVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBackVector'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->getBackVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBackVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: inverse of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_inverse00
static int tolua_common_Mat4_inverse00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'inverse'", NULL);
#endif
  {
   self->inverse();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_negate00
static int tolua_common_Mat4_negate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'negate'", NULL);
#endif
  {
   self->negate();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_rotate00
static int tolua_common_Mat4_rotate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(*q);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_rotate01
static int tolua_common_Mat4_rotate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* axis = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(*axis,angle);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Mat4_rotate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateX of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_rotateX00
static int tolua_common_Mat4_rotateX00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateX'", NULL);
#endif
  {
   self->rotateX(angle);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateY of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_rotateY00
static int tolua_common_Mat4_rotateY00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateY'", NULL);
#endif
  {
   self->rotateY(angle);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateZ of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_rotateZ00
static int tolua_common_Mat4_rotateZ00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotateZ'", NULL);
#endif
  {
   self->rotateZ(angle);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_scale00
static int tolua_common_Mat4_scale00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float scale = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(scale);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_scale01
static int tolua_common_Mat4_scale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Mat4_scale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_scale02
static int tolua_common_Mat4_scale02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* scale = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(*scale);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Mat4_scale01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_translate00
static int tolua_common_Mat4_translate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(x,y,z);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_translate01
static int tolua_common_Mat4_translate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* t = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(*t);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Mat4_translate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: transpose of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_transpose00
static int tolua_common_Mat4_transpose00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mat4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mat4* self = (Mat4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'transpose'", NULL);
#endif
  {
   self->transpose();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transpose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: transformVec3 of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_transformVec300
static int tolua_common_Mat4_transformVec300(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* vec = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'transformVec3'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->transformVec3(*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transformVec3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: transformVec4 of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_common_Mat4_transformVec400
static int tolua_common_Mat4_transformVec400(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Mat4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* self = (const Mat4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* vec = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'transformVec4'", NULL);
#endif
  {
   Vec4 tolua_ret = (Vec4)  self->transformVec4(*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transformVec4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IDENTITY of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_get_Mat4_IDENTITY
static int tolua_get_Mat4_IDENTITY(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Mat4::IDENTITY,"const Mat4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Mat4 */
#ifndef TOLUA_DISABLE_tolua_get_Mat4_ZERO
static int tolua_get_Mat4_ZERO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Mat4::ZERO,"const Mat4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_add00
static int tolua_common_Mathm4_add00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* lhs = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  float scalar = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::add(*lhs,scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_add01
static int tolua_common_Mathm4_add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* lhs = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  const Mat4* rhs = ((const Mat4*)  tolua_tousertype(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::add(*lhs,*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_sub00
static int tolua_common_Mathm4_sub00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* lhs = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  float scalar = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::sub(*lhs,scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_sub01
static int tolua_common_Mathm4_sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* lhs = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  const Mat4* rhs = ((const Mat4*)  tolua_tousertype(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::sub(*lhs,*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_mul00
static int tolua_common_Mathm4_mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* lhs = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  float scalar = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::mul(*lhs,scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_mul01
static int tolua_common_Mathm4_mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* lhs = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  const Mat4* rhs = ((const Mat4*)  tolua_tousertype(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::mul(*lhs,*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_copy00
static int tolua_common_Mathm4_copy00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::copy(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fill00
static int tolua_common_Mathm4_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,8,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,9,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,10,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,11,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,12,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,13,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,14,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,15,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,16,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,17,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,18,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float m11 = ((float)  tolua_tonumber(tolua_S,2,0));
  float m12 = ((float)  tolua_tonumber(tolua_S,3,0));
  float m13 = ((float)  tolua_tonumber(tolua_S,4,0));
  float m14 = ((float)  tolua_tonumber(tolua_S,5,0));
  float m21 = ((float)  tolua_tonumber(tolua_S,6,0));
  float m22 = ((float)  tolua_tonumber(tolua_S,7,0));
  float m23 = ((float)  tolua_tonumber(tolua_S,8,0));
  float m24 = ((float)  tolua_tonumber(tolua_S,9,0));
  float m31 = ((float)  tolua_tonumber(tolua_S,10,0));
  float m32 = ((float)  tolua_tonumber(tolua_S,11,0));
  float m33 = ((float)  tolua_tonumber(tolua_S,12,0));
  float m34 = ((float)  tolua_tonumber(tolua_S,13,0));
  float m41 = ((float)  tolua_tonumber(tolua_S,14,0));
  float m42 = ((float)  tolua_tonumber(tolua_S,15,0));
  float m43 = ((float)  tolua_tonumber(tolua_S,16,0));
  float m44 = ((float)  tolua_tonumber(tolua_S,17,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fill(m11,m12,m13,m14,m21,m22,m23,m24,m31,m32,m33,m34,m41,m42,m43,m44);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
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

/* method: fill of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fill01
static int tolua_common_Mathm4_fill01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fill(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_fill00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillIdentity of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillIdentity00
static int tolua_common_Mathm4_fillIdentity00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillIdentity();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillZero of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillZero00
static int tolua_common_Mathm4_fillZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillLookAt of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillLookAt00
static int tolua_common_Mathm4_fillLookAt00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* eye = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* target = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  const Vec3* up = ((const Vec3*)  tolua_tousertype(tolua_S,4,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillLookAt(*eye,*target,*up);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillLookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillPerspective of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillPerspective00
static int tolua_common_Mathm4_fillPerspective00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float fov = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspect = ((float)  tolua_tonumber(tolua_S,3,0));
  float znear = ((float)  tolua_tonumber(tolua_S,4,0));
  float zfar = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillPerspective(fov,aspect,znear,zfar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillPerspective'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillOrthographic of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillOrthographic00
static int tolua_common_Mathm4_fillOrthographic00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float right = ((float)  tolua_tonumber(tolua_S,3,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,4,0));
  float top = ((float)  tolua_tonumber(tolua_S,5,0));
  float near = ((float)  tolua_tonumber(tolua_S,6,0));
  float far = ((float)  tolua_tonumber(tolua_S,7,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillOrthographic(left,right,bottom,top,near,far);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillOrthographic'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillScale of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillScale00
static int tolua_common_Mathm4_fillScale00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* scale = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillScale(*scale);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillScale of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillScale01
static int tolua_common_Mathm4_fillScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillScale(x,y,z);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_fillScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillRotation of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillRotation00
static int tolua_common_Mathm4_fillRotation00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillRotation(*q);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillRotation of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillRotation01
static int tolua_common_Mathm4_fillRotation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* axis = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillRotation(*axis,angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_fillRotation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillRotationX of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillRotationX00
static int tolua_common_Mathm4_fillRotationX00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillRotationX(angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillRotationX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillRotationY of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillRotationY00
static int tolua_common_Mathm4_fillRotationY00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillRotationY(angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillRotationY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillRotationZ of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillRotationZ00
static int tolua_common_Mathm4_fillRotationZ00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillRotationZ(angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillRotationZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillTranslation of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillTranslation00
static int tolua_common_Mathm4_fillTranslation00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* translation = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillTranslation(*translation);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillTranslation of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_fillTranslation01
static int tolua_common_Mathm4_fillTranslation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::fillTranslation(x,y,z);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_fillTranslation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIdentity of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_isIdentity00
static int tolua_common_Mathm4_isIdentity00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  Mathm4::isIdentity(*m);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUpVector of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_getUpVector00
static int tolua_common_Mathm4_getUpVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathm4::getUpVector(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUpVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDownVector of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_getDownVector00
static int tolua_common_Mathm4_getDownVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathm4::getDownVector(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDownVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLeftVector of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_getLeftVector00
static int tolua_common_Mathm4_getLeftVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathm4::getLeftVector(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLeftVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRightVector of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_getRightVector00
static int tolua_common_Mathm4_getRightVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathm4::getRightVector(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRightVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getForwardVector of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_getForwardVector00
static int tolua_common_Mathm4_getForwardVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathm4::getForwardVector(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getForwardVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBackVector of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_getBackVector00
static int tolua_common_Mathm4_getBackVector00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathm4::getBackVector(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBackVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: inverse of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_inverse00
static int tolua_common_Mathm4_inverse00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::inverse(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_negate00
static int tolua_common_Mathm4_negate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::negate(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_rotate00
static int tolua_common_Mathm4_rotate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::rotate(*m,*q);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_rotate01
static int tolua_common_Mathm4_rotate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* axis = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  float angle = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::rotate(*m,*axis,angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_rotate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateX of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_rotateX00
static int tolua_common_Mathm4_rotateX00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::rotateX(*m,angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateY of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_rotateY00
static int tolua_common_Mathm4_rotateY00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::rotateY(*m,angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotateZ of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_rotateZ00
static int tolua_common_Mathm4_rotateZ00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::rotateZ(*m,angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotateZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_scale00
static int tolua_common_Mathm4_scale00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  float scale = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::scale(*m,scale);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
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

/* method: scale of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_scale01
static int tolua_common_Mathm4_scale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::scale(*m,x,y,z);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_scale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_scale02
static int tolua_common_Mathm4_scale02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* scale = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::scale(*m,*scale);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_scale01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_translate00
static int tolua_common_Mathm4_translate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  float x = ((float)  tolua_tonumber(tolua_S,3,0));
  float y = ((float)  tolua_tonumber(tolua_S,4,0));
  float z = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::translate(*m,x,y,z);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_translate01
static int tolua_common_Mathm4_translate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* t = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::translate(*m,*t);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathm4_translate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: transpose of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_transpose00
static int tolua_common_Mathm4_transpose00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   Mat4 tolua_ret = (Mat4)  Mathm4::transpose(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Mat4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Mat4));
     tolua_pushusertype(tolua_S,tolua_obj,"Mat4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transpose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: transformVec3 of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_transformVec300
static int tolua_common_Mathm4_transformVec300(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* vec = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathm4::transformVec3(*m,*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transformVec3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: transformVec4 of class  Mathm4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathm4_transformVec400
static int tolua_common_Mathm4_transformVec400(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathm4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* m = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* vec = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathm4::transformVec4(*m,*vec);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transformVec4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_get_Vec2_x
static int tolua_get_Vec2_x(lua_State* tolua_S)
{
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_set_Vec2_x
static int tolua_set_Vec2_x(lua_State* tolua_S)
{
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: y of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_get_Vec2_y
static int tolua_get_Vec2_y(lua_State* tolua_S)
{
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_set_Vec2_y
static int tolua_set_Vec2_y(lua_State* tolua_S)
{
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
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

/* method: new of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_new00
static int tolua_common_Vec2_new00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec2* tolua_ret = (Vec2*)  Mtolua_new((Vec2)(rx,ry));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec2");
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

/* method: new_local of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_new00_local
static int tolua_common_Vec2_new00_local(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec2* tolua_ret = (Vec2*)  Mtolua_new((Vec2)(rx,ry));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec2");
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

/* method: new of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_new01
static int tolua_common_Vec2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec2* tolua_ret = (Vec2*)  Mtolua_new((Vec2)(*rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec2");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec2_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_new01_local
static int tolua_common_Vec2_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec2* tolua_ret = (Vec2*)  Mtolua_new((Vec2)(*rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec2_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_new02
static int tolua_common_Vec2_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vec2* tolua_ret = (Vec2*)  Mtolua_new((Vec2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec2");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec2_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_new02_local
static int tolua_common_Vec2_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vec2* tolua_ret = (Vec2*)  Mtolua_new((Vec2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec2_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2__add00
static int tolua_common_Vec2__add00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->operator+(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
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

/* method: operator+ of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2__add01
static int tolua_common_Vec2__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->operator+(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec2__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2__sub00
static int tolua_common_Vec2__sub00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->operator-(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
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

/* method: operator- of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2__sub01
static int tolua_common_Vec2__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->operator-(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec2__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2__mul00
static int tolua_common_Vec2__mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->operator*(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
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

/* method: operator* of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2__mul01
static int tolua_common_Vec2__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->operator*(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec2__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2__div00
static int tolua_common_Vec2__div00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->operator/(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
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

/* method: operator/ of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2__div01
static int tolua_common_Vec2__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->operator/(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec2__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2__eq00
static int tolua_common_Vec2__eq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
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

/* method: isZero of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_isZero00
static int tolua_common_Vec2_isZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_copy00
static int tolua_common_Vec2_copy00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   Vec2 tolua_ret = (Vec2)  self->copy();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_fill00
static int tolua_common_Vec2_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(rx,ry);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_fill01
static int tolua_common_Vec2_fill01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(*rhs);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vec2_fill00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillZero of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_fillZero00
static int tolua_common_Vec2_fillZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillZero'", NULL);
#endif
  {
   self->fillZero();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_clamp00
static int tolua_common_Vec2_clamp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
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
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clamp'", NULL);
#endif
  {
   self->clamp(*min,*max);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distance of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_distance00
static int tolua_common_Vec2_distance00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* v = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distance'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distance(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceSq of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_distanceSq00
static int tolua_common_Vec2_distanceSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* v = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distanceSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distanceSq(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_length00
static int tolua_common_Vec2_length00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
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

/* method: lengthSq of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_lengthSq00
static int tolua_common_Vec2_lengthSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lengthSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->lengthSq();
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

/* method: dot of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_dot00
static int tolua_common_Vec2_dot00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* v = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
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

/* method: angle of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_angle00
static int tolua_common_Vec2_angle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* self = (const Vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_negate00
static int tolua_common_Vec2_negate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'negate'", NULL);
#endif
  {
   self->negate();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_normalize00
static int tolua_common_Vec2_normalize00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_rotate00
static int tolua_common_Vec2_rotate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* point = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(*point,angle);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: middle of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_common_Vec2_middle00
static int tolua_common_Vec2_middle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec2* self = (Vec2*)  tolua_tousertype(tolua_S,1,0);
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'middle'", NULL);
#endif
  {
   self->middle(*rhs);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'middle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Vec2 */
#ifndef TOLUA_DISABLE_tolua_get_Vec2_ZERO
static int tolua_get_Vec2_ZERO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vec2::ZERO,"const Vec2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_add00
static int tolua_common_Mathv2_add00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* v1 = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* v2 = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::add(*v1,*v2);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_add01
static int tolua_common_Mathv2_add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* v1 = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::add(*v1,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv2_add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_sub00
static int tolua_common_Mathv2_sub00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* v1 = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* v2 = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::sub(*v1,*v2);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_sub01
static int tolua_common_Mathv2_sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* v1 = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::sub(*v1,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv2_sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_mul00
static int tolua_common_Mathv2_mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* v1 = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* v2 = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::mul(*v1,*v2);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_mul01
static int tolua_common_Mathv2_mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* v1 = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::mul(*v1,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv2_mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: div of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_div00
static int tolua_common_Mathv2_div00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* v1 = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* v2 = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::div(*v1,*v2);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: div of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_div01
static int tolua_common_Mathv2_div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* v1 = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::div(*v1,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv2_div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_equals00
static int tolua_common_Mathv2_equals00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* v1 = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* v2 = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Mathv2::equals(*v1,*v2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_copy00
static int tolua_common_Mathv2_copy00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::copy(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_fill00
static int tolua_common_Mathv2_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::fill(rx,ry);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
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

/* method: fill of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_fill01
static int tolua_common_Mathv2_fill01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::fill(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv2_fill00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillZero of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_fillZero00
static int tolua_common_Mathv2_fillZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::fillZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_clamp00
static int tolua_common_Mathv2_clamp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* lhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* min = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  const Vec2* max = ((const Vec2*)  tolua_tousertype(tolua_S,4,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::clamp(*lhs,*min,*max);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distance of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_distance00
static int tolua_common_Mathv2_distance00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* lhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* v = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv2::distance(*lhs,*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceSq of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_distanceSq00
static int tolua_common_Mathv2_distanceSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* lhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* v = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv2::distanceSq(*lhs,*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_length00
static int tolua_common_Mathv2_length00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* lhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  Mathv2::length(*lhs);
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

/* method: lengthSq of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_lengthSq00
static int tolua_common_Mathv2_lengthSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* lhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  Mathv2::lengthSq(*lhs);
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

/* method: dot of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_dot00
static int tolua_common_Mathv2_dot00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* lhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* v = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv2::dot(*lhs,*v);
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

/* method: angle of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_angle00
static int tolua_common_Mathv2_angle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* v = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  Mathv2::angle(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_negate00
static int tolua_common_Mathv2_negate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* v = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::negate(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_normalize00
static int tolua_common_Mathv2_normalize00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* v = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::normalize(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
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

/* method: rotate of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_rotate00
static int tolua_common_Mathv2_rotate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* lhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* point = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  float angle = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::rotate(*lhs,*point,angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: middle of class  Mathv2 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv2_middle00
static int tolua_common_Mathv2_middle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec2* lhs = ((const Vec2*)  tolua_tousertype(tolua_S,2,0));
  const Vec2* rhs = ((const Vec2*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec2 tolua_ret = (Vec2)  Mathv2::middle(*lhs,*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'middle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_get_Vec3_x
static int tolua_get_Vec3_x(lua_State* tolua_S)
{
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_set_Vec3_x
static int tolua_set_Vec3_x(lua_State* tolua_S)
{
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: y of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_get_Vec3_y
static int tolua_get_Vec3_y(lua_State* tolua_S)
{
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_set_Vec3_y
static int tolua_set_Vec3_y(lua_State* tolua_S)
{
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: z of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_get_Vec3_z
static int tolua_get_Vec3_z(lua_State* tolua_S)
{
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_set_Vec3_z
static int tolua_set_Vec3_z(lua_State* tolua_S)
{
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_new00
static int tolua_common_Vec3_new00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vec3* tolua_ret = (Vec3*)  Mtolua_new((Vec3)(rx,ry,rz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec3");
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

/* method: new_local of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_new00_local
static int tolua_common_Vec3_new00_local(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vec3* tolua_ret = (Vec3*)  Mtolua_new((Vec3)(rx,ry,rz));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec3");
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

/* method: new of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_new01
static int tolua_common_Vec3_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* rhs = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3* tolua_ret = (Vec3*)  Mtolua_new((Vec3)(*rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec3");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec3_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_new01_local
static int tolua_common_Vec3_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* rhs = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3* tolua_ret = (Vec3*)  Mtolua_new((Vec3)(*rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec3_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_new02
static int tolua_common_Vec3_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vec3* tolua_ret = (Vec3*)  Mtolua_new((Vec3)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec3");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec3_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_new02_local
static int tolua_common_Vec3_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vec3* tolua_ret = (Vec3*)  Mtolua_new((Vec3)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec3_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_delete00
static int tolua_common_Vec3_delete00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
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

/* method: operator+ of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3__add00
static int tolua_common_Vec3__add00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->operator+(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
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

/* method: operator+ of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3__add01
static int tolua_common_Vec3__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* rhs = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->operator+(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec3__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3__sub00
static int tolua_common_Vec3__sub00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->operator-(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
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

/* method: operator- of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3__sub01
static int tolua_common_Vec3__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* rhs = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->operator-(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec3__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3__mul00
static int tolua_common_Vec3__mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->operator*(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
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

/* method: operator* of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3__mul01
static int tolua_common_Vec3__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* rhs = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->operator*(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec3__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3__div00
static int tolua_common_Vec3__div00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->operator/(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
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

/* method: operator/ of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3__div01
static int tolua_common_Vec3__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* rhs = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->operator/(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec3__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3__eq00
static int tolua_common_Vec3__eq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* rhs = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
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

/* method: isZero of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_isZero00
static int tolua_common_Vec3_isZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_fill00
static int tolua_common_Vec3_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(rx,ry,rz);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_fill01
static int tolua_common_Vec3_fill01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* rhs = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(*rhs);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vec3_fill00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillZero of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_fillZero00
static int tolua_common_Vec3_fillZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillZero'", NULL);
#endif
  {
   self->fillZero();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_copy00
static int tolua_common_Vec3_copy00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->copy();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_clamp00
static int tolua_common_Vec3_clamp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* min = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* max = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clamp'", NULL);
#endif
  {
   self->clamp(*min,*max);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cross of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_cross00
static int tolua_common_Vec3_cross00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cross'", NULL);
#endif
  {
   self->cross(*v);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cross'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_negate00
static int tolua_common_Vec3_negate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'negate'", NULL);
#endif
  {
   self->negate();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_normalize00
static int tolua_common_Vec3_normalize00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_scale00
static int tolua_common_Vec3_scale00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec3* self = (Vec3*)  tolua_tousertype(tolua_S,1,0);
  float scalar = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(scalar);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angle of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_angle00
static int tolua_common_Vec3_angle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angle(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_dot00
static int tolua_common_Vec3_dot00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
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

/* method: distance of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_distance00
static int tolua_common_Vec3_distance00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distance'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distance(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceSq of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_distanceSq00
static int tolua_common_Vec3_distanceSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distanceSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distanceSq(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_length00
static int tolua_common_Vec3_length00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
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

/* method: lengthSq of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_common_Vec3_lengthSq00
static int tolua_common_Vec3_lengthSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* self = (const Vec3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lengthSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->lengthSq();
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

/* get function: ZERO of class  Vec3 */
#ifndef TOLUA_DISABLE_tolua_get_Vec3_ZERO
static int tolua_get_Vec3_ZERO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vec3::ZERO,"const Vec3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_add00
static int tolua_common_Mathv3_add00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* v2 = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::add(*v1,*v2);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_add01
static int tolua_common_Mathv3_add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::add(*v1,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv3_add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_sub00
static int tolua_common_Mathv3_sub00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* v2 = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::sub(*v1,*v2);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_sub01
static int tolua_common_Mathv3_sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::sub(*v1,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv3_sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_mul00
static int tolua_common_Mathv3_mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* v2 = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::mul(*v1,*v2);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_mul01
static int tolua_common_Mathv3_mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::mul(*v1,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv3_mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: div of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_div00
static int tolua_common_Mathv3_div00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* v2 = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::div(*v1,*v2);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: div of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_div01
static int tolua_common_Mathv3_div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::div(*v1,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv3_div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_equals00
static int tolua_common_Mathv3_equals00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* v2 = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Mathv3::equals(*v1,*v2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_fill00
static int tolua_common_Mathv3_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::fill(rx,ry,rz);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
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

/* method: fill of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_fill01
static int tolua_common_Mathv3_fill01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* rhs = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::fill(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv3_fill00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillZero of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_fillZero00
static int tolua_common_Mathv3_fillZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::fillZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_copy00
static int tolua_common_Mathv3_copy00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3 rhs = *((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::copy(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_clamp00
static int tolua_common_Mathv3_clamp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* min = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  const Vec3* max = ((const Vec3*)  tolua_tousertype(tolua_S,4,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::clamp(*v,*min,*max);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cross of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_cross00
static int tolua_common_Mathv3_cross00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* v2 = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::cross(*v1,*v2);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
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

/* method: negate of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_negate00
static int tolua_common_Mathv3_negate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::negate(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_normalize00
static int tolua_common_Mathv3_normalize00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::normalize(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
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

/* method: scale of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_scale00
static int tolua_common_Mathv3_scale00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float scalar = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathv3::scale(*v,scalar);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
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

/* method: angle of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_angle00
static int tolua_common_Mathv3_angle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* v2 = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv3::angle(*v1,*v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_dot00
static int tolua_common_Mathv3_dot00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* v2 = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv3::dot(*v1,*v2);
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

/* method: distance of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_distance00
static int tolua_common_Mathv3_distance00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* v2 = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv3::distance(*v1,*v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceSq of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_distanceSq00
static int tolua_common_Mathv3_distanceSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v1 = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  const Vec3* v2 = ((const Vec3*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv3::distanceSq(*v1,*v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_length00
static int tolua_common_Mathv3_length00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  Mathv3::length(*v);
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

/* method: lengthSq of class  Mathv3 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv3_lengthSq00
static int tolua_common_Mathv3_lengthSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* v = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  Mathv3::lengthSq(*v);
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

/* get function: x of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_get_Vec4_x
static int tolua_get_Vec4_x(lua_State* tolua_S)
{
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_set_Vec4_x
static int tolua_set_Vec4_x(lua_State* tolua_S)
{
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: y of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_get_Vec4_y
static int tolua_get_Vec4_y(lua_State* tolua_S)
{
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_set_Vec4_y
static int tolua_set_Vec4_y(lua_State* tolua_S)
{
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: z of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_get_Vec4_z
static int tolua_get_Vec4_z(lua_State* tolua_S)
{
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_set_Vec4_z
static int tolua_set_Vec4_z(lua_State* tolua_S)
{
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_get_Vec4_w
static int tolua_get_Vec4_w(lua_State* tolua_S)
{
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_set_Vec4_w
static int tolua_set_Vec4_w(lua_State* tolua_S)
{
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_new00
static int tolua_common_Vec4_new00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  float rw = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Vec4* tolua_ret = (Vec4*)  Mtolua_new((Vec4)(rx,ry,rz,rw));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec4");
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

/* method: new_local of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_new00_local
static int tolua_common_Vec4_new00_local(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  float rw = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Vec4* tolua_ret = (Vec4*)  Mtolua_new((Vec4)(rx,ry,rz,rw));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec4");
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

/* method: new of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_new01
static int tolua_common_Vec4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec4* tolua_ret = (Vec4*)  Mtolua_new((Vec4)(*rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_new01_local
static int tolua_common_Vec4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec4* tolua_ret = (Vec4*)  Mtolua_new((Vec4)(*rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_new02
static int tolua_common_Vec4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vec4* tolua_ret = (Vec4*)  Mtolua_new((Vec4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_new02_local
static int tolua_common_Vec4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vec4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vec4* tolua_ret = (Vec4*)  Mtolua_new((Vec4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4__add00
static int tolua_common_Vec4__add00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vec4 tolua_ret = (Vec4)  self->operator+(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
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

/* method: operator+ of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4__add01
static int tolua_common_Vec4__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vec4 tolua_ret = (Vec4)  self->operator+(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec4__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4__sub00
static int tolua_common_Vec4__sub00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vec4 tolua_ret = (Vec4)  self->operator-(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
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

/* method: operator- of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4__sub01
static int tolua_common_Vec4__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vec4 tolua_ret = (Vec4)  self->operator-(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec4__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4__mul00
static int tolua_common_Vec4__mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vec4 tolua_ret = (Vec4)  self->operator*(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
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

/* method: operator* of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4__mul01
static int tolua_common_Vec4__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vec4 tolua_ret = (Vec4)  self->operator*(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec4__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4__div00
static int tolua_common_Vec4__div00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  float rhs = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vec4 tolua_ret = (Vec4)  self->operator/(rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
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

/* method: operator/ of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4__div01
static int tolua_common_Vec4__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vec4 tolua_ret = (Vec4)  self->operator/(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vec4__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4__eq00
static int tolua_common_Vec4__eq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
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

/* method: isZero of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_isZero00
static int tolua_common_Vec4_isZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_fill00
static int tolua_common_Vec4_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  float rw = ((float)  tolua_tonumber(tolua_S,5,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(rx,ry,rz,rw);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_fill01
static int tolua_common_Vec4_fill01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(*rhs);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vec4_fill00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillZero of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_fillZero00
static int tolua_common_Vec4_fillZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillZero'", NULL);
#endif
  {
   self->fillZero();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_copy00
static int tolua_common_Vec4_copy00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'copy'", NULL);
#endif
  {
   Vec4 tolua_ret = (Vec4)  self->copy();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_negate00
static int tolua_common_Vec4_negate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'negate'", NULL);
#endif
  {
   self->negate();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_normalize00
static int tolua_common_Vec4_normalize00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_clamp00
static int tolua_common_Vec4_clamp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vec4* self = (Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* min = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* max = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clamp'", NULL);
#endif
  {
   self->clamp(*min,*max);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angle of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_angle00
static int tolua_common_Vec4_angle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angle(*rhs);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_dot00
static int tolua_common_Vec4_dot00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* v = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
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

/* method: distance of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_distance00
static int tolua_common_Vec4_distance00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* v = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distance'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distance(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceSq of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_distanceSq00
static int tolua_common_Vec4_distanceSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
  const Vec4* v = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distanceSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distanceSq(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_length00
static int tolua_common_Vec4_length00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
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

/* method: lengthSq of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_common_Vec4_lengthSq00
static int tolua_common_Vec4_lengthSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vec4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* self = (const Vec4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lengthSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->lengthSq();
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

/* get function: ZERO of class  Vec4 */
#ifndef TOLUA_DISABLE_tolua_get_Vec4_ZERO
static int tolua_get_Vec4_ZERO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vec4::ZERO,"const Vec4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_add00
static int tolua_common_Mathv4_add00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* lhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::add(*lhs,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_add01
static int tolua_common_Mathv4_add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* lhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::add(*lhs,*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv4_add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_sub00
static int tolua_common_Mathv4_sub00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* lhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::sub(*lhs,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_sub01
static int tolua_common_Mathv4_sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* lhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::sub(*lhs,*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv4_sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_mul00
static int tolua_common_Mathv4_mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* lhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::mul(*lhs,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_mul01
static int tolua_common_Mathv4_mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* lhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::mul(*lhs,*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv4_mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: div of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_div00
static int tolua_common_Mathv4_div00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* lhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  float rhs = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::div(*lhs,rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: div of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_div01
static int tolua_common_Mathv4_div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* lhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::div(*lhs,*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv4_div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_equals00
static int tolua_common_Mathv4_equals00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v1 = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* v2 = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Mathv4::equals(*v1,*v2);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_fill00
static int tolua_common_Mathv4_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  float rw = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::fill(rx,ry,rz,rw);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
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

/* method: fill of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_fill01
static int tolua_common_Mathv4_fill01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::fill(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathv4_fill00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillZero of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_fillZero00
static int tolua_common_Mathv4_fillZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::fillZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: copy of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_copy00
static int tolua_common_Mathv4_copy00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::copy(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'copy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_negate00
static int tolua_common_Mathv4_negate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::negate(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_normalize00
static int tolua_common_Mathv4_normalize00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::normalize(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
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

/* method: clamp of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_clamp00
static int tolua_common_Mathv4_clamp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* min = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  const Vec4* max = ((const Vec4*)  tolua_tousertype(tolua_S,4,0));
  {
   Vec4 tolua_ret = (Vec4)  Mathv4::clamp(*v,*min,*max);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'clamp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angle of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_angle00
static int tolua_common_Mathv4_angle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* rhs = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv4::angle(*v,*rhs);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_dot00
static int tolua_common_Mathv4_dot00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v1 = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* v2 = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv4::dot(*v1,*v2);
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

/* method: distance of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_distance00
static int tolua_common_Mathv4_distance00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v1 = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* v2 = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv4::distance(*v1,*v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceSq of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_distanceSq00
static int tolua_common_Mathv4_distanceSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v1 = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  const Vec4* v2 = ((const Vec4*)  tolua_tousertype(tolua_S,3,0));
  {
   float tolua_ret = (float)  Mathv4::distanceSq(*v1,*v2);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_length00
static int tolua_common_Mathv4_length00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  Mathv4::length(*v);
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

/* method: lengthSq of class  Mathv4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathv4_lengthSq00
static int tolua_common_Mathv4_lengthSq00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathv4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec4* v = ((const Vec4*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  Mathv4::lengthSq(*v);
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

/* get function: x of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_x
static int tolua_get_Quaternion_x(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_set_Quaternion_x
static int tolua_set_Quaternion_x(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: y of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_y
static int tolua_get_Quaternion_y(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_set_Quaternion_y
static int tolua_set_Quaternion_y(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: z of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_z
static int tolua_get_Quaternion_z(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_set_Quaternion_z
static int tolua_set_Quaternion_z(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->z = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: w of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_w
static int tolua_get_Quaternion_w(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_set_Quaternion_w
static int tolua_set_Quaternion_w(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->w = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_new00
static int tolua_common_Quaternion_new00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  float rw = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(rx,ry,rz,rw));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
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

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_new00_local
static int tolua_common_Quaternion_new00_local(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  float rw = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(rx,ry,rz,rw));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
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

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_new01
static int tolua_common_Quaternion_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Quaternion_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_new01_local
static int tolua_common_Quaternion_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*rhs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Quaternion_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_new02
static int tolua_common_Quaternion_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* axis = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*axis,angle));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Quaternion_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_new02_local
static int tolua_common_Quaternion_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vec3* axis = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*axis,angle));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Quaternion_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_new03
static int tolua_common_Quaternion_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Quaternion_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_new03_local
static int tolua_common_Quaternion_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Quaternion_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion__mul00
static int tolua_common_Quaternion__mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->operator*(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
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

/* method: fill of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_fill00
static int tolua_common_Quaternion_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  float rw = ((float)  tolua_tonumber(tolua_S,5,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(rx,ry,rz,rw);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_fill01
static int tolua_common_Quaternion_fill01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fill'", NULL);
#endif
  {
   self->fill(*rhs);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Quaternion_fill00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillAxisAngle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_fillAxisAngle00
static int tolua_common_Quaternion_fillAxisAngle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Vec3* axis = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillAxisAngle'", NULL);
#endif
  {
   self->fillAxisAngle(*axis,angle);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillAxisAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillIdentity of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_fillIdentity00
static int tolua_common_Quaternion_fillIdentity00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillIdentity'", NULL);
#endif
  {
   self->fillIdentity();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillZero of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_fillZero00
static int tolua_common_Quaternion_fillZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fillZero'", NULL);
#endif
  {
   self->fillZero();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIdentity of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_isIdentity00
static int tolua_common_Quaternion_isIdentity00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isIdentity'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isIdentity();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isZero of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_isZero00
static int tolua_common_Quaternion_isZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_negate00
static int tolua_common_Quaternion_negate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'negate'", NULL);
#endif
  {
   self->negate();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: inverse of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_inverse00
static int tolua_common_Quaternion_inverse00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'inverse'", NULL);
#endif
  {
   self->inverse();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_normalize00
static int tolua_common_Quaternion_normalize00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: axis of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_axis00
static int tolua_common_Quaternion_axis00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'axis'", NULL);
#endif
  {
   Vec3 tolua_ret = (Vec3)  self->axis();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'axis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_angle00
static int tolua_common_Quaternion_angle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angle'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angle();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lerp of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_lerp00
static int tolua_common_Quaternion_lerp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  float t = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lerp'", NULL);
#endif
  {
   self->lerp(*rhs,t);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: slerp of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_slerp00
static int tolua_common_Quaternion_slerp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  float t = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAG_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'slerp'", NULL);
#endif
  {
   self->slerp(*rhs,t);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'slerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: IDENTITY of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_IDENTITY
static int tolua_get_Quaternion_IDENTITY(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Quaternion::IDENTITY,"const Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ZERO of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_ZERO
static int tolua_get_Quaternion_ZERO(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Quaternion::ZERO,"const Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_mul00
static int tolua_common_Mathq4_mul00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* lhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::mul(*lhs,*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fill of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_fill00
static int tolua_common_Mathq4_fill00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float rx = ((float)  tolua_tonumber(tolua_S,2,0));
  float ry = ((float)  tolua_tonumber(tolua_S,3,0));
  float rz = ((float)  tolua_tonumber(tolua_S,4,0));
  float rw = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::fill(rx,ry,rz,rw);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
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

/* method: fill of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_fill01
static int tolua_common_Mathq4_fill01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::fill(*rhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Mathq4_fill00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillAxisAngle of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_fillAxisAngle00
static int tolua_common_Mathq4_fillAxisAngle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vec3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vec3* axis = ((const Vec3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::fillAxisAngle(*axis,angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillAxisAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillIdentity of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_fillIdentity00
static int tolua_common_Mathq4_fillIdentity00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::fillIdentity();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fillZero of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_fillZero00
static int tolua_common_Mathq4_fillZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::fillZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fillZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIdentity of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_isIdentity00
static int tolua_common_Mathq4_isIdentity00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* lhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  Mathq4::isIdentity(*lhs);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isZero of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_isZero00
static int tolua_common_Mathq4_isZero00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* lhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  Mathq4::isZero(*lhs);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_negate00
static int tolua_common_Mathq4_negate00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* lhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::negate(*lhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: inverse of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_inverse00
static int tolua_common_Mathq4_inverse00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* lhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::inverse(*lhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_normalize00
static int tolua_common_Mathq4_normalize00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* lhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::normalize(*lhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
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

/* method: axis of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_axis00
static int tolua_common_Mathq4_axis00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* lhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Vec3 tolua_ret = (Vec3)  Mathq4::axis(*lhs);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vec3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vec3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vec3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'axis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angle of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_angle00
static int tolua_common_Mathq4_angle00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* lhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   float tolua_ret = (float)  Mathq4::angle(*lhs);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lerp of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_lerp00
static int tolua_common_Mathq4_lerp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* lhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  float t = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::lerp(*lhs,*rhs,t);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
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

/* method: slerp of class  Mathq4 */
#ifndef TOLUA_DISABLE_tolua_common_Mathq4_slerp00
static int tolua_common_Mathq4_slerp00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mathq4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* lhs = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* rhs = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  float t = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Quaternion tolua_ret = (Quaternion)  Mathq4::slerp(*lhs,*rhs,t);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'slerp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_init00
static int tolua_common_MatrixStack_init00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MatrixStack::init();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delc of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_delc00
static int tolua_common_MatrixStack_delc00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MatrixStack::delc();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: use of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_use00
static int tolua_common_MatrixStack_use00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MatrixStackMode mode = ((MatrixStackMode) (int)  tolua_tonumber(tolua_S,2,0));
  {
   MatrixStack::use(mode);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'use'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: reset of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_reset00
static int tolua_common_MatrixStack_reset00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MatrixStack::reset();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'reset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetAll of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_resetAll00
static int tolua_common_MatrixStack_resetAll00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MatrixStack::resetAll();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: push of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_push00
static int tolua_common_MatrixStack_push00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MatrixStack::push();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'push'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pop of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_pop00
static int tolua_common_MatrixStack_pop00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MatrixStack::pop();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: identity of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_identity00
static int tolua_common_MatrixStack_identity00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MatrixStack::identity();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'identity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: load of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_load00
static int tolua_common_MatrixStack_load00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* mat = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   MatrixStack::load(*mat);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: multiply of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_multiply00
static int tolua_common_MatrixStack_multiply00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Mat4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Mat4* mat = ((const Mat4*)  tolua_tousertype(tolua_S,2,0));
  {
   MatrixStack::multiply(*mat);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'multiply'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  MatrixStack */
#ifndef TOLUA_DISABLE_tolua_common_MatrixStack_get00
static int tolua_common_MatrixStack_get00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MatrixStack",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   const Mat4& tolua_ret = (const Mat4&)  MatrixStack::get();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Mat4");
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
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
  tolua_function(tolua_S,"magicalIsError",tolua_common_magicalIsError00);
  tolua_function(tolua_S,"magicalIgnoreLastError",tolua_common_magicalIgnoreLastError00);
  tolua_function(tolua_S,"magicalSetLastErrorInfo",tolua_common_magicalSetLastErrorInfo00);
  tolua_function(tolua_S,"magicalGetLastErrorInfo",tolua_common_magicalGetLastErrorInfo00);
  tolua_function(tolua_S,"magicalAssert",tolua_common_magicalAssert00);
  tolua_function(tolua_S,"magicalBeginTicking",tolua_common_magicalBeginTicking00);
  tolua_function(tolua_S,"magicalEndTicking",tolua_common_magicalEndTicking00);
  tolua_function(tolua_S,"magicalBeginObserve",tolua_common_magicalBeginObserve00);
  tolua_function(tolua_S,"magicalEndObserve",tolua_common_magicalEndObserve00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Reference","Reference","",tolua_collect_Reference);
  #else
  tolua_cclass(tolua_S,"Reference","Reference","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Reference");
   tolua_function(tolua_S,"delete",tolua_common_Reference_delete00);
   tolua_function(tolua_S,"retain",tolua_common_Reference_retain00);
   tolua_function(tolua_S,"release",tolua_common_Reference_release00);
   tolua_function(tolua_S,"referenceCount",tolua_common_Reference_referenceCount00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Data","Data","Reference",tolua_collect_Data);
  #else
  tolua_cclass(tolua_S,"Data","Data","Reference",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Data");
   tolua_function(tolua_S,"delete",tolua_common_Data_delete00);
   tolua_function(tolua_S,"create",tolua_common_Data_create00);
   tolua_function(tolua_S,"assign",tolua_common_Data_assign00);
   tolua_function(tolua_S,"malloc",tolua_common_Data_malloc00);
   tolua_function(tolua_S,"realloc",tolua_common_Data_realloc00);
   tolua_function(tolua_S,"empty",tolua_common_Data_empty00);
   tolua_function(tolua_S,"size",tolua_common_Data_size00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Assets","Assets","",NULL);
  tolua_beginmodule(tolua_S,"Assets");
   tolua_function(tolua_S,"getAbsolutePath",tolua_common_Assets_getAbsolutePath00);
   tolua_function(tolua_S,"getDefaultSearchPath",tolua_common_Assets_getDefaultSearchPath00);
   tolua_function(tolua_S,"addSearchPath",tolua_common_Assets_addSearchPath00);
   tolua_function(tolua_S,"removeSearchPath",tolua_common_Assets_removeSearchPath00);
   tolua_function(tolua_S,"clearSearchPath",tolua_common_Assets_clearSearchPath00);
   tolua_function(tolua_S,"clearCachedAbsPath",tolua_common_Assets_clearCachedAbsPath00);
   tolua_function(tolua_S,"isAssetsFileExist",tolua_common_Assets_isAssetsFileExist00);
   tolua_function(tolua_S,"loadAssetsFile",tolua_common_Assets_loadAssetsFile00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"magicalLog",tolua_common_magicalLog00);
  tolua_function(tolua_S,"magicalLogD",tolua_common_magicalLogD00);
  tolua_function(tolua_S,"magicalLogE",tolua_common_magicalLogE00);
  tolua_function(tolua_S,"magicalLogLastError",tolua_common_magicalLogLastError00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Mat4","Mat4","",tolua_collect_Mat4);
  #else
  tolua_cclass(tolua_S,"Mat4","Mat4","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Mat4");
   tolua_array(tolua_S,"mat",tolua_get_common_Mat4_mat,tolua_set_common_Mat4_mat);
   tolua_function(tolua_S,"new",tolua_common_Mat4_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Mat4_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Mat4_new00_local);
   tolua_function(tolua_S,"new",tolua_common_Mat4_new01);
   tolua_function(tolua_S,"new_local",tolua_common_Mat4_new01_local);
   tolua_function(tolua_S,".call",tolua_common_Mat4_new01_local);
   tolua_function(tolua_S,"new",tolua_common_Mat4_new02);
   tolua_function(tolua_S,"new_local",tolua_common_Mat4_new02_local);
   tolua_function(tolua_S,".call",tolua_common_Mat4_new02_local);
   tolua_function(tolua_S,"delete",tolua_common_Mat4_delete00);
   tolua_function(tolua_S,".add",tolua_common_Mat4__add00);
   tolua_function(tolua_S,".add",tolua_common_Mat4__add01);
   tolua_function(tolua_S,".sub",tolua_common_Mat4__sub00);
   tolua_function(tolua_S,".sub",tolua_common_Mat4__sub01);
   tolua_function(tolua_S,".mul",tolua_common_Mat4__mul00);
   tolua_function(tolua_S,".mul",tolua_common_Mat4__mul01);
   tolua_function(tolua_S,"copy",tolua_common_Mat4_copy00);
   tolua_function(tolua_S,"fill",tolua_common_Mat4_fill00);
   tolua_function(tolua_S,"fill",tolua_common_Mat4_fill01);
   tolua_function(tolua_S,"fillIdentity",tolua_common_Mat4_fillIdentity00);
   tolua_function(tolua_S,"fillZero",tolua_common_Mat4_fillZero00);
   tolua_function(tolua_S,"fillLookAt",tolua_common_Mat4_fillLookAt00);
   tolua_function(tolua_S,"fillPerspective",tolua_common_Mat4_fillPerspective00);
   tolua_function(tolua_S,"fillOrthographic",tolua_common_Mat4_fillOrthographic00);
   tolua_function(tolua_S,"fillScale",tolua_common_Mat4_fillScale00);
   tolua_function(tolua_S,"fillScale",tolua_common_Mat4_fillScale01);
   tolua_function(tolua_S,"fillRotation",tolua_common_Mat4_fillRotation00);
   tolua_function(tolua_S,"fillRotation",tolua_common_Mat4_fillRotation01);
   tolua_function(tolua_S,"fillRotationX",tolua_common_Mat4_fillRotationX00);
   tolua_function(tolua_S,"fillRotationY",tolua_common_Mat4_fillRotationY00);
   tolua_function(tolua_S,"fillRotationZ",tolua_common_Mat4_fillRotationZ00);
   tolua_function(tolua_S,"fillTranslation",tolua_common_Mat4_fillTranslation00);
   tolua_function(tolua_S,"fillTranslation",tolua_common_Mat4_fillTranslation01);
   tolua_function(tolua_S,"isIdentity",tolua_common_Mat4_isIdentity00);
   tolua_function(tolua_S,"getUpVector",tolua_common_Mat4_getUpVector00);
   tolua_function(tolua_S,"getDownVector",tolua_common_Mat4_getDownVector00);
   tolua_function(tolua_S,"getLeftVector",tolua_common_Mat4_getLeftVector00);
   tolua_function(tolua_S,"getRightVector",tolua_common_Mat4_getRightVector00);
   tolua_function(tolua_S,"getForwardVector",tolua_common_Mat4_getForwardVector00);
   tolua_function(tolua_S,"getBackVector",tolua_common_Mat4_getBackVector00);
   tolua_function(tolua_S,"inverse",tolua_common_Mat4_inverse00);
   tolua_function(tolua_S,"negate",tolua_common_Mat4_negate00);
   tolua_function(tolua_S,"rotate",tolua_common_Mat4_rotate00);
   tolua_function(tolua_S,"rotate",tolua_common_Mat4_rotate01);
   tolua_function(tolua_S,"rotateX",tolua_common_Mat4_rotateX00);
   tolua_function(tolua_S,"rotateY",tolua_common_Mat4_rotateY00);
   tolua_function(tolua_S,"rotateZ",tolua_common_Mat4_rotateZ00);
   tolua_function(tolua_S,"scale",tolua_common_Mat4_scale00);
   tolua_function(tolua_S,"scale",tolua_common_Mat4_scale01);
   tolua_function(tolua_S,"scale",tolua_common_Mat4_scale02);
   tolua_function(tolua_S,"translate",tolua_common_Mat4_translate00);
   tolua_function(tolua_S,"translate",tolua_common_Mat4_translate01);
   tolua_function(tolua_S,"transpose",tolua_common_Mat4_transpose00);
   tolua_function(tolua_S,"transformVec3",tolua_common_Mat4_transformVec300);
   tolua_function(tolua_S,"transformVec4",tolua_common_Mat4_transformVec400);
   tolua_variable(tolua_S,"IDENTITY",tolua_get_Mat4_IDENTITY,NULL);
   tolua_variable(tolua_S,"ZERO",tolua_get_Mat4_ZERO,NULL);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Mathm4","Mathm4","",NULL);
  tolua_beginmodule(tolua_S,"Mathm4");
   tolua_function(tolua_S,"add",tolua_common_Mathm4_add00);
   tolua_function(tolua_S,"add",tolua_common_Mathm4_add01);
   tolua_function(tolua_S,"sub",tolua_common_Mathm4_sub00);
   tolua_function(tolua_S,"sub",tolua_common_Mathm4_sub01);
   tolua_function(tolua_S,"mul",tolua_common_Mathm4_mul00);
   tolua_function(tolua_S,"mul",tolua_common_Mathm4_mul01);
   tolua_function(tolua_S,"copy",tolua_common_Mathm4_copy00);
   tolua_function(tolua_S,"fill",tolua_common_Mathm4_fill00);
   tolua_function(tolua_S,"fill",tolua_common_Mathm4_fill01);
   tolua_function(tolua_S,"fillIdentity",tolua_common_Mathm4_fillIdentity00);
   tolua_function(tolua_S,"fillZero",tolua_common_Mathm4_fillZero00);
   tolua_function(tolua_S,"fillLookAt",tolua_common_Mathm4_fillLookAt00);
   tolua_function(tolua_S,"fillPerspective",tolua_common_Mathm4_fillPerspective00);
   tolua_function(tolua_S,"fillOrthographic",tolua_common_Mathm4_fillOrthographic00);
   tolua_function(tolua_S,"fillScale",tolua_common_Mathm4_fillScale00);
   tolua_function(tolua_S,"fillScale",tolua_common_Mathm4_fillScale01);
   tolua_function(tolua_S,"fillRotation",tolua_common_Mathm4_fillRotation00);
   tolua_function(tolua_S,"fillRotation",tolua_common_Mathm4_fillRotation01);
   tolua_function(tolua_S,"fillRotationX",tolua_common_Mathm4_fillRotationX00);
   tolua_function(tolua_S,"fillRotationY",tolua_common_Mathm4_fillRotationY00);
   tolua_function(tolua_S,"fillRotationZ",tolua_common_Mathm4_fillRotationZ00);
   tolua_function(tolua_S,"fillTranslation",tolua_common_Mathm4_fillTranslation00);
   tolua_function(tolua_S,"fillTranslation",tolua_common_Mathm4_fillTranslation01);
   tolua_function(tolua_S,"isIdentity",tolua_common_Mathm4_isIdentity00);
   tolua_function(tolua_S,"getUpVector",tolua_common_Mathm4_getUpVector00);
   tolua_function(tolua_S,"getDownVector",tolua_common_Mathm4_getDownVector00);
   tolua_function(tolua_S,"getLeftVector",tolua_common_Mathm4_getLeftVector00);
   tolua_function(tolua_S,"getRightVector",tolua_common_Mathm4_getRightVector00);
   tolua_function(tolua_S,"getForwardVector",tolua_common_Mathm4_getForwardVector00);
   tolua_function(tolua_S,"getBackVector",tolua_common_Mathm4_getBackVector00);
   tolua_function(tolua_S,"inverse",tolua_common_Mathm4_inverse00);
   tolua_function(tolua_S,"negate",tolua_common_Mathm4_negate00);
   tolua_function(tolua_S,"rotate",tolua_common_Mathm4_rotate00);
   tolua_function(tolua_S,"rotate",tolua_common_Mathm4_rotate01);
   tolua_function(tolua_S,"rotateX",tolua_common_Mathm4_rotateX00);
   tolua_function(tolua_S,"rotateY",tolua_common_Mathm4_rotateY00);
   tolua_function(tolua_S,"rotateZ",tolua_common_Mathm4_rotateZ00);
   tolua_function(tolua_S,"scale",tolua_common_Mathm4_scale00);
   tolua_function(tolua_S,"scale",tolua_common_Mathm4_scale01);
   tolua_function(tolua_S,"scale",tolua_common_Mathm4_scale02);
   tolua_function(tolua_S,"translate",tolua_common_Mathm4_translate00);
   tolua_function(tolua_S,"translate",tolua_common_Mathm4_translate01);
   tolua_function(tolua_S,"transpose",tolua_common_Mathm4_transpose00);
   tolua_function(tolua_S,"transformVec3",tolua_common_Mathm4_transformVec300);
   tolua_function(tolua_S,"transformVec4",tolua_common_Mathm4_transformVec400);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vec2","Vec2","",tolua_collect_Vec2);
  #else
  tolua_cclass(tolua_S,"Vec2","Vec2","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vec2");
   tolua_variable(tolua_S,"x",tolua_get_Vec2_x,tolua_set_Vec2_x);
   tolua_variable(tolua_S,"y",tolua_get_Vec2_y,tolua_set_Vec2_y);
   tolua_function(tolua_S,"new",tolua_common_Vec2_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Vec2_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Vec2_new00_local);
   tolua_function(tolua_S,"new",tolua_common_Vec2_new01);
   tolua_function(tolua_S,"new_local",tolua_common_Vec2_new01_local);
   tolua_function(tolua_S,".call",tolua_common_Vec2_new01_local);
   tolua_function(tolua_S,"new",tolua_common_Vec2_new02);
   tolua_function(tolua_S,"new_local",tolua_common_Vec2_new02_local);
   tolua_function(tolua_S,".call",tolua_common_Vec2_new02_local);
   tolua_function(tolua_S,".add",tolua_common_Vec2__add00);
   tolua_function(tolua_S,".add",tolua_common_Vec2__add01);
   tolua_function(tolua_S,".sub",tolua_common_Vec2__sub00);
   tolua_function(tolua_S,".sub",tolua_common_Vec2__sub01);
   tolua_function(tolua_S,".mul",tolua_common_Vec2__mul00);
   tolua_function(tolua_S,".mul",tolua_common_Vec2__mul01);
   tolua_function(tolua_S,".div",tolua_common_Vec2__div00);
   tolua_function(tolua_S,".div",tolua_common_Vec2__div01);
   tolua_function(tolua_S,".eq",tolua_common_Vec2__eq00);
   tolua_function(tolua_S,"isZero",tolua_common_Vec2_isZero00);
   tolua_function(tolua_S,"copy",tolua_common_Vec2_copy00);
   tolua_function(tolua_S,"fill",tolua_common_Vec2_fill00);
   tolua_function(tolua_S,"fill",tolua_common_Vec2_fill01);
   tolua_function(tolua_S,"fillZero",tolua_common_Vec2_fillZero00);
   tolua_function(tolua_S,"clamp",tolua_common_Vec2_clamp00);
   tolua_function(tolua_S,"distance",tolua_common_Vec2_distance00);
   tolua_function(tolua_S,"distanceSq",tolua_common_Vec2_distanceSq00);
   tolua_function(tolua_S,"length",tolua_common_Vec2_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_Vec2_lengthSq00);
   tolua_function(tolua_S,"dot",tolua_common_Vec2_dot00);
   tolua_function(tolua_S,"angle",tolua_common_Vec2_angle00);
   tolua_function(tolua_S,"negate",tolua_common_Vec2_negate00);
   tolua_function(tolua_S,"normalize",tolua_common_Vec2_normalize00);
   tolua_function(tolua_S,"rotate",tolua_common_Vec2_rotate00);
   tolua_function(tolua_S,"middle",tolua_common_Vec2_middle00);
   tolua_variable(tolua_S,"ZERO",tolua_get_Vec2_ZERO,NULL);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Mathv2","Mathv2","",NULL);
  tolua_beginmodule(tolua_S,"Mathv2");
   tolua_function(tolua_S,"add",tolua_common_Mathv2_add00);
   tolua_function(tolua_S,"add",tolua_common_Mathv2_add01);
   tolua_function(tolua_S,"sub",tolua_common_Mathv2_sub00);
   tolua_function(tolua_S,"sub",tolua_common_Mathv2_sub01);
   tolua_function(tolua_S,"mul",tolua_common_Mathv2_mul00);
   tolua_function(tolua_S,"mul",tolua_common_Mathv2_mul01);
   tolua_function(tolua_S,"div",tolua_common_Mathv2_div00);
   tolua_function(tolua_S,"div",tolua_common_Mathv2_div01);
   tolua_function(tolua_S,"equals",tolua_common_Mathv2_equals00);
   tolua_function(tolua_S,"copy",tolua_common_Mathv2_copy00);
   tolua_function(tolua_S,"fill",tolua_common_Mathv2_fill00);
   tolua_function(tolua_S,"fill",tolua_common_Mathv2_fill01);
   tolua_function(tolua_S,"fillZero",tolua_common_Mathv2_fillZero00);
   tolua_function(tolua_S,"clamp",tolua_common_Mathv2_clamp00);
   tolua_function(tolua_S,"distance",tolua_common_Mathv2_distance00);
   tolua_function(tolua_S,"distanceSq",tolua_common_Mathv2_distanceSq00);
   tolua_function(tolua_S,"length",tolua_common_Mathv2_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_Mathv2_lengthSq00);
   tolua_function(tolua_S,"dot",tolua_common_Mathv2_dot00);
   tolua_function(tolua_S,"angle",tolua_common_Mathv2_angle00);
   tolua_function(tolua_S,"negate",tolua_common_Mathv2_negate00);
   tolua_function(tolua_S,"normalize",tolua_common_Mathv2_normalize00);
   tolua_function(tolua_S,"rotate",tolua_common_Mathv2_rotate00);
   tolua_function(tolua_S,"middle",tolua_common_Mathv2_middle00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vec3","Vec3","",tolua_collect_Vec3);
  #else
  tolua_cclass(tolua_S,"Vec3","Vec3","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vec3");
   tolua_variable(tolua_S,"x",tolua_get_Vec3_x,tolua_set_Vec3_x);
   tolua_variable(tolua_S,"y",tolua_get_Vec3_y,tolua_set_Vec3_y);
   tolua_variable(tolua_S,"z",tolua_get_Vec3_z,tolua_set_Vec3_z);
   tolua_function(tolua_S,"new",tolua_common_Vec3_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Vec3_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Vec3_new00_local);
   tolua_function(tolua_S,"new",tolua_common_Vec3_new01);
   tolua_function(tolua_S,"new_local",tolua_common_Vec3_new01_local);
   tolua_function(tolua_S,".call",tolua_common_Vec3_new01_local);
   tolua_function(tolua_S,"new",tolua_common_Vec3_new02);
   tolua_function(tolua_S,"new_local",tolua_common_Vec3_new02_local);
   tolua_function(tolua_S,".call",tolua_common_Vec3_new02_local);
   tolua_function(tolua_S,"delete",tolua_common_Vec3_delete00);
   tolua_function(tolua_S,".add",tolua_common_Vec3__add00);
   tolua_function(tolua_S,".add",tolua_common_Vec3__add01);
   tolua_function(tolua_S,".sub",tolua_common_Vec3__sub00);
   tolua_function(tolua_S,".sub",tolua_common_Vec3__sub01);
   tolua_function(tolua_S,".mul",tolua_common_Vec3__mul00);
   tolua_function(tolua_S,".mul",tolua_common_Vec3__mul01);
   tolua_function(tolua_S,".div",tolua_common_Vec3__div00);
   tolua_function(tolua_S,".div",tolua_common_Vec3__div01);
   tolua_function(tolua_S,".eq",tolua_common_Vec3__eq00);
   tolua_function(tolua_S,"isZero",tolua_common_Vec3_isZero00);
   tolua_function(tolua_S,"fill",tolua_common_Vec3_fill00);
   tolua_function(tolua_S,"fill",tolua_common_Vec3_fill01);
   tolua_function(tolua_S,"fillZero",tolua_common_Vec3_fillZero00);
   tolua_function(tolua_S,"copy",tolua_common_Vec3_copy00);
   tolua_function(tolua_S,"clamp",tolua_common_Vec3_clamp00);
   tolua_function(tolua_S,"cross",tolua_common_Vec3_cross00);
   tolua_function(tolua_S,"negate",tolua_common_Vec3_negate00);
   tolua_function(tolua_S,"normalize",tolua_common_Vec3_normalize00);
   tolua_function(tolua_S,"scale",tolua_common_Vec3_scale00);
   tolua_function(tolua_S,"angle",tolua_common_Vec3_angle00);
   tolua_function(tolua_S,"dot",tolua_common_Vec3_dot00);
   tolua_function(tolua_S,"distance",tolua_common_Vec3_distance00);
   tolua_function(tolua_S,"distanceSq",tolua_common_Vec3_distanceSq00);
   tolua_function(tolua_S,"length",tolua_common_Vec3_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_Vec3_lengthSq00);
   tolua_variable(tolua_S,"ZERO",tolua_get_Vec3_ZERO,NULL);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Mathv3","Mathv3","",NULL);
  tolua_beginmodule(tolua_S,"Mathv3");
   tolua_function(tolua_S,"add",tolua_common_Mathv3_add00);
   tolua_function(tolua_S,"add",tolua_common_Mathv3_add01);
   tolua_function(tolua_S,"sub",tolua_common_Mathv3_sub00);
   tolua_function(tolua_S,"sub",tolua_common_Mathv3_sub01);
   tolua_function(tolua_S,"mul",tolua_common_Mathv3_mul00);
   tolua_function(tolua_S,"mul",tolua_common_Mathv3_mul01);
   tolua_function(tolua_S,"div",tolua_common_Mathv3_div00);
   tolua_function(tolua_S,"div",tolua_common_Mathv3_div01);
   tolua_function(tolua_S,"equals",tolua_common_Mathv3_equals00);
   tolua_function(tolua_S,"fill",tolua_common_Mathv3_fill00);
   tolua_function(tolua_S,"fill",tolua_common_Mathv3_fill01);
   tolua_function(tolua_S,"fillZero",tolua_common_Mathv3_fillZero00);
   tolua_function(tolua_S,"copy",tolua_common_Mathv3_copy00);
   tolua_function(tolua_S,"clamp",tolua_common_Mathv3_clamp00);
   tolua_function(tolua_S,"cross",tolua_common_Mathv3_cross00);
   tolua_function(tolua_S,"negate",tolua_common_Mathv3_negate00);
   tolua_function(tolua_S,"normalize",tolua_common_Mathv3_normalize00);
   tolua_function(tolua_S,"scale",tolua_common_Mathv3_scale00);
   tolua_function(tolua_S,"angle",tolua_common_Mathv3_angle00);
   tolua_function(tolua_S,"dot",tolua_common_Mathv3_dot00);
   tolua_function(tolua_S,"distance",tolua_common_Mathv3_distance00);
   tolua_function(tolua_S,"distanceSq",tolua_common_Mathv3_distanceSq00);
   tolua_function(tolua_S,"length",tolua_common_Mathv3_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_Mathv3_lengthSq00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vec4","Vec4","",tolua_collect_Vec4);
  #else
  tolua_cclass(tolua_S,"Vec4","Vec4","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vec4");
   tolua_variable(tolua_S,"x",tolua_get_Vec4_x,tolua_set_Vec4_x);
   tolua_variable(tolua_S,"y",tolua_get_Vec4_y,tolua_set_Vec4_y);
   tolua_variable(tolua_S,"z",tolua_get_Vec4_z,tolua_set_Vec4_z);
   tolua_variable(tolua_S,"w",tolua_get_Vec4_w,tolua_set_Vec4_w);
   tolua_function(tolua_S,"new",tolua_common_Vec4_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Vec4_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Vec4_new00_local);
   tolua_function(tolua_S,"new",tolua_common_Vec4_new01);
   tolua_function(tolua_S,"new_local",tolua_common_Vec4_new01_local);
   tolua_function(tolua_S,".call",tolua_common_Vec4_new01_local);
   tolua_function(tolua_S,"new",tolua_common_Vec4_new02);
   tolua_function(tolua_S,"new_local",tolua_common_Vec4_new02_local);
   tolua_function(tolua_S,".call",tolua_common_Vec4_new02_local);
   tolua_function(tolua_S,".add",tolua_common_Vec4__add00);
   tolua_function(tolua_S,".add",tolua_common_Vec4__add01);
   tolua_function(tolua_S,".sub",tolua_common_Vec4__sub00);
   tolua_function(tolua_S,".sub",tolua_common_Vec4__sub01);
   tolua_function(tolua_S,".mul",tolua_common_Vec4__mul00);
   tolua_function(tolua_S,".mul",tolua_common_Vec4__mul01);
   tolua_function(tolua_S,".div",tolua_common_Vec4__div00);
   tolua_function(tolua_S,".div",tolua_common_Vec4__div01);
   tolua_function(tolua_S,".eq",tolua_common_Vec4__eq00);
   tolua_function(tolua_S,"isZero",tolua_common_Vec4_isZero00);
   tolua_function(tolua_S,"fill",tolua_common_Vec4_fill00);
   tolua_function(tolua_S,"fill",tolua_common_Vec4_fill01);
   tolua_function(tolua_S,"fillZero",tolua_common_Vec4_fillZero00);
   tolua_function(tolua_S,"copy",tolua_common_Vec4_copy00);
   tolua_function(tolua_S,"negate",tolua_common_Vec4_negate00);
   tolua_function(tolua_S,"normalize",tolua_common_Vec4_normalize00);
   tolua_function(tolua_S,"clamp",tolua_common_Vec4_clamp00);
   tolua_function(tolua_S,"angle",tolua_common_Vec4_angle00);
   tolua_function(tolua_S,"dot",tolua_common_Vec4_dot00);
   tolua_function(tolua_S,"distance",tolua_common_Vec4_distance00);
   tolua_function(tolua_S,"distanceSq",tolua_common_Vec4_distanceSq00);
   tolua_function(tolua_S,"length",tolua_common_Vec4_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_Vec4_lengthSq00);
   tolua_variable(tolua_S,"ZERO",tolua_get_Vec4_ZERO,NULL);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Mathv4","Mathv4","",NULL);
  tolua_beginmodule(tolua_S,"Mathv4");
   tolua_function(tolua_S,"add",tolua_common_Mathv4_add00);
   tolua_function(tolua_S,"add",tolua_common_Mathv4_add01);
   tolua_function(tolua_S,"sub",tolua_common_Mathv4_sub00);
   tolua_function(tolua_S,"sub",tolua_common_Mathv4_sub01);
   tolua_function(tolua_S,"mul",tolua_common_Mathv4_mul00);
   tolua_function(tolua_S,"mul",tolua_common_Mathv4_mul01);
   tolua_function(tolua_S,"div",tolua_common_Mathv4_div00);
   tolua_function(tolua_S,"div",tolua_common_Mathv4_div01);
   tolua_function(tolua_S,"equals",tolua_common_Mathv4_equals00);
   tolua_function(tolua_S,"fill",tolua_common_Mathv4_fill00);
   tolua_function(tolua_S,"fill",tolua_common_Mathv4_fill01);
   tolua_function(tolua_S,"fillZero",tolua_common_Mathv4_fillZero00);
   tolua_function(tolua_S,"copy",tolua_common_Mathv4_copy00);
   tolua_function(tolua_S,"negate",tolua_common_Mathv4_negate00);
   tolua_function(tolua_S,"normalize",tolua_common_Mathv4_normalize00);
   tolua_function(tolua_S,"clamp",tolua_common_Mathv4_clamp00);
   tolua_function(tolua_S,"angle",tolua_common_Mathv4_angle00);
   tolua_function(tolua_S,"dot",tolua_common_Mathv4_dot00);
   tolua_function(tolua_S,"distance",tolua_common_Mathv4_distance00);
   tolua_function(tolua_S,"distanceSq",tolua_common_Mathv4_distanceSq00);
   tolua_function(tolua_S,"length",tolua_common_Mathv4_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_Mathv4_lengthSq00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Quaternion","Quaternion","",tolua_collect_Quaternion);
  #else
  tolua_cclass(tolua_S,"Quaternion","Quaternion","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Quaternion");
   tolua_variable(tolua_S,"x",tolua_get_Quaternion_x,tolua_set_Quaternion_x);
   tolua_variable(tolua_S,"y",tolua_get_Quaternion_y,tolua_set_Quaternion_y);
   tolua_variable(tolua_S,"z",tolua_get_Quaternion_z,tolua_set_Quaternion_z);
   tolua_variable(tolua_S,"w",tolua_get_Quaternion_w,tolua_set_Quaternion_w);
   tolua_function(tolua_S,"new",tolua_common_Quaternion_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Quaternion_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Quaternion_new00_local);
   tolua_function(tolua_S,"new",tolua_common_Quaternion_new01);
   tolua_function(tolua_S,"new_local",tolua_common_Quaternion_new01_local);
   tolua_function(tolua_S,".call",tolua_common_Quaternion_new01_local);
   tolua_function(tolua_S,"new",tolua_common_Quaternion_new02);
   tolua_function(tolua_S,"new_local",tolua_common_Quaternion_new02_local);
   tolua_function(tolua_S,".call",tolua_common_Quaternion_new02_local);
   tolua_function(tolua_S,"new",tolua_common_Quaternion_new03);
   tolua_function(tolua_S,"new_local",tolua_common_Quaternion_new03_local);
   tolua_function(tolua_S,".call",tolua_common_Quaternion_new03_local);
   tolua_function(tolua_S,".mul",tolua_common_Quaternion__mul00);
   tolua_function(tolua_S,"fill",tolua_common_Quaternion_fill00);
   tolua_function(tolua_S,"fill",tolua_common_Quaternion_fill01);
   tolua_function(tolua_S,"fillAxisAngle",tolua_common_Quaternion_fillAxisAngle00);
   tolua_function(tolua_S,"fillIdentity",tolua_common_Quaternion_fillIdentity00);
   tolua_function(tolua_S,"fillZero",tolua_common_Quaternion_fillZero00);
   tolua_function(tolua_S,"isIdentity",tolua_common_Quaternion_isIdentity00);
   tolua_function(tolua_S,"isZero",tolua_common_Quaternion_isZero00);
   tolua_function(tolua_S,"negate",tolua_common_Quaternion_negate00);
   tolua_function(tolua_S,"inverse",tolua_common_Quaternion_inverse00);
   tolua_function(tolua_S,"normalize",tolua_common_Quaternion_normalize00);
   tolua_function(tolua_S,"axis",tolua_common_Quaternion_axis00);
   tolua_function(tolua_S,"angle",tolua_common_Quaternion_angle00);
   tolua_function(tolua_S,"lerp",tolua_common_Quaternion_lerp00);
   tolua_function(tolua_S,"slerp",tolua_common_Quaternion_slerp00);
   tolua_variable(tolua_S,"IDENTITY",tolua_get_Quaternion_IDENTITY,NULL);
   tolua_variable(tolua_S,"ZERO",tolua_get_Quaternion_ZERO,NULL);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Mathq4","Mathq4","",NULL);
  tolua_beginmodule(tolua_S,"Mathq4");
   tolua_function(tolua_S,"mul",tolua_common_Mathq4_mul00);
   tolua_function(tolua_S,"fill",tolua_common_Mathq4_fill00);
   tolua_function(tolua_S,"fill",tolua_common_Mathq4_fill01);
   tolua_function(tolua_S,"fillAxisAngle",tolua_common_Mathq4_fillAxisAngle00);
   tolua_function(tolua_S,"fillIdentity",tolua_common_Mathq4_fillIdentity00);
   tolua_function(tolua_S,"fillZero",tolua_common_Mathq4_fillZero00);
   tolua_function(tolua_S,"isIdentity",tolua_common_Mathq4_isIdentity00);
   tolua_function(tolua_S,"isZero",tolua_common_Mathq4_isZero00);
   tolua_function(tolua_S,"negate",tolua_common_Mathq4_negate00);
   tolua_function(tolua_S,"inverse",tolua_common_Mathq4_inverse00);
   tolua_function(tolua_S,"normalize",tolua_common_Mathq4_normalize00);
   tolua_function(tolua_S,"axis",tolua_common_Mathq4_axis00);
   tolua_function(tolua_S,"angle",tolua_common_Mathq4_angle00);
   tolua_function(tolua_S,"lerp",tolua_common_Mathq4_lerp00);
   tolua_function(tolua_S,"slerp",tolua_common_Mathq4_slerp00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"kModelView",kModelView);
  tolua_constant(tolua_S,"kProjection",kProjection);
  tolua_cclass(tolua_S,"MatrixStack","MatrixStack","",NULL);
  tolua_beginmodule(tolua_S,"MatrixStack");
   tolua_function(tolua_S,"init",tolua_common_MatrixStack_init00);
   tolua_function(tolua_S,"delc",tolua_common_MatrixStack_delc00);
   tolua_function(tolua_S,"use",tolua_common_MatrixStack_use00);
   tolua_function(tolua_S,"reset",tolua_common_MatrixStack_reset00);
   tolua_function(tolua_S,"resetAll",tolua_common_MatrixStack_resetAll00);
   tolua_function(tolua_S,"push",tolua_common_MatrixStack_push00);
   tolua_function(tolua_S,"pop",tolua_common_MatrixStack_pop00);
   tolua_function(tolua_S,"identity",tolua_common_MatrixStack_identity00);
   tolua_function(tolua_S,"load",tolua_common_MatrixStack_load00);
   tolua_function(tolua_S,"multiply",tolua_common_MatrixStack_multiply00);
   tolua_function(tolua_S,"get",tolua_common_MatrixStack_get00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_common (lua_State* tolua_S) {
 return tolua_common_open(tolua_S);
};
#endif

