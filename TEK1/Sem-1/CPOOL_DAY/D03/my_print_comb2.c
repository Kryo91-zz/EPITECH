/*
** EPITECH PROJECT, 2019
** MY_PRINT_COMB2
** File description:
** displays, all the different combinaisons of two two-digit number
*/

int    my_print_comb2(void)
{
    for (int a = 0 ; a <= 9 ; a = a + 1){
        for (int b = 0 ; b <= 9 ; b = b + 1){
            my_for2(a,b);
        }
    }
    return (0);
}
void my_for2 (int a, int b)
{
    for (int c = 0 ; c <= 9 ; c = c + 1){
        for (int d = 0 ; d <= 9 ; d = d + 1){
            my_if(a,b,c,d);
        }
    }
}
int my_if (int a, int b, int c, int d)
{
    int gch = a * 10 + b;
    int drt = c * 10 + d;

    if (gch < drt && gch < 100 && drt < 100){
        my_putchar(a+'0');
        my_putchar(b+'0');
        my_putchar(' ');
        my_putchar(c+'0');
        my_putchar(d+'0'); {
            if (gch !=98);
            my_putchar(',');
            my_putchar(' ');
        }
    }
    return(0);
}
        
        
        
        
