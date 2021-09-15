section .text

global strchr:function

strchr:
    mov rax, rdi

loop:
    cmp BYTE[rax], sil
    je find
    cmp BYTE[rax], 0
    je end
    inc rax
    jmp loop

end:
    xor rax, rax

find:
    ret