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
#if defined(WIN32) || defined(_WIN32)
    uint64_t rdi;
    uint64_t rsi;
    uint8_t  xmm6[16];
    uint8_t  xmm7[16];
    uint8_t  xmm8[16];
    uint8_t  xmm9[16];
    uint8_t  xmm10[16];
    uint8_t  xmm11[16];
    uint8_t  xmm12[16];
    uint8_t  xmm13[16];
    uint8_t  xmm14[16];
    uint8_t  xmm15[16];
#endif
} FT_CoroutineContext;
#pragma pack(pop)

#endif
