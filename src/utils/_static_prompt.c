/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _static_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:32:46 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/05 06:32:21 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	l(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while(str[i])
		i++;
	return (i);
}

static char	*prompt_join(char *s1, char *s2, char *s3)
{
	int		i;
	char	*new_str;

	if (!s1 || !s2 || !s3)
		return (NULL);
	i = 0;
	new_str = malloc(sizeof(char) * (l(s1) + l(s2) + l(s3) + 1));
	if (!new_str)
		return (NULL);
	while (*s1)
		new_str[i++] = *s1++;
	while (*s2)
		new_str[i++] = *s2++;
	while (*s3)
		new_str[i++] = *s3++;
	new_str[i] = 0;
	return (new_str);
}

int		is_in_git(char *current_dir, char *dir_to_check)
{
	DIR 	*dir_return;
	char	*git_dir;

	git_dir = prompt_join(current_dir, "/", dir_to_check);
	dir_return = opendir(git_dir);
	free(git_dir);
	if (!dir_return)
	{
		free(dir_return);
		return (0);
	}
	free(dir_return);
	return (1);
}

char	*_static_prompt(void)
{
	static	char *full_prompt;
	char	tmp[PATH_MAX];

	if (full_prompt)
		free(full_prompt);
	if (is_in_git(getcwd(tmp, PATH_MAX), ".git"))
		full_prompt =  prompt_join("\033[32;1mMinishell\033[0m 🍋 \033[33;3m", getcwd(tmp, PATH_MAX), "\t\t\tGIT DETECTED\n\033[0m🔥 ➤ ");
	else
		full_prompt =  prompt_join("\033[32;1mMinishell\033[0m 🍋 \033[33;3m", getcwd(tmp, PATH_MAX), "\n\033[0m🔥 ➤ ");
	return (full_prompt);
}
