#ifndef FT_INCLUDED_ABI_H
#define FT_INCLUDED_ABI_H 1

/* C++ support */
#if defined(__cplusplus)
# define FT_ABI_EXTERN extern "C"
#else
# define FT_ABI_EXTERN
#endif

/* DLL support */
#if defined(WIN32) || defined(_WIN32)
# if defined(FT_STATIC)
#  define FT_ABI_DECLSPEC
# elif defined(FT_DLL)
#  define FT_ABI_DECLSPEC __declspec(dllexport)
# else
#  define FT_ABI_DECLSPEC __declspec(dllimport)
# endif
#else
# define FT_ABI_DECLSPEC
#endif

/* Visibility */
#if defined(__GNUC__) || defined(__clang__)
# define FT_PUBLIC __attribute__ ((visibility("default")))
#else
# define FT_PUBLIC
#endif

#define FT_ABI FT_ABI_DECLSPEC FT_ABI_EXTERN
#define FT_API FT_PUBLIC FT_ABI

#endif
