/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:12:21 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 12:24:11 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_signaux(int sig)
{
	(void)sig;
	printf("\n\n%s", _static_prompt());
}

void	sig_handler(t_shell *shell)
{
	struct termios	flag;

	if (tcgetattr(0, &flag) != 0)
		perror("tcgetattr() error");
	flag.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &flag);
	sigaction(SIGINT, &shell->sa_int, NULL);
	sigaction(SIGQUIT, &shell->sa_bs, NULL);
	printf("\n\n%s", _static_prompt());
}