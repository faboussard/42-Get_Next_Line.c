//
// Created by juba on 1/10/24.
//

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

//penser a tester avec buffer size 42
int main()
{
	int fd1;
	int fd2;
	int fd3;
	char *myfile1;
	char *myfile2;
	char *myfile3;

	myfile1 = "/home/juba/CLionProjects/gnl/lines_around_10.txt";
	myfile2 = "/home/juba/CLionProjects/gnl/read_error.txt";
	myfile3 = "/home/juba/CLionProjects/gnl/multiple_nl.txt";
	fd1 = open(myfile1, O_RDONLY);
	fd2 = open(myfile2, O_RDONLY);
	fd3 = open(myfile3, O_RDONLY);
	if (fd1 < 0)
		return (-1);
	if (fd2 < 0)
		return (-2);
	if (fd3 < 0)
		return (-3);
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd3));
	printf("%s", get_next_line(fd1));
	close(fd1);
	close(fd2);
	close(fd3);
	return (EXIT_SUCCESS);
}