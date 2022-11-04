/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:23:07 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/04 08:49:54 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	cmd_pwd(void)
{
	char	*cwd;
	char	buff[PATH_MAX];

	cwd = getcwd(buff, PATH_MAX);
	if (cwd != NULL)
		printf("%s\n", cwd);
	return (1);
}
