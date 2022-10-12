/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:26:32 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/11 16:30:55 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	__init_useful(t_useful *useful)
{
	if (cmd_pwd(useful, 0))
		return (1);
	return (0);
}

int	__init__(t_shell *shell)
{
	shell->useful = malloc(sizeof(t_useful));
	if (!shell->useful)
		return (1);
	if (__init_useful(shell->useful))
		return (1);
	return (0);
}
