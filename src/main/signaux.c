/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:12:21 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/21 23:30:09 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	handle_signaux(int sig)
{
	char	*tmp;
	char	cwd[PATH_MAX];

	if (!getcwd(cwd, sizeof(cwd)))
	{
		printf("%i", sig);
		handle_error("Could not get the path");
	}
	change_color(1, PINK);
	tmp = ft_strjoin(cwd, INPUTCLR);
	printf("\n%s", tmp);
	free(tmp);
}
