/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:57:15 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/06 14:25:03 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/*
	run the builtin
*/
int	run_builtin(char *str, t_cmdli *cmd, t_shell *shell)
{
	if (ft_strcmp(str, "env") == 0)
		cmd_env(shell);
	else if (ft_strcmp(str, "export") == 0)
		cmd_export(shell, cmd);
	else if (ft_strcmp(str, "pwd") == 0)
		cmd_pwd();
	if (!ft_strcmp(str, "echo"))
		cmd_echo(&cmd->cmd_args[1]);
	if (!ft_strcmp(str, "cd"))
		cmd_cd(cmd);
	if (!ft_strcmp(str, "exit"))
		cmd_exit(shell, &cmd);
	return (1);
}

int	is_builtin(t_cmdli *cmd, t_shell *shell)
{
	const char	*builtins[]
		= {"echo", "cd", "pwd", "env", "export", "unset", "exit", NULL};
	int			builtin_len;
	int			i;

	if (!cmd || !cmd->cmd)
		return (0);
	i = 0;
	while (builtins[i])
	{
		builtin_len = ft_strlen((char *)builtins[i]);
		if (ft_strncmp(builtins[i], cmd->cmd, builtin_len) == 0)
			return (run_builtin((char *)builtins[i], cmd, shell));
		++i;
	}
	return (0);
}

int	is_builtin_no_run(t_cmdli *cmd)
{
	const char	*builtins[]
		= {"echo", "cd", "pwd", "env", "export", "unset", "exit", NULL};
	int			builtin_len;
	int			i;

	if (!cmd || !cmd->cmd)
		return (0);
	i = 0;
	while (builtins[i])
	{
		builtin_len = ft_strlen((char *)builtins[i]);
		if (ft_strncmp(builtins[i], cmd->cmd, builtin_len) == 0)
			return (1);
		++i;
	}
	return (0);
}
