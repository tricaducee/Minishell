/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:40:20 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/12 15:40:58 by tgoel            ###   ########.fr       */
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

static void	free_useful(t_useful *useful)
{
	if (useful)
	{
		free(useful);
		useful = NULL;
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
	free_useful(shell->useful);
}
