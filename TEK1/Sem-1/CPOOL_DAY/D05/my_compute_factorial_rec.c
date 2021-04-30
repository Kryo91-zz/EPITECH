/*
** EPITECH PROJECT, 2019
** MY_COMPUTE_FACTORIAL_REC
** File description:
** recurcive function return the factorial of the number given
*/

int my_compute_factorial_rec(int nb)
{
	int a =nb;
	
	if(a < 0 || a > 12) 
		return(0);

	if(a==0)
		return(1);

	else{ 
		a = a * my_compute_factorial_rec(nb-1);
		return(a);
	}
}
