SECTION .text

EXTERN ftCoCurrent
EXTERN ft_CoSetCurrent

GLOBAL ft_ArchCoFirstRun
GLOBAL ftCoSwitch

%ifdef WIN32
%define ARG0   rcx
%else
%define ARG0   rdi
%endif

ft_ArchCoFirstRun:
    call    ftCoCurrent
    mov     ARG0, [rax + 0x8]
    jmp     [rax]

ftCoSwitch:
    ; Fetch the current coroutine
    call    ftCoCurrent

    ; Save registers
    lea     rcx, [REL .switch_ret]
    mov     [rax + 0x10], rcx
    mov     [rax + 0x18], rsp
    mov     [rax + 0x20], rbp
    mov     [rax + 0x28], rbx
    mov     [rax + 0x30], r12
    mov     [rax + 0x38], r13
    mov     [rax + 0x40], r14
    mov     [rax + 0x48], r15

%ifdef WIN32
    mov     [rax + 0x50], rdi
    mov     [rax + 0x58], rsi
    movaps  [rax + 0x60], xmm6
    movaps  [rax + 0x70], xmm7
    movaps  [rax + 0x80], xmm8
    movaps  [rax + 0x90], xmm9
    movaps  [rax + 0x100], xmm10
    movaps  [rax + 0x110], xmm11
    movaps  [rax + 0x120], xmm12
    movaps  [rax + 0x130], xmm13
    movaps  [rax + 0x140], xmm14
    movaps  [rax + 0x150], xmm15
%endif

    ; Mark the given coroutine as the current one
    mov rbx, ARG0
    call ft_CoSetCurrent

    ; Jump to the next routine
    jmp [rbx + 0x10]

.switch_ret:
    ; Fetch the current coroutine
    call    ftCoCurrent

    ; Restore registers
    mov     rsp, [rax + 0x18]
    mov     rbp, [rax + 0x20]
    mov     rbx, [rax + 0x28]
    mov     r12, [rax + 0x30]
    mov     r13, [rax + 0x38]
    mov     r14, [rax + 0x40]
    mov     r15, [rax + 0x48]

%ifdef WIN32
    mov     rdi,   [rax + 0x50]
    mov     rsi,   [rax + 0x58]
    movaps  xmm6,  [rax + 0x60]
    movaps  xmm7,  [rax + 0x70]
    movaps  xmm8,  [rax + 0x80]
    movaps  xmm9,  [rax + 0x90]
    movaps  xmm10, [rax + 0x100]
    movaps  xmm11, [rax + 0x110]
    movaps  xmm12, [rax + 0x120]
    movaps  xmm13, [rax + 0x130]
    movaps  xmm14, [rax + 0x140]
    movaps  xmm15, [rax + 0x150]
%endif

    ret
