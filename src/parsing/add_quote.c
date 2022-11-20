/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 06:58:54 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/20 14:02:44 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*add_quote(char **cmdline, char *str, unsigned int *i)
{
	char			*ret;
	unsigned int	j;
	char			*tmp;
	char			*new;

	++*i;
	ret = NULL;
	j = 0;
	while ((*cmdline)[*i + j] && (*cmdline)[*i + j] != '\'')
		j++;
	tmp = str;
	new = ft_substr((*cmdline), *i, j);
	if (!new)
	{
		if (tmp)
			free(tmp);
		return (NULL);
	}
	ret = ft_strjoin(str, new);
	free(new);
	if (tmp)
		free(tmp);
	if (ret)
		*i += j + 1;
	return (ret);
}
