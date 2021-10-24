#include "get_next_line.h"

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if(s == NULL)
		return(0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	void		*ptr;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < size * count)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

 char *ft_strjoin(char *s1, char *s2, char **main)
{
	size_t	i;
	size_t	start;
	char	*ptr;

	i = 0;
	start = 0;
	ptr = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
		while (s1 != NULL && s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
	while (s2 != NULL && s2[start])
	{
		ptr[i] = s2[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	ft_free(main);
	return (ptr);
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
