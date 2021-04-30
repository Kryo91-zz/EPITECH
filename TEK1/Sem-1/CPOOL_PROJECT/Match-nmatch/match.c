/*
** EPITECH PROJECT, 2019
** MATCH
** File description:
** .C
*/

int    match(char const *s1, char const *s2)
{
	int j = 0;
	int start = -1;
	int end = -1;
	int buff;
	int i;

	if(s2[j] == '\0')
		return(0);
	for (i = 0; s1[i] != '\0';) {
		if (s2[j] == '\0')
			break;
		if (s1[i] == s2[j]) {
			j++;
			i++;
		} else if (s2[j] != '*')
			return (0);
		if (s2[j] == '*'){
			start = start_star(s2, j);
			end = end_star(s2, start) - 1;
		}
		if (start >= 0 && end >= 0) {
			buff = search(s1 + i, s2, start, end);
			if (buff == -1) {
				return(0);
			} else {
				i = buff + i;
				j = start;
				start = -1;
				end = -1;
			}
		}
	}
	j = my_strlen(s2);
	if (s1[i - 1] == s2[j - 1] || s2[j - 1] == '*')
		return(1);
	return (0);
}

int my_strlen(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++);
	return (i);
}

int 	start_star(char const *s2, int j)
{
	for(; s2[j] == '*'; j++);
	return(j);
}

int 	end_star(char const *s2, int j)
{
	if (s2[j] == '\0')
		return (j);
	for(; s2[j] != '\0' ; j++) {
		if (s2[j] == '*')
			return (j);
	}
	return(j);
}

int search(char const *s1, char const *s2, int start, int end)
{
	int i = 0;
	int is_valide = 0;

	if (s2[start] == '\0')
		return 0;
	for(; s1[i] != '\0'; i++) {
		is_valide = 0;
		for(int j = start, k = 0; j <= end; j++, k++) {
			if (s1[i + k] == '\0') {
				return (-1);
			}
			if (s1[i + k] != s2[j]) {
				is_valide = -1;
				}
		}
		if (is_valide == 0) {
			return (i);
		}
	}
	return(-1);
}