/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:12:21 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 14:01:30 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// void	handle_signaux(int sig)
// {
// 	(void)sig;
// 	printf("\n\n%s", _static_prompt());
// }

void	handle_interrupt(int sig)
{
	t_shell	*shell;

	shell = ft_get_shell(NULL);
	if (sig == SIGINT && shell->if_sig)
	{
		write(1, "\n\n", 2);
		printf("%s", _static_prompt());
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/*
	handle ctrl + \
	no ^C with ECHOCTL option
*/
void	sig_handler(t_shell *shell)
{
	struct termios	term_flag;

	if (tcgetattr(0, &term_flag) != 0)
	{
		perror("tcgetattr() error");
		g_errno = -1;
	}
	term_flag.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term_flag);
	sigaction(SIGINT, &shell->sa_int, NULL);
	sigaction(SIGQUIT, &shell->sa_bs, NULL);
}