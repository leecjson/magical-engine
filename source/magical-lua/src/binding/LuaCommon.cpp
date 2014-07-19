/*
** Lua binding: common
** Generated automatically by tolua++-1.0.92 on 07/13/14 18:20:11.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_common_open (lua_State* tolua_S);

#include "LuaCommon.h"
#include "tolua_ext.h"
#include "magical-engine.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Reference (lua_State* tolua_S)
{
 Reference* self = (Reference*) tolua_tousertype(tolua_S,1,0);
	self->release();
	return 0;
}

static int tolua_collect_Data (lua_State* tolua_S)
{
 Data* self = (Data*) tolua_tousertype(tolua_S,1,0);
	self->release();
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"AssetsSystem");
 tolua_usertype(tolua_S,"Data");
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

/* method: addSearchPath of class  AssetsSystem */
#ifndef TOLUA_DISABLE_tolua_common_AssetsSystem_addSearchPath00
static int tolua_common_AssetsSystem_addSearchPath00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AssetsSystem",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   AssetsSystem::addSearchPath(path);
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

/* method: removeSearchPath of class  AssetsSystem */
#ifndef TOLUA_DISABLE_tolua_common_AssetsSystem_removeSearchPath00
static int tolua_common_AssetsSystem_removeSearchPath00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AssetsSystem",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   AssetsSystem::removeSearchPath(path);
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

/* method: clearSearchPath of class  AssetsSystem */
#ifndef TOLUA_DISABLE_tolua_common_AssetsSystem_clearSearchPath00
static int tolua_common_AssetsSystem_clearSearchPath00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AssetsSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AssetsSystem::clearSearchPath();
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

/* method: isAssetsFileExist of class  AssetsSystem */
#ifndef TOLUA_DISABLE_tolua_common_AssetsSystem_isAssetsFileExist00
static int tolua_common_AssetsSystem_isAssetsFileExist00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AssetsSystem",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* file_name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  AssetsSystem::isAssetsFileExist(file_name);
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

/* method: loadAssetsFile of class  AssetsSystem */
#ifndef TOLUA_DISABLE_tolua_common_AssetsSystem_loadAssetsFile00
static int tolua_common_AssetsSystem_loadAssetsFile00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AssetsSystem",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* file_name = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Shared<Data> tolua_ret = (Shared<Data>)  AssetsSystem::loadAssetsFile(file_name);
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
  tolua_cclass(tolua_S,"AssetsSystem","AssetsSystem","",NULL);
  tolua_beginmodule(tolua_S,"AssetsSystem");
   tolua_function(tolua_S,"addSearchPath",tolua_common_AssetsSystem_addSearchPath00);
   tolua_function(tolua_S,"removeSearchPath",tolua_common_AssetsSystem_removeSearchPath00);
   tolua_function(tolua_S,"clearSearchPath",tolua_common_AssetsSystem_clearSearchPath00);
   tolua_function(tolua_S,"isAssetsFileExist",tolua_common_AssetsSystem_isAssetsFileExist00);
   tolua_function(tolua_S,"loadAssetsFile",tolua_common_AssetsSystem_loadAssetsFile00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"magicalLog",tolua_common_magicalLog00);
  tolua_function(tolua_S,"magicalLogD",tolua_common_magicalLogD00);
  tolua_function(tolua_S,"magicalLogE",tolua_common_magicalLogE00);
  tolua_function(tolua_S,"magicalLogLastError",tolua_common_magicalLogLastError00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_common (lua_State* tolua_S) {
 return tolua_common_open(tolua_S);
};
#endif

