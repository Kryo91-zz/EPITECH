/*
** EPITECH PROJECT, 2019
** MY_PRINT_COMB
** File description:
** displays, all the numbers composed by three different digits numbers.
*/
int     my_print_comb(void)
{
    int a = 48;
    int b = 49;
    int c = 50;

    while ( a < 56) {
        my_putchar(a);
        my_putchar(b);
        my_putchar(c);
	c = c + 1;
	my_putchar(',');
       	my_putchar(' ');
        if (b >= 56) {
            b = a + 1;
            a = a + 1;
        }
        if (c > 57) {
            b = b + 1;
            c = b + 1;
	}
    }
}

                    
