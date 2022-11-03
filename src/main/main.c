/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:57:32 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/03 01:41:03 by tgoel            ###   ########.fr       */
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
	char	*save_line;

	while (1)
	{
		change_color(1, PINK);
		shell->useful.display = ft_strjoin(shell->useful.cwd, INPUTCLR);
		signal(SIGINT, handle_signaux);
		shell->line = readline(shell->useful.display);
		add_history(shell->line);
		free(shell->useful.display);
		save_line = shell->line;
		if (save_line == NULL)
			break ;
		while (*save_line == ' ' || *save_line == '\t')
			save_line++;
		if (*save_line)
		{
			shell->to_parse = ft_split(save_line, ' ');
			if (!strcmp("exit", shell->to_parse[0]))
			{
				free_while(NULL, shell->to_parse);
				break ;
			}
			free_while(shell->line, shell->to_parse);
		}
	}
	return (0);
}

// initialiser les structs
int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	if (!argc || argv)
		write(1, "", 1);
	if (__init__(&shell, env))
		return (1);
	//while_loop(&shell);
	//free_struct(&shell);
	return (0);
}
