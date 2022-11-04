/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 00:31:19 by hermesrolle       #+#    #+#             */
/*   Updated: 2022/11/04 05:53:57 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	interpret(t_cmdli **cmds_list, char **cmdline,
					t_type *type, unsigned int *i)
{
	while ((*cmdline)[*i] == ' ' ||
			((*cmdline)[*i] >= '\t' && (*cmdline)[*i] <= '\r'))
		++*i;
	if ((*cmdline)[*i] == '<')
		type_and_set(split_cmd(cmdline, i, '<'), cmds_list, type, 1);
	else if ((*cmdline)[*i] == '>')
		type_and_set(split_cmd(cmdline, i, '>'), cmds_list, type, 1);
	else if ((*cmdline)[*i] == '|')
		type_and_set(split_cmd(cmdline, i, '|'), cmds_list, type, 1);
	else if ((*cmdline)[*i] == '&')
		type_and_set(split_cmd(cmdline, i, '&'), cmds_list, type, 1);
	else
		type_and_set(split_cmd_sp(cmdline, i), cmds_list, type, 0);
}

t_cmdli	*get_cmds(char **cmdline)
{
	unsigned int	i;
	t_cmdli			*cmds_list;
	t_type			type;

	if (!(*cmdline))
		return (NULL);
	i = 0;
	type = 0;
	cmds_list = NULL;
	while ((*cmdline)[i])
	{
		interpret(&cmds_list, cmdline, &type, &i);
		if (!cmds_list)
			return (NULL);
	}
	if (type != CMD && type != ARG && type != RFILE)
		return (error_cmdli_nl(&cmds_list));
	return (cmdli_first(cmds_list));
}
