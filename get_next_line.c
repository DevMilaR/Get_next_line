#include "get_next_line.h"

char	*leftover(char *storage)
{
	char	*leftover;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (storage[i] != '\0' && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free (storage);
		return (NULL);
	}
	leftover = malloc(sizeof(char) * (ft_strlen(storage) - i + 1));
	if (!leftover)
		return (NULL);
	i++;
	while (storage[i])
	{
		leftover[j++] = storage[i++];
	}
	leftover[j] = '\0'; 
	free(storage);   
	return (leftover);  
}
char	*create_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage[0])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';  
	return (line);  
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		buffer[BUFFER_SIZE +1];
	int			readbytes;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr(storage, '\n') && readbytes > 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
			return (NULL);
		buffer[readbytes] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	if (readbytes == -1)
		free (storage);
	if (!storage)
		return (NULL);
	line = create_line(storage);
	storage = leftover(storage);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
} 
