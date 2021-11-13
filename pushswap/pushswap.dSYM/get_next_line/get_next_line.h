#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#include <unistd.h>
#include <stdlib.h>
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2, char **main);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_free(char **str);
char	*get_next_line(int fd);

#endif