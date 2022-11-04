/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:17:32 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/04 04:31:51 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_variables	*ft_get_env(void)
{
	t_shell	*shell;

	shell = ft_get_shell(NULL);
	return (shell->env);
}
