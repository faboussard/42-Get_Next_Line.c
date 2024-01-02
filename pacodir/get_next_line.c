#include "get_next_line.h"


ssize_t read_function(int fd, char *stash)
{
	if (stash[0] != '\0')
		return ft_strlen(stash);
	else
		return read(fd, stash, BUFFER_SIZE);
}

char *malloc_line(char *line)
{
	if (line[100] != '\0')
		line = realloc(line,100 + 2);
	if (line == NULL)
		return NULL;
	return line;
}

char *get_next_line(int fd)
{
    ssize_t return_read;
    char *line;
    static char stash[BUFFER_SIZE] = "\0";

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
	line = malloc(sizeof(char) * 100 + 2);
	if (line = NULL)
			return NULL;
	return_read = read_function(fd, stash);
	line =
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

