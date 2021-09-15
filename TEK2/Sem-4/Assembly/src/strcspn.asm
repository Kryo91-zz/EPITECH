section .text

global strcspn:function

strcspn:
    xor rax, rax
    xor rdx, rdx
    xor rcx, rcx
    cmp BYTE[rdi], 0x00
    je .end
    cmp rsi, 0x00
    je .get_lenght
    jmp .loop_first

.inc_first_loop:
    xor rcx, rcx
    inc rdx
    inc rax
    jmp .loop_first

.loop_second:
    inc rcx
    mov r8b, BYTE[rsi + rcx]
    cmp r9b, r8b
    je .end
    cmp r8b, 0x00
    je .inc_first_loop
    jmp .loop_second


.loop_first:
    mov r9b, BYTE[rdi + rdx]
    mov r8b, BYTE[rsi + rcx]
    cmp r9b, r8b
    jne .loop_second
    jmp .end

.get_lenght:
    cmp BYTE[rdi], 0x00
    je .end
    inc rax
    inc rdi
    jmp .get_lenght

.end:
    ret