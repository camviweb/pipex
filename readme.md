# Projet en cours ⚡
![validation](./pipex.png)
- ~50h
- Page 9/9 done

## Description
Reproduce the behaviour of `< file1 cmd1 | cmd2 > file2` with a program 

## Keywords
- redirections
- subprocesses (child and parent)
- pipes to connect the processes 

## To test
- [ ] make fclean
- [ ] norminette (42 header)
- [ ] valgrind !!
- [ ] file names/git repo : Makefile, *.h, *.c
- [ ] (guidelines -> tests)

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

## Utilisation
### Compilation
```bash
make
```

### Execution
```bash
./pipex [file1] "[cmd1]" "[cmd2]" [file2]
```
file1, file2 des noms des fichiers
cmd1, cmd2 des commandes shell (avec parametres)