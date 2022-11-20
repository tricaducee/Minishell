/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmdli.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 06:48:33 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/20 14:02:58 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmdli	*create_cmdli(void)
{
	t_cmdli	*ret;

	ret = malloc(1 * sizeof(t_cmdli));
	if (!ret)
		return (NULL);
	*ret = (t_cmdli){};
	ret->fd_in = -1;
	ret->fd_out = -1;
	return (ret);
}

	// ret->cmd = NULL;
	// ret->cmd_args = NULL;
	// ret->pipe_in = NULL;
	// ret->pipe_out = NULL;
	// ret->file_in = NULL;
	// ret->file_out = NULL;
	// ret->file_type = EMPTY;
	// ret->here_doc = NULL;
	// ret->and_or = 0;
	// ret->previous = NULL;
	// ret->next = NULL;
