.name "bunker"
.comment "create wall and defensive champ"

live:
    w1: ld 9,r4
    live %0
    ld 900,r5
    sti r4, r5, %0
    sub r5, r10, r5
    ld 0,r2
    live %0
    zjmp %:w1