/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:33:42 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/06 14:48:13 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	cmd_unset(t_shell *shell, char **args)
{
	int			i;
	t_variables	*env;

	if (!shell->env || !shell->export || !args)
		return ;
	i = 0;
	while (args[i])
	{
		if (!ft_is_uppercase(args[i]))
			return ;
		env = shell->env;
		while (env)
		{
			if (ft_strcmp(args[i], env->name) == 0)
			{
				printf("ft_unset argument %d : [%s]\n", i, args[i]);
				env->next = env->next->next;
				break ;
			}
			env = env->next;
		}
		++i;
	}
}
