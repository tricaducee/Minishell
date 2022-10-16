/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishellstruct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 10:18:32 by tgoel             #+#    #+#             */
/*   Updated: 2022/10/16 18:46:41 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLSTRUCT_H
# define MINISHELLSTRUCT_H

# include "minishell.h"

typedef struct S_exec
{
	char			*pathname;
	char			**args;
	char			delim;
	struct S_exec	*prev;
	struct S_exec	*next;
}	t_exec;

typedef struct S_env
{
	char	*val;
	struct S_env *next;
	struct S_env *prev;
}	t_env;

typedef struct S_useful
{
	char	cwd[PATH_MAX];
	char	*display;
}	t_useful;

typedef struct S_shell
{
	char		**env;
	char		**to_parse;
	char		*line;
	t_useful	useful;
	t_exec		exec;
}	t_shell;

#endif
