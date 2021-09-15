section .text

global strstr:function

strstr:
    mov rax, rdi
    xor rcx, rcx
    mov r8b, BYTE[rax]
    cmp r8b, 0x00
    je .end_string_null
    mov r9b, BYTE[rsi + rcx]
    cmp r9b, 0x00
    je .end_empty
    jmp .compare

.increment_false:
    cmp r9b, 0x00
    je .end
    inc rax
    xor rcx, rcx
    jmp .loop

.loop:
    mov r8b, BYTE[rax]
    cmp r8b, 0x00
    je .end_string_null
    jmp .compare


.compare:
    mov r8b, BYTE[rax]
    mov r9b, BYTE[rsi + rcx]
    cmp r8b, r9b
    jne .increment_false
    cmp r8b, 0x00
    je .increment_false
    inc rax
    inc rcx
    jmp .compare

.end_string_null:
    xor rax, rax
    ret

.end_empty:
    ret

.end:
    sub rax, rcx
    ret