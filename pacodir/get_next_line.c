#include "get_next_line.h"

char *get_before_new_line(char *stash)
{
	int i;
	i = 0;
	while ((ft_strchr(stash, '\n') == 0) || (ft_strchr(stash, '\0') == 0))
		i++;
	return (stash);
}

char *return_line(int fd, char *stash)
{
	char *line;
	line = malloc(sizeof(char) * 100);
	if (line == NULL)
		return NULL;
	ssize_t n_read_bytes;
	int i;
	i = -1;
	n_read_bytes = read(fd, stash, BUFFER_SIZE);
	while (n_read_bytes > 0)
	{
		line = ft_strjoin(line, get_before_new_line(stash));
		stash = stash[current_index];
	}
	line = ft_strjoin(line, stash[pos]);
	return line;
}

char *get_next_line(int fd)
{
    char *line;
    static char stash[BUFFER_SIZE] = "\0";

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	line = return_line(fd, stash);
}

#include <stdio.h>
#include <fcntl.h>

    int main()
    {
        int fd;
        char *myfile;

        myfile = "/home/fanny/getnextlinefanny/1char.txt";
        fd = open(myfile, O_RDONLY);
        if (fd < 0)
            return (EXIT_FAILURE);
        printf("fd file is %d\n", fd);
        // get_next_line(fd);
        //get_next_line(fd);
        //get_next_line(fd);
        printf("first line is %s\n", get_next_line(fd));
        printf("second line is %s", get_next_line(fd));
        printf("third line is %s", get_next_line(fd));
        printf("fourth line is %s", get_next_line(fd));
        printf("fifth line is %s", get_next_line(fd));
        printf("sixth line is %s", get_next_line(fd));
        printf("seventh line is %s", get_next_line(fd));
        printf("eighth line is %s", get_next_line(fd));
        printf("ninth line is %s", get_next_line(fd));
        close(fd);
        return (EXIT_SUCCESS);
    }

