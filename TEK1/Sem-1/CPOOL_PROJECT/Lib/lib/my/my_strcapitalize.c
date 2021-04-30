/*
** EPITECH PROJECT, 2019
** MY_STRCAPITALIZE
** File description:
** strcapitalize
*/

char *my_strcapitalize(char *str)
{
  int	i = -1;
  int	new_word = 1;

  while (str[(i = i + 1)] != '\0')
  {
    if (str[i] < 123 && str[i] > 96 && new_word)
    {
      new_word = 0;
      str[i] = str[i] - 32;
    }
    if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
      new_word = 1;
  }
  return (str);
}
