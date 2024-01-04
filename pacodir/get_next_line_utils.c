/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:02:50 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/02 19:35:11 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *string)
{
	int i;
	i = 0;
	while (string[i])
		i++;
	return (i);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *substr;
	size_t i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *) ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) <= start + len)
		substr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

void *ft_calloc(size_t count, size_t size)
{
	void *res;

	res = malloc(size * count);
	if (!res)
		return (0);
	ft_bzero(res, size * count);
	return (res);
}

void ft_bzero(void *s, size_t n)
{
	while (n--)
		*((unsigned char *) (s + n)) = 0;
}


int ft_strchri(char *s, char c, size_t index)
{
	while (index < (ft_strlen(s - 1)))
	{
		while (*(s + index) != '\0' && *(s + index) != c)
		{
			index++;
		}
	}
	if (*(s + index) == c)
		return (index);
	return -1;
}

char    *ft_strjoin(char const *s1, char const *s2, size_t dstsize)
{
	char            *new_string;
	long unsigned int          i;
	long unsigned int           j;
	long unsigned int           k;
	size_t          total_length;

	k = 1;
	total_length = ft_strlen(s1) + ft_strlen(s2);
	if (total_length + 1 >= k  * dstsize)
		k++;
	if (k != 1)
	{
		new_string = malloc(sizeof(char) * total_length + 1);
		if (new_string == NULL)
			return (0);
	}
	i = 0;
	while (i < ft_strlen(s1))
	{
		new_string[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		new_string[i] = s2[j];
		j++;
		i++;
	}
	new_string[i] = '\0';
	if (s1 != NULL)
		free((void *)s1);
	return (new_string);
}

char *ft_concat(char *dst, const char *src, size_t dstsize)
{
	unsigned long src_len = ft_strlen(src);
	unsigned long dst_len = ft_strlen(dst);
	unsigned long i = 1;
	char* old_dst = dst;
	while (src_len + dst_len + 1 >= i * dstsize)
		i++;
//	i = src_len + dst_len + 1 / dstsize;
	if (i != 1)
		dst = (char *) realloc(dst, i * dstsize * sizeof(char));
	if (dst == NULL)
	{
		free(old_dst);
		return NULL;
	}
	while (*src != '\0')
	{
		dst[dst_len] = *src;
		dst_len++;
		src++;
	}
	dst[dst_len] = '\0';
	return dst;
}

void *ft_realloc(void *ptr, size_t newsize)
{
	char *newptr;
	size_t cursize;

	if (ptr == 0)
		return (malloc(newsize));
	cursize = sizeof(ptr);
	if (newsize <= cursize)
		return (ptr);
	newptr = malloc(sizeof (char)* newsize);
	if (newptr == NULL)
		return NULL;
	ft_memcpy(ptr, newptr, cursize);
	free(ptr);
	return (newptr);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *oct1;
	unsigned char *oct2;

	if (dst == src || n == 0)
		return (dst);
	oct1 = (unsigned char *) dst;
	oct2 = (unsigned char *) src;
	while (n--)
		*oct1++ = *oct2++;
	return (dst);
}