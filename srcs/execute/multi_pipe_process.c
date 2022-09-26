#include "minishell.h"

int	cmd_len(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		len;

	len = 0;
	tmp = cmd;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return len;
}

int	**make_pipe_space(int **pipes, int len)
{
	int i;

	pipes = malloc(sizeof(int *) * (len - 1));
	if (!pipes)
		return (error_msg_return_int(MSG_ERR_MEM, NULL, malloc_error,
											1));
//		trigger_malloc_error();//need to clarify!
	i = 0;
	while (i < (len - 1))
	{
		pipes[i] = malloc(sizeof(int) * 2);
		if (!pipes[i])
			return (error_msg_return_int(MSG_ERR_MEM, NULL, malloc_error,
										 1));
		i++;
	}
	return (pipes);
}

void	begin_pipes(int **pipes, int len)
{
	int	i;

	i = 0;
	while(i < (len - 1))
	{
		if(pipe(pipes[i]))
//			trigger_pipes_error();//need to feat a new func
		i++;
	}
}

void	multi_pipe_process(t_env **env, t_cmd *cmd)
{
	int		len;
	int 	**pipes;
	int		i;
	t_cmd	*tmp;
	t_cmd	*prev;

	len = cmd_len(cmd);
	pipes = NULL;
	pipes = make_pipe_space(pipes, len);
	begin_pipes(pipes, len);
	tmp = cmd;
	prev = NULL;
	while(tmp != NULL)
	{

		if (prev == NULL)
			exec_first_cmd(*env, tmp);
		else if (tmp->next == NULL)
			exec_last_cmd(*env, tmp);
		else
			exec_middle_cmd(*env, tmp);
		prev = tmp;
		tmp = tmp->next;
	}
}