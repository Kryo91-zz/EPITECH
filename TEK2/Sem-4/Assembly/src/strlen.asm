segment .text

global strlen:function

strlen:
    mov rax, 0

loop:
    cmp BYTE[rdi + rax], 0
    je end
    inc rax
    jmp loop

end:
    ret