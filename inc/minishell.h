/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgoel <tgoel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:56:56 by tgoel             #+#    #+#             */
/*   Updated: 2022/11/20 13:40:57 by tgoel            ###   ########.fr       */
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
# include <termios.h>
# include <signal.h>

# include "colorminishell.h"
# include "minishellstruct.h"

int	g_errno;

/*  ----------------- MAIN ------------------ */
void			handle_signaux(int sig);
void			sig_handler(t_shell *shell);
void			handle_interrupt(int sig);

/* ----------------- __INIT__ --------------- */
int				__init__(t_shell *shell, char **v_env);

/* ----------------- BUILT IN --------------- */
void			cmd_echo(char **ss);
int				cmd_env(t_shell *shell);
void			cmd_unset(t_shell *shell, char **args);
int				cmd_export(t_shell *shell, t_cmdli *cmdli);
int				cmd_pwd(void);
int				cmd_cd(t_cmdli *cmdli);
int				cmd_exit(t_shell *shell, t_cmdli **cmdli);

/* ------------------ FREE ------------------- */
void			handle_error(char *str);
void			free_struct(t_shell *shell);
char			**free_tab_null(char **ss);
void			free_nodes(t_variables **list);
void			free_nodes_contents(t_variables **list);
void			free_cmdli(t_cmdli **cmdli);
void			free_content(t_cmdli *cmdli);
void			free_tab(char **ss);
void			free_file(t_file **files);

/* ------------------ UTILS ------------------ */
char			*ft_strdup(char *str);
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
void			change_color(int fd, char *color);
char			**ft_split(char *s, char c);
int				ft_strcmp(char *s1, char *s2);
char			**ft_strsjoin(char *s, char **ss);
int				ft_strslen(char **s);
int				ft_strcmp_int(char *s1, char *s2);
char			*ft_itoa(int n);
char			*ft_substr(char *s, unsigned int start, unsigned int len);
int				ft_strinset(char *str, char *set);
int				ft_is_uppercase(char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			*_static_prompt(void);
char			*get_branch_name(char *str);
char			**dir_name(void);
char			*send_one_file(void);
int				return_error(char *debug);
int				exit_error(void);

/* ----------------- NODES ------------------- */

t_variables		*create_parsed_node(char *str);
t_variables		*create_node_name_value(char *name, char *value);
int				modify_node(t_variables *node, char *str);

/* ------------------- GET ------------------- */
char			*ft_get_var(char *substr);
char			**ft_get_str_env(void);
t_shell			*ft_get_shell(t_shell *new_shell);
t_variables		*ft_get_export(void);
t_variables		*ft_get_env(void);

/* ------------------ EXEC -------------------- */
int				close_pipe(int *pipe);
void			set_file_in(t_cmdli *cmdli);
void			set_file_out(t_cmdli *cmdli);
void			set_in(t_cmdli *cmdli);
void			set_out(t_cmdli *cmdli);
void			set_redirection(t_cmdli *cmdli);
int				run_builtin(char *str, t_cmdli *cmd, t_shell *shell);
int				is_builtin(t_cmdli *cmd, t_shell *shell);
int				is_builtin_no_run(t_cmdli *cmd);
unsigned int	path_counter(char *path);
char			*path_join(char *path, char *cmd,
				unsigned int path_len, unsigned int cmd_len);
char			**split_path(char *path, char *cmd, unsigned int cmd_len);
char			*get_absolute_path(char *cmd, char *path);
int				close_pipe(int *pipe);
int				exec_cmd(t_cmdli *cmdli);
int				set_buildin_redirect(t_cmdli *cmdli);
int				ft_strchr_path(char *s, char *path, int c);

/* ----------------- PARSING -------------------*/
void			add_andor(t_cmdli **cmds_list, t_type *type, int and_or);
t_file			**file_join(char *file, t_file **files, t_type type);
void			add_arg(t_cmdli **cmds_list, char *arg, t_type *type);
void			add_cmd(t_cmdli **cmds_list, char *cmd, t_type *type);
char			*add_dquote(char **cmdline, char *str, unsigned int *i);
char			*add_dquote_ret(char **cmdline, char *ret, char **tmp, unsigned int *i);
void			add_file(t_cmdli **cmds_list, char *file, t_type *type);
void			file_heredoc(t_cmdli **cmds_list, char *file);
void			file_rdoa(t_cmdli **cmds_list, char *file);
void			file_rdo(t_cmdli **cmds_list, char *file, t_type type);
void			file_rdi(t_cmdli **cmds_list, char *file);
void			add_pipe(t_cmdli **cmds_list, t_type *type);
char			*add_quote(char **cmdline, char *str, unsigned int *i);
char			*add_var(char **cmdline, char *str, unsigned int *i);
char			*add_var_free(char *str, char *new);
t_cmdli			*cmdli_first(t_cmdli *cmds_list);
t_cmdli			*create_cmdli(void);
void			error_cmdli_interpret(t_cmdli **cmds_list, char *s);
void			error_cmdli(t_cmdli **cmds_list, char *s);
t_cmdli			*error_cmdli_nl(t_cmdli **cmds_list);
t_cmdli			*get_cmds(char **cmdline);
void			interpret(t_cmdli **cmds_list, char **cmdline,
					t_type *type, unsigned int *i);
char			*heredoc(char *limit);
char			*ft_strjoin_nl(char *s1, char *s2);
void			print_cmdli(t_cmdli *cmds_list);
void			print_content(t_cmdli *cmds_list);
void			print_cmdli_tab(char **ss, char *s);
void			print_tab(char **s);
char			*split_cmd_sp(char **cmdline, unsigned int *i);
char			*split_cmd_sp_add_func(char **cmdline, char *ret, unsigned int *i);
char			*split_cmd_sp_ret(char	**cmdline, char *ret,
					unsigned int *i, unsigned int j);
char			*split_cmd(char *(*cmdline), unsigned int *i, char c);
void			type_and_set(char *s, t_cmdli **cmds_list, t_type *type, int interpret);
void			interpret_func(char *s, t_cmdli **cmds_list, t_type *type, int rd);

#endif