/*
** EPITECH PROJECT, 2019
** INFIN_ADD
** File description:
** add infinite integer
*/

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

char my_revstr(char *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putchar(char c);

char *malloc_mem(char const *nb1, char const *nb2)
{
	int max_long = my_strlen(nb1) + my_strlen(nb2) + 1;
	char *str = malloc(sizeof(char) * max_long  + 1);
  	int count = 0;
	
  while(count < max_long) {
		str[count] = 0;
    	count++;
  }
	return (str);
}

int	my_convert_chars_to_nb(char c)
{
	if(c >= '0' && c <= '9')
		return (c - 48);	
		return (0);
}

char *infin_add(char const *nb1, char const *nb2)
{
	char *res = malloc_mem(nb1, nb2);
	int count = 0;
	int size1 = my_strlen(nb1) - 1;
	int size2 = my_strlen(nb2) - 1;
	int num_add1 = 0;
	int num_add2 = 0;
	int ret = 0;

	for(; size1 >= 0 || size2 >= 0 || ret != 0; size1--, size2--, count++) {
		num_add1 = (size1 >= 0) ? my_convert_chars_to_nb(nb1[size1]) : 0;
		num_add2 = (size2 >= 0) ? my_convert_chars_to_nb(nb2[size2]) : 0;
		res[count] =((num_add1 + num_add2 + ret) % 10) + '0';
    	ret = ((num_add1 + num_add2 + ret) / 10);
	}
  	my_revstr(res);
	return (res);
}

char *infin_add_neg(char const *nb1, char const *nb2)
{
	char *res = malloc_mem(nb1, nb2);
	int count = 0;
	int size1 = my_strlen(nb1) - 1;
	int size2 = my_strlen(nb2) - 1;
	int num_add1 = 0;
	int num_add2 = 0;
	int ret = 0;

	for(; size1 > 0 || size2 > 0 || ret != 0; size1--, size2--, count++) {
		num_add1 = (size1 >= 0) ? my_convert_chars_to_nb(nb1[size1]) : 0;
		num_add2 = (size2 >= 0) ? my_convert_chars_to_nb(nb2[size2]) : 0;
		res[count] =((num_add1 + num_add2 + ret) % 10) + '0';
    	ret = ((num_add1 + num_add2 + ret) / 10);
	}
  	my_revstr(res);
	return (res);
}

int main(int ac, char **av)
{
	char *res = 0;
	
  	if(ac != 3)
    	return (0);
  	if (av[1][0] == '-' && av[2][0] == '-') {
    	my_putchar('-');
    	res = infin_add_neg(av[1], av[2]);
		my_putstr(res);
  	}else{	
    	res = infin_add(av[1], av[2]);
		my_putstr(res);
  	}
  	my_putchar('\n');
  	free(res);
	return (0);
}
