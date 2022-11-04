/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:12:42 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/04 08:52:17 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	printlist(t_variables *top)
{
	while (top)
	{
		printf("%s=%s\n", top->name, top->value);
		top = top->next;
	}
}

int	cmd_env(t_shell *shell)
{
	printlist(shell->env);
	return (1);
}
