/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:47:09 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/02 19:31:17 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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

char *get_next_line(int fd)
{
	static int current_index = -1;
	static char stash[BUFFER_SIZE] = "\0";
	static ssize_t n_read_bytes = 0;
	int pos;
	char *line = malloc(sizeof(char) * LINE_MAX_SIZE);
	ssize_t n_read_bytes_prev = 0;
	char eof = 0;
	if (line == NULL)
	{
		return NULL;
	}
	if (current_index == -1)
	{
		n_read_bytes = read(fd, stash, BUFFER_SIZE);
		current_index = 0;
	}
	int count = 0;
	while ((pos = ft_strchri(stash, '\n', current_index)) == -1 && n_read_bytes == BUFFER_SIZE)
	{
		line = ft_concat(line, stash + current_index,
						 LINE_MAX_SIZE);
		n_read_bytes_prev = n_read_bytes;
		n_read_bytes = read(fd, stash, BUFFER_SIZE);
		if (n_read_bytes == 0)
		{
			n_read_bytes = n_read_bytes_prev;
			eof = 1;
			break;
		}
		current_index = 0;
		count++;
	}
//	if (n_read_bytes == 0)
//	{
//		free(line);
//		return NULL;
//	}


	if ((pos == -1 && n_read_bytes < BUFFER_SIZE) || eof != 0)
	{
		if (current_index >= n_read_bytes)
		{
			free(line);
			return NULL;
		}
		if(BUFFER_SIZE != 1)
			line = ft_concat(line, ft_substr(stash, current_index, n_read_bytes),
						 LINE_MAX_SIZE);
		n_read_bytes = 0;
		return line;
	}

	line = ft_concat(line, ft_substr(stash, current_index, pos - current_index + 1),
					 LINE_MAX_SIZE);
	current_index = pos + 1;
	return line;
}

#include <stdio.h>
#include <fcntl.h>
//
//int main()
//{
//	int fd;
//	char *myfile;
//
//	//myfile = "/home/juba/CLionProjects/gnl/giant_line_nl.txt";
//	//myfile = "/home/juba/CLionProjects/gnl/giant_line.txt";
//	//myfile = "/home/juba/CLionProjects/gnl/multiple_nl.txt";
//myfile = "/home/juba/CLionProjects/gnl/1char.txt";
//	//myfile = "/home/juba/CLionProjects/gnl/variable_nls.txt";
//	fd = open(myfile, O_RDONLY);
//	if (fd < 0)
//		return (EXIT_FAILURE);
//	printf("fd file is %d\n", fd);
//	// get_next_line(fd);
//	//get_next_line(fd);
//	//get_next_line(fd);
//
//	int nb_lines=10;
//	int i = 0;
//	char* line = NULL;
//	while(i < nb_lines){
//		line = get_next_line(fd);
//		if (line != NULL)
//		{
//			printf("first line is %s", line);
//			free(line);
//		}
//		i++;
//	}
//
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
//	close(fd);
//	return (EXIT_SUCCESS);
//}
//
