/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:04:50 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/21 23:10:23 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	**split_path(char *env_path)
{
	char **path_splitted;

	path_splitted = ft_split(env_path, ':');
	if (!path_splitted)
		handle_error("Could not split the path");
	return (path_splitted);
}

int	check_access(char **env_path)
{

}