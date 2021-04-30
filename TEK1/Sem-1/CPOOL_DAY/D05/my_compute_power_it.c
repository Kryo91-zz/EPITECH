/*
** EPITECH PROJECT, 2019
** MY_COMPUTE_POWER_IT
** File description:
** return the first argument raised to the power p
*/

int my_compute_power_it(int nb, int p)
{
    int res = 1;
    if (p == 0){
        return(1);
    }
    if (p < 0){
        return(0);
    }
    while (p > 0){
        res = nb * res;
        p--;
    }
    return(res);
}
