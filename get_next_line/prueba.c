
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*static size_t ft_strlen(char const *string)
{
	size_t i = 0;
	
	while(string[i] != '\0')
		i++;
	return(i);
}
*/
/*static char *ft_strdup(const char *s1)
{
	char *copy;
	int i = 0;

	if (!s1)
		return(NULL);	
	if (!(copy = (char *)malloc(sizeof(*copy) * (ft_strlen(s1) + 1))))
		return(NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = 0;
	return(copy);
}
*/

static char *ft_strchr(const char *s, int c)
{
	int i = 0;

	while(s[i] != '\0')
	{
		if(s[i] == c)
			return((char *)s);
		i++;
	}
	return(0);
}





int main()
{
	char *x = "Hola platano";
	printf("%s", ft_strchr(x, 'l'));
	printf("\n%s", strchr(x, 'l'));
	return(0);
}