/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:42:31 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/10 09:22:00 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H
#define GNL_GET_NEXT_LINE_H

#define LINE_MAX_SIZE 50000

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif //BUFFER_SIZE

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>

char *get_next_line(int fd);
int  ft_strlen(const char *string);
char *ft_substr(char const *s, size_t total_len, unsigned int start, size_t len);
char *ft_concat(char *dst, const char *src, size_t src_len, size_t dstsize);
int ft_strchri(const char *s, size_t len, char c, size_t index);
void *ft_realloc(void *ptr, unsigned int new_size);
//int is_stash_empty(const char stash[BUFFER_SIZE]);
char *cook_line(char *s);
//void set_current_index(char (*stash)[BUFFER_SIZE], size_t current_index);
//int find_current_index(const char stash[BUFFER_SIZE]);
int ft_stash(const int action, char (*stash)[BUFFER_SIZE], size_t current_index);

#endif //GNL_GET_NEXT_LINE_H