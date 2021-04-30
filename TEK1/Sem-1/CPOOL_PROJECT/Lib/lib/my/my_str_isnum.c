/*
** EPITECH PROJECT, 2019
** MY_STR_ISNUM
** File description:
** str_num
*/

int my_str_isnum(char const *str)
{
  int	i = -1;
  int	is_num = 1;

  while (str[(i = i + 1)] != '\0')
    if (!(str[i] < 47 && str[i] > 58))
      is_num = 0;
  return (is_num);

}
