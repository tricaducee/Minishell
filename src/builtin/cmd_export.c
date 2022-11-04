/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:46:29 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/04 09:07:29 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	print_export(void)
{
	t_variables	*export;

	export = ft_get_export();
	if (export == NULL)
		return ;
	while (export)
	{
		if (export->value)
			printf("declare -x %s=\"%s\"\n", export->name, export->value);
		else
			printf("declare -x %s\n", export->name);
		export = export->next;
	}
}

t_variables	*get_last_node(t_variables *list)
{
	t_variables	*last;

	if (!list)
		return (NULL);
	last = list;
	while (list)
	{
		last = list;
		list = list->next;
	}
	return (last);
}

void	add_node_back(t_variables **list, t_variables *new)
{
	t_variables	*last;

	if (*list && new)
	{
		last = get_last_node(*list);
		last->next = new;
	}
	else
		*list = new;
}

t_variables	*update_list(char *arg)
{
	t_variables	*new;

	new = create_parsed_node(arg);
	//add_node_back(list, new);
	return (new);
}

int	cmd_export(t_shell *shell, t_cmdli *cmdli)
{
	t_variables	*export;
	int			invalid_identifier;

	if (ft_strslen(cmdli->cmd_args) == 1)
	{
		print_export();
		return (1);
	}
	export = shell->export;
	invalid_identifier = 0;
	while (*cmdli->cmd_args)
	{
		if (!ft_strcmp(*cmdli->cmd_args, "="))
		{
			invalid_identifier = 1;
			continue ;
		}
		while (export)
		{
			if (ft_strcmp(*cmdli->cmd_args, export->name) == 0)
			{
				return (1);
			}
			export = export->next;
		}
		++cmdli->cmd_args;
	}
	if (invalid_identifier)
		printf("export: `=': not a valid identifier\n");
	return (1);
}
