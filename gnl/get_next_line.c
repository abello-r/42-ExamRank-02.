#include "get_next_line.h"

/* 
Ft_strlen
ft_strchr
ft_strdup
ft_strjoin
getnextline
*/

size_t ft_strlen(const  char *str)
{
	size_t i = 0;

	while(str[i] != '\0')
		i++;
	return(i);
}

char *ft_strchr (const char *str, int ch_find)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (str[i] == '\0')
	{
		if (ch_find == '\0')
			return ((char *)str);
		return(0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == ch_find)
			return((char *)str + i);
		i++;
	}
	return(0);
}

char *ft_strdup(const char *str)
{
	size_t i = 0;
	char *dup;

	if (!(dup = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return(NULL);
	while(str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}

char *ft_strjoin(const char *s1, const char *s2)
{
	size_t i = 0;
	size_t c = 0;
	char *new;


	if (s1 == NULL || s2 == NULL)
		return(NULL);
	if (!(new = malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2) + 1)))))
		return(NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[c] != '\0')
	{
		new[i] = s2[c];
		c++;
		i++;
	}
	new[i] = '\0';
	return(new);
}

int get_next_line (char **line)
{
	static char *mem;
	char	buffer[256 + 1];
	char	*tmp;
	char	*aux1;
	char	*aux2;
	int		ret;

	if (!line)
		return(-1);
		while (ft_strchr(mem, '\n') == NULL)
		{
			ret = read(0, buffer, 256);
			if (ret < 0)
				return(-1);
			if (ret == 0)
				break ;
			buffer[ret] = 0;
			if (!mem)
				mem = ft_strdup(buffer);
			else
			{
				tmp = ft_strjoin(mem, buffer);
				free(mem);
				mem = tmp;
			}
		}
		if (!mem && !ret)
		{
			*line = ft_strdup("");
			return(0);
		}
		else if ((aux1 = ft_strchr(mem, '\n')))
		{
			*aux1 = 0;
			*line = ft_strdup(mem);
			aux2 = ft_strdup(++aux1);
			free(mem);
			mem = aux2;
		}
		else
		{
			*line = ft_strdup(mem);
			free(mem);
			mem = NULL;
			return(0);
		}
	return(1);
}
