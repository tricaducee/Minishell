/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:57:41 by tgoel             #+#    #+#             */
/*   Updated: 2022/10/30 16:52:22 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	cmd_echo(int n, char *display)
{
	if (n)
		printf("%s", display);
	else
		printf("%s\n", display);
	return (0);
}

int	cmd_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

int	cmd_unset(char *unsetted)
{
	if (!unsetted)
		return (1);
	printf("Does nothing for now: unset\n");
	return (1);
}

int	cmd_export(char *exported)
{
	if (!exported)
		return (1);
	printf("Does nothing for now: EXPORT\n");
	return (1);
}

int	cmd_pwd(t_useful *useful, int display)
{
	if (!getcwd(useful->cwd, sizeof(useful->cwd)))
	{
		perror("Getcwd() error\n");
		return (1);
	}
	if (display)
		printf("%s\n", useful->cwd);
	return (0);
}

int	cmd_cd(t_useful *useful, char *path)
{
	if (chdir(path))
	{
		printf("Path does not exist\n");
		return (1);
	}
	cmd_pwd(useful, 0);
	return (0);
}
