/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:57:32 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 07:57:46 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// free tout ce qui doit etre free dans la boucle while
void	free_while(char *s1, char **splitted)
{
	int	i;

	i = -1;
	if (s1 && *s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (splitted)
	{
		while (splitted[++i])
		{
			free(splitted[i]);
			splitted[i] = NULL;
		}
		free(splitted);
		splitted = NULL;
	}
}

int	while_loop(t_shell *shell)
{
	char	*read;
	t_cmdli	*cmdli;
	//t_cmdli	*cmdli_i;

	while (1)
	{
		change_color(1, PINK);
		shell->useful.display = ft_strjoin(shell->useful.cwd, INPUTCLR);
		signal(SIGINT, handle_signaux);
		read = readline(shell->useful.display);
		free(shell->useful.display);
		if (read)
		{
			add_history(read);
			signal(SIGINT, handle_signaux);
			cmdli = get_cmds(&read);
			free(read);
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	if (!argc || argv)
		write(1, "", 1);
	if (__init__(&shell, env))
		return (1);
	while_loop(&shell);
	free_struct(&shell);
	exit(0);
}
