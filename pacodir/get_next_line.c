/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:47:09 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/09 18:16:25 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

void *ft_free_all(char *s, char *stash, int *index, ssize_t *n_read_bytes)
{
    size_t i;

    i = 0;
    if (*n_read_bytes != 0)
        *n_read_bytes = 0;
    if (*index != -1)
        *index = -1;
    if (stash != NULL)
    {
        while (i <= BUFFER_SIZE)
            stash[i++] = '\0';
    }
    if (s != NULL)
        free(s);
    return (NULL);
}

char *cook_line(char *s, char *s3, int *a, ssize_t *n_read_bytes)
{
    int     size;
    char    *s2;
    int     i;

    i = 0;
    size = ft_strlen(s);
    s2 = malloc(size + 1);
    if (s2 == NULL)
        ft_free_all(s, s3, a, n_read_bytes);
    while (i < size)
    {
        s2[i] = s[i];
        i++;
    }
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

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (current_index == -1 || current_index == BUFFER_SIZE)
    {
        n_read_bytes = read(fd, stash, BUFFER_SIZE);
        if (n_read_bytes <= 0)
            return (current_index = -1, NULL);
        current_index = 0;
    }
    if (current_index >= n_read_bytes)
        return (n_read_bytes = 0, current_index = -1, NULL);
    line = malloc(sizeof(char) * LINE_MAX_SIZE);
    if (line == NULL)
        return ft_free_all(line, stash, &current_index, &n_read_bytes);
    line[0] = '\0';

	//une fonction
    //jusquau backslash n et tant quon nest pas a la fin du fichier ,  on concat et on remet le current index a 0. si on arrive a la fin d fichier on break
    while ((pos = ft_strchri(stash, BUFFER_SIZE, '\n', current_index)) == -1 && n_read_bytes >= BUFFER_SIZE)
    {
        line = ft_concat(line, stash + current_index, BUFFER_SIZE - current_index, LINE_MAX_SIZE);
        if (line == NULL)
            return ft_free_all(line, stash, &current_index, &n_read_bytes);
        n_read_bytes = read(fd, stash, BUFFER_SIZE);
        if (n_read_bytes < 0) //free sqns nread bytes
            return (free(line), current_index = -1, NULL);
        current_index = 0;
        if (n_read_bytes == 0)
            break;
    }
    //si on ne  trouve pas le back slash n et que je suis a la fin du fichier, je mets tout
    if (pos == -1)
    {
        substring = ft_substr(stash, BUFFER_SIZE, current_index, n_read_bytes - current_index);
        if (substring == NULL)
            return ft_free_all(substring, stash, &current_index, &n_read_bytes);

		//
        line = ft_concat(line, substring, ft_strlen(substring), LINE_MAX_SIZE);
        if (line == NULL)
            return ft_free_all(substring, stash, &current_index, &n_read_bytes);
        free(substring);
		//
        n_read_bytes = 0;
        return (cook_line(line, stash, &current_index, &n_read_bytes));
    }
    //si jai trouve le backslash n ou que je suis pas a la fin du fichier
    if (n_read_bytes <= 0)
        return (free(line), NULL);

    substring = ft_substr(stash, BUFFER_SIZE, current_index, MIN(n_read_bytes, pos - current_index + 1));
    if (substring == NULL)
        return ft_free_all(line, stash, &current_index, &n_read_bytes);

	//
    line = ft_concat(line, substring, ft_strlen(substring), LINE_MAX_SIZE);
    if (line == NULL)
        return ft_free_all(substring, stash, &current_index, &n_read_bytes);
    free(substring);
    current_index = pos + 1;
    return (cook_line(line, stash, &current_index, &n_read_bytes));
}

#include <stdio.h>
#include <fcntl.h>
//
//int main()
//{
//    int fd;
//    char *myfile;
////
//    	myfile = "/home/juba/CLionProjects/gnl/giant_line.txt";
////    	myfile = "/home/juba/CLionProjects/gnl/giant_line_nl.txt";
//    	myfile = "/home/juba/CLionProjects/gnl/multiple_nl.txt";
//        myfile = "/home/juba/CLionProjects/gnl/1char.txt";
//    myfile = "/home/juba/CLionProjects/gnl/read_error.txt";
////    	myfile = "/home/juba/CLionProjects/gnl/bible.txt";
//	 	myfile = "/home/juba/CLionProjects/gnl/41_with_nl.txt";
//	myfile = "/home/juba/CLionProjects/gnl/multiple_line_no_nl.txt";
//    	myfile = "/home/juba/CLionProjects/gnl/variable_nls.txt";
//
//    //	myfile = "/home/faboussa/gnl2024/giant_line.txt";
//    //	myfile = "/home/faboussa/gnl2024/giant_line_nl.txt";
//    // myfile = "/home/faboussa/gnl2024/big_line_no_nl.txt";
//    //	myfile = "/home/faboussa/gnl2024/multiple_nl.txt";
//    //myfile = "/home/faboussa/gnl2024/1char.txt";
//    //myfile = "/home/faboussa/gnl2024/bible.txt";
//    //	myfile = "/home/faboussa/gnl2024/variable_nls.txt";
//    //myfile = "/home/faboussa/gnl2024/43_with_nl.txt";
//    //myfile = "/home/faboussa/gnl2024/41_with_nl.txt";
//    //myfile = "/home/faboussa/gnl2024/multiple_line_no_nl.txt";
//    //myfile = "/home/faboussa/gnl2024/read_error.txt";
//    fd = open(myfile, O_RDONLY);
//    if (fd < 0)
//        return (EXIT_FAILURE);
//    printf("fd file is %d\n", fd);
//
//    int nb_lines = 15;
//    int i = 0;
//    char *line = NULL;
//    while (i < nb_lines)
//    {
//        line = get_next_line(fd);
//        if (line != NULL)
//        {
//            printf(" line is %s", line);
//            free(line);
//        }
//        i++;
//    }
//
//    ////	printf("first line is %s\n", gnl(fd));
//    ////	printf("seco	nd line is %s\n", gnl(fd));
//    ////	printf("third line is %s\n", gnl(fd));
//    ////	printf("fourth line is %s\n", gnl(fd));
//    ////	printf("5th line is %s\n", gnl(fd));
//    ////	printf("6th line is %s\n", gnl(fd));
//    ////	printf("7th line is %s\n", gnl(fd));
//    ////	printf("8th line is %s\n", gnl(fd));
//    ////        printf("second line is %s", get_next_line(fd));
//    ////        printf("third line is %s", get_next_line(fd));
//    ////        printf("fourth line is %s", get_next_line(fd));
//    ////        printf("fifth line is %s", get_next_line(fd));
//    ////        printf("sixth line is %s", get_next_line(fd));
//    ////        printf("seventh line is %s", get_next_line(fd));
//    ////        printf("eighth line is %s", get_next_line(fd));
//    ////        printf("ninth line is %s", get_next_line(fd));
//    close(fd);
//    return (EXIT_SUCCESS);
//}
//
