/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:58:57 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 04:39:29 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (!s)
		return (NULL);
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[x])
	{
		if (len > y && start <= x)
		{
			substr[y] = s[x];
			y++;
		}
		x++;
	}
	substr[y] = '\0';
	return (substr);
}

int	bloc_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (i == 0 && *s != c)
		{
			i = 1;
			count++;
		}
		else if (i == 1 && *s == c)
			i = 0;
		s++;
	}
	return (count);
}

int	block_len(char *s, char c)
{
	int	len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

void	*array_free(char **array, int i)
{
	while (i > 0)
	{
		free(array[i]);
		i--;
	}
	free (array[i]);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	char	**array;
	int		blockcount;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	blockcount = bloc_count((char *)s, c);
	array = (char **)malloc(sizeof(char **) * (blockcount + 1));
	if (!array)
		return (NULL);
	while (blockcount--)
	{
		while (*s == c && *s != '\0')
			s++;
		array[i] = ft_substr2((char *)s, 0, block_len((char *)s, c));
		if (!array)
			return (array_free(array, i));
		s = s + block_len((char *)s, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}

