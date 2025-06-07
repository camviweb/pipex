/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:43:47 by canguyen          #+#    #+#             */
/*   Updated: 2025/06/07 17:43:50 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
give the output to input of cm2 (pipe)

give (write) the output to file2, only when the 2 processes end
*/

void	exec_cmd(char *cmd, char **env)
{
	char	**args_of_cmd;
	char	*cmd_path;

	args_of_cmd = ft_split(cmd, ' ');
	cmd_path = get_cmd_path(args_of_cmd[0], env);
	if (!cmd_path)
	{
		free_split(args_of_cmd);
		m_error("command not found\n", 127);
	}
	if (execve(cmd_path, args_of_cmd, env) == -1)
	{
		free_split(args_of_cmd);
		free(cmd_path);
		m_error("Erreur lors de l'exécution d'une commande :/\n", 1);
	}
}

void	child(char **argv, int *fd, char **env)
{
	int	child_fd;

	child_fd = open(argv[1], O_RDONLY);
	if (child_fd == -1)
		m_error("Erreur d'ouverture ou fichier 1 inexistant :/\n", 1);
	dup2(child_fd, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	exec_cmd(argv[2], env);
}

void	parent(char **argv, int *fd, char **env)
{
	int	parent_fd;

	parent_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (parent_fd == -1)
		m_error("Bad ouverture ou fichier 2 inexistant ou bad permissions\n", 1);
	dup2(fd[0], 0);
	dup2(parent_fd, 1);
	close(fd[1]);
	exec_cmd(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
		m_error("Il faut 4 arguments !!!\n", 1);
	env_check(env);
	if (pipe(fd) == -1)
		m_error("Erreur de pipe :/\n", 1);
	pid = fork();
	if (pid == -1)
		m_error("Erreur de fork :/\n", 1);
	if (pid == 0)
		child(argv, fd, env);
	parent(argv, fd, env);
}
