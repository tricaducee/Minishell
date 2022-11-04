/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:56:56 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/04 07:35:21 by tgoel            ###   ########.fr       */
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
void		handle_signaux(int sig);

/* ----------------- __INIT__ --------------- */
int			__init__(t_shell *shell, char **v_env);

/* ----------------- BUILT IN --------------- */
int			cmd_echo(int n, char *display);
int			cmd_env(char **env);
int			cmd_unset(char *unsetted);
int			cmd_export(char *exported);
int			cmd_pwd(t_useful *useful, int display);
int			cmd_cd(t_useful *useful, char *path);

/* ------------------ UTILS ------------------ */
char		*ft_strdup(char *str);
int			ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoin2(char *s1, char *s2);
void		change_color(int fd, char *color);
char		**ft_split(char *s, char c);
t_variables	*create_parsed_node(char *str);
int			modify_node(t_variables *node, char *str);
int			ft_strcmp(char *s1, char *s2);
t_variables	*create_node_name_value(char *name, char *value);
char		**ft_strsjoin(char *s, char **ss);
int			ft_strslen(char **s);
int			ft_strcmp_int(char *s1, char *s2);
char		*ft_itoa(int n);
char		*ft_substr(char *s, unsigned int start, unsigned int len);


/* ------------------- GET ------------------- */
char	*ft_get_var(char *substr);
char	**ft_get_str_env(void);
t_shell	*ft_get_shell(t_shell *new_shell);
t_variables	*ft_get_export(void);
t_variables	*ft_get_env(void);


/* ------------------ FREE ------------------- */
void		handle_error(char *str);
void		free_struct(t_shell *shell);

/* ----------------- PARSING -------------------*/
void	add_andor(t_cmdli **cmds_list, t_type *type, int and_or);
void	add_arg(t_cmdli **cmds_list, char *arg, t_type *type);
void	add_cmd(t_cmdli **cmds_list, char *cmd, t_type *type);
char	*add_dquote(char **cmdline, char *str, unsigned int *i);
char	*add_dquote_ret(char **cmdline, char *ret, char **tmp, unsigned int *i);
void	add_file(t_cmdli **cmds_list, char *file, t_type *type);
void	file_heredoc(t_cmdli **cmds_list, char *file);
void	file_rdoa(t_cmdli **cmds_list, char *file);
void	file_rdo(t_cmdli **cmds_list, char *file);
void	file_rdi(t_cmdli **cmds_list, char *file);
void	add_pipe(t_cmdli **cmds_list, t_type *type);
char	*add_quote(char **cmdline, char *str, unsigned int *i);
char	*add_var(char **cmdline, char *str, unsigned int *i);
char	*add_var_free(char *str, char *new);
t_cmdli	*cmdli_first(t_cmdli *cmds_list);
t_cmdli	*create_cmdli(void);
void	error_cmdli_interpret(t_cmdli **cmds_list, char *s);
void	error_cmdli(t_cmdli **cmds_list, char *s);
t_cmdli	*error_cmdli_nl(t_cmdli **cmds_list);
void	free_cmdli(t_cmdli **cmdli);
void	free_content(t_cmdli *cmdli);
void	free_tab(char **ss);
t_cmdli	*get_cmds(char **cmdline);
void	interpret(t_cmdli **cmds_list, char **cmdline,
					t_type *type, unsigned int *i);
char	*heredoc(char *limit);
char	*ft_strjoin_nl(char *s1, char *s2);
void	print_cmdli(t_cmdli *cmds_list);
void	print_content(t_cmdli *cmds_list);
void	print_cmdli_tab(char **ss, char *s);
void	print_tab(char **s);
char	*split_cmd_sp(char **cmdline, unsigned int *i);
char	*split_cmd_sp_add_func(char **cmdline, char *ret, unsigned int *i);
char	*split_cmd_sp_ret(char	**cmdline, char *ret,
		unsigned int *i, unsigned int j);
char	*split_cmd(char *(*cmdline), unsigned int *i, char c);
void	type_and_set(char *s, t_cmdli **cmds_list, t_type *type, int interpret);
void	interpret_func(char *s, t_cmdli **cmds_list, t_type *type, int rd);


#endif
