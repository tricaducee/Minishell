/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishellstruct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:47:16 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/06 14:52:25 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELLSTRUCT_H
# define MINISHELLSTRUCT_H

# include "minishell.h"


typedef enum E_type
{
	EMPTY,
	CMD,
	ARG,
	PIPE,
	RFILE,
	RDI,
	RDO,
	RDIH,
	RDOA,
	ANDOR
}			t_type;

typedef struct S_cmdli
{
	char			*cmd;
	char			**cmd_args;
	int				*pipe_in;
	int				*pipe_out;
	char			*here_doc;
	int				fd_in;
	int				fd_out;
	char			**file_in;
	char			**file_out;
	t_type			file_type;
	int				and_or;
	pid_t			pid;
	int				cmd_error;
	struct S_cmdli	*previous;
	struct S_cmdli	*next;
}	t_cmdli;

typedef struct S_variables
{
	char				*name;
	char				*value;
	struct S_variables	*next;
}	t_variables;

typedef struct S_useful
{
	char	cwd[PATH_MAX];
	char	*display;
}	t_useful;

typedef struct S_shell
{
	char		**str_env;
	char		*line;
	t_useful	useful;
	t_variables	*env;
	t_variables	*export;
	t_variables	*variables;
}	t_shell;

#endif
