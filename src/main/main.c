/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:57:32 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 13:51:41 by tgoel            ###   ########.fr       */
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
	t_cmdli	*cmdli_i;

	(void)shell;
	sig_handler(shell);
	while (1)
	{
		read = readline(_static_prompt());
		if (read)
		{
			if (*read)
				add_history(read);
			cmdli = get_cmds(&read);
			if (cmdli)
			{
				cmdli_i = cmdli;
				while (cmdli_i)
				{
					shell->if_sig = 0;
					exec_cmd(cmdli_i);
					cmdli_i = cmdli_i->next;
				}
				free_cmdli(&cmdli);
			}
			while (wait(NULL) != -1)
				;
			free(read);
			printf("\n");
			shell->if_sig = 1;
		}
		else
			exit(0);
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
