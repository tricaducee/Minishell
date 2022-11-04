/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdli_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 06:42:18 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/04 11:15:39 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_strcmp_int(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 || *s2)
		return (0);
	return (1);
}

int	ft_strslen(char **s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	**ft_strsjoin(char *s, char **ss)
{
	char			**ret;
	unsigned int	i;

	ret = malloc((ft_strslen(ss) + 2) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	if (ss)
	{
		while (ss[i])
		{
			ret[i] = ss[i];
			++i;
		}
	}
	ret[i] = s;
	ret[++i] = 0;
	return (ret);
}
