/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:26:32 by tgoel             #+#    #+#             */
/*   Updated: 2022/10/30 23:25:31 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	__init_env(t_env *node, char **v_env)
{

	return (0);
}

static int	__init_useful(t_useful *useful)
{
	if (cmd_pwd(useful, 0))
		return (1);
	return (0);
}

int	__init__(t_shell *shell, char **v_env)
{
	if (__init_useful(&shell->useful))
		return (1);
	if (__init_env(&shell->env, v_env))
		return (1);
	return (0);
}
