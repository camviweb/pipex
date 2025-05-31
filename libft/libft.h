/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 11:07:18 by canguyen          #+#    #+#             */
/*   Updated: 2024/12/09 19:01:10 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h> // exit, free, malloc
# include <unistd.h> // write, read, access, execve, fork, pipe, dup2

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE > 8000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 8000000
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_strlen(char *str);
void				*ft_memset(void *ptr, int c, size_t n);
void				ft_bzero(void *ptr, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t size);
void				*ft_memmove(void *dst, const void *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(char *src);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// partie bonus
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);

// ft_printf
int					ft_printf(const char *s, ...);
int					ft_putchar(char c);
int					ft_putptr(unsigned long long ptr);
int					ft_putstr(char *s);
int					ft_putnbr(int n);
int					ft_putunbr(unsigned int n);
int					ft_putx(unsigned int n, char c);
int					do_format(const char *s, va_list args, int i);
int					handle_pointer_null(unsigned long long adr);

// get_next_line
char				*get_next_line(int fd);
int					has_newline(char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*get_before_newline(const char *s);
char				*get_after_newline(const char *s);
void				ft_read(int fd, char **rest, char **tmp);
void				ft_free(char **str, char **str2, char **str3);

// others
long				ft_atol(const char *str);

#endif
