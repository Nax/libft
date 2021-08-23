.section .text

.extern ftCoCurrent
.extern ft_CoSetCurrent

.global ft_ArchCoFirstRun
.global ftCoSwitch

.hidden ft_ArchCoFirstRun
.type ftCoSwitch, @function

ft_ArchCoFirstRun:
    call    ftCoCurrent
    mov     8(%rax), %rdi
    jmp     *0(%rax)

ftCoSwitch:
    /* Fetch the current coroutine */
    call    ftCoCurrent

    /* Save registers */
    lea     ft_CoSwitchRet(%rip), %rcx
    mov     %rcx, 0x10(%rax)
    mov     %rsp, 0x18(%rax)
    mov     %rbp, 0x20(%rax)
    mov     %rbx, 0x28(%rax)
    mov     %r12, 0x30(%rax)
    mov     %r13, 0x38(%rax)
    mov     %r14, 0x40(%rax)
    mov     %r15, 0x48(%rax)

    /* Mark the given coroutine as the current one */
    mov %rdi, %rbx
    call ft_CoSetCurrent

    /* Jump to the next routine */
    jmp *0x10(%rbx)

ft_CoSwitchRet:
    /* Fetch the current coroutine */
    call    ftCoCurrent

    /* Restore registers */
    mov     0x18(%rax), %rsp
    mov     0x20(%rax), %rbp
    mov     0x28(%rax), %rbx
    mov     0x30(%rax), %r12
    mov     0x38(%rax), %r13
    mov     0x40(%rax), %r14
    mov     0x48(%rax), %r15

    retq
