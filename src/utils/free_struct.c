/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:40:20 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 07:50:44 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* FREE MEMO :
 *
 *	STRUCT USEFUL: OK
 *
 *	STRUCT SHELL: (nothing to free)
 *		line: 			OK	
 *  
*/


void	free_export(t_variables **vars)
{
	t_variables	*tmp;

	while (*vars)
	{
		tmp = *vars;
		free((*vars)->name);
		free((*vars)->value);
		*vars = (*vars)->next;
		free(tmp);
	}
}


void	free_struct(t_shell *shell)
{
	if (shell)
	{
		if (shell->line)
		{
			free(shell->line);
			shell->line = NULL;
		}
	}
	free_cmdli(&shell->cmdli);
	free_export(&shell->export);
}
