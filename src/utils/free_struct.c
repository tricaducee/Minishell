/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:40:20 by tgoel             #+#    #+#             */
/*   Updated: 2022/10/30 17:38:45 by tgoel            ###   ########.fr       */
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
}
