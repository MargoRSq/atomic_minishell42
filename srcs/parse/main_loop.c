/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angelinamazurova <angelinamazurova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:35:14 by svyatoslav        #+#    #+#             */
/*   Updated: 2022/10/02 15:44:58 by angelinamaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_list *envlst)
{
	char	*cur_level;

	cur_level = get_env_value("SHLVL", envlst);
	if (cur_level)
		g_status.shell_level = ft_atoi(cur_level) + 1;
	else
		g_status.shell_level = 1;
	read_history(HISTORY_FILE);
}

static char	*launch_readline(t_env *env)
{
	char	*tmp;
	char	*prefix;
	char	*line;
	char	*pwd;

	pwd = get_cur_dir(env);
	if (!pwd)
		return (NULL);
	prefix = ft_strjoin(DEFAULT_PREFIX, pwd);
	if (!prefix)
		return (error_msg_return_null(MSG_SYSCALL_ERR_MEM, NULL, malloc_error, 1));
	tmp = prefix;
	prefix = ft_strjoin(tmp, DOLLAR);
	if (!prefix)
		return (error_msg_return_null(MSG_SYSCALL_ERR_MEM, NULL, malloc_error, 1));
	free(tmp);
	line = readline(prefix);
	free(prefix);
	return (line);
}

static char	*get_entered_line(t_env *env)
{
	char	*entered_line;

	entered_line = launch_readline(env);
	add_history(entered_line);
	write_history(HISTORY_FILE);
	return (entered_line);
}

void	start_shell(t_list **env)
{
	char		*line;
	t_list		*tokens;
	t_list		*cmds;

	while (!g_status.interrupt)
	{
		line = get_entered_line(*env);
		if (!line || !(*line))
			continue ;
		if (g_status.interrupt)
			break ;
		tokens = lex_line(line, *env);
		if (g_status.interrupt)
			break ;
		check_tokens(tokens, *env);
		if (g_status.interrupt)
			break ;
		cmds = create_commands(tokens);
		if (g_status.interrupt)
			break ;
		execute(env, cmds);
	}
}
