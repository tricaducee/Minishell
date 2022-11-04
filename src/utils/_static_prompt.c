/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _static_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:32:46 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 11:01:19 by tgoel            ###   ########.fr       */
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

char	*_static_prompt(void)
{
	static	char *full_prompt;
	char	tmp[PATH_MAX];

	if (full_prompt)
		free(full_prompt);
	full_prompt =  prompt_join("\033[32;1mMinishell\033[0m 🍋 \033[33;3m", getcwd(tmp, PATH_MAX), "\n\033[0m🔥 ➤ ");
	return (full_prompt);
}
