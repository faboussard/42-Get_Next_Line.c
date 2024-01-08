/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:42:31 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/05 02:46:12 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H

#define LINE_MAX_SIZE 1000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif //BUFFER_SIZE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>

void	ft_bzero(void *s, size_t n);
char *get_next_line(int fd);
int  ft_strlen(const char *string);
void    *ft_calloc(size_t nmemb, size_t size);
char *ft_substr(char const *s, size_t total_len, unsigned int start, size_t len);
char *ft_concat(char *dst, const char *src, size_t src_len, size_t dstsize);
int ft_strchri(char *s, size_t len, char c, size_t index);
void *ft_realloc(void *ptr, unsigned int new_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif //GNL_GET_NEXT_LINE_H