#include <stdlib.h>
#include <libft/libft.h>

THREAD_LOCAL FT_CoroutineThreadContext FT_tCoCtx;

FT_API void ftCoThreadInit(void)
{
    FT_tCoCtx.current = &FT_tCoCtx.thread;
}

FT_API FT_Coroutine* ftCoThreadRoutine(void)
{
    return &FT_tCoCtx.thread;
}

FT_ABI FT_Coroutine* ftCoCreate(FT_CoroutineEntry entry, void* arg, int stacksize, int flags)
{
    FT_Coroutine* coro;

    /* Fix the stack size */
    stacksize = ((stacksize + sizeof(FT_Coroutine) + ARCH_STACK_ALIGN - 1) / ARCH_STACK_ALIGN) * ARCH_STACK_ALIGN - sizeof(FT_Coroutine);

    /* Allocate the coroutine */
    coro = calloc(1, sizeof(FT_Coroutine) + stacksize);
    if (!coro)
        return NULL;

    /* Set the coroutine params */
    coro->entry = entry;
    coro->arg = arg;

    ft_ArchCoCreate(coro, stacksize, flags);

    return coro;
}

FT_ABI void ftCoDestroy(FT_Coroutine* coro)
{
    free(coro);
}

FT_ABI FT_Coroutine* ftCoCurrent(void)
{
    return FT_tCoCtx.current;
}

FT_API void ftCoYield(void)
{
    ftCoSwitch(ftCoThreadRoutine());
}

void ft_CoSetCurrent(FT_Coroutine* coro)
{
    FT_tCoCtx.current = coro;
}
