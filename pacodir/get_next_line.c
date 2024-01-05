/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:47:09 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/05 02:46:51 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static int current_index = -1;
	static char stash[BUFFER_SIZE] = "\0";
	static ssize_t n_read_bytes = 0;
	int pos;
	char *substring;
	char *line;
	static int total_read;

	if (fd < 0)
		return (NULL);

	if (current_index == -1 || current_index == BUFFER_SIZE)
	{
		n_read_bytes = read(fd, stash, BUFFER_SIZE);
		if (n_read_bytes <= 0)
			return (NULL);
		current_index = 0;
		total_read += n_read_bytes;
	}
	if (current_index >= n_read_bytes)
		return (NULL);
//faire ce ca que dans un certain cas pou pas tout  niquer
	if (ft_strchri(stash, BUFFER_SIZE, '\n', current_index) == -1 && n_read_bytes < BUFFER_SIZE )
	{
		if (n_read_bytes >= total_read)
			n_read_bytes = total_read;
	}
	line = malloc(sizeof(char) * LINE_MAX_SIZE);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';

	//on recherche le backslash n et si on ne le touve pas on incremente line
	while ((pos = ft_strchri(stash, BUFFER_SIZE, '\n', current_index)) == -1 && n_read_bytes >= BUFFER_SIZE)
	{
	line = ft_concat(line, stash + current_index, BUFFER_SIZE - current_index, LINE_MAX_SIZE);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
		n_read_bytes = read(fd, stash, BUFFER_SIZE);
		total_read += n_read_bytes;
		if (n_read_bytes < 0)
		{
			free(line);
			return (NULL);
		}
		current_index = 0;
	}

	//si on ne trouve pas le back slash n et que je suis a la fin du fichier
	if (pos == -1)
	{
		substring = ft_substr(stash, BUFFER_SIZE, current_index, n_read_bytes);
		if (substring == NULL)
			return (NULL);
		line = ft_concat(line, substring, ft_strlen(substring), LINE_MAX_SIZE);
		if (line == NULL)
		{
			free(substring);
			free(line);
			return (NULL);
		}
		free(substring);
		n_read_bytes = 0;
		return (line);
	}

	//si jai trouve le backslash n ou que je suis pas a la fin du fichier
	if (n_read_bytes <= 0)
	{
		free(line);
		return (NULL);
		}
	substring = ft_substr(stash, BUFFER_SIZE, current_index, pos - current_index + 1);
	if (substring == NULL)
		return (NULL);
	line = ft_concat(line, substring, ft_strlen(substring), LINE_MAX_SIZE);
	if (line == NULL)
	{
		free(substring);
		free(line);
		return (NULL);
	}
	free(substring);
	current_index = pos + 1;
	total_read = total_read - ft_strlen(line);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>
//
//int main()
//{
//	int fd;
//	char *myfile;
//
////	myfile = "/home/juba/CLionProjects/gnl/giant_line.txt";
////	myfile = "/home/juba/CLionProjects/gnl/giant_line_nl.txt";
////	myfile = "/home/juba/CLionProjects/gnl/multiple_nl.txt";
////    myfile = "/home/juba/CLionProjects/gnl/1char.txt";
//	//myfile = "/home/juba/CLionProjects/gnl/read_error.txt";
////	myfile = "/home/juba/CLionProjects/gnl/bible.txt";
////	myfile = "/home/juba/CLionProjects/gnl/variable_nls.txt";
//
////	myfile = "/home/faboussa/gnl2024/giant_line.txt";
////	myfile = "/home/faboussa/gnl2024/giant_line_nl.txt";
////	myfile = "/home/faboussa/gnl2024/multiple_nl.txt";
////myfile = "/home/faboussa/gnl2024/1char.txt";
//	//myfile = "/home/faboussa/gnl2024/bible.txt";
////	myfile = "/home/faboussa/gnl2024/variable_nls.txt";
//// myfile = "/home/faboussa/gnl2024/with_nl.txt";
////	myfile = "/home/faboussa/gnl2024/multiple_line_no_nl.txt";
////myfile = "/home/faboussa/gnl2024/read_error.txt";
//	fd = open(myfile, O_RDONLY);
//	if (fd < 0)
//		return (EXIT_FAILURE);
//	printf("fd file is %d\n", fd);
//
//	int nb_lines=15;
//	int i = 0;
//	char* line = NULL;
//	while (i < nb_lines)
//	{
//		line = get_next_line(fd);
//		if (line != NULL){
//			printf(" line is %s", line);
//			free(line);
//		}
//		i++;
//	}
//
//////	printf("first line is %s\n", gnl(fd));
//////	printf("seco	nd line is %s\n", gnl(fd));
//////	printf("third line is %s\n", gnl(fd));
//////	printf("fourth line is %s\n", gnl(fd));
//////	printf("5th line is %s\n", gnl(fd));
//////	printf("6th line is %s\n", gnl(fd));
//////	printf("7th line is %s\n", gnl(fd));
//////	printf("8th line is %s\n", gnl(fd));
//////        printf("second line is %s", get_next_line(fd));
//////        printf("third line is %s", get_next_line(fd));
//////        printf("fourth line is %s", get_next_line(fd));
//////        printf("fifth line is %s", get_next_line(fd));
//////        printf("sixth line is %s", get_next_line(fd));
//////        printf("seventh line is %s", get_next_line(fd));
//////        printf("eighth line is %s", get_next_line(fd));
//////        printf("ninth line is %s", get_next_line(fd));
//	close(fd);
//	return (EXIT_SUCCESS);
//}
//
