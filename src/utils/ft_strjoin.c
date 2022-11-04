/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:08:47 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 07:31:18 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = 0;
	return (new_str);
}

char	*ft_strjoin2(char *s1, char *s2)
{
    char    *str;
    char    *ret;

    str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    ret = str;
    if (!str)
        return (0);
    if (s1)
        while (*s1)
            *(str++) = *(s1++);
    if (s2)
        while (*s2)
            *(str++) = *(s2++);
    *str = 0;
    return (ret);
}