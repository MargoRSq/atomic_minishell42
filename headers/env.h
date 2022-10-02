#include "minishell.h"

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}	t_env;

t_env	*envlst_new(char *key, char *value);
t_env	*envlst_last(t_env *lst);
void	envlst_add_back(t_env **lst, t_env *new_lst);
void	envlst_clear(t_env **lst);
void	envlst_print(t_list *envlst);
void	envlst_delete_one(char *key, t_list **envlst);
char	**envlst_to_arr(t_list *envlst);

t_list	*parse_envp(char **envp);

char	*get_env_value(char *key, t_list *envlst);
// void	append_env_var(t_env *env, char *arg);

t_env	*update_env_value(char *key, char *value);