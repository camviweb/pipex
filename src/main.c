#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
    int fd[2];

	if (argc != 5)
	    m_error("Il faut 4 arguments !!!");
    // while (env[i]){
    //     ft_printf(env[i++]);
    //     ft_printf("\n");
	if (access(argv[1], F_OK) != 0)
		m_error("Le premier fichier doit exister !!!");
    fd[0] = open(argv[1], O_RDONLY);
    if (fd[0] < 0)
        m_error("Erreur lors de l'ouverture du fichier :/");
    fd[1] = open(argv[4], O_RDONLY);
    if (fd[1] < 0)
        m_error("Erreur lors de l'ouverture du fichier :/");
    char *const argu[] = {"/usr/bin/grep", "a", NULL};
    execve("/usr/bin/grep", argu, env);
    if (pipe(fd) != 0)
        m_error("Erreur de pipe :/")
	// case of > when infile doesn't exist
	// read, write OK
	// malloc, free OK
	// perror, strerror
	// dup, dup2
	// fork
	// unlink
	// wait
	// waitpid
    close(fd[0]);
}

/*take input (file2)

do_cm1 -> child process -> see execute checklist

take output of cm1

give the output to input of cm2 (pipe)

do cmdd2 -> child process 

give (write) the output to file2, only when the 2 processes end*/

void	m_error(char *mess)
{
	ft_putstr_fd(mess, 2);
	exit(1);
}