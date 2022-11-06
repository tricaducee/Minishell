/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __init__.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:26:32 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/06 14:50:44 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_variables	*__init_variables(t_variables *node, char **v_env)
{
	t_variables	*ret;
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strdup(v_env[0]);
	node = create_parsed_node(tmp);
	ret = node;
	free(tmp);
	while (v_env[++i])
	{
		tmp = ft_strdup(v_env[i]);
		node->next = create_parsed_node(tmp);
		free(tmp);
		node = node->next;
	}
	return (ret);
}

void    sort_alpha(t_variables **exp, t_variables *new_node)
{
    t_variables    *prev;
    t_variables    *current;

    prev = NULL;
    current = *exp;
    while (current)
    {
        if (ft_strcmp(current->name, new_node->name) >= 0)
        {
            if (prev)
                prev->next = new_node;
            else
                (*exp) = new_node;
            new_node->next = current;
            return ;
        }
        prev = current;
        current = current->next;
    }
    if (!current)
        prev->next = new_node;
}

t_variables	*__init_exp(t_variables *old_env)
{
	t_variables	*exp;

	if (!old_env)
		return (NULL);
	exp = create_node_name_value(old_env->name, old_env->value);
	while (old_env->next)
	{
		old_env = old_env->next;
		sort_alpha(&exp, create_node_name_value(old_env->name, old_env->value));
	}
	return (exp);
}

void	print_exp(t_variables *exp)
{
	while (exp)
	{
		printf("%s=%s\n", exp->name, exp->value);
		exp = exp->next;
	}
}

int	__init_env(t_shell *shell, char **v_env)
{
	shell->str_env = v_env;
	shell->env = __init_variables(shell->env, v_env);
	if (!shell->env)
		return (1);
	return (0);
}

int	__init__(t_shell *shell, char **v_env)
{
	ft_get_shell(shell);
	if (__init_env(shell, v_env))
		return (1);
	shell->export = __init_exp(shell->env);
	if (!shell->export)
		return (1);
	return (0);
}
