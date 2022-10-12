/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:56:56 by tgoel             #+#    #+#             */
/*   Updated: 2022/08/19 18:41:22 by tgoel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/signal.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

# include "colorminishell.h"
# include "minishellstruct.h"


/*  ----------------- MAIN ------------------ */
void	handle_signaux(int sig);

/* ----------------- __INIT__ --------------- */
int		__init__(t_shell *shell);

/* ----------------- BUILT IN --------------- */
int		cmd_echo(int n, char *display);
int		cmd_env(char **env);
int		cmd_unset(char *unsetted);
int		cmd_export(char *exported);
int		cmd_pwd(t_useful *useful, int display);
int		cmd_cd(t_useful *useful, char *path);

/* ------------------ UTILS ------------------ */
char	*ft_strdup(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	change_color(int fd, char *color);
char	**ft_split(char *s, char c);

/* ------------------ FREE ------------------- */
void	handle_error(char *str);
void	free_struct(t_shell *shell);

#endif
