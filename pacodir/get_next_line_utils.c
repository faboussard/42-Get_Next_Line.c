/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faboussa <faboussa@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:02:50 by faboussa          #+#    #+#             */
/*   Updated: 2024/01/05 02:46:01 by faboussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "get_next_line.h"

size_t ft_strlen(const char *string)
{
	int i;
	i = 0;
	while (string[i])
		i++;
	return (i);
}

char *ft_substr(char const *s, size_t total_len, unsigned int start, size_t len)
{
	char *substr;
	size_t i;

	i = 0;
	if (!s)
		return (NULL);
//	if (start >= ft_strlen(s))
	if (start >= total_len)
		return ((char *) ft_calloc(1, sizeof(char)));
	if (total_len <= start + len)
		substr = malloc(sizeof(char) * (total_len - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (start < total_len && i < len)
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


int ft_strchri(char *s, size_t len, char c, size_t index)
{

	while (index < len - 1 && *(s + index) != c)
	{
		index++;
	}

	if (s[index] == c)
		return (index);
	return -1;
}

char *ft_concat(char *dst, const char *src, size_t src_len, size_t dstsize)
{
	unsigned long dst_len = ft_strlen(dst);
	unsigned long i;

	i = 1;
	while (src_len + dst_len + 1 >= i * dstsize)
		i++;
	if (i != 1)
		dst = (char *) ft_realloc(dst, src_len + dst_len, i * dstsize * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (dst);
}

void *ft_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new;
	char *temp;
	unsigned int i;

	i = 0;
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
			return (NULL);
		return (ptr);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(new_size);
	if (new == NULL)
    {
        free(ptr);
        return (NULL);
    }
	old_size = (new_size < old_size) ? new_size : old_size;
	temp = ptr;
	while (i < old_size)
	{
		*(new + i) = *(temp + i);
		i++;
	}
	free(ptr);
	return (new);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t			i;
    unsigned char	*byte_dest;
    unsigned char	*byte_src;

    byte_dest = (unsigned char *) dest;
    byte_src = (unsigned char *) src;
    i = 0;
    if (dest == NULL && src == NULL)
        return (dest);
    while (i < n)
    {
        byte_dest[i] = byte_src[i];
        i++;
    }
    return (dest);
}