# Projet en cours ⚡
![validation](./pipex.png)

## Description
Reproduce the behaviour of `< file1 cmd1 | cmd2 > file2` with a program 

## Tasks
- [x] Read the subject
- [x] Initialize a git repo with a readme
- [x] Create a makefile with the required rules
- [x] Parsing (arguments count management)
- [x] ? Check the existence of infile ? in open
- [x] Errors management choice : simple -> m_error with a custom message and exit(1) = execution interrompue
    - [x] Existing files
    - [x] Files rights
    - [x] Binaries of the commands
- [x] Check path variable exists
- [x] Search the 2 commands paths
- [x] Build the arguments array for commands 
- [x] Create the pipe WHY ? To link subprocesses
- [x] Create the fork WHY ? Split the process in 2 parallel subprocesses
- [x] Create a child and parent process
- [x] In child : redirect standard input to infile && standard output to pipe writeend
- [x] In parent : redirect standard input to pipe readend && standard output to outfile 
- [x] open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777) for rights 
- [x] No wait for /dev/urandom
- [x] make fclean
- [x] norminette (42 header)
- [x] valgrind !!
- [x] file names/git repo : Makefile, *.h, *.c
- [x] git push and check

## CI
```bash
./pipex infile "ls -l" "wc -l" outfile
```
```bash
./pipex infile "grep a1" "wc -w" outfile
```
```bash
./pipex infile "cat" "wc" outfile
```
```bash
valgrind --leak-check=full --trace-children=yes ./pipex infile "sleep 5" "wc -w" outfile
```

## Utilisation
### Compilation
```bash
make
```

### Execution
```bash
./pipex [file1] "[cmd1]" "[cmd2]" [file2]
```
file1, file2 des noms des fichiers \
cmd1, cmd2 des commandes shell (avec parametres)
