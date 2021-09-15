section .text

global memset:function

memset:
    mov rax, rdi
    mov r9, 0
    cmp rdx, r9
    je end

loop:
    mov BYTE[rdi + r9], sil
    inc r9
    cmp rdx, r9
    jne loop

end:
    ret