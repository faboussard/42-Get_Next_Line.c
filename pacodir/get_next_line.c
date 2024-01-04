/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:47:09 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/02 19:53:39 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_next_line(int fd)
{
	static int current_index = -1;
	static char stash[BUFFER_SIZE] = "\0";
	static ssize_t n_read_bytes = 0;
	int pos;
	char eof = 0;
	char *substring;
	ssize_t n_read_bytes_prev;
//dabord on read
	if (current_index == -1)
	{
		n_read_bytes = read(fd, stash, BUFFER_SIZE);
		if (n_read_bytes == -1)
			return (NULL);
		current_index = 0;
	}
	//on fait le malloc
	char *line = malloc(sizeof(char) * LINE_MAX_SIZE);
	if (line == NULL)
		return NULL;

	//on recherche le backslash n et si on ne le touve pas on incremente line
	while ((pos = ft_strchri(stash, '\n', current_index)) == -1 && n_read_bytes == BUFFER_SIZE)
	{
		line = ft_concat(line, stash + current_index, LINE_MAX_SIZE);
		if (line == NULL)
			return NULL;

		// si on na plus rien a lire on va retourner sur ce quon lisait avant
		n_read_bytes_prev = n_read_bytes;
		n_read_bytes = read(fd, stash, BUFFER_SIZE);
		if (n_read_bytes == 0)
		{
			n_read_bytes = n_read_bytes_prev;
			eof = 1;
			break;
		}
		else if (n_read_bytes == -1)
			return NULL;
		current_index = 0;
	}

	//si on ne trouve pas le back slash n et que ce qui a alire est inferieur a buffe size ou que
	if ((pos == -1 && n_read_bytes < BUFFER_SIZE) || eof != 0)
	{
		if (current_index >= n_read_bytes)
		{
			free(line);
			return NULL;
		}
		if (BUFFER_SIZE != 1)
		{
			substring = ft_substr(stash, current_index, pos - current_index + 1);
			if (substring == NULL)
				return NULL;
			line = ft_concat(line, substring,LINE_MAX_SIZE);
			free (substring);
		}
		n_read_bytes = 0;
		return (line);
	}

	substring = ft_substr(stash, current_index, pos - current_index + 1);
	if (substring == NULL)
		return NULL;
	line = ft_concat(line, substring, LINE_MAX_SIZE);
	if (line == NULL)
		return NULL;
	free(substring);
	current_index = pos + 1;
	return line;
}

#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd;
	char *myfile;

	//myfile = "/home/juba/CLionProjects/gnl/giant_line.txt";
	//myfile = "/home/juba/CLionProjects/gnl/giant_line_nl.txt";
	//myfile = "/home/juba/CLionProjects/gnl/multiple_nl.txt";
//myfile = "/home/juba/CLionProjects/gnl/1char.txt";
	//myfile = "/home/juba/CLionProjects/gnl/bible.txt";
	myfile = "/home/juba/CLionProjects/gnl/variable_nls.txt";

	//myfile = "/home/faboussa/gnl2024/giant_line.txt";
	//myfile = "/home/faboussa/gnl2024/giant_line_nl.txt";
	//myfile = "/home/faboussa/gnl2024/multiple_nl.txt";
//myfile = "/home/faboussa/gnl2024/1char.txt";
	//myfile = "/home/faboussa/gnl2024/bible.txt";
//	myfile = "/home/faboussa/gnl2024/variable_nls.txt";
	fd = open(myfile, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	printf("fd file is %d\n", fd);

	int nb_lines=15;
	int i = 0;
	char* line = NULL;
	while (i < nb_lines)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf(" line is %s", line);
		i++;
	}
	free(line);
////	printf("first line is %s\n", gnl(fd));
////	printf("second line is %s\n", gnl(fd));
////	printf("third line is %s\n", gnl(fd));
////	printf("fourth line is %s\n", gnl(fd));
////	printf("5th line is %s\n", gnl(fd));
////	printf("6th line is %s\n", gnl(fd));
////	printf("7th line is %s\n", gnl(fd));
////	printf("8th line is %s\n", gnl(fd));
////        printf("second line is %s", get_next_line(fd));
////        printf("third line is %s", get_next_line(fd));
////        printf("fourth line is %s", get_next_line(fd));
////        printf("fifth line is %s", get_next_line(fd));
////        printf("sixth line is %s", get_next_line(fd));
////        printf("seventh line is %s", get_next_line(fd));
////        printf("eighth line is %s", get_next_line(fd));
////        printf("ninth line is %s", get_next_line(fd));
	close(fd);
	return (EXIT_SUCCESS);
}

