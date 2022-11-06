/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:09:31 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/06 13:54:41 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

// cmdli->cmd_arg

int	cmd_cd(t_cmdli *cmdli)
{
	char	*tmp;

	if (!cmdli->cmd_args[1])
	{
		tmp = ft_get_var("HOME");
		if(chdir(tmp))
			ft_printfd(2, "cd: %s: %s\n", strerror(errno), ft_get_var("HOME"));
		free(tmp);
	}
	else if (chdir(cmdli->cmd_args[1]))
		ft_printfd(2, "cd: %s: %s\n", strerror(errno), cmdli->cmd_args[1]);
	return (1);
}
