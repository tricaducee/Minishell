/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 07:46:33 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/05 08:53:08 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*
	dirp->d_type:
	type: 8 = fichier / 4 = dossier

	dirp->d_name:
	name of the
*/
char	**dir_name(void)
{
	char				tmp[PATH_MAX];
	DIR					*dp;
	struct dirent		*dirp;
	static char			**rtn_val;
	char				**rtn_tmp;

	if (rtn_val)
		rtn_val++;
	getcwd(tmp, PATH_MAX);
	dp = opendir(tmp);
	dirp = readdir(dp);
	while(dirp)
	{
		rtn_tmp = rtn_val;
		rtn_val = ft_strsjoin(ft_strdup(dirp->d_name), rtn_tmp);
		if (rtn_tmp)
		{
			free(rtn_tmp);
			rtn_tmp = NULL;
		}
		dirp = readdir(dp);
	}
	closedir(dp);
	return (rtn_val);
}

char	*send_one_file(void)
{
	static char	**d;

	if (!d)
		d = dir_name();
	else
		d++;
	return (*d);
}