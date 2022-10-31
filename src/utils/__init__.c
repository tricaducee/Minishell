/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:26:32 by tgoel             #+#    #+#             */
/*   Updated: 2022/10/31 16:47:01 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	__init_env(t_env *node, char **v_env)
{
	int		i;
	char	*tmp;

	i = -1;
	while (v_env[++i])
	{
		tmp = ft_strdup(v_env[i]);
		node = create_parsed_node(tmp);
		node->index = i;
		free(tmp);
		node = node->next;
	}
	return (0);
}

static int	__init_useful(t_useful *useful)
{
	if (cmd_pwd(useful, 0))
		return (1);
	return (0);
}

void	print_nodes(t_env *node)
{
	int	i;

	i = 0;
	while (node->next)
	{

		i++;
		node = node->next;
	}
}

int	__init__(t_shell *shell, char **v_env)
{
	if (__init_useful(&shell->useful))
		return (1);
	if (__init_env(&(shell->global_env), v_env))
		return (1);
	return (0);
}
