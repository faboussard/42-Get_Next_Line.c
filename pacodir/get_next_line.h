/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:42:31 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/02 19:43:10 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H

#define LINE_MAX_SIZE 1000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif //BUFFER_SIZE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>

void	ft_bzero(void *s, size_t n);
char *get_next_line(int fd);
long unsigned int  ft_strlen(const char *string);
void *ft_memcpy(void *dst, const void *src, size_t n);
void    *ft_calloc(size_t nmemb, size_t size);
void	*ft_realloc(void *ptr, size_t newsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char *ft_concat(char *dst, const char* src, size_t dstsize);
int ft_strchri(char *s, char c, size_t index);
char    *ft_strjoin(char const *s1, char const *s2, size_t dstsize);


#endif //GNL_GET_NEXT_LINE_H