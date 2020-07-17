#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
	size_t a;

	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}

char *ft_strdup(const char *s)
{
	unsigned int a;
	unsigned int l;
	char *str;

	a = 0;
	l = (unsigned int)ft_strlen((char*)s);
	if (!(str=(char*)malloc(l + 1)))
		return (NULL);
	while (a < l)
	{
		str[a] = s[a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int i;
	int j;
	size_t l;
	char *str;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	if (!(str=(char*)malloc(sizeof(char) * (l + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

int ft_streol(const char *s)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	if (s[i] == '\0' && s[i] == '\n')
		return (i);
	return (-1);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	a;
	char 	*str;

	if ( s == NULL || ft_strlen(s) < start)
		return (ft_strdup(""));
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	a = 0;
	while (a < len)
	{
		str[a] = s[start + a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

int saveline(char **st, char ***line)
{
	char	*tem;

	**line = ft_substr(*st, 0, ft_streol(*st));
	tem = ft_strdup(*st);
	free(*st);
	*st = NULL;
	*st = ft_substr(tem, ft_streol(tem) + 1, ft_strlen(tem) - ft_streol(tem));
	free(tem);
	tem = NULL;
	return (1);
}

int readline(char *buf, char **st, int fd)
{
	char	*tem;
	int 	ret;

	while ((ret = read (fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tem = ft_strdup(*st);
		free(*st);
		*st = NULL;
		*st = ft_strjoin(tem, buf);
		free(tem);
		tem = NULL;
		if (ft_streol(*st) != -1)
			break;
	}
	return (ret);
}

int get_next_line(int fd, char **line)
{
	static char *st;
	char		*buf;
	int			ret;

	ret = 1;
	if ((buf=(char*)malloc(BUFFER_SIZE + 1)) == NULL || fd == -1 || line == NULL || BUFFER_SIZE == 0 || read(fd,buf,0) == -1)
	{
		free(buf);
		return (-1);
	}
	if (st == NULL)
		st = ft_strdup(st);
	if (ft_streol(st) == -1)
		ret = readline(buf,&st,fd);
	free(buf);
	if (ret == 0)
	{
		*line = ft_strdup(st);
		free(st);
		st = NULL;
		return (0);
	}
	return(saveline(&st,&line));
}

