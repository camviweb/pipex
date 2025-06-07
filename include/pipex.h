/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:44:05 by canguyen          #+#    #+#             */
/*   Updated: 2025/06/07 17:44:08 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <fcntl.h>     // open, close
# include <sys/types.h> // pid_t
# include <sys/wait.h>  // waitpid
// # include <stdio.h>
// # include <sys/stat.h>

// main.c
void	exec_cmd(char *cmd, char **env);
void	child(char **argv, int *fd, char **env);
void	parent(char **argv, int *fd, char **env);

// utils.c
void	m_error(char *mess, int code);
void	env_check(char **env);
char	*get_cmd_path(char *cmd, char **env);
int		get_cmd_path_helper(char **env);
void	free_split(char **str);

#endif
