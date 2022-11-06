/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_in_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:54:58 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/06 14:30:30 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"
#include "../../../printfd/HEADER/ft_printfd.h"

int	set_buildin_redirect(t_cmdli *cmdli)
{
	if (!cmdli->pipe_in && !cmdli->pipe_out)
		return (run_builtin(cmdli->cmd, cmdli, ft_get_shell(NULL)));
	cmdli->pid = fork();
	if (cmdli->pid == -1)
	{
		g_errno = errno;
		ft_printfd(2, "#+wminishell#0:#/r %s#0\n", strerror(g_errno));
		return (g_errno);
	}
	else if (cmdli->pid == 0)
	{
		set_redirection(cmdli);
		run_builtin(cmdli->cmd, cmdli, ft_get_shell(NULL));
		exit (0);
	}
	else
		return (1);
	return (0);
}