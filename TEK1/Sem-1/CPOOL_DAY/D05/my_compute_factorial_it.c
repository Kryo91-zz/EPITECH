/*
** EPITECH PROJECT, 2019
** MY_COMPUTE_FACTORIAL_IT
** File description:
** returns the factorial of the number given as a parameter
*/

int my_compute_factorial_it(int nb)
{
    int a = nb;
    int res = 1;

    if (a == 0 || a == 1){
        return(1);
    }
    if ( a < 0 || nb >= 13){
        return(0);
    }
    while(a > 1) {
        res = res * a;
        a--;
    }
    return(res);
}


