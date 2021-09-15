section .text

global strcasecmp:function

strcasecmp:
    xor rcx, rcx


.loop:
    mov al, BYTE[rdi + rcx]
    mov r8b, BYTE[rsi + rcx]
    inc rcx


.increment:
    cmp al, 0x00
    je .check_second
    cmp r8b, 0x00
    je .end
    cmp al, r8b
    jne .lower
    jmp .loop

.lower:
    add al, 32
    cmp al, r8b
    jne .remise
    jmp .loop

.upper:
    sub al, 32
    cmp al, r8b
    jne .remise2
    jmp .loop

.remise:
    sub al, 32
    jmp .upper

.remise2:
    add al, 32
    jmp .check_first

.put_lower_first:
    add al, 32
    jmp .check_second

.put_lower_second:
    add r8b, 32
    jmp .end


.check_first:
    cmp al, 65
    jl .check_second
    cmp al, 97
    jge .check_second
    jmp .put_lower_first

.check_second:
    cmp r8b, 65
    jl .end
    cmp r8b, 97
    jge .end
    jmp .put_lower_second

.end:
    sub al, r8b
    movsx rax, al
    ret
