/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:58:36 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 09:01:13 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_nodes(t_variables **list)
{
	t_variables	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}

void	free_nodes_contents(t_variables **list)
{
	t_variables	*tmp;

	while (*list)
	{
		if ((*list)->name)
			free((*list)->name);
		if ((*list)->value)
			free((*list)->value);
		tmp = *list;
		*list = (*list)->next;
		free(tmp);
	}
}