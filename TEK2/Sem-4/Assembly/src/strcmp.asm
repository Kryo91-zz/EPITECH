segment .text

global strcmp:function

strcmp:
    xor rcx, rcx


.loop:
    mov al, BYTE[rdi + rcx]
    mov r8b, BYTE[rsi + rcx]

.increment:
    cmp al, 0x00
    je .end
    cmp r8b, 0x00
    je .end
    cmp al, r8b
    jne .end
    inc rcx
    jmp .loop


.end:
    sub al, r8b
    movsx rax, al
    ret