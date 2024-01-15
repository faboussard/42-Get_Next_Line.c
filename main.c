//
// Created by juba on 1/10/24.
//

#include <fcntl.h>
#include <stdio.h>
#include "pacodir/get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd;
	char *myfile;

	//      myfile = "/home/faboussa/gnl2024/giant_line.txt";
	//      myfile = "/home/faboussa/gnl2024/giant_line_nl.txt";
	// myfile = "/home/faboussa/gnl2024/big_line_no_nl.txt";
	//      myfile = "/home/faboussa/gnl2024/multiple_nl.txt";
	//myfile = "/home/faboussa/gnl2024/1char.txt";
	//myfile = "/home/faboussa/gnl2024/bible.txt";
	//      myfile = "/home/faboussa/gnl2024/variable_nls.txt";
	myfile = "/home/faboussa/gnl2024/43_with_nl.txt";
	//myfile = "/home/faboussa/gnl2024/41_with_nl.txt";
	//myfile = "/home/faboussa/gnl2024/multiple_line_no_nl.txt";
	//myfile = "/home/faboussa/gnl2024/read_error.txt";
	fd = open(myfile, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);

	int nb_lines = 15;
	int i = 0;
	char *line = NULL;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			printf(" line is %s", line);
			free(line);
		}
		i++;
	}
	////    printf("first line is %s\n", gnl(fd));
	////    printf("seco    nd line is %s\n", gnl(fd));
	////    printf("third line is %s\n", gnl(fd));
	////    printf("fourth line is %s\n", gnl(fd));
	////    printf("5th line is %s\n", gnl(fd));
	////    printf("6th line is %s\n", gnl(fd));
	////    printf("7th line is %s\n", gnl(fd));
	////    printf("8th line is %s\n", gnl(fd));
}