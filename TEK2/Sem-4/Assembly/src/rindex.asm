section .text

global rindex:function

rindex:
    xor rax, rax

.loop:
    mov r8b, BYTE[rdi]
    jmp .compare

.compare:
    cmp r8b, sil
    cmove rax, rdi
    inc rdi
    cmp r8b, 0x00
    jne .loop

.end:
    ret