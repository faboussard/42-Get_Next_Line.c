#include "get_next_line.h"

long unsigned int  ft_strlen(const char *string)
{
	int i;
	i = 0;
	while (string[i])
		i++;
	return (i);
}


char    *ft_strjoin(char const *s1, char const *s2)
{
    char            *new_string;
    long unsigned int          i;
    long unsigned int           j;
    size_t          total_length;

    total_length = ft_strlen(s1) + ft_strlen(s2);
    new_string = malloc(sizeof(char) * total_length + 1);
    if (new_string == NULL)
        return (0);
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
    if (s1)
        free((void*)(s1));
    if (s2)
        free((void*)(s2));
    new_string[i] = '\0';
    return (new_string);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char	*substr;
    size_t	i;

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

void	*ft_calloc(size_t count, size_t size)
{
    void	*res;

    res = malloc(size * count);
    if (!res)
        return (0);
    ft_bzero(res, size * count);
    return (res);
}
void	ft_bzero(void *s, size_t n)
{
    while (n--)
        *((unsigned char *)(s + n)) = 0;
}

int	ft_strchr(char s, int c)
{
	char	*result;

	result = (char *)s;
	while (*result != '\0' && *result != (char)c)
		result++;
	if (*result == (char)c)
		return (1);
	else
		return (0);
}