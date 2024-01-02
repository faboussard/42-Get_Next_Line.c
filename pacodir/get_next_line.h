/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:42:31 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/02 19:17:38 by faboussa         ###   ########.fr       */
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
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
void    *ft_calloc(size_t nmemb, size_t size);
void    *ft_memset(void *s, int c, size_t n);
long unsigned int  ft_strlen2(const char *string);
void	*ft_realloc(void *ptr, size_t newsize);
long unsigned int  ft_strlen_special(const char *string);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char *ft_concat(char *dst, const char* src, size_t dstsize);
int ft_strchri(const char *s, char c, int start_index);
char	*ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif //GNL_GET_NEXT_LINE_H