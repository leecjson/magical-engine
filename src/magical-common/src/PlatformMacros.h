#ifndef __PLATFORM_MACROS_H__
#define __PLATFORM_MACROS_H__

/*
MAG_DEBUG
*/

/*
MAG_WIN32
MAG_ANDROID
MAG_IOS
MAG_LINUX
MAG_MAC
*/

#if defined( MAG_WIN32 ) && !defined( __cplusplus )
#define inline __inline
#endif

#if !defined( __cplusplus )
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif
#endif

#if !defined( MAGAPI )
#define MAGAPI extern
#define MAGAPI_INLINE static inline
#endif

#if !defined( MAGGLOBAL )
#define MAGGLOBAL
#endif

#if !defined( MAGCONST )
#define MAGCONST static const
#endif

#endif //__PLATFORM_MACROS_H__