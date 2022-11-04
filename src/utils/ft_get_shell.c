/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 04:27:27 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/04 04:32:06 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_shell	*ft_get_shell(t_shell *new_shell)
{
	static t_shell	*shell;

	if (new_shell)
		shell = new_shell;
	return (shell);
}
