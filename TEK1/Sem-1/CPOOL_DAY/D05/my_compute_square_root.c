/*
** EPITECH PROJECT, 2019
** MY_COMPUTE_SQUARE_ROOT
** File description:
** function that returns the square root of the number given as argument  
*/

int my_compute_square_root(int nb)
{
    int p = 1;

    while (nb != p*p) {
        p++;

        if (nb == p*p) {
            return(p);
        }

        if (p >= 0.5*nb) {
            return(0);
        }
    }
    return(0);
}

