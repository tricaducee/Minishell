/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:43:07 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 08:44:50 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**free_tab_null(char **ss)
{
	unsigned int	i;

	i = 0;
	if (!ss)
		return (NULL);
	while (ss[i])
		free(ss[i++]);
	free(ss);
	return (NULL);
}
