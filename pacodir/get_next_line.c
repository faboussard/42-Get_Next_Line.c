/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:47:09 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/09 22:15:38 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *cook_line(char *s)
{
	int size;
	char *s2;
	int i;

	i = 0;
	size = ft_strlen(s);
	s2 = malloc(size + 1);
	if (s2 == NULL)
		return (free(s), NULL);
	while (i < size)
	{
		s2[i] = s[i];
		i++;
	}
	s2[size] = '\0';
	free(s);
	return (s2);
}

void init_stash(char (*stash)[BUFFER_SIZE])
{
	size_t i = 0;
	while (i < BUFFER_SIZE)
		(*stash)[i++] = '\0';
}

int find_current_index(const char stash[BUFFER_SIZE])
{
	size_t i = 0;
	while (stash[i] == '\0')
		i++;
	return i % BUFFER_SIZE;
}

void set_current_index(char (*stash)[BUFFER_SIZE], size_t current_index)
{
	size_t i = 0;
	while (i < current_index)
		(*stash)[i++] = '\0';
}

int is_stash_empty(const char stash[BUFFER_SIZE])
{
	size_t i = 0;
	while (i < BUFFER_SIZE)
	{
		if (stash[i++] != '\0')
			return 0;
	}
	return 1;
}

char *get_next_line(int fd)
{
	static char stash[BUFFER_SIZE] = "\0";
	int current_index;
	int pos;
	char *substring;
	char *line;
	ssize_t n_read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * LINE_MAX_SIZE);
	if (line == NULL)
		return (init_stash(&stash), NULL);
	line[0] = '\0';
	while (!is_stash_empty(stash) || ((n_read_bytes = read(fd, stash, BUFFER_SIZE))))
	{
		if (n_read_bytes < 0)
			break;
		current_index = find_current_index(stash);
		pos = ft_strchri(stash, BUFFER_SIZE, '\n', current_index);
		if (pos == -1)
		{
			line = ft_concat(line, stash + current_index, BUFFER_SIZE - current_index, LINE_MAX_SIZE);
			if (line == NULL)
				return (free(line),init_stash(&stash), NULL);
			set_current_index(&stash, BUFFER_SIZE);
			current_index = 0;
		}
		else
		{
			substring = ft_substr(stash, BUFFER_SIZE, current_index, pos - current_index + 1);
			if (substring == NULL)
				return (free(line),init_stash(&stash), NULL);
			line = ft_concat(line, substring, ft_strlen(substring), LINE_MAX_SIZE);
			if (line == NULL)
				return (init_stash(&stash), free(substring), NULL);
			set_current_index(&stash, pos + 1);
			free(substring);
			break;
		}
	}
	if (line[0] == '\0' || n_read_bytes < 0)
		return (free(line), NULL);
	return (cook_line(line));
}

#include <stdio.h>
#include <fcntl.h>

//int main()
//{
//	int fd;
//	char *myfile;
//
////
////	myfile = "/home/juba/CLionProjects/gnl/giant_line.txt";
////    	myfile = "/home/juba/CLionProjects/gnl/giant_line_nl.txt";
////	myfile = "/home/juba/CLionProjects/gnl/multiple_nl.txt";
////	myfile = "/home/juba/CLionProjects/gnl/1char.txt";
////	myfile = "/home/juba/CLionProjects/gnl/read_error.txt";
////    	myfile = "/home/juba/CLionProjects/gnl/bible.txt";
////    	myfile = "/home/juba/CLionProjects/gnl/only_nl.txt";
////	myfile = "/home/juba/CLionProjects/gnl/41_with_nl.txt";
////	myfile = "/home/juba/CLionProjects/gnl/multiple_line_no_nl.txt";
//	myfile = "/home/juba/CLionProjects/gnl/variable_nls.txt";
//
//	//	myfile = "/home/faboussa/gnl2024/giant_line.txt";
//	//	myfile = "/home/faboussa/gnl2024/giant_line_nl.txt";
//	// myfile = "/home/faboussa/gnl2024/big_line_no_nl.txt";
//	//	myfile = "/home/faboussa/gnl2024/multiple_nl.txt";
//	//myfile = "/home/faboussa/gnl2024/1char.txt";
//	//myfile = "/home/faboussa/gnl2024/bible.txt";
//	//	myfile = "/home/faboussa/gnl2024/variable_nls.txt";
//	//myfile = "/home/faboussa/gnl2024/43_with_nl.txt";
//	//myfile = "/home/faboussa/gnl2024/41_with_nl.txt";
//	//myfile = "/home/faboussa/gnl2024/multiple_line_no_nl.txt";
//	//myfile = "/home/faboussa/gnl2024/read_error.txt";
//	fd = open(myfile, O_RDONLY);
//	if (fd < 0)
//		return (EXIT_FAILURE);
//	printf("fd file is %d\n", fd);
//
//	int nb_lines = 15;
//	int i = 0;
//	char *line = NULL;
//	while (i < nb_lines)
//	{
//		line = get_next_line(fd);
//		if (line != NULL)
//		{
//			printf(" line is %s", line);
//			free(line);
//		}
//		i++;
//	}
//
//	////	printf("first line is %s\n", gnl(fd));
//	////	printf("seco	nd line is %s\n", gnl(fd));
//	////	printf("third line is %s\n", gnl(fd));
//	////	printf("fourth line is %s\n", gnl(fd));
//	////	printf("5th line is %s\n", gnl(fd));
//	////	printf("6th line is %s\n", gnl(fd));
//	////	printf("7th line is %s\n", gnl(fd));
//	////	printf("8th line is %s\n", gnl(fd));
//	////        printf("second line is %s", get_next_line(fd));
//	////        printf("third line is %s", get_next_line(fd));
//	////        printf("fourth line is %s", get_next_line(fd));
//	////        printf("fifth line is %s", get_next_line(fd));
//	////        printf("sixth line is %s", get_next_line(fd));
//	////        printf("seventh line is %s", get_next_line(fd));
//	////        printf("eighth line is %s", get_next_line(fd));
//	////        printf("ninth line is %s", get_next_line(fd));
//	close(fd);
//	return (EXIT_SUCCESS);
//}
//
