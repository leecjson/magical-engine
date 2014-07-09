/*
** Lua binding: common
** Generated automatically by tolua++-1.0.92 on 07/06/14 13:49:43.
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

static int tolua_collect_Data (lua_State* tolua_S)
{
 Data* self = (Data*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"AssetsSystem");
 tolua_usertype(tolua_S,"FileUtils");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"TimeUtils");
 tolua_usertype(tolua_S,"Data");
 tolua_usertype(tolua_S,"LogSystem");
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

/* function: magicalBeginObserveObject */
#ifndef TOLUA_DISABLE_tolua_common_magicalBeginObserveObject00
static int tolua_common_magicalBeginObserveObject00(lua_State* tolua_S)
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
   magicalBeginObserveObject();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalBeginObserveObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalEndObserveObject */
#ifndef TOLUA_DISABLE_tolua_common_magicalEndObserveObject00
static int tolua_common_magicalEndObserveObject00(lua_State* tolua_S)
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
   magicalEndObserveObject();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalEndObserveObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: newObject */
#ifndef TOLUA_DISABLE_tolua_common_newObject00
static int tolua_common_newObject00(lua_State* tolua_S)
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
   Object tolua_ret = (Object)  newObject();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Object)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Object");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Object));
     tolua_pushusertype(tolua_S,tolua_obj,"Object");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'newObject'.",&tolua_err);
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

/* function: newData */
#ifndef TOLUA_DISABLE_tolua_common_newData00
static int tolua_common_newData00(lua_State* tolua_S)
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
   Data tolua_ret = (Data)  newData();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Data)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Data");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Data));
     tolua_pushusertype(tolua_S,tolua_obj,"Data");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'newData'.",&tolua_err);
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

/* method: get()->assign of class  Data */
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get()->assign'", NULL);
#endif
  {
   self->get()->assign(data,size);
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

/* method: get()->malloc of class  Data */
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get()->malloc'", NULL);
#endif
  {
   self->get()->malloc(size);
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

/* method: get()->realloc of class  Data */
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get()->realloc'", NULL);
#endif
  {
   self->get()->realloc(size);
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

/* method: get()->empty of class  Data */
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get()->empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->get()->empty();
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

/* method: get()->size of class  Data */
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
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get()->size'", NULL);
#endif
  {
   unsigned int tolua_ret = ( unsigned int)  self->get()->size();
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

/* method: get()->toString of class  Data */
#ifndef TOLUA_DISABLE_tolua_common_Data_toString00
static int tolua_common_Data_toString00(lua_State* tolua_S)
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

/* method: getAssetsFile of class  AssetsSystem */
#ifndef TOLUA_DISABLE_tolua_common_AssetsSystem_getAssetsFile00
static int tolua_common_AssetsSystem_getAssetsFile00(lua_State* tolua_S)
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
   Data tolua_ret = (Data)  AssetsSystem::getAssetsFile(file_name);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Data)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Data");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Data));
     tolua_pushusertype(tolua_S,tolua_obj,"Data");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAssetsFile'.",&tolua_err);
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

/* method: I of class  LogSystem */
#ifndef TOLUA_DISABLE_tolua_common_LogSystem_I00
static int tolua_common_LogSystem_I00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LogSystem",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* msg = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   LogSystem::I(msg);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'I'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: D of class  LogSystem */
#ifndef TOLUA_DISABLE_tolua_common_LogSystem_D00
static int tolua_common_LogSystem_D00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LogSystem",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* msg = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   LogSystem::D(msg);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'D'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: E of class  LogSystem */
#ifndef TOLUA_DISABLE_tolua_common_LogSystem_E00
static int tolua_common_LogSystem_E00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LogSystem",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* msg = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   LogSystem::E(msg);
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'E'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: currentMicrosecondsTime of class  TimeUtils */
#ifndef TOLUA_DISABLE_tolua_common_TimeUtils_currentMicrosecondsTime00
static int tolua_common_TimeUtils_currentMicrosecondsTime00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TimeUtils",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   long long tolua_ret = (long long)  TimeUtils::currentMicrosecondsTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'currentMicrosecondsTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: beginTicking of class  TimeUtils */
#ifndef TOLUA_DISABLE_tolua_common_TimeUtils_beginTicking00
static int tolua_common_TimeUtils_beginTicking00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TimeUtils",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   TimeUtils::beginTicking();
  }
 }
 return 0;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'beginTicking'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: endTicking of class  TimeUtils */
#ifndef TOLUA_DISABLE_tolua_common_TimeUtils_endTicking00
static int tolua_common_TimeUtils_endTicking00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"TimeUtils",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   float tolua_ret = (float)  TimeUtils::endTicking();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'endTicking'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAbsolutePath of class  FileUtils */
#ifndef TOLUA_DISABLE_tolua_common_FileUtils_isAbsolutePath00
static int tolua_common_FileUtils_isAbsolutePath00(lua_State* tolua_S)
{
#ifdef MAG_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FileUtils",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* path = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   bool tolua_ret = (bool)  FileUtils::isAbsolutePath(path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAG_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAbsolutePath'.",&tolua_err);
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
  tolua_function(tolua_S,"magicalBeginObserveObject",tolua_common_magicalBeginObserveObject00);
  tolua_function(tolua_S,"magicalEndObserveObject",tolua_common_magicalEndObserveObject00);
  tolua_function(tolua_S,"newObject",tolua_common_newObject00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Object","Object","",tolua_collect_Object);
  #else
  tolua_cclass(tolua_S,"Object","Object","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Object");
   tolua_function(tolua_S,"delete",tolua_common_Object_delete00);
   tolua_function(tolua_S,"toString",tolua_common_Object_toString00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"newData",tolua_common_newData00);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Data","Data","",tolua_collect_Data);
  #else
  tolua_cclass(tolua_S,"Data","Data","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Data");
   tolua_function(tolua_S,"delete",tolua_common_Data_delete00);
   tolua_function(tolua_S,"assign",tolua_common_Data_assign00);
   tolua_function(tolua_S,"malloc",tolua_common_Data_malloc00);
   tolua_function(tolua_S,"realloc",tolua_common_Data_realloc00);
   tolua_function(tolua_S,"empty",tolua_common_Data_empty00);
   tolua_function(tolua_S,"size",tolua_common_Data_size00);
   tolua_function(tolua_S,"toString",tolua_common_Data_toString00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"AssetsSystem","AssetsSystem","",NULL);
  tolua_beginmodule(tolua_S,"AssetsSystem");
   tolua_function(tolua_S,"addSearchPath",tolua_common_AssetsSystem_addSearchPath00);
   tolua_function(tolua_S,"removeSearchPath",tolua_common_AssetsSystem_removeSearchPath00);
   tolua_function(tolua_S,"clearSearchPath",tolua_common_AssetsSystem_clearSearchPath00);
   tolua_function(tolua_S,"isAssetsFileExist",tolua_common_AssetsSystem_isAssetsFileExist00);
   tolua_function(tolua_S,"getAssetsFile",tolua_common_AssetsSystem_getAssetsFile00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"magicalLog",tolua_common_magicalLog00);
  tolua_function(tolua_S,"magicalLogD",tolua_common_magicalLogD00);
  tolua_function(tolua_S,"magicalLogE",tolua_common_magicalLogE00);
  tolua_function(tolua_S,"magicalLogLastError",tolua_common_magicalLogLastError00);
  tolua_cclass(tolua_S,"LogSystem","LogSystem","",NULL);
  tolua_beginmodule(tolua_S,"LogSystem");
   tolua_function(tolua_S,"I",tolua_common_LogSystem_I00);
   tolua_function(tolua_S,"D",tolua_common_LogSystem_D00);
   tolua_function(tolua_S,"E",tolua_common_LogSystem_E00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"TimeUtils","TimeUtils","",NULL);
  tolua_beginmodule(tolua_S,"TimeUtils");
   tolua_function(tolua_S,"currentMicrosecondsTime",tolua_common_TimeUtils_currentMicrosecondsTime00);
   tolua_function(tolua_S,"beginTicking",tolua_common_TimeUtils_beginTicking00);
   tolua_function(tolua_S,"endTicking",tolua_common_TimeUtils_endTicking00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"FileUtils","FileUtils","",NULL);
  tolua_beginmodule(tolua_S,"FileUtils");
   tolua_function(tolua_S,"isAbsolutePath",tolua_common_FileUtils_isAbsolutePath00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_common (lua_State* tolua_S) {
 return tolua_common_open(tolua_S);
};
#endif

