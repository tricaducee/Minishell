/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:59:19 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 13:07:23 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	return_error(char *debug)
{
	if (debug)
		ft_printfd(1, "Here : line %s\n", debug);
	g_errno = errno;
	ft_printfd(2, "#+bminishell#0: #/r%s#0\n", strerror(g_errno));
	return (g_errno);
}

int	exit_error(void)
{
	g_errno = errno;
	ft_printfd(2, "#+wminishell#0: #/r%s#0\n", strerror(g_errno));
	exit(g_errno);
}