#ifndef ERROR_MSGS_H
# define ERROR_MSGS_H

int		trigger_unclosed_quote_error(char q_type);
int		trigger_too_many_redirects_error();

void	error_msg_return_void(char *msg, char *arg, int code, short interrupt);
void	*error_msg_return_null(char *msg, char *arg, int code, short interrupt);
char	*error_msg_return_charz(char *msg, int code, short interrupt);
int		error_msg_return_int(char *msg, char *arg, int code, short interrupt);

# define ERR_ARGC				"minishell: There should be no arguments\n"
# define MSG_ERR_MEM			"minishell: Memory allocation failed\n"
# define MSG_ERR_PWD			"minishell: No pwd value\n"
# define MSG_ERR_CD				"minishell: cd: %s: "
# define MSG_ERR_HOME			"minishell: cd: HOME not set\n"
# define MSG_ERR_CD_ARGS		"minishell: cd: too many arguments\n"
# define MSG_ERR_ENV			"minishell: ENV error .\n"
# define MSG_ERR_SYNATX			"minishell: Syntax error\n"
# define MSG_ERR_EXECVE			"minishell: EXECVE error .\n"

# define MSG_SYSCALL_ERR_GETCWD
# define MSG_SYSCALL_ERR_CHDIR

# define MSG_ERR_CMD_TMR\
	"minishell: parse error\n"
# define MSG_ERR_CMD_USQ\
	"minishell: Syntax error: command has unclosed \' sign\n"
# define MSG_ERR_CMD_UDQ\
	"minishell: Syntax error: command has unclosed \" sign\n"

# define MSG_ERR_PIPE_LOC\
	"minishell: parse error: pipe at the start or at the end\n"
# define MSG_ERR_REDIR_PARSE\
	"minishell: parse error: wrong redir usage\n"
# define MSG_ERR_FILE_FAIL\
	"minishell: parse error: file not exists or not accessible\n"

# define MSG_ERR_CMD_EEOF\
	"minishell: Syntax error: command has escaped EOF\n"
# define MSG_ERR_MORE2CNTRLS\
	"minishell: Syntax error: command has wrong number of `%c\'\n"
# define MSG_ERR_CMD_HAS_UP\
	"minishell: Syntax error: command has unclosed parenthesis\n"
# define MSG_ERR_CMD_PARSEERR	"minishell: Parse command unsucces\n"
# define MSG_ERR_CMD_NFOUND		"minishell: %s: command not found\n"
# define MSG_ERR_CMD_ISDIR		"minishell: %s: it`s a directory\n"
# define MSG_ERR_PIPE			"minishell: Pipes creation fail\n"
# define MSG_ERR_INVRDTYPE		"minishell: Invalid redirect type\n"
# define MSG_ERR_EXIT_NUM\
	"minishell: exit: %s: Numeric argument required\n"
# define MSG_ERR_EXIT_ARGS		"minishell: exit: Too many arguments\n"
# define MSG_ERR_INVAL_HIS_FD	"minishell: Invalid descriptor of history file\n"
# define MSG_ERR_INVAL_ENVNAME	"minishell: Invalid env name: %s\n"
# define MSG_ERR_HEREDOC\
	"minishell: warning: here-document delimited by end-of-file (wanted `%s\')\n"


# define MSG_ERR_ENV_ARGS		"minishell: %s: No such file or directory\n"
# define MSG_ERR_EXPORT_KEY		"minishell: export: `%s': not a valid identifier\n"
# define MSG_ERR_UNSET_KEY		"minishell: unset: `%s': not a valid identifier\n"
# define MSG_ERR_CD_NO			"minishell: cd: %s: No such file or directory\n"
#endif
