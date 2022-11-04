/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:37:25 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 04:15:27 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	len_b_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}

static char	*split_before_equal(char *str)
{
	char	*b_equal;
	int	size;
	int	i;

	size = len_b_equal(str);
	b_equal = malloc(sizeof(char) * size + 1);
	i = 0;
	while (i < size)
	{
		b_equal[i] = str[i];
		i++;
	}
	b_equal[i] = 0;
	return (b_equal);
}

static char	*split_after_equal(char *str)
{
	char	*a_equal;
	int	i;

	a_equal = malloc(sizeof(char) * ft_strlen(str) + 1);
	i = -1;
	while (str[++i])
		a_equal[i] = str[i];
	a_equal[i] = 0;
	return (a_equal);
}

int	modify_node(t_variables *node, char *str)
{
	node->name = split_before_equal(str);
	node->value = split_after_equal(str + (len_b_equal(str) + 1));
	return (0);
}

t_variables *create_node_name_value(char *name, char *value)
{
	t_variables	*new_node;

	new_node = malloc(sizeof(t_variables));
	new_node->name = name;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

t_variables *create_parsed_node(char *str)
{
	t_variables	*next_node;

	next_node = malloc(sizeof(t_variables));
	modify_node(next_node, str);
	next_node->next = NULL;
	return (next_node);
}
