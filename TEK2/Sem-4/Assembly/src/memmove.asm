section .text

global memmove:function

memmove:
    mov rax, rdi
    mov r9, 0
    push rbx
    mov rbx, rsi
    cmp rdx, 0
    je .end

.loop:
    mov r8b, BYTE[rbx + r9] 
    mov BYTE[rax + r9], r8b
    inc r9
    cmp rdx, r9
    jne .loop


.end:
    pop rbx
    ret