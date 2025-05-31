#include "pipex.h"

void	m_error(char *mess)
{
	ft_putstr_fd(mess, 2);
	exit(1);
}

void	env_check(char **env)
{
    int i;
    int ok;

    i = 0;
    ok = 0;
    while (env[i]){
	    ft_printf(env[i]);
	    ft_printf("\n");
		if (ft_strnstr(env[i], "PATH=", 5) && env[i][5])
        	ok = 1;
		i++;
    }
    if (!ok)
        m_error("Path incorrect");
}

char	*get_cmd_path(char *cmd, char **env)
{
	char	**envp_paths;
	char	*cmd_path;
	int		i;
	char	*only_path;

	i = 0;
	while (!ft_strnstr(env[i], "PATH=", 5))
		i++;
	envp_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (envp_paths[++i])
	{
		only_path = ft_strjoin(envp_paths[i], "/");
		cmd_path = ft_strjoin(only_path, cmd);
		free (only_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_split(envp_paths);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_split(envp_paths);
	m_error("Une commande n'a pas été trouvée :/");
	return (NULL);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}