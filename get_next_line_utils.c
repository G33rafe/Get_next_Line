/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajacque <rajacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:20:45 by rajacque          #+#    #+#             */
/*   Updated: 2022/09/06 13:51:16 by rajacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nbr, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if (nbr == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	ptr = malloc(nbr * size);
	if (!ptr)
		return (NULL);
	while (i < nbr * size)
	{
		*(char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = (char *)ft_calloc(sizeof(char), 1);
	if (!s1 || !s2)
		return (NULL);
	str = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	free (s1);
	return (str);
}
