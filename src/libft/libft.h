#ifndef FT_INCLUDED_LIBFT_H
#define FT_INCLUDED_LIBFT_H 1

/* FT API */
#include <ft/ft.h>

/* Compiler macros */
#if defined(_MSC_VER)
# define THREAD_LOCAL __declspec(thread)
#elif defined(__GNUC__) || defined(__clang__)
# define THREAD_LOCAL __thread
#else
# error "Unsupported compiler"
#endif

/* Determine the correct arch */
#if defined(_M_X64) || defined(_M_AMD64) || defined(__amd64__) || defined(__x86_64__)
# include <libft/arch/x86_64/x86_64.h>
#elif defined(_M_IX86) || defined(__x86__) || defined(__i386__)
# include <libft/arch/x86/x86.h>
#else
# error "Unsupported architecture"
#endif

struct FT_Coroutine
{
    FT_CoroutineEntry   entry;
    void*               arg;
    FT_FiberContext     ctx;
};

typedef struct
{
    FT_Coroutine*   current;
    FT_Coroutine    thread;
} FT_CoroutineThreadContext;

extern THREAD_LOCAL FT_CoroutineThreadContext FT_tCoCtx;

void ft_ArchCoCreate(FT_Coroutine* c, int stacksize, int flags);
void ft_ArchCoFirstRun(void);

#endif
