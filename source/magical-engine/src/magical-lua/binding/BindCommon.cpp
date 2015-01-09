/*
** Lua binding: common
** Generated automatically by tolua++-1.0.92 on 01/06/15 14:38:36.
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

static int tolua_collect_Quaternion (lua_State* tolua_S)
{
 Quaternion* self = (Quaternion*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Data (lua_State* tolua_S)
{
 Data* self = (Data*) tolua_tousertype(tolua_S,1,0);
	self->release();
	return 0;
}

static int tolua_collect_Vector4 (lua_State* tolua_S)
{
 Vector4* self = (Vector4*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_EulerAngles (lua_State* tolua_S)
{
 EulerAngles* self = (EulerAngles*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector2 (lua_State* tolua_S)
{
 Vector2* self = (Vector2*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Transform (lua_State* tolua_S)
{
 Transform* self = (Transform*) tolua_tousertype(tolua_S,1,0);
	self->release();
	return 0;
}

static int tolua_collect_Matrix4 (lua_State* tolua_S)
{
 Matrix4* self = (Matrix4*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_AxisAngle (lua_State* tolua_S)
{
 AxisAngle* self = (AxisAngle*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Transform");
 tolua_usertype(tolua_S,"Vector4");
 tolua_usertype(tolua_S,"Reference");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"Log");
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"EulerAngles");
 tolua_usertype(tolua_S,"Vector2");
 tolua_usertype(tolua_S,"Assets");
 tolua_usertype(tolua_S,"Data");
 tolua_usertype(tolua_S,"Matrix4");
 tolua_usertype(tolua_S,"AxisAngle");
}

/* method: resetAssetsPath of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_resetAssetsPath00
static int tolua_common_Assets_resetAssetsPath00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
   Assets::resetAssetsPath();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetAssetsPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setAssetsPath of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_setAssetsPath00
static int tolua_common_Assets_setAssetsPath00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
   Assets::setAssetsPath(path);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setAssetsPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAssetsPath of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_getAssetsPath00
static int tolua_common_Assets_getAssetsPath00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
   std::string tolua_ret = (std::string)  Assets::getAssetsPath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAssetsPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAssetsAbsoluteFilename of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_getAssetsAbsoluteFilename00
static int tolua_common_Assets_getAssetsAbsoluteFilename00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
   std::string tolua_ret = (std::string)  Assets::getAssetsAbsoluteFilename(file_name);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAssetsAbsoluteFilename'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isAssetsFileExist of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_isAssetsFileExist00
static int tolua_common_Assets_isAssetsFileExist00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isAssetsFileExist'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAssetsFileData of class  Assets */
#ifndef TOLUA_DISABLE_tolua_common_Assets_getAssetsFileData00
static int tolua_common_Assets_getAssetsFileData00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
   Shared<Data> tolua_ret =   Assets::getAssetsFileData(file_name);
    tolua_ret->retain();
    tolua_pushusertype(tolua_S,(void*)(tolua_ret.get()),"Data");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAssetsFileData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalIsError */
#ifndef TOLUA_DISABLE_tolua_common_magicalIsError00
static int tolua_common_magicalIsError00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* info = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* func = ((const char*)  tolua_tostring(tolua_S,2,NULL));
  int line = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   magicalSetLastErrorInfo(info,func,line);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalSetLastErrorInfo'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalSetLastErrorInfoB */
#ifndef TOLUA_DISABLE_tolua_common_magicalSetLastErrorInfoB00
static int tolua_common_magicalSetLastErrorInfoB00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* __info = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   magicalSetLastErrorInfoB(__info);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalSetLastErrorInfoB'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalShowLastError */
#ifndef TOLUA_DISABLE_tolua_common_magicalShowLastError00
static int tolua_common_magicalShowLastError00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   magicalShowLastError();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalShowLastError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalMessageBox */
#ifndef TOLUA_DISABLE_tolua_common_magicalMessageBox00
static int tolua_common_magicalMessageBox00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* msg = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* title = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   magicalMessageBox(msg,title);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalMessageBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalDebugMessageBox */
#ifndef TOLUA_DISABLE_tolua_common_magicalDebugMessageBox00
static int tolua_common_magicalDebugMessageBox00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* __msg = ((const char*)  tolua_tostring(tolua_S,1,0));
  const char* __title = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   magicalDebugMessageBox(__msg,__title);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalDebugMessageBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalAssert */
#ifndef TOLUA_DISABLE_tolua_common_magicalAssert00
static int tolua_common_magicalAssert00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalAssert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalIsTimerStarted */
#ifndef TOLUA_DISABLE_tolua_common_magicalIsTimerStarted00
static int tolua_common_magicalIsTimerStarted00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  magicalIsTimerStarted();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalIsTimerStarted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalStartTimer */
#ifndef TOLUA_DISABLE_tolua_common_magicalStartTimer00
static int tolua_common_magicalStartTimer00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   magicalStartTimer();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalStartTimer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalEndTimer */
#ifndef TOLUA_DISABLE_tolua_common_magicalEndTimer00
static int tolua_common_magicalEndTimer00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   double tolua_ret = (double)  magicalEndTimer();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalEndTimer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Data */
#ifndef TOLUA_DISABLE_tolua_common_Data_delete00
static int tolua_common_Data_delete00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
   Shared<Data> tolua_ret =   Data::create();
    tolua_ret->retain();
    tolua_pushusertype(tolua_S,(void*)(tolua_ret.get()),"Data");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
  unsigned int size = (( unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'assign'", NULL);
#endif
  {
   self->assign(data,size);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
  unsigned int size = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'malloc'", NULL);
#endif
  {
   self->malloc(size);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
  unsigned int size = (( unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'realloc'", NULL);
#endif
  {
   self->realloc(size);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'empty'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->empty();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'size'", NULL);
#endif
  {
   unsigned int tolua_ret = ( unsigned int)  self->size();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'size'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ptr of class  Data */
#ifndef TOLUA_DISABLE_tolua_common_Data_ptr00
static int tolua_common_Data_ptr00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ptr'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->ptr();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ptr'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: retain of class  Reference */
#ifndef TOLUA_DISABLE_tolua_common_Reference_retain00
static int tolua_common_Reference_retain00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'retain'", NULL);
#endif
  {
   self->retain();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'release'", NULL);
#endif
  {
   self->release();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'referenceCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->referenceCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'referenceCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_delete00
static int tolua_common_Transform_delete00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_create00
static int tolua_common_Transform_create00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Shared<Transform> tolua_ret =   Transform::create();
    tolua_ret->retain();
    tolua_pushusertype(tolua_S,(void*)(tolua_ret.get()),"Transform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setName of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setName00
static int tolua_common_Transform_setName00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'", NULL);
#endif
  {
   self->setName(name);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_getName00
static int tolua_common_Transform_getName00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
   const std::string tolua_ret = (const std::string)  self->getName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addChild of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_addChild00
static int tolua_common_Transform_addChild00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Transform* child = ((const Transform*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addChild'", NULL);
#endif
  {
   self->addChild(child);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeChild of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_removeChild00
static int tolua_common_Transform_removeChild00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Transform* child = ((const Transform*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeChild'", NULL);
#endif
  {
   self->removeChild(child);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllChildren of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_removeAllChildren00
static int tolua_common_Transform_removeAllChildren00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllChildren'", NULL);
#endif
  {
   self->removeAllChildren();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllChildren'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeFromParent of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_removeFromParent00
static int tolua_common_Transform_removeFromParent00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeFromParent'", NULL);
#endif
  {
   self->removeFromParent();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeFromParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: findChild of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_findChild00
static int tolua_common_Transform_findChild00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'findChild'", NULL);
#endif
  {
   Shared<Transform> tolua_ret =   self->findChild(name);
    tolua_ret->retain();
    tolua_pushusertype(tolua_S,(void*)(tolua_ret.get()),"Transform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'findChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getChild of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_getChild00
static int tolua_common_Transform_getChild00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
  unsigned int index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getChild'", NULL);
#endif
  {
   Shared<Transform> tolua_ret =   self->getChild(index);
    tolua_ret->retain();
    tolua_pushusertype(tolua_S,(void*)(tolua_ret.get()),"Transform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: childrenCount of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_childrenCount00
static int tolua_common_Transform_childrenCount00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'childrenCount'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->childrenCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'childrenCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParent of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_getParent00
static int tolua_common_Transform_getParent00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParent'", NULL);
#endif
  {
   Shared<Transform> tolua_ret =   self->getParent();
    tolua_ret->retain();
    tolua_pushusertype(tolua_S,(void*)(tolua_ret.get()),"Transform");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isChildOf of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_isChildOf00
static int tolua_common_Transform_isChildOf00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
  const Transform* parent = ((const Transform*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isChildOf'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isChildOf(parent);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isChildOf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setPosition00
static int tolua_common_Transform_setPosition00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* t = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(*t);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setPosition01
static int tolua_common_Transform_setPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(*t);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_setPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setPosition02
static int tolua_common_Transform_setPosition02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(x,y);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_setPosition01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setPosition03
static int tolua_common_Transform_setPosition03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_setPosition02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_translate00
static int tolua_common_Transform_translate00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* t = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  Space relative_to = ((Space) (int)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(*t,relative_to);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'translate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_translate01
static int tolua_common_Transform_translate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  Space relative_to = ((Space) (int)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(*t,relative_to);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_translate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_translate02
static int tolua_common_Transform_translate02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  Space relative_to = ((Space) (int)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(x,y,relative_to);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_translate01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: translate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_translate03
static int tolua_common_Transform_translate03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  Space relative_to = ((Space) (int)  tolua_tonumber(tolua_S,5,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'translate'", NULL);
#endif
  {
   self->translate(x,y,z,relative_to);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_translate02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getPosition of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_getPosition00
static int tolua_common_Transform_getPosition00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getPosition'", NULL);
#endif
  {
   const Vector3& tolua_ret = (const Vector3&)  self->getPosition();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotation of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setRotation00
static int tolua_common_Transform_setRotation00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const EulerAngles* r = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotation'", NULL);
#endif
  {
   self->setRotation(*r);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotation of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setRotation01
static int tolua_common_Transform_setRotation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* r = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotation'", NULL);
#endif
  {
   self->setRotation(*r);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_setRotation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotation of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setRotation02
static int tolua_common_Transform_setRotation02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float yaw = ((float)  tolua_tonumber(tolua_S,2,0));
  float pitch = ((float)  tolua_tonumber(tolua_S,3,0));
  float roll = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotation'", NULL);
#endif
  {
   self->setRotation(yaw,pitch,roll);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_setRotation01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_rotate00
static int tolua_common_Transform_rotate00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const EulerAngles* r = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
  Space relative_to = ((Space) (int)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(*r,relative_to);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_rotate01
static int tolua_common_Transform_rotate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* r = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  Space relative_to = ((Space) (int)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(*r,relative_to);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_rotate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_rotate02
static int tolua_common_Transform_rotate02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float yaw = ((float)  tolua_tonumber(tolua_S,2,0));
  float pitch = ((float)  tolua_tonumber(tolua_S,3,0));
  float roll = ((float)  tolua_tonumber(tolua_S,4,0));
  Space relative_to = ((Space) (int)  tolua_tonumber(tolua_S,5,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(yaw,pitch,roll,relative_to);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_rotate01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: yaw of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_yaw00
static int tolua_common_Transform_yaw00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float yaw = ((float)  tolua_tonumber(tolua_S,2,0));
  Space relative_to = ((Space) (int)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'yaw'", NULL);
#endif
  {
   self->yaw(yaw,relative_to);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'yaw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: pitch of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_pitch00
static int tolua_common_Transform_pitch00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float pitch = ((float)  tolua_tonumber(tolua_S,2,0));
  Space relative_to = ((Space) (int)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'pitch'", NULL);
#endif
  {
   self->pitch(pitch,relative_to);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'pitch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: roll of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_roll00
static int tolua_common_Transform_roll00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float roll = ((float)  tolua_tonumber(tolua_S,2,0));
  Space relative_to = ((Space) (int)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'roll'", NULL);
#endif
  {
   self->roll(roll,relative_to);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'roll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotation of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_getRotation00
static int tolua_common_Transform_getRotation00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotation'", NULL);
#endif
  {
   const Quaternion& tolua_ret = (const Quaternion&)  self->getRotation();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Quaternion");
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setScale00
static int tolua_common_Transform_setScale00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* s = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(*s);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setScale01
static int tolua_common_Transform_setScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* s = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(*s);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_setScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setScale02
static int tolua_common_Transform_setScale02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(x,y);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_setScale01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_setScale03
static int tolua_common_Transform_setScale03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScale'", NULL);
#endif
  {
   self->setScale(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_setScale02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_scale00
static int tolua_common_Transform_scale00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* s = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(*s);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_scale01
static int tolua_common_Transform_scale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* s = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(*s);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_scale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_scale02
static int tolua_common_Transform_scale02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(x,y);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_scale01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_scale03
static int tolua_common_Transform_scale03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(x,y,z);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_scale02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_scale04
static int tolua_common_Transform_scale04(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(s);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Transform_scale03(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_getScale00
static int tolua_common_Transform_getScale00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Transform* self = (const Transform*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScale'", NULL);
#endif
  {
   const Vector3& tolua_ret = (const Vector3&)  self->getScale();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const Vector3");
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lookAt of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_lookAt00
static int tolua_common_Transform_lookAt00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* target = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* up = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lookAt'", NULL);
#endif
  {
   self->lookAt(*target,*up);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resetTransform of class  Transform */
#ifndef TOLUA_DISABLE_tolua_common_Transform_resetTransform00
static int tolua_common_Transform_resetTransform00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Transform",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Transform* self = (Transform*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resetTransform'", NULL);
#endif
  {
   self->resetTransform();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resetTransform'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalLogLastError */
#ifndef TOLUA_DISABLE_tolua_common_magicalLogLastError00
static int tolua_common_magicalLogLastError00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalLogLastError'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalLog */
#ifndef TOLUA_DISABLE_tolua_common_magicalLog00
static int tolua_common_magicalLog00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* __txt = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   magicalLog(__txt);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: magicalDebugLog */
#ifndef TOLUA_DISABLE_tolua_common_magicalDebugLog00
static int tolua_common_magicalDebugLog00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* __txt = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   magicalDebugLog(__txt);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'magicalDebugLog'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: write of class  Log */
#ifndef TOLUA_DISABLE_tolua_common_Log_write00
static int tolua_common_Log_write00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Log",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* txt = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Log::write(txt);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'write'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_get_AxisAngle_x
static int tolua_get_AxisAngle_x(lua_State* tolua_S)
{
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_set_AxisAngle_x
static int tolua_set_AxisAngle_x(lua_State* tolua_S)
{
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: y of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_get_AxisAngle_y
static int tolua_get_AxisAngle_y(lua_State* tolua_S)
{
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_set_AxisAngle_y
static int tolua_set_AxisAngle_y(lua_State* tolua_S)
{
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: z of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_get_AxisAngle_z
static int tolua_get_AxisAngle_z(lua_State* tolua_S)
{
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_set_AxisAngle_z
static int tolua_set_AxisAngle_z(lua_State* tolua_S)
{
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: w of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_get_AxisAngle_w
static int tolua_get_AxisAngle_w(lua_State* tolua_S)
{
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_set_AxisAngle_w
static int tolua_set_AxisAngle_w(lua_State* tolua_S)
{
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: Identity of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_get_AxisAngle_Identity
static int tolua_get_AxisAngle_Identity(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&AxisAngle::Identity,"const AxisAngle");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Zero of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_get_AxisAngle_Zero
static int tolua_get_AxisAngle_Zero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&AxisAngle::Zero,"const AxisAngle");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: var of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_get_AxisAngle_var
static int tolua_get_AxisAngle_var(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&AxisAngle::var,"AxisAngle");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: var of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_set_AxisAngle_var
static int tolua_set_AxisAngle_var(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"AxisAngle",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  AxisAngle::var = *((AxisAngle*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_new00
static int tolua_common_AxisAngle_new00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
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
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   AxisAngle* tolua_ret = (AxisAngle*)  Mtolua_new((AxisAngle)(x,y,z,w));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AxisAngle");
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_new00_local
static int tolua_common_AxisAngle_new00_local(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
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
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   AxisAngle* tolua_ret = (AxisAngle*)  Mtolua_new((AxisAngle)(x,y,z,w));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_new01
static int tolua_common_AxisAngle_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   AxisAngle* tolua_ret = (AxisAngle*)  Mtolua_new((AxisAngle)(*axis,angle));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AxisAngle");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_AxisAngle_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_new01_local
static int tolua_common_AxisAngle_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   AxisAngle* tolua_ret = (AxisAngle*)  Mtolua_new((AxisAngle)(*axis,angle));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_AxisAngle_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_new02
static int tolua_common_AxisAngle_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AxisAngle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const AxisAngle* aa = ((const AxisAngle*)  tolua_tousertype(tolua_S,2,0));
  {
   AxisAngle* tolua_ret = (AxisAngle*)  Mtolua_new((AxisAngle)(*aa));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AxisAngle");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_AxisAngle_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_new02_local
static int tolua_common_AxisAngle_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AxisAngle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const AxisAngle* aa = ((const AxisAngle*)  tolua_tousertype(tolua_S,2,0));
  {
   AxisAngle* tolua_ret = (AxisAngle*)  Mtolua_new((AxisAngle)(*aa));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_AxisAngle_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_new03
static int tolua_common_AxisAngle_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   AxisAngle* tolua_ret = (AxisAngle*)  Mtolua_new((AxisAngle)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AxisAngle");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_AxisAngle_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_new03_local
static int tolua_common_AxisAngle_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   AxisAngle* tolua_ret = (AxisAngle*)  Mtolua_new((AxisAngle)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_AxisAngle_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_delete00
static int tolua_common_AxisAngle_delete00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_create00
static int tolua_common_AxisAngle_create00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   AxisAngle tolua_ret = (AxisAngle)  AxisAngle::create(*axis,angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AxisAngle)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AxisAngle));
     tolua_pushusertype(tolua_S,tolua_obj,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createIdentity of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_createIdentity00
static int tolua_common_AxisAngle_createIdentity00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AxisAngle tolua_ret = (AxisAngle)  AxisAngle::createIdentity();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AxisAngle)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AxisAngle));
     tolua_pushusertype(tolua_S,tolua_obj,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createZero of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_createZero00
static int tolua_common_AxisAngle_createZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AxisAngle tolua_ret = (AxisAngle)  AxisAngle::createZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AxisAngle)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AxisAngle));
     tolua_pushusertype(tolua_S,tolua_obj,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromQuaternion of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_createFromQuaternion00
static int tolua_common_AxisAngle_createFromQuaternion00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   AxisAngle tolua_ret = (AxisAngle)  AxisAngle::createFromQuaternion(*q);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AxisAngle)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AxisAngle));
     tolua_pushusertype(tolua_S,tolua_obj,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_equals00
static int tolua_common_AxisAngle_equals00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AxisAngle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AxisAngle* self = (const AxisAngle*)  tolua_tousertype(tolua_S,1,0);
  const AxisAngle* aa = ((const AxisAngle*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*aa);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIdentity of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_isIdentity00
static int tolua_common_AxisAngle_isIdentity00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AxisAngle* self = (const AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isIdentity'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isIdentity();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isZero of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_isZero00
static int tolua_common_AxisAngle_isZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AxisAngle* self = (const AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle__eq00
static int tolua_common_AxisAngle__eq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AxisAngle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AxisAngle* self = (const AxisAngle*)  tolua_tousertype(tolua_S,1,0);
  const AxisAngle* aa = ((const AxisAngle*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*aa);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_set00
static int tolua_common_AxisAngle_set00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AxisAngle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
  const AxisAngle* aa = ((const AxisAngle*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(*aa);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_set01
static int tolua_common_AxisAngle_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(*axis,angle);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_AxisAngle_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIdentity of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_setIdentity00
static int tolua_common_AxisAngle_setIdentity00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIdentity'", NULL);
#endif
  {
   self->setIdentity();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setZero of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_setZero00
static int tolua_common_AxisAngle_setZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZero'", NULL);
#endif
  {
   self->setZero();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScalaas of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_setScalaas00
static int tolua_common_AxisAngle_setScalaas00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AxisAngle",0,&tolua_err) ||
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
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScalaas'", NULL);
#endif
  {
   self->setScalaas(x,y,z,w);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScalaas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromQuaternion of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_fromQuaternion00
static int tolua_common_AxisAngle_fromQuaternion00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AxisAngle",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AxisAngle* self = (AxisAngle*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromQuaternion'", NULL);
#endif
  {
   self->fromQuaternion(*q);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toQuaternion of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_toQuaternion00
static int tolua_common_AxisAngle_toQuaternion00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AxisAngle* self = (const AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toQuaternion'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->toQuaternion();
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: axis of class  AxisAngle */
#ifndef TOLUA_DISABLE_tolua_common_AxisAngle_axis00
static int tolua_common_AxisAngle_axis00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const AxisAngle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AxisAngle* self = (const AxisAngle*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'axis'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->axis();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'axis'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: yaw of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_get_EulerAngles_yaw
static int tolua_get_EulerAngles_yaw(lua_State* tolua_S)
{
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'yaw'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->yaw);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: yaw of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_set_EulerAngles_yaw
static int tolua_set_EulerAngles_yaw(lua_State* tolua_S)
{
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'yaw'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->yaw = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pitch of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_get_EulerAngles_pitch
static int tolua_get_EulerAngles_pitch(lua_State* tolua_S)
{
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pitch'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->pitch);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pitch of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_set_EulerAngles_pitch
static int tolua_set_EulerAngles_pitch(lua_State* tolua_S)
{
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pitch'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pitch = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: roll of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_get_EulerAngles_roll
static int tolua_get_EulerAngles_roll(lua_State* tolua_S)
{
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'roll'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->roll);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: roll of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_set_EulerAngles_roll
static int tolua_set_EulerAngles_roll(lua_State* tolua_S)
{
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'roll'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->roll = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Zero of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_get_EulerAngles_Zero
static int tolua_get_EulerAngles_Zero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EulerAngles::Zero,"const EulerAngles");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: var of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_get_EulerAngles_var
static int tolua_get_EulerAngles_var(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&EulerAngles::var,"EulerAngles");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: var of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_set_EulerAngles_var
static int tolua_set_EulerAngles_var(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EulerAngles",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  EulerAngles::var = *((EulerAngles*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_new00
static int tolua_common_EulerAngles_new00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float yaw = ((float)  tolua_tonumber(tolua_S,2,0));
  float pitch = ((float)  tolua_tonumber(tolua_S,3,0));
  float roll = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   EulerAngles* tolua_ret = (EulerAngles*)  Mtolua_new((EulerAngles)(yaw,pitch,roll));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EulerAngles");
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_new00_local
static int tolua_common_EulerAngles_new00_local(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float yaw = ((float)  tolua_tonumber(tolua_S,2,0));
  float pitch = ((float)  tolua_tonumber(tolua_S,3,0));
  float roll = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   EulerAngles* tolua_ret = (EulerAngles*)  Mtolua_new((EulerAngles)(yaw,pitch,roll));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_new01
static int tolua_common_EulerAngles_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
  {
   EulerAngles* tolua_ret = (EulerAngles*)  Mtolua_new((EulerAngles)(*ea));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EulerAngles");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_EulerAngles_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_new01_local
static int tolua_common_EulerAngles_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
  {
   EulerAngles* tolua_ret = (EulerAngles*)  Mtolua_new((EulerAngles)(*ea));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_EulerAngles_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_new02
static int tolua_common_EulerAngles_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   EulerAngles* tolua_ret = (EulerAngles*)  Mtolua_new((EulerAngles)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EulerAngles");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_EulerAngles_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_new02_local
static int tolua_common_EulerAngles_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   EulerAngles* tolua_ret = (EulerAngles*)  Mtolua_new((EulerAngles)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_EulerAngles_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_delete00
static int tolua_common_EulerAngles_delete00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createZero of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_createZero00
static int tolua_common_EulerAngles_createZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   EulerAngles tolua_ret = (EulerAngles)  EulerAngles::createZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((EulerAngles)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(EulerAngles));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromQuaternion of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_createFromQuaternion00
static int tolua_common_EulerAngles_createFromQuaternion00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   EulerAngles tolua_ret = (EulerAngles)  EulerAngles::createFromQuaternion(*q);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((EulerAngles)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(EulerAngles));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_add00
static int tolua_common_EulerAngles_add00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EulerAngles",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const EulerAngles",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EulerAngles* out = ((EulerAngles*)  tolua_tousertype(tolua_S,2,0));
  const EulerAngles* ea1 = ((const EulerAngles*)  tolua_tousertype(tolua_S,3,0));
  const EulerAngles* ea2 = ((const EulerAngles*)  tolua_tousertype(tolua_S,4,0));
  {
   EulerAngles::add(*out,*ea1,*ea2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_sub00
static int tolua_common_EulerAngles_sub00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EulerAngles",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const EulerAngles",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EulerAngles* out = ((EulerAngles*)  tolua_tousertype(tolua_S,2,0));
  const EulerAngles* ea1 = ((const EulerAngles*)  tolua_tousertype(tolua_S,3,0));
  const EulerAngles* ea2 = ((const EulerAngles*)  tolua_tousertype(tolua_S,4,0));
  {
   EulerAngles::sub(*out,*ea1,*ea2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulScalar of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_mulScalar00
static int tolua_common_EulerAngles_mulScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EulerAngles",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EulerAngles* out = ((EulerAngles*)  tolua_tousertype(tolua_S,2,0));
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   EulerAngles::mulScalar(*out,*ea,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_mul00
static int tolua_common_EulerAngles_mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EulerAngles",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const EulerAngles",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EulerAngles* out = ((EulerAngles*)  tolua_tousertype(tolua_S,2,0));
  const EulerAngles* ea1 = ((const EulerAngles*)  tolua_tousertype(tolua_S,3,0));
  const EulerAngles* ea2 = ((const EulerAngles*)  tolua_tousertype(tolua_S,4,0));
  {
   EulerAngles::mul(*out,*ea1,*ea2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: limit of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_limit00
static int tolua_common_EulerAngles_limit00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"EulerAngles",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EulerAngles* out = ((EulerAngles*)  tolua_tousertype(tolua_S,2,0));
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,3,0));
  {
   EulerAngles::limit(*out,*ea);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'limit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_equals00
static int tolua_common_EulerAngles_equals00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EulerAngles* self = (const EulerAngles*)  tolua_tousertype(tolua_S,1,0);
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*ea);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isZero of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_isZero00
static int tolua_common_EulerAngles_isZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EulerAngles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EulerAngles* self = (const EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles__eq00
static int tolua_common_EulerAngles__eq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EulerAngles* self = (const EulerAngles*)  tolua_tousertype(tolua_S,1,0);
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*ea);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles__add00
static int tolua_common_EulerAngles__add00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EulerAngles* self = (const EulerAngles*)  tolua_tousertype(tolua_S,1,0);
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   EulerAngles tolua_ret = (EulerAngles)  self->operator+(*ea);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((EulerAngles)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(EulerAngles));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles__sub00
static int tolua_common_EulerAngles__sub00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EulerAngles* self = (const EulerAngles*)  tolua_tousertype(tolua_S,1,0);
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   EulerAngles tolua_ret = (EulerAngles)  self->operator-(*ea);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((EulerAngles)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(EulerAngles));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles__mul00
static int tolua_common_EulerAngles__mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EulerAngles* self = (const EulerAngles*)  tolua_tousertype(tolua_S,1,0);
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   EulerAngles tolua_ret = (EulerAngles)  self->operator*(*ea);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((EulerAngles)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(EulerAngles));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles__mul01
static int tolua_common_EulerAngles__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EulerAngles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const EulerAngles* self = (const EulerAngles*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   EulerAngles tolua_ret = (EulerAngles)  self->operator*(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((EulerAngles)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(EulerAngles));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_EulerAngles__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_set00
static int tolua_common_EulerAngles_set00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(*ea);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setZero of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_setZero00
static int tolua_common_EulerAngles_setZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZero'", NULL);
#endif
  {
   self->setZero();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScalars of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_setScalars00
static int tolua_common_EulerAngles_setScalars00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
  float yaw = ((float)  tolua_tonumber(tolua_S,2,0));
  float pitch = ((float)  tolua_tonumber(tolua_S,3,0));
  float roll = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScalars'", NULL);
#endif
  {
   self->setScalars(yaw,pitch,roll);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScalars'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromQuaternion of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_fromQuaternion00
static int tolua_common_EulerAngles_fromQuaternion00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromQuaternion'", NULL);
#endif
  {
   self->fromQuaternion(*q);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: toQuaternion of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_toQuaternion00
static int tolua_common_EulerAngles_toQuaternion00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EulerAngles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EulerAngles* self = (const EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toQuaternion'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->toQuaternion();
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: limit of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_limit01
static int tolua_common_EulerAngles_limit01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"EulerAngles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  EulerAngles* self = (EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'limit'", NULL);
#endif
  {
   self->limit();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_EulerAngles_limit00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLimited of class  EulerAngles */
#ifndef TOLUA_DISABLE_tolua_common_EulerAngles_getLimited00
static int tolua_common_EulerAngles_getLimited00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const EulerAngles",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EulerAngles* self = (const EulerAngles*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLimited'", NULL);
#endif
  {
   EulerAngles tolua_ret = (EulerAngles)  self->getLimited();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((EulerAngles)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(EulerAngles));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLimited'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m11 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m11
static int tolua_get_Matrix4_m11(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm11'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m11);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m11 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m11
static int tolua_set_Matrix4_m11(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm11'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m11 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m12 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m12
static int tolua_get_Matrix4_m12(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm12'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m12);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m12 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m12
static int tolua_set_Matrix4_m12(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm12'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m12 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m13 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m13
static int tolua_get_Matrix4_m13(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm13'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m13);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m13 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m13
static int tolua_set_Matrix4_m13(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm13'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m13 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m14 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m14
static int tolua_get_Matrix4_m14(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm14'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m14);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m14 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m14
static int tolua_set_Matrix4_m14(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm14'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m14 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m21 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m21
static int tolua_get_Matrix4_m21(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm21'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m21);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m21 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m21
static int tolua_set_Matrix4_m21(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm21'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m21 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m22 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m22
static int tolua_get_Matrix4_m22(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm22'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m22);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m22 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m22
static int tolua_set_Matrix4_m22(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm22'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m22 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m23 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m23
static int tolua_get_Matrix4_m23(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm23'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m23);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m23 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m23
static int tolua_set_Matrix4_m23(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm23'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m23 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m24 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m24
static int tolua_get_Matrix4_m24(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm24'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m24);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m24 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m24
static int tolua_set_Matrix4_m24(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm24'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m24 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m31 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m31
static int tolua_get_Matrix4_m31(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm31'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m31);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m31 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m31
static int tolua_set_Matrix4_m31(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm31'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m31 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m32 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m32
static int tolua_get_Matrix4_m32(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm32'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m32);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m32 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m32
static int tolua_set_Matrix4_m32(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm32'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m32 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m33 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m33
static int tolua_get_Matrix4_m33(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm33'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m33);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m33 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m33
static int tolua_set_Matrix4_m33(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm33'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m33 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m34 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m34
static int tolua_get_Matrix4_m34(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm34'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m34);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m34 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m34
static int tolua_set_Matrix4_m34(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm34'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m34 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m41 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m41
static int tolua_get_Matrix4_m41(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm41'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m41);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m41 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m41
static int tolua_set_Matrix4_m41(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm41'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m41 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m42 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m42
static int tolua_get_Matrix4_m42(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm42'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m42);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m42 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m42
static int tolua_set_Matrix4_m42(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm42'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m42 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m43 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m43
static int tolua_get_Matrix4_m43(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm43'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m43);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m43 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m43
static int tolua_set_Matrix4_m43(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm43'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m43 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: m44 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_m44
static int tolua_get_Matrix4_m44(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm44'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->m44);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: m44 of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_m44
static int tolua_set_Matrix4_m44(lua_State* tolua_S)
{
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'm44'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->m44 = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Identity of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_Identity
static int tolua_get_Matrix4_Identity(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Matrix4::Identity,"const Matrix4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Zero of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_Zero
static int tolua_get_Matrix4_Zero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Matrix4::Zero,"const Matrix4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: var of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_get_Matrix4_var
static int tolua_get_Matrix4_var(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Matrix4::var,"Matrix4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: var of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_set_Matrix4_var
static int tolua_set_Matrix4_var(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Matrix4::var = *((Matrix4*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_new00
static int tolua_common_Matrix4_new00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
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
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(m11,m12,m13,m14,m21,m22,m23,m24,m31,m32,m33,m34,m41,m42,m43,m44));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_new00_local
static int tolua_common_Matrix4_new00_local(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
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
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(m11,m12,m13,m14,m21,m22,m23,m24,m31,m32,m33,m34,m41,m42,m43,m44));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_new01
static int tolua_common_Matrix4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(*m));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_new01_local
static int tolua_common_Matrix4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)(*m));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_new02
static int tolua_common_Matrix4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_new02_local
static int tolua_common_Matrix4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Matrix4* tolua_ret = (Matrix4*)  Mtolua_new((Matrix4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_delete00
static int tolua_common_Matrix4_delete00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createIdentity of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_createIdentity00
static int tolua_common_Matrix4_createIdentity00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Matrix4 tolua_ret = (Matrix4)  Matrix4::createIdentity();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createZero of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_createZero00
static int tolua_common_Matrix4_createZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Matrix4 tolua_ret = (Matrix4)  Matrix4::createZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createTRS of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_createTRS00
static int tolua_common_Matrix4_createTRS00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* r = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* s = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Matrix4 tolua_ret = (Matrix4)  Matrix4::createTRS(*t,*r,*s);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createTRS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulScalar of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_mulScalar00
static int tolua_common_Matrix4_mulScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* out = ((Matrix4*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Matrix4::mulScalar(*out,*m,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_mul00
static int tolua_common_Matrix4_mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* out = ((Matrix4*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m1 = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  const Matrix4* m2 = ((const Matrix4*)  tolua_tousertype(tolua_S,4,0));
  {
   Matrix4::mul(*out,*m1,*m2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUpVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getUpVector00
static int tolua_common_Matrix4_getUpVector00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::getUpVector(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getUpVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDownVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getDownVector00
static int tolua_common_Matrix4_getDownVector00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::getDownVector(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getDownVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLeftVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getLeftVector00
static int tolua_common_Matrix4_getLeftVector00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::getLeftVector(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getLeftVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRightVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getRightVector00
static int tolua_common_Matrix4_getRightVector00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::getRightVector(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRightVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getForwardVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getForwardVector00
static int tolua_common_Matrix4_getForwardVector00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::getForwardVector(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getForwardVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBackVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getBackVector00
static int tolua_common_Matrix4_getBackVector00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::getBackVector(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBackVector'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTranslation of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getTranslation00
static int tolua_common_Matrix4_getTranslation00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::getTranslation(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getScale00
static int tolua_common_Matrix4_getScale00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::getScale(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotationQuaternion of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getRotationQuaternion00
static int tolua_common_Matrix4_getRotationQuaternion00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* out = ((Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::getRotationQuaternion(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotationQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: inverse of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_inverse00
static int tolua_common_Matrix4_inverse00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* out = ((Matrix4*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   bool tolua_ret = (bool)  Matrix4::inverse(*out,*m);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: transpose of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_transpose00
static int tolua_common_Matrix4_transpose00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* out = ((Matrix4*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::transpose(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'transpose'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_negate00
static int tolua_common_Matrix4_negate00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* out = ((Matrix4*)  tolua_tousertype(tolua_S,2,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,3,0));
  {
   Matrix4::negate(*out,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_equals00
static int tolua_common_Matrix4_equals00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*m);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isZero of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_isZero00
static int tolua_common_Matrix4_isZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIdentity of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_isIdentity00
static int tolua_common_Matrix4_isIdentity00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isIdentity'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isIdentity();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4__eq00
static int tolua_common_Matrix4__eq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*m);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4__mul00
static int tolua_common_Matrix4__mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Matrix4 tolua_ret = (Matrix4)  self->operator*(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4__mul01
static int tolua_common_Matrix4__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Matrix4 tolua_ret = (Matrix4)  self->operator*(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_set00
static int tolua_common_Matrix4_set00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const float m = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(&m);
   tolua_pushnumber(tolua_S,(lua_Number)m);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_set01
static int tolua_common_Matrix4_set01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(*m);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Matrix4_set00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIdentity of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_setIdentity00
static int tolua_common_Matrix4_setIdentity00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIdentity'", NULL);
#endif
  {
   self->setIdentity();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setZero of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_setZero00
static int tolua_common_Matrix4_setZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZero'", NULL);
#endif
  {
   self->setZero();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLookAt of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_setLookAt00
static int tolua_common_Matrix4_setLookAt00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* eye = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* target = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* up = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLookAt'", NULL);
#endif
  {
   self->setLookAt(*eye,*target,*up);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLookAt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPerspective of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_setPerspective00
static int tolua_common_Matrix4_setPerspective00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
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
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float fov = ((float)  tolua_tonumber(tolua_S,2,0));
  float aspect = ((float)  tolua_tonumber(tolua_S,3,0));
  float znear = ((float)  tolua_tonumber(tolua_S,4,0));
  float zfar = ((float)  tolua_tonumber(tolua_S,5,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPerspective'", NULL);
#endif
  {
   self->setPerspective(fov,aspect,znear,zfar);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPerspective'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOrth of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_setOrth00
static int tolua_common_Matrix4_setOrth00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
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
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float left = ((float)  tolua_tonumber(tolua_S,2,0));
  float right = ((float)  tolua_tonumber(tolua_S,3,0));
  float bottom = ((float)  tolua_tonumber(tolua_S,4,0));
  float top = ((float)  tolua_tonumber(tolua_S,5,0));
  float near = ((float)  tolua_tonumber(tolua_S,6,0));
  float far = ((float)  tolua_tonumber(tolua_S,7,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOrth'", NULL);
#endif
  {
   self->setOrth(left,right,bottom,top,near,far);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOrth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTRS of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_setTRS00
static int tolua_common_Matrix4_setTRS00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* r = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* s = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTRS'", NULL);
#endif
  {
   self->setTRS(*t,*r,*s);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTRS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeTranslation of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeTranslation00
static int tolua_common_Matrix4_makeTranslation00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeTranslation'", NULL);
#endif
  {
   self->makeTranslation(x,y,z);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeTranslation of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeTranslation01
static int tolua_common_Matrix4_makeTranslation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeTranslation'", NULL);
#endif
  {
   self->makeTranslation(*t);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Matrix4_makeTranslation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeScale00
static int tolua_common_Matrix4_makeScale00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeScale'", NULL);
#endif
  {
   self->makeScale(x,y,z);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeScale01
static int tolua_common_Matrix4_makeScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* s = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeScale'", NULL);
#endif
  {
   self->makeScale(*s);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Matrix4_makeScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotationX of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeRotationX00
static int tolua_common_Matrix4_makeRotationX00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotationX'", NULL);
#endif
  {
   self->makeRotationX(angle);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotationX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotationY of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeRotationY00
static int tolua_common_Matrix4_makeRotationY00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotationY'", NULL);
#endif
  {
   self->makeRotationY(angle);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotationY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotationZ of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeRotationZ00
static int tolua_common_Matrix4_makeRotationZ00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotationZ'", NULL);
#endif
  {
   self->makeRotationZ(angle);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotationZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotationAxisAngle of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeRotationAxisAngle00
static int tolua_common_Matrix4_makeRotationAxisAngle00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotationAxisAngle'", NULL);
#endif
  {
   self->makeRotationAxisAngle(*axis,angle);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotationAxisAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotationAxisAngle of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeRotationAxisAngle01
static int tolua_common_Matrix4_makeRotationAxisAngle01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AxisAngle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const AxisAngle* aa = ((const AxisAngle*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotationAxisAngle'", NULL);
#endif
  {
   self->makeRotationAxisAngle(*aa);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Matrix4_makeRotationAxisAngle00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotationEulerAngles of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeRotationEulerAngles00
static int tolua_common_Matrix4_makeRotationEulerAngles00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float yaw = ((float)  tolua_tonumber(tolua_S,2,0));
  float pitch = ((float)  tolua_tonumber(tolua_S,3,0));
  float roll = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotationEulerAngles'", NULL);
#endif
  {
   self->makeRotationEulerAngles(yaw,pitch,roll);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotationEulerAngles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotationEulerAngles of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeRotationEulerAngles01
static int tolua_common_Matrix4_makeRotationEulerAngles01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotationEulerAngles'", NULL);
#endif
  {
   self->makeRotationEulerAngles(*ea);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Matrix4_makeRotationEulerAngles00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: makeRotationQuaternion of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_makeRotationQuaternion00
static int tolua_common_Matrix4_makeRotationQuaternion00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'makeRotationQuaternion'", NULL);
#endif
  {
   self->makeRotationQuaternion(*q);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'makeRotationQuaternion'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getUpVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getUpVector01
static int tolua_common_Matrix4_getUpVector01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getUpVector'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getUpVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_getUpVector00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getDownVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getDownVector01
static int tolua_common_Matrix4_getDownVector01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getDownVector'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getDownVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_getDownVector00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getLeftVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getLeftVector01
static int tolua_common_Matrix4_getLeftVector01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getLeftVector'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getLeftVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_getLeftVector00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRightVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getRightVector01
static int tolua_common_Matrix4_getRightVector01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRightVector'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getRightVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_getRightVector00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getForwardVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getForwardVector01
static int tolua_common_Matrix4_getForwardVector01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getForwardVector'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getForwardVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_getForwardVector00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBackVector of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getBackVector01
static int tolua_common_Matrix4_getBackVector01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBackVector'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getBackVector();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_getBackVector00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTranslation of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_setTranslation00
static int tolua_common_Matrix4_setTranslation00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTranslation'", NULL);
#endif
  {
   self->setTranslation(x,y,z);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTranslation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTranslation of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_setTranslation01
static int tolua_common_Matrix4_setTranslation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* t = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTranslation'", NULL);
#endif
  {
   self->setTranslation(*t);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Matrix4_setTranslation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTranslation of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getTranslation01
static int tolua_common_Matrix4_getTranslation01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTranslation'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getTranslation();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_getTranslation00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScale of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getScale01
static int tolua_common_Matrix4_getScale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScale'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getScale();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_getScale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotationQuaternion of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getRotationQuaternion01
static int tolua_common_Matrix4_getRotationQuaternion01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotationQuaternion'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->getRotationQuaternion();
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
 return tolua_common_Matrix4_getRotationQuaternion00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: inverse of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_inverse01
static int tolua_common_Matrix4_inverse01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'inverse'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->inverse();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Matrix4_inverse00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: transpose of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_transpose01
static int tolua_common_Matrix4_transpose01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'transpose'", NULL);
#endif
  {
   self->transpose();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Matrix4_transpose00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_negate01
static int tolua_common_Matrix4_negate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Matrix4* self = (Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'negate'", NULL);
#endif
  {
   self->negate();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Matrix4_negate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInversed of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getInversed00
static int tolua_common_Matrix4_getInversed00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
  Matrix4* out = ((Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInversed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getInversed(*out);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInversed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTransposed of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getTransposed00
static int tolua_common_Matrix4_getTransposed00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTransposed'", NULL);
#endif
  {
   Matrix4 tolua_ret = (Matrix4)  self->getTransposed();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTransposed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNegated of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_getNegated00
static int tolua_common_Matrix4_getNegated00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNegated'", NULL);
#endif
  {
   Matrix4 tolua_ret = (Matrix4)  self->getNegated();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Matrix4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Matrix4));
     tolua_pushusertype(tolua_S,tolua_obj,"Matrix4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNegated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: determinant of class  Matrix4 */
#ifndef TOLUA_DISABLE_tolua_common_Matrix4_determinant00
static int tolua_common_Matrix4_determinant00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Matrix4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Matrix4* self = (const Matrix4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'determinant'", NULL);
#endif
  {
   float tolua_ret = (float)  self->determinant();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'determinant'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_x
static int tolua_get_Quaternion_x(lua_State* tolua_S)
{
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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

/* get function: Identity of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_Identity
static int tolua_get_Quaternion_Identity(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Quaternion::Identity,"const Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Zero of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_Zero
static int tolua_get_Quaternion_Zero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Quaternion::Zero,"const Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: var of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_get_Quaternion_var
static int tolua_get_Quaternion_var(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Quaternion::var,"Quaternion");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: var of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_set_Quaternion_var
static int tolua_set_Quaternion_var(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Quaternion::var = *((Quaternion*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_new00
static int tolua_common_Quaternion_new00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(x,y,z,w));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(x,y,z,w));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
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
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*q));
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
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
  {
   Quaternion* tolua_ret = (Quaternion*)  Mtolua_new((Quaternion)(*q));
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
 return tolua_common_Quaternion_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_delete00
static int tolua_common_Quaternion_delete00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createIdentity of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_createIdentity00
static int tolua_common_Quaternion_createIdentity00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Quaternion tolua_ret = (Quaternion)  Quaternion::createIdentity();
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createZero of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_createZero00
static int tolua_common_Quaternion_createZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Quaternion tolua_ret = (Quaternion)  Quaternion::createZero();
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createRotationX of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_createRotationX00
static int tolua_common_Quaternion_createRotationX00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Quaternion tolua_ret = (Quaternion)  Quaternion::createRotationX(angle);
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createRotationX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createRotationY of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_createRotationY00
static int tolua_common_Quaternion_createRotationY00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Quaternion tolua_ret = (Quaternion)  Quaternion::createRotationY(angle);
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createRotationY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createRotationZ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_createRotationZ00
static int tolua_common_Quaternion_createRotationZ00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
  {
   Quaternion tolua_ret = (Quaternion)  Quaternion::createRotationZ(angle);
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createRotationZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromAxisAngle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_createFromAxisAngle00
static int tolua_common_Quaternion_createFromAxisAngle00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AxisAngle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const AxisAngle* aa = ((const AxisAngle*)  tolua_tousertype(tolua_S,2,0));
  {
   Quaternion tolua_ret = (Quaternion)  Quaternion::createFromAxisAngle(*aa);
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromAxisAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromAxisAngle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_createFromAxisAngle01
static int tolua_common_Quaternion_createFromAxisAngle01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Quaternion tolua_ret = (Quaternion)  Quaternion::createFromAxisAngle(*axis,angle);
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
 return tolua_common_Quaternion_createFromAxisAngle00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromEulerAngles of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_createFromEulerAngles00
static int tolua_common_Quaternion_createFromEulerAngles00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
  {
   Quaternion tolua_ret = (Quaternion)  Quaternion::createFromEulerAngles(*ea);
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromEulerAngles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromEulerAngles of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_createFromEulerAngles01
static int tolua_common_Quaternion_createFromEulerAngles01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  float yaw = ((float)  tolua_tonumber(tolua_S,2,0));
  float pitch = ((float)  tolua_tonumber(tolua_S,3,0));
  float roll = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Quaternion tolua_ret = (Quaternion)  Quaternion::createFromEulerAngles(yaw,pitch,roll);
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
 return tolua_common_Quaternion_createFromEulerAngles00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_add00
static int tolua_common_Quaternion_add00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* out = ((Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* q1 = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* q2 = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
  {
   Quaternion::add(*out,*q1,*q2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_sub00
static int tolua_common_Quaternion_sub00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* out = ((Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* q1 = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* q2 = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
  {
   Quaternion::sub(*out,*q1,*q2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_mul00
static int tolua_common_Quaternion_mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* out = ((Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* q1 = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  const Quaternion* q2 = ((const Quaternion*)  tolua_tousertype(tolua_S,4,0));
  {
   Quaternion::mul(*out,*q1,*q2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulVector3 of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_mulVector300
static int tolua_common_Quaternion_mulVector300(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Quaternion::mulVector3(*out,*q,*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulScalar of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_mulScalar00
static int tolua_common_Quaternion_mulScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* out = ((Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Quaternion::mulScalar(*out,*q,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_normalize00
static int tolua_common_Quaternion_normalize00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* out = ((Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  {
   Quaternion::normalize(*out,*q);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: conjugate of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_conjugate00
static int tolua_common_Quaternion_conjugate00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* out = ((Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  {
   Quaternion::conjugate(*out,*q);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'conjugate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_negate00
static int tolua_common_Quaternion_negate00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* out = ((Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  {
   Quaternion::negate(*out,*q);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Quaternion",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* out = ((Quaternion*)  tolua_tousertype(tolua_S,2,0));
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,3,0));
  {
   Quaternion::inverse(*out,*q);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'inverse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_equals00
static int tolua_common_Quaternion_equals00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*q);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIdentity of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_isIdentity00
static int tolua_common_Quaternion_isIdentity00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isIdentity'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isIdentity();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isNormalized of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_isNormalized00
static int tolua_common_Quaternion_isNormalized00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isNormalized'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isNormalized();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion__eq00
static int tolua_common_Quaternion__eq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*q);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion__add00
static int tolua_common_Quaternion__add00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->operator+(*q);
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion__sub00
static int tolua_common_Quaternion__sub00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->operator-(*q);
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion__mul00
static int tolua_common_Quaternion__mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->operator*(a);
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion__mul01
static int tolua_common_Quaternion__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator*(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Quaternion__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion__mul02
static int tolua_common_Quaternion__mul02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Quaternion* self = (const Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->operator*(*q);
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
 return tolua_common_Quaternion__mul01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_set00
static int tolua_common_Quaternion_set00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Quaternion",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(*q);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setIdentity of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_setIdentity00
static int tolua_common_Quaternion_setIdentity00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setIdentity'", NULL);
#endif
  {
   self->setIdentity();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setIdentity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setZero of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_setZero00
static int tolua_common_Quaternion_setZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZero'", NULL);
#endif
  {
   self->setZero();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScalars of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_setScalars00
static int tolua_common_Quaternion_setScalars00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScalars'", NULL);
#endif
  {
   self->setScalars(x,y,z,w);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScalars'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotationX of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_setRotationX00
static int tolua_common_Quaternion_setRotationX00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotationX'", NULL);
#endif
  {
   self->setRotationX(angle);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotationX'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotationY of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_setRotationY00
static int tolua_common_Quaternion_setRotationY00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotationY'", NULL);
#endif
  {
   self->setRotationY(angle);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotationY'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setRotationZ of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_setRotationZ00
static int tolua_common_Quaternion_setRotationZ00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setRotationZ'", NULL);
#endif
  {
   self->setRotationZ(angle);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setRotationZ'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromAxisAngle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_fromAxisAngle00
static int tolua_common_Quaternion_fromAxisAngle00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const AxisAngle",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const AxisAngle* aa = ((const AxisAngle*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromAxisAngle'", NULL);
#endif
  {
   self->fromAxisAngle(*aa);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromAxisAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromAxisAngle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_fromAxisAngle01
static int tolua_common_Quaternion_fromAxisAngle01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* axis = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  float angle = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromAxisAngle'", NULL);
#endif
  {
   self->fromAxisAngle(*axis,angle);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Quaternion_fromAxisAngle00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: toAxisAngle of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_toAxisAngle00
static int tolua_common_Quaternion_toAxisAngle00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toAxisAngle'", NULL);
#endif
  {
   AxisAngle tolua_ret = (AxisAngle)  self->toAxisAngle();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((AxisAngle)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(AxisAngle));
     tolua_pushusertype(tolua_S,tolua_obj,"AxisAngle");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toAxisAngle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromEulerAngles of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_fromEulerAngles00
static int tolua_common_Quaternion_fromEulerAngles00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const EulerAngles",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  const EulerAngles* ea = ((const EulerAngles*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromEulerAngles'", NULL);
#endif
  {
   self->fromEulerAngles(*ea);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromEulerAngles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromEulerAngles of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_fromEulerAngles01
static int tolua_common_Quaternion_fromEulerAngles01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
  float yaw = ((float)  tolua_tonumber(tolua_S,2,0));
  float pitch = ((float)  tolua_tonumber(tolua_S,3,0));
  float roll = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromEulerAngles'", NULL);
#endif
  {
   self->fromEulerAngles(yaw,pitch,roll);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Quaternion_fromEulerAngles00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: toEulerAngles of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_toEulerAngles00
static int tolua_common_Quaternion_toEulerAngles00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'toEulerAngles'", NULL);
#endif
  {
   EulerAngles tolua_ret = (EulerAngles)  self->toEulerAngles();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((EulerAngles)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(EulerAngles));
     tolua_pushusertype(tolua_S,tolua_obj,"EulerAngles");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'toEulerAngles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_normalize01
static int tolua_common_Quaternion_normalize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Quaternion_normalize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: conjugate of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_conjugate01
static int tolua_common_Quaternion_conjugate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'conjugate'", NULL);
#endif
  {
   self->conjugate();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Quaternion_conjugate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_negate01
static int tolua_common_Quaternion_negate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'negate'", NULL);
#endif
  {
   self->negate();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Quaternion_negate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: inverse of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_inverse01
static int tolua_common_Quaternion_inverse01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Quaternion",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Quaternion* self = (Quaternion*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'inverse'", NULL);
#endif
  {
   self->inverse();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Quaternion_inverse00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNormalized of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_getNormalized00
static int tolua_common_Quaternion_getNormalized00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNormalized'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->getNormalized();
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getConjugated of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_getConjugated00
static int tolua_common_Quaternion_getConjugated00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getConjugated'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->getConjugated();
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getConjugated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNegated of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_getNegated00
static int tolua_common_Quaternion_getNegated00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNegated'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->getNegated();
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNegated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInversed of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_getInversed00
static int tolua_common_Quaternion_getInversed00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInversed'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->getInversed();
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
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInversed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_dot00
static int tolua_common_Quaternion_dot00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
  const Quaternion* q = ((const Quaternion*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*q);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_length00
static int tolua_common_Quaternion_length00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lengthSq of class  Quaternion */
#ifndef TOLUA_DISABLE_tolua_common_Quaternion_lengthSq00
static int tolua_common_Quaternion_lengthSq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
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
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lengthSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->lengthSq();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lengthSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_x
static int tolua_get_Vector2_x(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Vector2_x
static int tolua_set_Vector2_x(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: y of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_y
static int tolua_get_Vector2_y(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Vector2_y
static int tolua_set_Vector2_y(lua_State* tolua_S)
{
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: Zero of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_Zero
static int tolua_get_Vector2_Zero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector2::Zero,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: One of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_One
static int tolua_get_Vector2_One(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector2::One,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Right of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_Right
static int tolua_get_Vector2_Right(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector2::Right,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Left of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_Left
static int tolua_get_Vector2_Left(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector2::Left,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Up of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_Up
static int tolua_get_Vector2_Up(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector2::Up,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Down of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_Down
static int tolua_get_Vector2_Down(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector2::Down,"const Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: var of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_get_Vector2_var
static int tolua_get_Vector2_var(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector2::var,"Vector2");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: var of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_set_Vector2_var
static int tolua_set_Vector2_var(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Vector2::var = *((Vector2*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_new00
static int tolua_common_Vector2_new00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_new00_local
static int tolua_common_Vector2_new00_local(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(x,y));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_new01
static int tolua_common_Vector2_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(*v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_new01_local
static int tolua_common_Vector2_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)(*v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_new02
static int tolua_common_Vector2_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_new02_local
static int tolua_common_Vector2_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector2* tolua_ret = (Vector2*)  Mtolua_new((Vector2)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_delete00
static int tolua_common_Vector2_delete00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createZero of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_createZero00
static int tolua_common_Vector2_createZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vector2 tolua_ret = (Vector2)  Vector2::createZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createOne of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_createOne00
static int tolua_common_Vector2_createOne00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vector2 tolua_ret = (Vector2)  Vector2::createOne();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromVector3 of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_createFromVector300
static int tolua_common_Vector2_createFromVector300(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector2 tolua_ret = (Vector2)  Vector2::createFromVector3(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromVector4 of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_createFromVector400
static int tolua_common_Vector2_createFromVector400(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector2 tolua_ret = (Vector2)  Vector2::createFromVector4(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addScalar of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_addScalar00
static int tolua_common_Vector2_addScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector2::addScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_add00
static int tolua_common_Vector2_add00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v1 = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  const Vector2* v2 = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector2::add(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: subScalar of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_subScalar00
static int tolua_common_Vector2_subScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector2::subScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'subScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_sub00
static int tolua_common_Vector2_sub00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v1 = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  const Vector2* v2 = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector2::sub(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulScalar of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_mulScalar00
static int tolua_common_Vector2_mulScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector2::mulScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_mul00
static int tolua_common_Vector2_mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v1 = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  const Vector2* v2 = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector2::mul(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: divScalar of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_divScalar00
static int tolua_common_Vector2_divScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector2::divScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'divScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: div of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_div00
static int tolua_common_Vector2_div00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v1 = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  const Vector2* v2 = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector2::div(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_clamp00
static int tolua_common_Vector2_clamp00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  const Vector2* min = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
  const Vector2* max = ((const Vector2*)  tolua_tousertype(tolua_S,5,0));
  {
   Vector2::clamp(*out,*v,*min,*max);
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

/* method: negate of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_negate00
static int tolua_common_Vector2_negate00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  {
   Vector2::negate(*out,*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_normalize00
static int tolua_common_Vector2_normalize00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  {
   Vector2::normalize(*out,*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_rotate00
static int tolua_common_Vector2_rotate00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  float angle = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector2::rotate(*out,*v,angle);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'rotate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_scale00
static int tolua_common_Vector2_scale00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  float s = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector2::scale(*out,*v,s);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: midPointBetween of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_midPointBetween00
static int tolua_common_Vector2_midPointBetween00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v1 = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  const Vector2* v2 = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector2::midPointBetween(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'midPointBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: project of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_project00
static int tolua_common_Vector2_project00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* out = ((Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
  const Vector2* n = ((const Vector2*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector2::project(*out,*v,*n);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'project'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_equals00
static int tolua_common_Vector2_equals00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isZero of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_isZero00
static int tolua_common_Vector2_isZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOne of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_isOne00
static int tolua_common_Vector2_isOne00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOne'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isOne();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isNormalized of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_isNormalized00
static int tolua_common_Vector2_isNormalized00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isNormalized'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isNormalized();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__eq00
static int tolua_common_Vector2__eq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__add00
static int tolua_common_Vector2__add00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->operator+();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__add01
static int tolua_common_Vector2__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->operator+(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__add02
static int tolua_common_Vector2__add02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->operator+(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2__add01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__sub00
static int tolua_common_Vector2__sub00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->operator-();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__sub01
static int tolua_common_Vector2__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->operator-(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__sub02
static int tolua_common_Vector2__sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->operator-(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2__sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__mul00
static int tolua_common_Vector2__mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->operator*(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__mul01
static int tolua_common_Vector2__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->operator*(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__div00
static int tolua_common_Vector2__div00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->operator/(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2__div01
static int tolua_common_Vector2__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->operator/(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_set00
static int tolua_common_Vector2_set00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setZero of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_setZero00
static int tolua_common_Vector2_setZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZero'", NULL);
#endif
  {
   self->setZero();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOne of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_setOne00
static int tolua_common_Vector2_setOne00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOne'", NULL);
#endif
  {
   self->setOne();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScalars of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_setScalars00
static int tolua_common_Vector2_setScalars00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScalars'", NULL);
#endif
  {
   self->setScalars(x,y);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScalars'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromVector3 of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_fromVector300
static int tolua_common_Vector2_fromVector300(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromVector3'", NULL);
#endif
  {
   self->fromVector3(*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromVector4 of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_fromVector400
static int tolua_common_Vector2_fromVector400(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromVector4'", NULL);
#endif
  {
   self->fromVector4(*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_clamp01
static int tolua_common_Vector2_clamp01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* min = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* max = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clamp'", NULL);
#endif
  {
   self->clamp(*min,*max);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector2_clamp00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_negate01
static int tolua_common_Vector2_negate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'negate'", NULL);
#endif
  {
   self->negate();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector2_negate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_normalize01
static int tolua_common_Vector2_normalize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector2_normalize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: rotate of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_rotate01
static int tolua_common_Vector2_rotate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'rotate'", NULL);
#endif
  {
   self->rotate(angle);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector2_rotate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_scale01
static int tolua_common_Vector2_scale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector2* self = (Vector2*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(s);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector2_scale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClamped of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_getClamped00
static int tolua_common_Vector2_getClamped00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* min = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  const Vector2* max = ((const Vector2*)  tolua_tousertype(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClamped'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->getClamped(*min,*max);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClamped'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNegated of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_getNegated00
static int tolua_common_Vector2_getNegated00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNegated'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->getNegated();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNegated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNormalized of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_getNormalized00
static int tolua_common_Vector2_getNormalized00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNormalized'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->getNormalized();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getRotated of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_getRotated00
static int tolua_common_Vector2_getRotated00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  float angle = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getRotated'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->getRotated(angle);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getRotated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScaled of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_getScaled00
static int tolua_common_Vector2_getScaled00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScaled'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->getScaled(s);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScaled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_dot00
static int tolua_common_Vector2_dot00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cross of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_cross00
static int tolua_common_Vector2_cross00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cross'", NULL);
#endif
  {
   float tolua_ret = (float)  self->cross(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cross'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceBetween of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_distanceBetween00
static int tolua_common_Vector2_distanceBetween00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distanceBetween'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distanceBetween(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceBetweenSq of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_distanceBetweenSq00
static int tolua_common_Vector2_distanceBetweenSq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distanceBetweenSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distanceBetweenSq(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceBetweenSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_length00
static int tolua_common_Vector2_length00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lengthSq of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_lengthSq00
static int tolua_common_Vector2_lengthSq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lengthSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->lengthSq();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lengthSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angleBetween of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_angleBetween00
static int tolua_common_Vector2_angleBetween00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angleBetween'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angleBetween(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angleBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: midPointBetween of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_midPointBetween01
static int tolua_common_Vector2_midPointBetween01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'midPointBetween'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->midPointBetween(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2_midPointBetween00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: project of class  Vector2 */
#ifndef TOLUA_DISABLE_tolua_common_Vector2_project01
static int tolua_common_Vector2_project01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector2",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector2* self = (const Vector2*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* n = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'project'", NULL);
#endif
  {
   Vector2 tolua_ret = (Vector2)  self->project(*n);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector2)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector2));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector2");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector2_project00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_x
static int tolua_get_Vector3_x(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_x
static int tolua_set_Vector3_x(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: y of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_y
static int tolua_get_Vector3_y(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_y
static int tolua_set_Vector3_y(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: z of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_z
static int tolua_get_Vector3_z(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_z
static int tolua_set_Vector3_z(lua_State* tolua_S)
{
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: Zero of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_Zero
static int tolua_get_Vector3_Zero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector3::Zero,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: One of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_One
static int tolua_get_Vector3_One(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector3::One,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Up of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_Up
static int tolua_get_Vector3_Up(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector3::Up,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Down of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_Down
static int tolua_get_Vector3_Down(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector3::Down,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Right of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_Right
static int tolua_get_Vector3_Right(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector3::Right,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Left of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_Left
static int tolua_get_Vector3_Left(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector3::Left,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Forward of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_Forward
static int tolua_get_Vector3_Forward(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector3::Forward,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Back of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_Back
static int tolua_get_Vector3_Back(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector3::Back,"const Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: var of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_get_Vector3_var
static int tolua_get_Vector3_var(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector3::var,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: var of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_set_Vector3_var
static int tolua_set_Vector3_var(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Vector3::var = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_new00
static int tolua_common_Vector3_new00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(x,y,z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_new00_local
static int tolua_common_Vector3_new00_local(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(x,y,z));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_new01
static int tolua_common_Vector3_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(*v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_new01_local
static int tolua_common_Vector3_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)(*v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_new02
static int tolua_common_Vector3_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_new02_local
static int tolua_common_Vector3_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector3* tolua_ret = (Vector3*)  Mtolua_new((Vector3)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_delete00
static int tolua_common_Vector3_delete00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createZero of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_createZero00
static int tolua_common_Vector3_createZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vector3 tolua_ret = (Vector3)  Vector3::createZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createOne of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_createOne00
static int tolua_common_Vector3_createOne00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vector3 tolua_ret = (Vector3)  Vector3::createOne();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromVector2 of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_createFromVector200
static int tolua_common_Vector3_createFromVector200(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector3 tolua_ret = (Vector3)  Vector3::createFromVector2(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromVector4 of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_createFromVector400
static int tolua_common_Vector3_createFromVector400(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector3 tolua_ret = (Vector3)  Vector3::createFromVector4(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addScalar of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_addScalar00
static int tolua_common_Vector3_addScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3::addScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_add00
static int tolua_common_Vector3_add00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector3::add(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: subScalar of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_subScalar00
static int tolua_common_Vector3_subScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3::subScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'subScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_sub00
static int tolua_common_Vector3_sub00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector3::sub(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulMatrix4 of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_mulMatrix400
static int tolua_common_Vector3_mulMatrix400(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector3::mulMatrix4(*out,*v,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulScalar of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_mulScalar00
static int tolua_common_Vector3_mulScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3::mulScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_mul00
static int tolua_common_Vector3_mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector3::mul(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: divScalar of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_divScalar00
static int tolua_common_Vector3_divScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3::divScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'divScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: div of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_div00
static int tolua_common_Vector3_div00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector3::div(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cross of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_cross00
static int tolua_common_Vector3_cross00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector3::cross(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'cross'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_clamp00
static int tolua_common_Vector3_clamp00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* min = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  const Vector3* max = ((const Vector3*)  tolua_tousertype(tolua_S,5,0));
  {
   Vector3::clamp(*out,*v,*min,*max);
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

/* method: negate of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_negate00
static int tolua_common_Vector3_negate00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  {
   Vector3::negate(*out,*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_normalize00
static int tolua_common_Vector3_normalize00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  {
   Vector3::normalize(*out,*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_scale00
static int tolua_common_Vector3_scale00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  float s = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector3::scale(*out,*v,s);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: midPointBetween of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_midPointBetween00
static int tolua_common_Vector3_midPointBetween00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v1 = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* v2 = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector3::midPointBetween(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'midPointBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: project of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_project00
static int tolua_common_Vector3_project00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* out = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  const Vector3* n = ((const Vector3*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector3::project(*out,*v,*n);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'project'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_equals00
static int tolua_common_Vector3_equals00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isZero of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_isZero00
static int tolua_common_Vector3_isZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOne of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_isOne00
static int tolua_common_Vector3_isOne00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOne'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isOne();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isNormalized of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_isNormalized00
static int tolua_common_Vector3_isNormalized00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isNormalized'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isNormalized();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__eq00
static int tolua_common_Vector3__eq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__add00
static int tolua_common_Vector3__add00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator+();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__add01
static int tolua_common_Vector3__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator+(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__add02
static int tolua_common_Vector3__add02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator+(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3__add01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__sub00
static int tolua_common_Vector3__sub00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator-();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__sub01
static int tolua_common_Vector3__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator-(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__sub02
static int tolua_common_Vector3__sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator-(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3__sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__mul00
static int tolua_common_Vector3__mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator*(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__mul01
static int tolua_common_Vector3__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator*(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__mul02
static int tolua_common_Vector3__mul02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator*(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3__mul01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__div00
static int tolua_common_Vector3__div00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator/(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3__div01
static int tolua_common_Vector3__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->operator/(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_set00
static int tolua_common_Vector3_set00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setZero of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_setZero00
static int tolua_common_Vector3_setZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZero'", NULL);
#endif
  {
   self->setZero();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOne of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_setOne00
static int tolua_common_Vector3_setOne00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOne'", NULL);
#endif
  {
   self->setOne();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScalars of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_setScalars00
static int tolua_common_Vector3_setScalars00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScalars'", NULL);
#endif
  {
   self->setScalars(x,y,z);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScalars'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromVector2 of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_fromVector200
static int tolua_common_Vector3_fromVector200(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromVector2'", NULL);
#endif
  {
   self->fromVector2(*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromVector4 of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_fromVector400
static int tolua_common_Vector3_fromVector400(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromVector4'", NULL);
#endif
  {
   self->fromVector4(*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromVector4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_clamp01
static int tolua_common_Vector3_clamp01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* min = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* max = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clamp'", NULL);
#endif
  {
   self->clamp(*min,*max);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector3_clamp00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_negate01
static int tolua_common_Vector3_negate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'negate'", NULL);
#endif
  {
   self->negate();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector3_negate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_normalize01
static int tolua_common_Vector3_normalize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector3_normalize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_scale01
static int tolua_common_Vector3_scale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector3* self = (Vector3*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(s);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector3_scale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClamped of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_getClamped00
static int tolua_common_Vector3_getClamped00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* min = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* max = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClamped'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getClamped(*min,*max);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClamped'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNegated of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_getNegated00
static int tolua_common_Vector3_getNegated00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNegated'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getNegated();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNegated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNormalized of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_getNormalized00
static int tolua_common_Vector3_getNormalized00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNormalized'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getNormalized();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScaled of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_getScaled00
static int tolua_common_Vector3_getScaled00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScaled'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->getScaled(s);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScaled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_dot00
static int tolua_common_Vector3_dot00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceBetween of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_distanceBetween00
static int tolua_common_Vector3_distanceBetween00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distanceBetween'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distanceBetween(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceBetweenSq of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_distanceBetweenSq00
static int tolua_common_Vector3_distanceBetweenSq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distanceBetweenSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distanceBetweenSq(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceBetweenSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_length00
static int tolua_common_Vector3_length00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lengthSq of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_lengthSq00
static int tolua_common_Vector3_lengthSq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lengthSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->lengthSq();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lengthSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angleBetween of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_angleBetween00
static int tolua_common_Vector3_angleBetween00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angleBetween'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angleBetween(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angleBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: cross of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_cross01
static int tolua_common_Vector3_cross01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'cross'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->cross(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3_cross00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: midPointBetween of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_midPointBetween01
static int tolua_common_Vector3_midPointBetween01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'midPointBetween'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->midPointBetween(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3_midPointBetween00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: project of class  Vector3 */
#ifndef TOLUA_DISABLE_tolua_common_Vector3_project01
static int tolua_common_Vector3_project01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector3",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector3* self = (const Vector3*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* n = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'project'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->project(*n);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector3_project00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: x of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_x
static int tolua_get_Vector4_x(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'x'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->x);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: x of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_x
static int tolua_set_Vector4_x(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: y of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_y
static int tolua_get_Vector4_y(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'y'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->y);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: y of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_y
static int tolua_set_Vector4_y(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: z of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_z
static int tolua_get_Vector4_z(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'z'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->z);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: z of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_z
static int tolua_set_Vector4_z(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: w of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_w
static int tolua_get_Vector4_w(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'w'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->w);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: w of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_w
static int tolua_set_Vector4_w(lua_State* tolua_S)
{
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
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

/* get function: Zero of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_Zero
static int tolua_get_Vector4_Zero(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::Zero,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: One of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_One
static int tolua_get_Vector4_One(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::One,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Up of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_Up
static int tolua_get_Vector4_Up(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::Up,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Down of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_Down
static int tolua_get_Vector4_Down(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::Down,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Right of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_Right
static int tolua_get_Vector4_Right(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::Right,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Left of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_Left
static int tolua_get_Vector4_Left(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::Left,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Forward of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_Forward
static int tolua_get_Vector4_Forward(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::Forward,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Back of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_Back
static int tolua_get_Vector4_Back(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::Back,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Space0 of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_Space0
static int tolua_get_Vector4_Space0(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::Space0,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Space1 of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_Space1
static int tolua_get_Vector4_Space1(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::Space1,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Space2 of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_Space2
static int tolua_get_Vector4_Space2(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::Space2,"const Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: var of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_get_Vector4_var
static int tolua_get_Vector4_var(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Vector4::var,"Vector4");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: var of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_set_Vector4_var
static int tolua_set_Vector4_var(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Vector4::var = *((Vector4*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_new00
static int tolua_common_Vector4_new00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
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
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(x,y,z,w));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_new00_local
static int tolua_common_Vector4_new00_local(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
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
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(x,y,z,w));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_new01
static int tolua_common_Vector4_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(*v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_new01_local
static int tolua_common_Vector4_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)(*v));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_new02
static int tolua_common_Vector4_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_new02_local
static int tolua_common_Vector4_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  {
   Vector4* tolua_ret = (Vector4*)  Mtolua_new((Vector4)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_delete00
static int tolua_common_Vector4_delete00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createZero of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_createZero00
static int tolua_common_Vector4_createZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vector4 tolua_ret = (Vector4)  Vector4::createZero();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createOne of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_createOne00
static int tolua_common_Vector4_createOne00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Vector4 tolua_ret = (Vector4)  Vector4::createOne();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromVector2 of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_createFromVector200
static int tolua_common_Vector4_createFromVector200(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector4 tolua_ret = (Vector4)  Vector4::createFromVector2(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createFromVector3 of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_createFromVector300
static int tolua_common_Vector4_createFromVector300(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  {
   Vector4 tolua_ret = (Vector4)  Vector4::createFromVector3(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createFromVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addScalar of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_addScalar00
static int tolua_common_Vector4_addScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector4::addScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: add of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_add00
static int tolua_common_Vector4_add00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v1 = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  const Vector4* v2 = ((const Vector4*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector4::add(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: subScalar of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_subScalar00
static int tolua_common_Vector4_subScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector4::subScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'subScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: sub of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_sub00
static int tolua_common_Vector4_sub00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v1 = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  const Vector4* v2 = ((const Vector4*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector4::sub(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulMatrix4 of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_mulMatrix400
static int tolua_common_Vector4_mulMatrix400(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector4::mulMatrix4(*out,*v,*m);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulMatrix4'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mulScalar of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_mulScalar00
static int tolua_common_Vector4_mulScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector4::mulScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mulScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mul of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_mul00
static int tolua_common_Vector4_mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v1 = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  const Vector4* v2 = ((const Vector4*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector4::mul(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: divScalar of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_divScalar00
static int tolua_common_Vector4_divScalar00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  float a = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector4::divScalar(*out,*v,a);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'divScalar'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: div of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_div00
static int tolua_common_Vector4_div00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v1 = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  const Vector4* v2 = ((const Vector4*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector4::div(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_clamp00
static int tolua_common_Vector4_clamp00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,5,&tolua_err) || !tolua_isusertype(tolua_S,5,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  const Vector4* min = ((const Vector4*)  tolua_tousertype(tolua_S,4,0));
  const Vector4* max = ((const Vector4*)  tolua_tousertype(tolua_S,5,0));
  {
   Vector4::clamp(*out,*v,*min,*max);
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

/* method: negate of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_negate00
static int tolua_common_Vector4_negate00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  {
   Vector4::negate(*out,*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'negate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_normalize00
static int tolua_common_Vector4_normalize00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  {
   Vector4::normalize(*out,*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'normalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_scale00
static int tolua_common_Vector4_scale00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  float s = ((float)  tolua_tonumber(tolua_S,4,0));
  {
   Vector4::scale(*out,*v,s);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: midPointBetween of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_midPointBetween00
static int tolua_common_Vector4_midPointBetween00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v1 = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  const Vector4* v2 = ((const Vector4*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector4::midPointBetween(*out,*v1,*v2);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'midPointBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: project of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_project00
static int tolua_common_Vector4_project00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* out = ((Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
  const Vector4* n = ((const Vector4*)  tolua_tousertype(tolua_S,4,0));
  {
   Vector4::project(*out,*v,*n);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'project'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: equals of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_equals00
static int tolua_common_Vector4_equals00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'equals'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->equals(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'equals'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isZero of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_isZero00
static int tolua_common_Vector4_isZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isZero'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isZero();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isOne of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_isOne00
static int tolua_common_Vector4_isOne00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isOne'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isOne();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isNormalized of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_isNormalized00
static int tolua_common_Vector4_isNormalized00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isNormalized'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isNormalized();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator== of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__eq00
static int tolua_common_Vector4__eq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator=='", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->operator==(*v);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.eq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__add00
static int tolua_common_Vector4__add00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator+();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.add'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__add01
static int tolua_common_Vector4__add01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator+(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4__add00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator+ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__add02
static int tolua_common_Vector4__add02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator+'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator+(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4__add01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__sub00
static int tolua_common_Vector4__sub00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator-();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.sub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__sub01
static int tolua_common_Vector4__sub01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator-(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4__sub00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator- of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__sub02
static int tolua_common_Vector4__sub02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator-'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator-(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4__sub01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__mul00
static int tolua_common_Vector4__mul00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Matrix4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Matrix4* m = ((const Matrix4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator*(*m);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.mul'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__mul01
static int tolua_common_Vector4__mul01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator*(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4__mul00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator* of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__mul02
static int tolua_common_Vector4__mul02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator*'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator*(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4__mul01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__div00
static int tolua_common_Vector4__div00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  float a = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator/(a);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function '.div'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: operator/ of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4__div01
static int tolua_common_Vector4__div01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'operator/'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->operator/(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4__div00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: set of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_set00
static int tolua_common_Vector4_set00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'set'", NULL);
#endif
  {
   self->set(*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'set'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setZero of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_setZero00
static int tolua_common_Vector4_setZero00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setZero'", NULL);
#endif
  {
   self->setZero();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setZero'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setOne of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_setOne00
static int tolua_common_Vector4_setOne00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setOne'", NULL);
#endif
  {
   self->setOne();
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setOne'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setScalars of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_setScalars00
static int tolua_common_Vector4_setScalars00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
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
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
  float z = ((float)  tolua_tonumber(tolua_S,4,0));
  float w = ((float)  tolua_tonumber(tolua_S,5,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setScalars'", NULL);
#endif
  {
   self->setScalars(x,y,z,w);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setScalars'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromVector2 of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_fromVector200
static int tolua_common_Vector4_fromVector200(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector2",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector2* v = ((const Vector2*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromVector2'", NULL);
#endif
  {
   self->fromVector2(*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromVector2'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: fromVector3 of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_fromVector300
static int tolua_common_Vector4_fromVector300(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* v = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'fromVector3'", NULL);
#endif
  {
   self->fromVector3(*v);
  }
 }
 return 0;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'fromVector3'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: clamp of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_clamp01
static int tolua_common_Vector4_clamp01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* min = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* max = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'clamp'", NULL);
#endif
  {
   self->clamp(*min,*max);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector4_clamp00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: negate of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_negate01
static int tolua_common_Vector4_negate01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'negate'", NULL);
#endif
  {
   self->negate();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector4_negate00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: normalize of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_normalize01
static int tolua_common_Vector4_normalize01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'normalize'", NULL);
#endif
  {
   self->normalize();
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector4_normalize00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: scale of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_scale01
static int tolua_common_Vector4_scale01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Vector4* self = (Vector4*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scale'", NULL);
#endif
  {
   self->scale(s);
  }
 }
 return 0;
tolua_lerror:
 return tolua_common_Vector4_scale00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: getClamped of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_getClamped00
static int tolua_common_Vector4_getClamped00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* min = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
  const Vector4* max = ((const Vector4*)  tolua_tousertype(tolua_S,3,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getClamped'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->getClamped(*min,*max);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getClamped'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNegated of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_getNegated00
static int tolua_common_Vector4_getNegated00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNegated'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->getNegated();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNegated'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNormalized of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_getNormalized00
static int tolua_common_Vector4_getNormalized00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNormalized'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->getNormalized();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNormalized'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getScaled of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_getScaled00
static int tolua_common_Vector4_getScaled00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  float s = ((float)  tolua_tonumber(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getScaled'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->getScaled(s);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getScaled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: dot of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_dot00
static int tolua_common_Vector4_dot00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'dot'", NULL);
#endif
  {
   float tolua_ret = (float)  self->dot(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'dot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceBetween of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_distanceBetween00
static int tolua_common_Vector4_distanceBetween00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distanceBetween'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distanceBetween(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: distanceBetweenSq of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_distanceBetweenSq00
static int tolua_common_Vector4_distanceBetweenSq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'distanceBetweenSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->distanceBetweenSq(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'distanceBetweenSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: length of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_length00
static int tolua_common_Vector4_length00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'length'", NULL);
#endif
  {
   float tolua_ret = (float)  self->length();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'length'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: lengthSq of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_lengthSq00
static int tolua_common_Vector4_lengthSq00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'lengthSq'", NULL);
#endif
  {
   float tolua_ret = (float)  self->lengthSq();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'lengthSq'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: angleBetween of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_angleBetween00
static int tolua_common_Vector4_angleBetween00(lua_State* tolua_S)
{
#ifdef MAGICAL_DEBUG
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'angleBetween'", NULL);
#endif
  {
   float tolua_ret = (float)  self->angleBetween(*v);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifdef MAGICAL_DEBUG
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'angleBetween'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: midPointBetween of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_midPointBetween01
static int tolua_common_Vector4_midPointBetween01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* v = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'midPointBetween'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->midPointBetween(*v);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4_midPointBetween00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: project of class  Vector4 */
#ifndef TOLUA_DISABLE_tolua_common_Vector4_project01
static int tolua_common_Vector4_project01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Vector4",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector4",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const Vector4* self = (const Vector4*)  tolua_tousertype(tolua_S,1,0);
  const Vector4* n = ((const Vector4*)  tolua_tousertype(tolua_S,2,0));
#ifdef MAGICAL_DEBUG
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'project'", NULL);
#endif
  {
   Vector4 tolua_ret = (Vector4)  self->project(*n);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector4)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector4));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector4");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
tolua_lerror:
 return tolua_common_Vector4_project00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_common_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Assets","Assets","",NULL);
  tolua_beginmodule(tolua_S,"Assets");
   tolua_function(tolua_S,"resetAssetsPath",tolua_common_Assets_resetAssetsPath00);
   tolua_function(tolua_S,"setAssetsPath",tolua_common_Assets_setAssetsPath00);
   tolua_function(tolua_S,"getAssetsPath",tolua_common_Assets_getAssetsPath00);
   tolua_function(tolua_S,"getAssetsAbsoluteFilename",tolua_common_Assets_getAssetsAbsoluteFilename00);
   tolua_function(tolua_S,"isAssetsFileExist",tolua_common_Assets_isAssetsFileExist00);
   tolua_function(tolua_S,"getAssetsFileData",tolua_common_Assets_getAssetsFileData00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"kBufferLen",kBufferLen);
  tolua_function(tolua_S,"magicalIsError",tolua_common_magicalIsError00);
  tolua_function(tolua_S,"magicalIgnoreLastError",tolua_common_magicalIgnoreLastError00);
  tolua_function(tolua_S,"magicalSetLastErrorInfo",tolua_common_magicalSetLastErrorInfo00);
  tolua_function(tolua_S,"magicalSetLastErrorInfoB",tolua_common_magicalSetLastErrorInfoB00);
  tolua_function(tolua_S,"magicalShowLastError",tolua_common_magicalShowLastError00);
  tolua_function(tolua_S,"magicalMessageBox",tolua_common_magicalMessageBox00);
  tolua_function(tolua_S,"magicalDebugMessageBox",tolua_common_magicalDebugMessageBox00);
  tolua_function(tolua_S,"magicalAssert",tolua_common_magicalAssert00);
  tolua_function(tolua_S,"magicalIsTimerStarted",tolua_common_magicalIsTimerStarted00);
  tolua_function(tolua_S,"magicalStartTimer",tolua_common_magicalStartTimer00);
  tolua_function(tolua_S,"magicalEndTimer",tolua_common_magicalEndTimer00);
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
   tolua_function(tolua_S,"ptr",tolua_common_Data_ptr00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Reference","Reference","",NULL);
  tolua_beginmodule(tolua_S,"Reference");
   tolua_function(tolua_S,"retain",tolua_common_Reference_retain00);
   tolua_function(tolua_S,"release",tolua_common_Reference_release00);
   tolua_function(tolua_S,"referenceCount",tolua_common_Reference_referenceCount00);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Space",0);
  tolua_beginmodule(tolua_S,"Space");
   tolua_constant(tolua_S,"Self", (int)Space::Self);
   tolua_constant(tolua_S,"Parent", (int)Space::Parent);
   tolua_constant(tolua_S,"World", (int)Space::World);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Transform","Transform","Reference",tolua_collect_Transform);
  #else
  tolua_cclass(tolua_S,"Transform","Transform","Reference",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Transform");
   tolua_function(tolua_S,"delete",tolua_common_Transform_delete00);
   tolua_function(tolua_S,"create",tolua_common_Transform_create00);
   tolua_function(tolua_S,"setName",tolua_common_Transform_setName00);
   tolua_function(tolua_S,"getName",tolua_common_Transform_getName00);
   tolua_function(tolua_S,"addChild",tolua_common_Transform_addChild00);
   tolua_function(tolua_S,"removeChild",tolua_common_Transform_removeChild00);
   tolua_function(tolua_S,"removeAllChildren",tolua_common_Transform_removeAllChildren00);
   tolua_function(tolua_S,"removeFromParent",tolua_common_Transform_removeFromParent00);
   tolua_function(tolua_S,"findChild",tolua_common_Transform_findChild00);
   tolua_function(tolua_S,"getChild",tolua_common_Transform_getChild00);
   tolua_function(tolua_S,"childrenCount",tolua_common_Transform_childrenCount00);
   tolua_function(tolua_S,"getParent",tolua_common_Transform_getParent00);
   tolua_function(tolua_S,"isChildOf",tolua_common_Transform_isChildOf00);
   tolua_function(tolua_S,"setPosition",tolua_common_Transform_setPosition00);
   tolua_function(tolua_S,"setPosition",tolua_common_Transform_setPosition01);
   tolua_function(tolua_S,"setPosition",tolua_common_Transform_setPosition02);
   tolua_function(tolua_S,"setPosition",tolua_common_Transform_setPosition03);
   tolua_function(tolua_S,"translate",tolua_common_Transform_translate00);
   tolua_function(tolua_S,"translate",tolua_common_Transform_translate01);
   tolua_function(tolua_S,"translate",tolua_common_Transform_translate02);
   tolua_function(tolua_S,"translate",tolua_common_Transform_translate03);
   tolua_function(tolua_S,"getPosition",tolua_common_Transform_getPosition00);
   tolua_function(tolua_S,"setRotation",tolua_common_Transform_setRotation00);
   tolua_function(tolua_S,"setRotation",tolua_common_Transform_setRotation01);
   tolua_function(tolua_S,"setRotation",tolua_common_Transform_setRotation02);
   tolua_function(tolua_S,"rotate",tolua_common_Transform_rotate00);
   tolua_function(tolua_S,"rotate",tolua_common_Transform_rotate01);
   tolua_function(tolua_S,"rotate",tolua_common_Transform_rotate02);
   tolua_function(tolua_S,"yaw",tolua_common_Transform_yaw00);
   tolua_function(tolua_S,"pitch",tolua_common_Transform_pitch00);
   tolua_function(tolua_S,"roll",tolua_common_Transform_roll00);
   tolua_function(tolua_S,"getRotation",tolua_common_Transform_getRotation00);
   tolua_function(tolua_S,"setScale",tolua_common_Transform_setScale00);
   tolua_function(tolua_S,"setScale",tolua_common_Transform_setScale01);
   tolua_function(tolua_S,"setScale",tolua_common_Transform_setScale02);
   tolua_function(tolua_S,"setScale",tolua_common_Transform_setScale03);
   tolua_function(tolua_S,"scale",tolua_common_Transform_scale00);
   tolua_function(tolua_S,"scale",tolua_common_Transform_scale01);
   tolua_function(tolua_S,"scale",tolua_common_Transform_scale02);
   tolua_function(tolua_S,"scale",tolua_common_Transform_scale03);
   tolua_function(tolua_S,"scale",tolua_common_Transform_scale04);
   tolua_function(tolua_S,"getScale",tolua_common_Transform_getScale00);
   tolua_function(tolua_S,"lookAt",tolua_common_Transform_lookAt00);
   tolua_function(tolua_S,"resetTransform",tolua_common_Transform_resetTransform00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"magicalLogLastError",tolua_common_magicalLogLastError00);
  tolua_function(tolua_S,"magicalLog",tolua_common_magicalLog00);
  tolua_function(tolua_S,"magicalDebugLog",tolua_common_magicalDebugLog00);
  tolua_cclass(tolua_S,"Log","Log","",NULL);
  tolua_beginmodule(tolua_S,"Log");
   tolua_function(tolua_S,"write",tolua_common_Log_write00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"AxisAngle","AxisAngle","",tolua_collect_AxisAngle);
  #else
  tolua_cclass(tolua_S,"AxisAngle","AxisAngle","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"AxisAngle");
   tolua_variable(tolua_S,"x",tolua_get_AxisAngle_x,tolua_set_AxisAngle_x);
   tolua_variable(tolua_S,"y",tolua_get_AxisAngle_y,tolua_set_AxisAngle_y);
   tolua_variable(tolua_S,"z",tolua_get_AxisAngle_z,tolua_set_AxisAngle_z);
   tolua_variable(tolua_S,"w",tolua_get_AxisAngle_w,tolua_set_AxisAngle_w);
   tolua_variable(tolua_S,"Identity",tolua_get_AxisAngle_Identity,NULL);
   tolua_variable(tolua_S,"Zero",tolua_get_AxisAngle_Zero,NULL);
   tolua_variable(tolua_S,"var",tolua_get_AxisAngle_var,tolua_set_AxisAngle_var);
   tolua_function(tolua_S,"new",tolua_common_AxisAngle_new00);
   tolua_function(tolua_S,"new_local",tolua_common_AxisAngle_new00_local);
   tolua_function(tolua_S,".call",tolua_common_AxisAngle_new00_local);
   tolua_function(tolua_S,"new",tolua_common_AxisAngle_new01);
   tolua_function(tolua_S,"new_local",tolua_common_AxisAngle_new01_local);
   tolua_function(tolua_S,".call",tolua_common_AxisAngle_new01_local);
   tolua_function(tolua_S,"new",tolua_common_AxisAngle_new02);
   tolua_function(tolua_S,"new_local",tolua_common_AxisAngle_new02_local);
   tolua_function(tolua_S,".call",tolua_common_AxisAngle_new02_local);
   tolua_function(tolua_S,"new",tolua_common_AxisAngle_new03);
   tolua_function(tolua_S,"new_local",tolua_common_AxisAngle_new03_local);
   tolua_function(tolua_S,".call",tolua_common_AxisAngle_new03_local);
   tolua_function(tolua_S,"delete",tolua_common_AxisAngle_delete00);
   tolua_function(tolua_S,"create",tolua_common_AxisAngle_create00);
   tolua_function(tolua_S,"createIdentity",tolua_common_AxisAngle_createIdentity00);
   tolua_function(tolua_S,"createZero",tolua_common_AxisAngle_createZero00);
   tolua_function(tolua_S,"createFromQuaternion",tolua_common_AxisAngle_createFromQuaternion00);
   tolua_function(tolua_S,"equals",tolua_common_AxisAngle_equals00);
   tolua_function(tolua_S,"isIdentity",tolua_common_AxisAngle_isIdentity00);
   tolua_function(tolua_S,"isZero",tolua_common_AxisAngle_isZero00);
   tolua_function(tolua_S,".eq",tolua_common_AxisAngle__eq00);
   tolua_function(tolua_S,"set",tolua_common_AxisAngle_set00);
   tolua_function(tolua_S,"set",tolua_common_AxisAngle_set01);
   tolua_function(tolua_S,"setIdentity",tolua_common_AxisAngle_setIdentity00);
   tolua_function(tolua_S,"setZero",tolua_common_AxisAngle_setZero00);
   tolua_function(tolua_S,"setScalaas",tolua_common_AxisAngle_setScalaas00);
   tolua_function(tolua_S,"fromQuaternion",tolua_common_AxisAngle_fromQuaternion00);
   tolua_function(tolua_S,"toQuaternion",tolua_common_AxisAngle_toQuaternion00);
   tolua_function(tolua_S,"axis",tolua_common_AxisAngle_axis00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"EulerAngles","EulerAngles","",tolua_collect_EulerAngles);
  #else
  tolua_cclass(tolua_S,"EulerAngles","EulerAngles","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"EulerAngles");
   tolua_variable(tolua_S,"yaw",tolua_get_EulerAngles_yaw,tolua_set_EulerAngles_yaw);
   tolua_variable(tolua_S,"pitch",tolua_get_EulerAngles_pitch,tolua_set_EulerAngles_pitch);
   tolua_variable(tolua_S,"roll",tolua_get_EulerAngles_roll,tolua_set_EulerAngles_roll);
   tolua_variable(tolua_S,"Zero",tolua_get_EulerAngles_Zero,NULL);
   tolua_variable(tolua_S,"var",tolua_get_EulerAngles_var,tolua_set_EulerAngles_var);
   tolua_function(tolua_S,"new",tolua_common_EulerAngles_new00);
   tolua_function(tolua_S,"new_local",tolua_common_EulerAngles_new00_local);
   tolua_function(tolua_S,".call",tolua_common_EulerAngles_new00_local);
   tolua_function(tolua_S,"new",tolua_common_EulerAngles_new01);
   tolua_function(tolua_S,"new_local",tolua_common_EulerAngles_new01_local);
   tolua_function(tolua_S,".call",tolua_common_EulerAngles_new01_local);
   tolua_function(tolua_S,"new",tolua_common_EulerAngles_new02);
   tolua_function(tolua_S,"new_local",tolua_common_EulerAngles_new02_local);
   tolua_function(tolua_S,".call",tolua_common_EulerAngles_new02_local);
   tolua_function(tolua_S,"delete",tolua_common_EulerAngles_delete00);
   tolua_function(tolua_S,"createZero",tolua_common_EulerAngles_createZero00);
   tolua_function(tolua_S,"createFromQuaternion",tolua_common_EulerAngles_createFromQuaternion00);
   tolua_function(tolua_S,"add",tolua_common_EulerAngles_add00);
   tolua_function(tolua_S,"sub",tolua_common_EulerAngles_sub00);
   tolua_function(tolua_S,"mulScalar",tolua_common_EulerAngles_mulScalar00);
   tolua_function(tolua_S,"mul",tolua_common_EulerAngles_mul00);
   tolua_function(tolua_S,"limit",tolua_common_EulerAngles_limit00);
   tolua_function(tolua_S,"equals",tolua_common_EulerAngles_equals00);
   tolua_function(tolua_S,"isZero",tolua_common_EulerAngles_isZero00);
   tolua_function(tolua_S,".eq",tolua_common_EulerAngles__eq00);
   tolua_function(tolua_S,".add",tolua_common_EulerAngles__add00);
   tolua_function(tolua_S,".sub",tolua_common_EulerAngles__sub00);
   tolua_function(tolua_S,".mul",tolua_common_EulerAngles__mul00);
   tolua_function(tolua_S,".mul",tolua_common_EulerAngles__mul01);
   tolua_function(tolua_S,"set",tolua_common_EulerAngles_set00);
   tolua_function(tolua_S,"setZero",tolua_common_EulerAngles_setZero00);
   tolua_function(tolua_S,"setScalars",tolua_common_EulerAngles_setScalars00);
   tolua_function(tolua_S,"fromQuaternion",tolua_common_EulerAngles_fromQuaternion00);
   tolua_function(tolua_S,"toQuaternion",tolua_common_EulerAngles_toQuaternion00);
   tolua_function(tolua_S,"limit",tolua_common_EulerAngles_limit01);
   tolua_function(tolua_S,"getLimited",tolua_common_EulerAngles_getLimited00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Matrix4","Matrix4","",tolua_collect_Matrix4);
  #else
  tolua_cclass(tolua_S,"Matrix4","Matrix4","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Matrix4");
   tolua_variable(tolua_S,"m11",tolua_get_Matrix4_m11,tolua_set_Matrix4_m11);
   tolua_variable(tolua_S,"m12",tolua_get_Matrix4_m12,tolua_set_Matrix4_m12);
   tolua_variable(tolua_S,"m13",tolua_get_Matrix4_m13,tolua_set_Matrix4_m13);
   tolua_variable(tolua_S,"m14",tolua_get_Matrix4_m14,tolua_set_Matrix4_m14);
   tolua_variable(tolua_S,"m21",tolua_get_Matrix4_m21,tolua_set_Matrix4_m21);
   tolua_variable(tolua_S,"m22",tolua_get_Matrix4_m22,tolua_set_Matrix4_m22);
   tolua_variable(tolua_S,"m23",tolua_get_Matrix4_m23,tolua_set_Matrix4_m23);
   tolua_variable(tolua_S,"m24",tolua_get_Matrix4_m24,tolua_set_Matrix4_m24);
   tolua_variable(tolua_S,"m31",tolua_get_Matrix4_m31,tolua_set_Matrix4_m31);
   tolua_variable(tolua_S,"m32",tolua_get_Matrix4_m32,tolua_set_Matrix4_m32);
   tolua_variable(tolua_S,"m33",tolua_get_Matrix4_m33,tolua_set_Matrix4_m33);
   tolua_variable(tolua_S,"m34",tolua_get_Matrix4_m34,tolua_set_Matrix4_m34);
   tolua_variable(tolua_S,"m41",tolua_get_Matrix4_m41,tolua_set_Matrix4_m41);
   tolua_variable(tolua_S,"m42",tolua_get_Matrix4_m42,tolua_set_Matrix4_m42);
   tolua_variable(tolua_S,"m43",tolua_get_Matrix4_m43,tolua_set_Matrix4_m43);
   tolua_variable(tolua_S,"m44",tolua_get_Matrix4_m44,tolua_set_Matrix4_m44);
   tolua_variable(tolua_S,"Identity",tolua_get_Matrix4_Identity,NULL);
   tolua_variable(tolua_S,"Zero",tolua_get_Matrix4_Zero,NULL);
   tolua_variable(tolua_S,"var",tolua_get_Matrix4_var,tolua_set_Matrix4_var);
   tolua_function(tolua_S,"new",tolua_common_Matrix4_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Matrix4_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Matrix4_new00_local);
   tolua_function(tolua_S,"new",tolua_common_Matrix4_new01);
   tolua_function(tolua_S,"new_local",tolua_common_Matrix4_new01_local);
   tolua_function(tolua_S,".call",tolua_common_Matrix4_new01_local);
   tolua_function(tolua_S,"new",tolua_common_Matrix4_new02);
   tolua_function(tolua_S,"new_local",tolua_common_Matrix4_new02_local);
   tolua_function(tolua_S,".call",tolua_common_Matrix4_new02_local);
   tolua_function(tolua_S,"delete",tolua_common_Matrix4_delete00);
   tolua_function(tolua_S,"createIdentity",tolua_common_Matrix4_createIdentity00);
   tolua_function(tolua_S,"createZero",tolua_common_Matrix4_createZero00);
   tolua_function(tolua_S,"createTRS",tolua_common_Matrix4_createTRS00);
   tolua_function(tolua_S,"mulScalar",tolua_common_Matrix4_mulScalar00);
   tolua_function(tolua_S,"mul",tolua_common_Matrix4_mul00);
   tolua_function(tolua_S,"getUpVector",tolua_common_Matrix4_getUpVector00);
   tolua_function(tolua_S,"getDownVector",tolua_common_Matrix4_getDownVector00);
   tolua_function(tolua_S,"getLeftVector",tolua_common_Matrix4_getLeftVector00);
   tolua_function(tolua_S,"getRightVector",tolua_common_Matrix4_getRightVector00);
   tolua_function(tolua_S,"getForwardVector",tolua_common_Matrix4_getForwardVector00);
   tolua_function(tolua_S,"getBackVector",tolua_common_Matrix4_getBackVector00);
   tolua_function(tolua_S,"getTranslation",tolua_common_Matrix4_getTranslation00);
   tolua_function(tolua_S,"getScale",tolua_common_Matrix4_getScale00);
   tolua_function(tolua_S,"getRotationQuaternion",tolua_common_Matrix4_getRotationQuaternion00);
   tolua_function(tolua_S,"inverse",tolua_common_Matrix4_inverse00);
   tolua_function(tolua_S,"transpose",tolua_common_Matrix4_transpose00);
   tolua_function(tolua_S,"negate",tolua_common_Matrix4_negate00);
   tolua_function(tolua_S,"equals",tolua_common_Matrix4_equals00);
   tolua_function(tolua_S,"isZero",tolua_common_Matrix4_isZero00);
   tolua_function(tolua_S,"isIdentity",tolua_common_Matrix4_isIdentity00);
   tolua_function(tolua_S,".eq",tolua_common_Matrix4__eq00);
   tolua_function(tolua_S,".mul",tolua_common_Matrix4__mul00);
   tolua_function(tolua_S,".mul",tolua_common_Matrix4__mul01);
   tolua_function(tolua_S,"set",tolua_common_Matrix4_set00);
   tolua_function(tolua_S,"set",tolua_common_Matrix4_set01);
   tolua_function(tolua_S,"setIdentity",tolua_common_Matrix4_setIdentity00);
   tolua_function(tolua_S,"setZero",tolua_common_Matrix4_setZero00);
   tolua_function(tolua_S,"setLookAt",tolua_common_Matrix4_setLookAt00);
   tolua_function(tolua_S,"setPerspective",tolua_common_Matrix4_setPerspective00);
   tolua_function(tolua_S,"setOrth",tolua_common_Matrix4_setOrth00);
   tolua_function(tolua_S,"setTRS",tolua_common_Matrix4_setTRS00);
   tolua_function(tolua_S,"makeTranslation",tolua_common_Matrix4_makeTranslation00);
   tolua_function(tolua_S,"makeTranslation",tolua_common_Matrix4_makeTranslation01);
   tolua_function(tolua_S,"makeScale",tolua_common_Matrix4_makeScale00);
   tolua_function(tolua_S,"makeScale",tolua_common_Matrix4_makeScale01);
   tolua_function(tolua_S,"makeRotationX",tolua_common_Matrix4_makeRotationX00);
   tolua_function(tolua_S,"makeRotationY",tolua_common_Matrix4_makeRotationY00);
   tolua_function(tolua_S,"makeRotationZ",tolua_common_Matrix4_makeRotationZ00);
   tolua_function(tolua_S,"makeRotationAxisAngle",tolua_common_Matrix4_makeRotationAxisAngle00);
   tolua_function(tolua_S,"makeRotationAxisAngle",tolua_common_Matrix4_makeRotationAxisAngle01);
   tolua_function(tolua_S,"makeRotationEulerAngles",tolua_common_Matrix4_makeRotationEulerAngles00);
   tolua_function(tolua_S,"makeRotationEulerAngles",tolua_common_Matrix4_makeRotationEulerAngles01);
   tolua_function(tolua_S,"makeRotationQuaternion",tolua_common_Matrix4_makeRotationQuaternion00);
   tolua_function(tolua_S,"getUpVector",tolua_common_Matrix4_getUpVector01);
   tolua_function(tolua_S,"getDownVector",tolua_common_Matrix4_getDownVector01);
   tolua_function(tolua_S,"getLeftVector",tolua_common_Matrix4_getLeftVector01);
   tolua_function(tolua_S,"getRightVector",tolua_common_Matrix4_getRightVector01);
   tolua_function(tolua_S,"getForwardVector",tolua_common_Matrix4_getForwardVector01);
   tolua_function(tolua_S,"getBackVector",tolua_common_Matrix4_getBackVector01);
   tolua_function(tolua_S,"setTranslation",tolua_common_Matrix4_setTranslation00);
   tolua_function(tolua_S,"setTranslation",tolua_common_Matrix4_setTranslation01);
   tolua_function(tolua_S,"getTranslation",tolua_common_Matrix4_getTranslation01);
   tolua_function(tolua_S,"getScale",tolua_common_Matrix4_getScale01);
   tolua_function(tolua_S,"getRotationQuaternion",tolua_common_Matrix4_getRotationQuaternion01);
   tolua_function(tolua_S,"inverse",tolua_common_Matrix4_inverse01);
   tolua_function(tolua_S,"transpose",tolua_common_Matrix4_transpose01);
   tolua_function(tolua_S,"negate",tolua_common_Matrix4_negate01);
   tolua_function(tolua_S,"getInversed",tolua_common_Matrix4_getInversed00);
   tolua_function(tolua_S,"getTransposed",tolua_common_Matrix4_getTransposed00);
   tolua_function(tolua_S,"getNegated",tolua_common_Matrix4_getNegated00);
   tolua_function(tolua_S,"determinant",tolua_common_Matrix4_determinant00);
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
   tolua_variable(tolua_S,"Identity",tolua_get_Quaternion_Identity,NULL);
   tolua_variable(tolua_S,"Zero",tolua_get_Quaternion_Zero,NULL);
   tolua_variable(tolua_S,"var",tolua_get_Quaternion_var,tolua_set_Quaternion_var);
   tolua_function(tolua_S,"new",tolua_common_Quaternion_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Quaternion_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Quaternion_new00_local);
   tolua_function(tolua_S,"new",tolua_common_Quaternion_new01);
   tolua_function(tolua_S,"new_local",tolua_common_Quaternion_new01_local);
   tolua_function(tolua_S,".call",tolua_common_Quaternion_new01_local);
   tolua_function(tolua_S,"new",tolua_common_Quaternion_new02);
   tolua_function(tolua_S,"new_local",tolua_common_Quaternion_new02_local);
   tolua_function(tolua_S,".call",tolua_common_Quaternion_new02_local);
   tolua_function(tolua_S,"delete",tolua_common_Quaternion_delete00);
   tolua_function(tolua_S,"createIdentity",tolua_common_Quaternion_createIdentity00);
   tolua_function(tolua_S,"createZero",tolua_common_Quaternion_createZero00);
   tolua_function(tolua_S,"createRotationX",tolua_common_Quaternion_createRotationX00);
   tolua_function(tolua_S,"createRotationY",tolua_common_Quaternion_createRotationY00);
   tolua_function(tolua_S,"createRotationZ",tolua_common_Quaternion_createRotationZ00);
   tolua_function(tolua_S,"createFromAxisAngle",tolua_common_Quaternion_createFromAxisAngle00);
   tolua_function(tolua_S,"createFromAxisAngle",tolua_common_Quaternion_createFromAxisAngle01);
   tolua_function(tolua_S,"createFromEulerAngles",tolua_common_Quaternion_createFromEulerAngles00);
   tolua_function(tolua_S,"createFromEulerAngles",tolua_common_Quaternion_createFromEulerAngles01);
   tolua_function(tolua_S,"add",tolua_common_Quaternion_add00);
   tolua_function(tolua_S,"sub",tolua_common_Quaternion_sub00);
   tolua_function(tolua_S,"mul",tolua_common_Quaternion_mul00);
   tolua_function(tolua_S,"mulVector3",tolua_common_Quaternion_mulVector300);
   tolua_function(tolua_S,"mulScalar",tolua_common_Quaternion_mulScalar00);
   tolua_function(tolua_S,"normalize",tolua_common_Quaternion_normalize00);
   tolua_function(tolua_S,"conjugate",tolua_common_Quaternion_conjugate00);
   tolua_function(tolua_S,"negate",tolua_common_Quaternion_negate00);
   tolua_function(tolua_S,"inverse",tolua_common_Quaternion_inverse00);
   tolua_function(tolua_S,"equals",tolua_common_Quaternion_equals00);
   tolua_function(tolua_S,"isIdentity",tolua_common_Quaternion_isIdentity00);
   tolua_function(tolua_S,"isZero",tolua_common_Quaternion_isZero00);
   tolua_function(tolua_S,"isNormalized",tolua_common_Quaternion_isNormalized00);
   tolua_function(tolua_S,".eq",tolua_common_Quaternion__eq00);
   tolua_function(tolua_S,".add",tolua_common_Quaternion__add00);
   tolua_function(tolua_S,".sub",tolua_common_Quaternion__sub00);
   tolua_function(tolua_S,".mul",tolua_common_Quaternion__mul00);
   tolua_function(tolua_S,".mul",tolua_common_Quaternion__mul01);
   tolua_function(tolua_S,".mul",tolua_common_Quaternion__mul02);
   tolua_function(tolua_S,"set",tolua_common_Quaternion_set00);
   tolua_function(tolua_S,"setIdentity",tolua_common_Quaternion_setIdentity00);
   tolua_function(tolua_S,"setZero",tolua_common_Quaternion_setZero00);
   tolua_function(tolua_S,"setScalars",tolua_common_Quaternion_setScalars00);
   tolua_function(tolua_S,"setRotationX",tolua_common_Quaternion_setRotationX00);
   tolua_function(tolua_S,"setRotationY",tolua_common_Quaternion_setRotationY00);
   tolua_function(tolua_S,"setRotationZ",tolua_common_Quaternion_setRotationZ00);
   tolua_function(tolua_S,"fromAxisAngle",tolua_common_Quaternion_fromAxisAngle00);
   tolua_function(tolua_S,"fromAxisAngle",tolua_common_Quaternion_fromAxisAngle01);
   tolua_function(tolua_S,"toAxisAngle",tolua_common_Quaternion_toAxisAngle00);
   tolua_function(tolua_S,"fromEulerAngles",tolua_common_Quaternion_fromEulerAngles00);
   tolua_function(tolua_S,"fromEulerAngles",tolua_common_Quaternion_fromEulerAngles01);
   tolua_function(tolua_S,"toEulerAngles",tolua_common_Quaternion_toEulerAngles00);
   tolua_function(tolua_S,"normalize",tolua_common_Quaternion_normalize01);
   tolua_function(tolua_S,"conjugate",tolua_common_Quaternion_conjugate01);
   tolua_function(tolua_S,"negate",tolua_common_Quaternion_negate01);
   tolua_function(tolua_S,"inverse",tolua_common_Quaternion_inverse01);
   tolua_function(tolua_S,"getNormalized",tolua_common_Quaternion_getNormalized00);
   tolua_function(tolua_S,"getConjugated",tolua_common_Quaternion_getConjugated00);
   tolua_function(tolua_S,"getNegated",tolua_common_Quaternion_getNegated00);
   tolua_function(tolua_S,"getInversed",tolua_common_Quaternion_getInversed00);
   tolua_function(tolua_S,"dot",tolua_common_Quaternion_dot00);
   tolua_function(tolua_S,"length",tolua_common_Quaternion_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_Quaternion_lengthSq00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vector2","Vector2","",tolua_collect_Vector2);
  #else
  tolua_cclass(tolua_S,"Vector2","Vector2","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vector2");
   tolua_variable(tolua_S,"x",tolua_get_Vector2_x,tolua_set_Vector2_x);
   tolua_variable(tolua_S,"y",tolua_get_Vector2_y,tolua_set_Vector2_y);
   tolua_variable(tolua_S,"Zero",tolua_get_Vector2_Zero,NULL);
   tolua_variable(tolua_S,"One",tolua_get_Vector2_One,NULL);
   tolua_variable(tolua_S,"Right",tolua_get_Vector2_Right,NULL);
   tolua_variable(tolua_S,"Left",tolua_get_Vector2_Left,NULL);
   tolua_variable(tolua_S,"Up",tolua_get_Vector2_Up,NULL);
   tolua_variable(tolua_S,"Down",tolua_get_Vector2_Down,NULL);
   tolua_variable(tolua_S,"var",tolua_get_Vector2_var,tolua_set_Vector2_var);
   tolua_function(tolua_S,"new",tolua_common_Vector2_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Vector2_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Vector2_new00_local);
   tolua_function(tolua_S,"new",tolua_common_Vector2_new01);
   tolua_function(tolua_S,"new_local",tolua_common_Vector2_new01_local);
   tolua_function(tolua_S,".call",tolua_common_Vector2_new01_local);
   tolua_function(tolua_S,"new",tolua_common_Vector2_new02);
   tolua_function(tolua_S,"new_local",tolua_common_Vector2_new02_local);
   tolua_function(tolua_S,".call",tolua_common_Vector2_new02_local);
   tolua_function(tolua_S,"delete",tolua_common_Vector2_delete00);
   tolua_function(tolua_S,"createZero",tolua_common_Vector2_createZero00);
   tolua_function(tolua_S,"createOne",tolua_common_Vector2_createOne00);
   tolua_function(tolua_S,"createFromVector3",tolua_common_Vector2_createFromVector300);
   tolua_function(tolua_S,"createFromVector4",tolua_common_Vector2_createFromVector400);
   tolua_function(tolua_S,"addScalar",tolua_common_Vector2_addScalar00);
   tolua_function(tolua_S,"add",tolua_common_Vector2_add00);
   tolua_function(tolua_S,"subScalar",tolua_common_Vector2_subScalar00);
   tolua_function(tolua_S,"sub",tolua_common_Vector2_sub00);
   tolua_function(tolua_S,"mulScalar",tolua_common_Vector2_mulScalar00);
   tolua_function(tolua_S,"mul",tolua_common_Vector2_mul00);
   tolua_function(tolua_S,"divScalar",tolua_common_Vector2_divScalar00);
   tolua_function(tolua_S,"div",tolua_common_Vector2_div00);
   tolua_function(tolua_S,"clamp",tolua_common_Vector2_clamp00);
   tolua_function(tolua_S,"negate",tolua_common_Vector2_negate00);
   tolua_function(tolua_S,"normalize",tolua_common_Vector2_normalize00);
   tolua_function(tolua_S,"rotate",tolua_common_Vector2_rotate00);
   tolua_function(tolua_S,"scale",tolua_common_Vector2_scale00);
   tolua_function(tolua_S,"midPointBetween",tolua_common_Vector2_midPointBetween00);
   tolua_function(tolua_S,"project",tolua_common_Vector2_project00);
   tolua_function(tolua_S,"equals",tolua_common_Vector2_equals00);
   tolua_function(tolua_S,"isZero",tolua_common_Vector2_isZero00);
   tolua_function(tolua_S,"isOne",tolua_common_Vector2_isOne00);
   tolua_function(tolua_S,"isNormalized",tolua_common_Vector2_isNormalized00);
   tolua_function(tolua_S,".eq",tolua_common_Vector2__eq00);
   tolua_function(tolua_S,".add",tolua_common_Vector2__add00);
   tolua_function(tolua_S,".add",tolua_common_Vector2__add01);
   tolua_function(tolua_S,".add",tolua_common_Vector2__add02);
   tolua_function(tolua_S,".sub",tolua_common_Vector2__sub00);
   tolua_function(tolua_S,".sub",tolua_common_Vector2__sub01);
   tolua_function(tolua_S,".sub",tolua_common_Vector2__sub02);
   tolua_function(tolua_S,".mul",tolua_common_Vector2__mul00);
   tolua_function(tolua_S,".mul",tolua_common_Vector2__mul01);
   tolua_function(tolua_S,".div",tolua_common_Vector2__div00);
   tolua_function(tolua_S,".div",tolua_common_Vector2__div01);
   tolua_function(tolua_S,"set",tolua_common_Vector2_set00);
   tolua_function(tolua_S,"setZero",tolua_common_Vector2_setZero00);
   tolua_function(tolua_S,"setOne",tolua_common_Vector2_setOne00);
   tolua_function(tolua_S,"setScalars",tolua_common_Vector2_setScalars00);
   tolua_function(tolua_S,"fromVector3",tolua_common_Vector2_fromVector300);
   tolua_function(tolua_S,"fromVector4",tolua_common_Vector2_fromVector400);
   tolua_function(tolua_S,"clamp",tolua_common_Vector2_clamp01);
   tolua_function(tolua_S,"negate",tolua_common_Vector2_negate01);
   tolua_function(tolua_S,"normalize",tolua_common_Vector2_normalize01);
   tolua_function(tolua_S,"rotate",tolua_common_Vector2_rotate01);
   tolua_function(tolua_S,"scale",tolua_common_Vector2_scale01);
   tolua_function(tolua_S,"getClamped",tolua_common_Vector2_getClamped00);
   tolua_function(tolua_S,"getNegated",tolua_common_Vector2_getNegated00);
   tolua_function(tolua_S,"getNormalized",tolua_common_Vector2_getNormalized00);
   tolua_function(tolua_S,"getRotated",tolua_common_Vector2_getRotated00);
   tolua_function(tolua_S,"getScaled",tolua_common_Vector2_getScaled00);
   tolua_function(tolua_S,"dot",tolua_common_Vector2_dot00);
   tolua_function(tolua_S,"cross",tolua_common_Vector2_cross00);
   tolua_function(tolua_S,"distanceBetween",tolua_common_Vector2_distanceBetween00);
   tolua_function(tolua_S,"distanceBetweenSq",tolua_common_Vector2_distanceBetweenSq00);
   tolua_function(tolua_S,"length",tolua_common_Vector2_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_Vector2_lengthSq00);
   tolua_function(tolua_S,"angleBetween",tolua_common_Vector2_angleBetween00);
   tolua_function(tolua_S,"midPointBetween",tolua_common_Vector2_midPointBetween01);
   tolua_function(tolua_S,"project",tolua_common_Vector2_project01);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vector3","Vector3","",tolua_collect_Vector3);
  #else
  tolua_cclass(tolua_S,"Vector3","Vector3","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vector3");
   tolua_variable(tolua_S,"x",tolua_get_Vector3_x,tolua_set_Vector3_x);
   tolua_variable(tolua_S,"y",tolua_get_Vector3_y,tolua_set_Vector3_y);
   tolua_variable(tolua_S,"z",tolua_get_Vector3_z,tolua_set_Vector3_z);
   tolua_variable(tolua_S,"Zero",tolua_get_Vector3_Zero,NULL);
   tolua_variable(tolua_S,"One",tolua_get_Vector3_One,NULL);
   tolua_variable(tolua_S,"Up",tolua_get_Vector3_Up,NULL);
   tolua_variable(tolua_S,"Down",tolua_get_Vector3_Down,NULL);
   tolua_variable(tolua_S,"Right",tolua_get_Vector3_Right,NULL);
   tolua_variable(tolua_S,"Left",tolua_get_Vector3_Left,NULL);
   tolua_variable(tolua_S,"Forward",tolua_get_Vector3_Forward,NULL);
   tolua_variable(tolua_S,"Back",tolua_get_Vector3_Back,NULL);
   tolua_variable(tolua_S,"var",tolua_get_Vector3_var,tolua_set_Vector3_var);
   tolua_function(tolua_S,"new",tolua_common_Vector3_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Vector3_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Vector3_new00_local);
   tolua_function(tolua_S,"new",tolua_common_Vector3_new01);
   tolua_function(tolua_S,"new_local",tolua_common_Vector3_new01_local);
   tolua_function(tolua_S,".call",tolua_common_Vector3_new01_local);
   tolua_function(tolua_S,"new",tolua_common_Vector3_new02);
   tolua_function(tolua_S,"new_local",tolua_common_Vector3_new02_local);
   tolua_function(tolua_S,".call",tolua_common_Vector3_new02_local);
   tolua_function(tolua_S,"delete",tolua_common_Vector3_delete00);
   tolua_function(tolua_S,"createZero",tolua_common_Vector3_createZero00);
   tolua_function(tolua_S,"createOne",tolua_common_Vector3_createOne00);
   tolua_function(tolua_S,"createFromVector2",tolua_common_Vector3_createFromVector200);
   tolua_function(tolua_S,"createFromVector4",tolua_common_Vector3_createFromVector400);
   tolua_function(tolua_S,"addScalar",tolua_common_Vector3_addScalar00);
   tolua_function(tolua_S,"add",tolua_common_Vector3_add00);
   tolua_function(tolua_S,"subScalar",tolua_common_Vector3_subScalar00);
   tolua_function(tolua_S,"sub",tolua_common_Vector3_sub00);
   tolua_function(tolua_S,"mulMatrix4",tolua_common_Vector3_mulMatrix400);
   tolua_function(tolua_S,"mulScalar",tolua_common_Vector3_mulScalar00);
   tolua_function(tolua_S,"mul",tolua_common_Vector3_mul00);
   tolua_function(tolua_S,"divScalar",tolua_common_Vector3_divScalar00);
   tolua_function(tolua_S,"div",tolua_common_Vector3_div00);
   tolua_function(tolua_S,"cross",tolua_common_Vector3_cross00);
   tolua_function(tolua_S,"clamp",tolua_common_Vector3_clamp00);
   tolua_function(tolua_S,"negate",tolua_common_Vector3_negate00);
   tolua_function(tolua_S,"normalize",tolua_common_Vector3_normalize00);
   tolua_function(tolua_S,"scale",tolua_common_Vector3_scale00);
   tolua_function(tolua_S,"midPointBetween",tolua_common_Vector3_midPointBetween00);
   tolua_function(tolua_S,"project",tolua_common_Vector3_project00);
   tolua_function(tolua_S,"equals",tolua_common_Vector3_equals00);
   tolua_function(tolua_S,"isZero",tolua_common_Vector3_isZero00);
   tolua_function(tolua_S,"isOne",tolua_common_Vector3_isOne00);
   tolua_function(tolua_S,"isNormalized",tolua_common_Vector3_isNormalized00);
   tolua_function(tolua_S,".eq",tolua_common_Vector3__eq00);
   tolua_function(tolua_S,".add",tolua_common_Vector3__add00);
   tolua_function(tolua_S,".add",tolua_common_Vector3__add01);
   tolua_function(tolua_S,".add",tolua_common_Vector3__add02);
   tolua_function(tolua_S,".sub",tolua_common_Vector3__sub00);
   tolua_function(tolua_S,".sub",tolua_common_Vector3__sub01);
   tolua_function(tolua_S,".sub",tolua_common_Vector3__sub02);
   tolua_function(tolua_S,".mul",tolua_common_Vector3__mul00);
   tolua_function(tolua_S,".mul",tolua_common_Vector3__mul01);
   tolua_function(tolua_S,".mul",tolua_common_Vector3__mul02);
   tolua_function(tolua_S,".div",tolua_common_Vector3__div00);
   tolua_function(tolua_S,".div",tolua_common_Vector3__div01);
   tolua_function(tolua_S,"set",tolua_common_Vector3_set00);
   tolua_function(tolua_S,"setZero",tolua_common_Vector3_setZero00);
   tolua_function(tolua_S,"setOne",tolua_common_Vector3_setOne00);
   tolua_function(tolua_S,"setScalars",tolua_common_Vector3_setScalars00);
   tolua_function(tolua_S,"fromVector2",tolua_common_Vector3_fromVector200);
   tolua_function(tolua_S,"fromVector4",tolua_common_Vector3_fromVector400);
   tolua_function(tolua_S,"clamp",tolua_common_Vector3_clamp01);
   tolua_function(tolua_S,"negate",tolua_common_Vector3_negate01);
   tolua_function(tolua_S,"normalize",tolua_common_Vector3_normalize01);
   tolua_function(tolua_S,"scale",tolua_common_Vector3_scale01);
   tolua_function(tolua_S,"getClamped",tolua_common_Vector3_getClamped00);
   tolua_function(tolua_S,"getNegated",tolua_common_Vector3_getNegated00);
   tolua_function(tolua_S,"getNormalized",tolua_common_Vector3_getNormalized00);
   tolua_function(tolua_S,"getScaled",tolua_common_Vector3_getScaled00);
   tolua_function(tolua_S,"dot",tolua_common_Vector3_dot00);
   tolua_function(tolua_S,"distanceBetween",tolua_common_Vector3_distanceBetween00);
   tolua_function(tolua_S,"distanceBetweenSq",tolua_common_Vector3_distanceBetweenSq00);
   tolua_function(tolua_S,"length",tolua_common_Vector3_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_Vector3_lengthSq00);
   tolua_function(tolua_S,"angleBetween",tolua_common_Vector3_angleBetween00);
   tolua_function(tolua_S,"cross",tolua_common_Vector3_cross01);
   tolua_function(tolua_S,"midPointBetween",tolua_common_Vector3_midPointBetween01);
   tolua_function(tolua_S,"project",tolua_common_Vector3_project01);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Vector4","Vector4","",tolua_collect_Vector4);
  #else
  tolua_cclass(tolua_S,"Vector4","Vector4","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Vector4");
   tolua_variable(tolua_S,"x",tolua_get_Vector4_x,tolua_set_Vector4_x);
   tolua_variable(tolua_S,"y",tolua_get_Vector4_y,tolua_set_Vector4_y);
   tolua_variable(tolua_S,"z",tolua_get_Vector4_z,tolua_set_Vector4_z);
   tolua_variable(tolua_S,"w",tolua_get_Vector4_w,tolua_set_Vector4_w);
   tolua_variable(tolua_S,"Zero",tolua_get_Vector4_Zero,NULL);
   tolua_variable(tolua_S,"One",tolua_get_Vector4_One,NULL);
   tolua_variable(tolua_S,"Up",tolua_get_Vector4_Up,NULL);
   tolua_variable(tolua_S,"Down",tolua_get_Vector4_Down,NULL);
   tolua_variable(tolua_S,"Right",tolua_get_Vector4_Right,NULL);
   tolua_variable(tolua_S,"Left",tolua_get_Vector4_Left,NULL);
   tolua_variable(tolua_S,"Forward",tolua_get_Vector4_Forward,NULL);
   tolua_variable(tolua_S,"Back",tolua_get_Vector4_Back,NULL);
   tolua_variable(tolua_S,"Space0",tolua_get_Vector4_Space0,NULL);
   tolua_variable(tolua_S,"Space1",tolua_get_Vector4_Space1,NULL);
   tolua_variable(tolua_S,"Space2",tolua_get_Vector4_Space2,NULL);
   tolua_variable(tolua_S,"var",tolua_get_Vector4_var,tolua_set_Vector4_var);
   tolua_function(tolua_S,"new",tolua_common_Vector4_new00);
   tolua_function(tolua_S,"new_local",tolua_common_Vector4_new00_local);
   tolua_function(tolua_S,".call",tolua_common_Vector4_new00_local);
   tolua_function(tolua_S,"new",tolua_common_Vector4_new01);
   tolua_function(tolua_S,"new_local",tolua_common_Vector4_new01_local);
   tolua_function(tolua_S,".call",tolua_common_Vector4_new01_local);
   tolua_function(tolua_S,"new",tolua_common_Vector4_new02);
   tolua_function(tolua_S,"new_local",tolua_common_Vector4_new02_local);
   tolua_function(tolua_S,".call",tolua_common_Vector4_new02_local);
   tolua_function(tolua_S,"delete",tolua_common_Vector4_delete00);
   tolua_function(tolua_S,"createZero",tolua_common_Vector4_createZero00);
   tolua_function(tolua_S,"createOne",tolua_common_Vector4_createOne00);
   tolua_function(tolua_S,"createFromVector2",tolua_common_Vector4_createFromVector200);
   tolua_function(tolua_S,"createFromVector3",tolua_common_Vector4_createFromVector300);
   tolua_function(tolua_S,"addScalar",tolua_common_Vector4_addScalar00);
   tolua_function(tolua_S,"add",tolua_common_Vector4_add00);
   tolua_function(tolua_S,"subScalar",tolua_common_Vector4_subScalar00);
   tolua_function(tolua_S,"sub",tolua_common_Vector4_sub00);
   tolua_function(tolua_S,"mulMatrix4",tolua_common_Vector4_mulMatrix400);
   tolua_function(tolua_S,"mulScalar",tolua_common_Vector4_mulScalar00);
   tolua_function(tolua_S,"mul",tolua_common_Vector4_mul00);
   tolua_function(tolua_S,"divScalar",tolua_common_Vector4_divScalar00);
   tolua_function(tolua_S,"div",tolua_common_Vector4_div00);
   tolua_function(tolua_S,"clamp",tolua_common_Vector4_clamp00);
   tolua_function(tolua_S,"negate",tolua_common_Vector4_negate00);
   tolua_function(tolua_S,"normalize",tolua_common_Vector4_normalize00);
   tolua_function(tolua_S,"scale",tolua_common_Vector4_scale00);
   tolua_function(tolua_S,"midPointBetween",tolua_common_Vector4_midPointBetween00);
   tolua_function(tolua_S,"project",tolua_common_Vector4_project00);
   tolua_function(tolua_S,"equals",tolua_common_Vector4_equals00);
   tolua_function(tolua_S,"isZero",tolua_common_Vector4_isZero00);
   tolua_function(tolua_S,"isOne",tolua_common_Vector4_isOne00);
   tolua_function(tolua_S,"isNormalized",tolua_common_Vector4_isNormalized00);
   tolua_function(tolua_S,".eq",tolua_common_Vector4__eq00);
   tolua_function(tolua_S,".add",tolua_common_Vector4__add00);
   tolua_function(tolua_S,".add",tolua_common_Vector4__add01);
   tolua_function(tolua_S,".add",tolua_common_Vector4__add02);
   tolua_function(tolua_S,".sub",tolua_common_Vector4__sub00);
   tolua_function(tolua_S,".sub",tolua_common_Vector4__sub01);
   tolua_function(tolua_S,".sub",tolua_common_Vector4__sub02);
   tolua_function(tolua_S,".mul",tolua_common_Vector4__mul00);
   tolua_function(tolua_S,".mul",tolua_common_Vector4__mul01);
   tolua_function(tolua_S,".mul",tolua_common_Vector4__mul02);
   tolua_function(tolua_S,".div",tolua_common_Vector4__div00);
   tolua_function(tolua_S,".div",tolua_common_Vector4__div01);
   tolua_function(tolua_S,"set",tolua_common_Vector4_set00);
   tolua_function(tolua_S,"setZero",tolua_common_Vector4_setZero00);
   tolua_function(tolua_S,"setOne",tolua_common_Vector4_setOne00);
   tolua_function(tolua_S,"setScalars",tolua_common_Vector4_setScalars00);
   tolua_function(tolua_S,"fromVector2",tolua_common_Vector4_fromVector200);
   tolua_function(tolua_S,"fromVector3",tolua_common_Vector4_fromVector300);
   tolua_function(tolua_S,"clamp",tolua_common_Vector4_clamp01);
   tolua_function(tolua_S,"negate",tolua_common_Vector4_negate01);
   tolua_function(tolua_S,"normalize",tolua_common_Vector4_normalize01);
   tolua_function(tolua_S,"scale",tolua_common_Vector4_scale01);
   tolua_function(tolua_S,"getClamped",tolua_common_Vector4_getClamped00);
   tolua_function(tolua_S,"getNegated",tolua_common_Vector4_getNegated00);
   tolua_function(tolua_S,"getNormalized",tolua_common_Vector4_getNormalized00);
   tolua_function(tolua_S,"getScaled",tolua_common_Vector4_getScaled00);
   tolua_function(tolua_S,"dot",tolua_common_Vector4_dot00);
   tolua_function(tolua_S,"distanceBetween",tolua_common_Vector4_distanceBetween00);
   tolua_function(tolua_S,"distanceBetweenSq",tolua_common_Vector4_distanceBetweenSq00);
   tolua_function(tolua_S,"length",tolua_common_Vector4_length00);
   tolua_function(tolua_S,"lengthSq",tolua_common_Vector4_lengthSq00);
   tolua_function(tolua_S,"angleBetween",tolua_common_Vector4_angleBetween00);
   tolua_function(tolua_S,"midPointBetween",tolua_common_Vector4_midPointBetween01);
   tolua_function(tolua_S,"project",tolua_common_Vector4_project01);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_common (lua_State* tolua_S) {
 return tolua_common_open(tolua_S);
};
#endif

