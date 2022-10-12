/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 22:49:23 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/18 23:06:40 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_ast	*create_root(char *value)
{
	t_ast	*new_root;
	
	new_root = malloc(sizeof(t_ast));
	if (!new_root)
		return (NULL);
	new_root->right = NULL;
	new_root->left = NULL;
	new_root->value = value;
	return (new_root);
}

void	add_right(t_ast *root, char *value)
{
	t_ast	*tree_right;

	tree_right = create_root(value);
	root->right = tree_right; 
}

void	add_left(t_ast *root, char *value)
{
	t_ast	*tree_left;

	tree_left = create_root(value);
	root->left = tree_left; 
}
