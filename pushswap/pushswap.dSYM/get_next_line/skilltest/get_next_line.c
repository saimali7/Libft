#include "get_next_line.h"
// #define BUFFER_SIZE 5
size_t ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_free(char **str)
{
		free (*str);
		*str = NULL;
}

void *ft_calloc(size_t length, size_t size)
{
     void *str;
     size_t i;

	 i = 0;
     str =(void *) malloc(size * length);
     if (str == NULL)
        return NULL;
      while(i < length * size)
      {
          ((unsigned char *)str)[i] = 0;
          i++;
 	}
      return (str);
}
 
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s) - start;
	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_calloc(1, 1));
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		ptr[i] = s[start];
		start++;
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char *strjoin(char *s1, char *s2, char **stat)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	str = NULL;
	str =(char *) ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	while (s1 != NULL && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while(s2 != NULL && s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i + j] = '\0';
	ft_free (stat);
	return (str);
}

char	*ft_read(int fd, int *rd)
{
	char *str;

	str = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while(*rd > 0)
	{
		*rd = read(fd, str, BUFFER_SIZE);
		if(rd <= 0)
		{	
			free(str);
			return (NULL);
		}
	return (str);
	}
return (NULL);
}

int		newline(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '\n')
		{
			i++;
			return (i);
		}
	i++;
	}
	return (0);
}

char *ft_rtstring(char **str)
{
	int line;
	char *buff;
	char *temp;

	buff = NULL;
	temp = NULL;
	line = newline(*str);
	if (line > 0)
	{
		buff = ft_substr(*str, 0, line);
		temp = ft_substr(*str, line, ft_strlen(*str) - line);
		ft_free(str);
		*str = temp;
		temp = NULL;
		return (buff);
	}
	else if (*str != NULL && ft_strlen(*str) > 0)
	{
		buff = ft_substr(*str, 0, ft_strlen(*str));
	   	free (*str);
		return (buff);	
	}
return (NULL);
}

char *get_next_line(int fd)
{
	char			*buff;
	static char		*st;
	int				read;

	if(fd < 0 || BUFFER_SIZE < 1)
		return NULL;
	read = 1;
	buff = NULL;
	while (read > 0)
	{
		ft_free(&buff);
		buff = ft_read(fd, &read);
		st = strjoin(st, buff, &st);
		if (newline(st) != 0)
		{
			ft_free(&buff);
			return(ft_rtstring(&st));
		}
	}
	if (ft_strlen(st) > 0 || newline(st) != 0)
		return (ft_rtstring(&st));
	else
		ft_free(&st);
	return (NULL);
}
// #include <fcntl.h>
// #include <stdio.h>
// int	main()
// {
// 	int fd;
// 	char *c;
// 	fd = open("patelsoft", O_RDONLY);
// 	while(c != NULL)
// 	{
// 		c = get_next_line(fd);
// 		printf("%s",c);
// 	}
// 	printf("%s", c);
// 	// printf("called read(% d, c, 10). returned that"
// 	// 		" %d bytes were read.\n", fd, sz);
// 	// c[sz] = '\0';
// 	// printf("Those bytes are as follows: %s\n", c);
// }

