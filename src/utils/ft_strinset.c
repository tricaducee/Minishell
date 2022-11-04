/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 08:56:21 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 08:56:36 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_strinset(char *str, char *set)
{
	unsigned int	i;

	while (*str)
	{
		i = 0;
		while (set[i] && set[i] != *str)
			i++;
		if (!set[i])
			return (1);
		str++;
	}
	return (0);
}