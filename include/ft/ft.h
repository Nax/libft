#ifndef FT_INCLUDED_FT_H
#define FT_INCLUDED_FT_H 1

#include <ft/abi.h>

/* Coroutines */
typedef void (*FT_CoroutineEntry)(void*);
typedef struct FT_Coroutine FT_Coroutine;

FT_API void          ftCoThreadInit(void);
FT_API FT_Coroutine* ftCoThreadRoutine(void);
FT_API FT_Coroutine* ftCoCreate(FT_CoroutineEntry entry, void* arg, int stacksize, int flags);
FT_API void          ftCoDestroy(FT_Coroutine* coro);
FT_API FT_Coroutine* ftCoCurrent(void);
FT_API void          ftCoSwitch(FT_Coroutine* coro);
FT_API void          ftCoYield(void);

#endif
