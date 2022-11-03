/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishellstruct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:47:16 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/02 22:11:01 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLSTRUCT_H
# define MINISHELLSTRUCT_H

# include "minishell.h"

typedef struct	S_cmdli
{
	char			*cmd_path;
	char			**cmd_args;
	char			**file_in;
	char			**file_out;
	int				*pipe_in;
	int				*pipe_out;
	int				fd_in;
	int				fd_out;
	int				and_or;
	struct S_cmdli	*previous;
	struct S_cmdli	*next;
}	t_cmdli;

typedef struct S_env
{
	char	*name;
	char	*value;
	struct S_env *next;
}	t_env;

typedef struct S_useful
{
	char	cwd[PATH_MAX];
	char	*display;
}	t_useful;

typedef struct S_shell
{
	char		**to_parse;
	char		*line;
	t_cmdli		cmdli;
	t_useful	useful;
	t_env		*env;
	t_env		*export;
	t_env		*variables;
}	t_shell;

#endif
