#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str)
{
	size_t i = 0;

	while(str[i] != '\0')
		i++;
	return(i);
}

char *ft_strdup(const char *s1)
{
	int x = 0;
	char *copy;

	if(!(copy=(char *)malloc(ft_strlen(s1) + 1)))
		return(NULL);
	
	while (s1[x] != '\0')
	{
		copy[x] = s1[x];
		x++;
	}
	copy[x] = '\0';
	return(copy);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i = 0;
	char *copy;

	if (s == NULL || ft_strlen(s) < start)
		return(ft_strdup(""));
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
	{
		free(copy);
		copy = NULL;
		return(NULL);
	}
	while (i < len)
	{
		copy[i] = s[start + i];
		i++;
	}
	copy[i] = '\0';
	return(copy);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *x;
	size_t i = 0;
	size_t c = 0;
	
	if (!s1 || !s2)
		return(NULL);
	
	if(!(x = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return(NULL);
	while (s1[i] != '\0')
	{
		x[c] = s1[i];
		i++;
		c++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		x[c] = s2[i];
		c++;
		i++;
	}
	x[c] = '\0';
	return(x);
}

int main ()
{
	char *x = "pepinillo volador";
	char *y = "banana explosiva";

	printf("%s", ft_strjoin(x, y));
	return(0);
}