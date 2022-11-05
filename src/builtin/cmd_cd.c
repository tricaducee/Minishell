/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:09:31 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/05 06:36:17 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	cmd_cd(char **opti)
{
	if (chdir(opti[1]) != 0)
		ft_printfd(2, "cd: %s: %s\n", strerror(errno), opti[1]);
	return (1);
}
