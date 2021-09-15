section .text

global strpbrk:function

strpbrk:
    xor rax, rax
    xor rdx, rdx
    xor rcx, rcx
    cmp BYTE[rdi], 0x00
    je .end2
    cmp BYTE[rsi], 0x00
    je .end2
    jmp .loop_first

.inc_first_loop:
    xor rcx, rcx
    inc rdi
    jmp .loop_first

.loop_second:
    inc rcx
    mov r9b, BYTE[rsi + rcx]
    cmp r8b, r9b
    je .end
    cmp r9b, 0x00
    je .inc_first_loop
    jmp .loop_second


.loop_first:
    mov r8b, BYTE[rdi]
    mov r9b, BYTE[rsi + rcx]
    cmp r8b, r9b
    je .end
    cmp r8b, 0x00
    je .end2
    jmp .loop_second


.end2:
    xor rax, rax
    ret

.end:
    mov rax, rdi
    ret