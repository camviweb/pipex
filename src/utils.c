/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:43:55 by canguyen          #+#    #+#             */
/*   Updated: 2025/06/07 17:43:57 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	m_error(char *mess, int code)
{
	ft_putstr_fd(mess, 2);
	exit(code);
}

void	env_check(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) && env[i][5])
			return ;
		i++;
	}
	m_error("No path variable :/\n", 1);
}

char	*get_cmd_path(char *cmd, char **env)
{
	char	**env_paths;
	char	*cmd_path;
	int		i;
	char	*one_path;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	if (!cmd)
		return (NULL);
	env_paths = ft_split(env[get_cmd_path_helper(env)] + 5, ':');
	i = -1;
	while (env_paths[++i])
	{
		one_path = ft_strjoin(env_paths[i], "/");
		cmd_path = ft_strjoin(one_path, cmd);
		free(one_path);
		if (access(cmd_path, F_OK) == 0)
		{
			free_split(env_paths);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_split(env_paths);
	return (NULL);
}

int	get_cmd_path_helper(char **env)
{
	int	i;

	i = 0;
	while (!ft_strnstr(env[i], "PATH=", 5))
		i++;
	return (i);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
