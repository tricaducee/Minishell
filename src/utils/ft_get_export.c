/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:44:08 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/04 04:29:24 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_variables	*ft_get_export(void)
{
	t_shell	*shell;

	shell = ft_get_shell(NULL);
	return (shell->export);
}
