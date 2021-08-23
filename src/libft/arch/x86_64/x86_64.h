#ifndef LIBFT_INCLUDED_ARCH_X86_64_H
#define LIBFT_INCLUDED_ARCH_X86_64_H

#include <stdint.h>

#define ARCH_STACK_ALIGN    16

#pragma pack(push, 1)
typedef struct
{
    uint64_t rip;
    uint64_t rsp;
    uint64_t rbp;
    uint64_t rbx;
    uint64_t r12;
    uint64_t r13;
    uint64_t r14;
    uint64_t r15;
} FT_FiberContext;
#pragma pack(pop)

#endif
