/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_uppercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:02:50 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 09:03:04 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_is_uppercase(char *str)
{
	printf("dans ft_is_uppercase\n");
	if (!str)
		return (0);
	while (*str)
	{
		if (*str <= 'A' || *str >= 'Z')
			return (0);
		++str;
	}
	return (1);
}