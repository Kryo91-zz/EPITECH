segment .text

global strncmp:function

strncmp:
    xor rcx, rcx
    cmp rdx, 0
    je .end2



.loop:
    mov al, BYTE[rdi + rcx]
    mov r8b, BYTE[rsi + rcx]

.increment:
    dec rdx
    cmp rdx, 0
    je .end
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

.end2:
    xor rax, rax
    ret