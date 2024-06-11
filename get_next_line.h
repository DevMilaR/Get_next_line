#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char	*storage, const char	*buffer);
char	*get_next_line(int fd);
char	*leftover(char *storage);
char	*create_line(char *storage);
size_t	ft_strlen(const char *str);

#endif
