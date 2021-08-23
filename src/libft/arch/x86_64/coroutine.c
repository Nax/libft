#include <libft/libft.h>

void ft_ArchCoCreate(FT_Coroutine* coro, int stacksize, int flags)
{
    uint64_t* retAddrAddr;

    retAddrAddr = (uint64_t*)((char*)coro + sizeof(*coro) + stacksize - 8);
    /* TODO: change this */
    *retAddrAddr = 0;

    coro->ctx.rip = (uint64_t)&ft_ArchCoFirstRun;
    coro->ctx.rsp = (uint64_t)retAddrAddr;
}
