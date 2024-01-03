//
// Created by faboussa on 1/3/24.
//


//unsigned long read_function(char *stash, int fd)
//{
//	ssize_t n_read_bytes;
//	if (stash[0] != '\0')
//		return (ft_strlen(stash));
//	else
//		n_read_bytes = read(fd, stash, BUFFER_SIZE);
//	if (n_read_bytes <= 0)
//		return (0);
//	return (n_read_bytes);
//}
//
//char *get_stash_before_nl(char *stash)
//{
//	int i;
//	i = 0;
//	while (stash[i] != '\n' && stash[i] != '\0')
//		i++;
//	return (stash);
//}
//
//char *get_before_nl(char *stash)
//{
//	char *line;
//	line = malloc(sizeof(char) * 100);
//	if (line == NULL)
//		return NULL;
//	line[0] = '\0';
//	line = ft_strlcat(line, get_stash_before_nl(stash), BUFFER_SIZE);
//	if (line == NULL)
//	{
//		free(line);
//		return NULL;
//	}
//	return (line);
//}
//
//char *get_next_line(int fd)
//{
//	char *line;
//	char *temp;
//	static char stash[BUFFER_SIZE] = "\0";
//	ssize_t n_read_bytes;
//
//	if (fd < 0 || BUFFER_SIZE <= 0)
//		return (NULL);
//	n_read_bytes = read_function(stash, fd);
//	while (n_read_bytes > 0)
//	{
//		line = get_before_nl(stash);
//		temp = get_stash_before_nl(stash);
//		ft_memmove(stash, temp + 1, BUFFER_SIZE);
//		n_read_bytes = read(fd, stash, BUFFER_SIZE);
//		stash[n_read_bytes] = '\0';
//	}
//	return (line);
//}