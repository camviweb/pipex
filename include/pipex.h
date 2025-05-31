#ifndef PIPEX_H
# define PIPEX_H
# include "../libft/libft.h"
# include <fcntl.h> // open, close
# include <sys/wait.h> // waitpid
# include <sys/types.h> // pid_t
// # include <stdio.h>
// # include <sys/stat.h>

// main.c
void	exec_cmd(char *cmd, char **env);
void	child(char **argv, int *fd, char **env);

// utils.c
void	m_error(char *mess);
void	env_check(char **env);
void	parent(char **argv, int *fd, char **env);

#endif