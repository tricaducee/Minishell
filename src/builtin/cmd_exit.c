/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:25:57 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/04 10:25:50 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	cmd_exit(t_shell *shell, t_cmdli **cmdli)
{
	int	error;

	if ((*cmdli)->cmd_args[1])
		error = ft_atoi((*cmdli)->cmd_args[1]);
	else
		error = 0;
	free_nodes_contents(&shell->export);
	free_nodes(&shell->env);
	free_cmdli(cmdli);
	exit(error);
}
