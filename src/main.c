#include "pipex.h"

/*
give the output to input of cm2 (pipe)

give (write) the output to file2, only when the 2 processes end
*/

void	exec_cmd(char *cmd, char **env)
{
    char	**cmd_and_flags;
	char	*path;

	cmd_and_flags = ft_split(cmd, ' ');
	path = get_cmd_path(cmd_and_flags[0], env);
	if (!path)
	{
		free_split(cmd_and_flags);
		free (path);
		exit(127);
	}
	if (execve(path, cmd_and_flags, env) == -1)
	{
		free_split(cmd_and_flags);
		free (path);
		m_error("Erreur lors de l'exécution d'une commande :/");
	}
}

void	child(char **argv, int *fd, char **env)
{
	int	child_fd;

	child_fd = open(argv[1], O_RDONLY);
	if (child_fd == -1)
		m_error("Erreur lors de l'ouverture du 1er fichier :/");
	dup2(child_fd, 0); // entrée
	dup2(fd[1], 1);    // sortie
	close(fd[0]);
	exec_cmd(argv[2], env);
}

void	parent(char **argv, int *fd, char **env)
{
	int		parent_fd;

	parent_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (parent_fd == -1)
		m_error("Erreur lors de l'ouverture du 2ème fichier :/");
    dup2(fd[0], 0);
    dup2(parent_fd, 1);
	close(fd[1]);
	exec_cmd(argv[3], env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid;

    (void)argv;
	env_check(env);
	if (argc != 5)
		m_error("Il faut 4 arguments !!!");

	// if (access(argv[1], F_OK) != 0)
	// 	m_error("Le premier fichier doit exister !!!");
	
    /*
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		m_error("Erreur lors de l'ouverture du fichier :/");
	fd[1] = open(argv[4], O_RDONLY);
	if (fd[1] < 0)
		m_error("Erreur lors de l'ouverture du fichier :/");
	close(fd[0]);
	*/

	/*
	char *const argu[] = {"/usr/bin/grep", "a", NULL};
	execve("/usr/bin/grep", argu, env);
	*/

	if (pipe(fd) == -1)
		m_error("Erreur de pipe :/");

	// read, write OK
	// malloc, free OK
	// unlink
	// wait

	pid = fork();
	if (pid == -1)
		m_error("Erreur de fork :/");
	child(argv, fd, env);
	waitpid(pid, NULL, 0);
    parent(argv, fd, env);
}