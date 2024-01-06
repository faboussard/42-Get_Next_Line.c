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
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *ft_malloc(size_t size)
{
    static int i = 0;

    if (i == 4)
        return (NULL);
    ++i;
    return (malloc(size));
}

char *cook_line(char *s, char *s3, int *a)
{
    int size = ft_strlen(s);
    char *s2 = malloc(size + 1);
    if (s2 == NULL)
    {
        s3[0] = '\0';
        *a = -1;
        free(s);
        return (NULL);
    }
    memcpy(s2, s, size);
    s2[size] = '\0';
    free(s);
    return (s2);
}

char *get_next_line(int fd)
{
	static int current_index = -1;
	static char stash[BUFFER_SIZE] = "\0";
	static ssize_t n_read_bytes = 0;
	int pos;
	char *substring;
	char *line;
	static ssize_t total_read;

	if (fd < 0)
    {
        stash[0] = '\0';
        current_index = -1;
        return (NULL);
    }

	if (current_index == -1 || current_index == BUFFER_SIZE)
	{
		n_read_bytes = read(fd, stash, BUFFER_SIZE);
		if (n_read_bytes <= 0)
        {
            n_read_bytes = 0;
			return (NULL);
            }
		current_index = 0;
		total_read += n_read_bytes;
	}
	if (current_index >= n_read_bytes)
    {
        n_read_bytes = 0;
        stash[0] = '\0';
        current_index = -1;
        return (NULL);
    }
	if (ft_strchri(stash, BUFFER_SIZE, '\n', current_index) == -1 && n_read_bytes < BUFFER_SIZE )
	{
		if (n_read_bytes >= total_read)
			n_read_bytes = total_read;
	}
	line = malloc(sizeof(char) * LINE_MAX_SIZE);
	if (line == NULL)
    {
        n_read_bytes = 0;
        stash[0] = '\0';
        current_index = -1;
        return (NULL);
    }
	line[0] = '\0';

	while ((pos = ft_strchri(stash, BUFFER_SIZE, '\n', current_index)) == -1 && n_read_bytes >= BUFFER_SIZE)
	{
        line = ft_concat(line, stash + current_index, BUFFER_SIZE - current_index, LINE_MAX_SIZE);
        if (line == NULL)
        {
            n_read_bytes = 0;
            stash[0] = '\0';
            current_index = -1;
            return (NULL);
        }
		n_read_bytes = read(fd, stash, BUFFER_SIZE);
		total_read += n_read_bytes;
		if (n_read_bytes < 0)
		{
            n_read_bytes = 0;
            stash[0] = '\0';
            current_index = -1;
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
        {
            stash[0] = '\0';
            current_index = -1;
            return (NULL);
        }
		line = ft_concat(line, substring, ft_strlen(substring), LINE_MAX_SIZE);
		if (line == NULL)
		{
            stash[0] = '\0';
            current_index = -1;
			free(substring);
			return (NULL);
		}
		free(substring);
		n_read_bytes = 0;
		return (cook_line(line, stash, &current_index));
	}

	//si jai trouve le backslash n ou que je suis pas a la fin du fichier
	if (n_read_bytes <= 0)
	{
        stash[0] = '\0';
        current_index = -1;
		free(line);
		return (NULL);
    }
	substring = ft_substr(stash, BUFFER_SIZE, current_index, pos - current_index + 1);
	if (substring == NULL)
    {
        stash[0] = '\0';
        current_index = -1;
        return (NULL);
    }
	line = ft_concat(line, substring, ft_strlen(substring), LINE_MAX_SIZE);
	if (line == NULL)
	{
        stash[0] = '\0';
        current_index = -1;
		free(substring);
		return (NULL);
	}
	free(substring);
	current_index = pos + 1;
	total_read = total_read - ft_strlen(line);

	return (cook_line(line, stash, &current_index));
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
//// myfile = "/home/faboussa/gnl2024/43_with_nl.txt";
//// myfile = "/home/faboussa/gnl2024/41_with_nl.txt";
////	myfile = "/home/faboussa/gnl2024/multiple_line_no_nl.txt";
//myfile = "/home/faboussa/gnl2024/read_error.txt";
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
