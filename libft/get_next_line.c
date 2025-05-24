/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:34:58 by canguyen          #+#    #+#             */
/*   Updated: 2025/02/03 15:36:54 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*rest = NULL;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	tmp = NULL;
	ft_read(fd, &rest, &tmp);
	if (rest != NULL && *rest != '\0')
	{
		tmp = ft_strdup(rest);
		ft_free(&rest, 0, 0);
		line = get_before_newline(tmp);
		rest = get_after_newline(tmp);
		ft_free(&tmp, 0, 0);
	}
	if (!line || *line == '\0')
	{
		ft_free(&line, &rest, &tmp);
		return (NULL);
	}
	return (line);
}

void	ft_read(int fd, char **rest, char **tmp)
{
	char	*buf;
	int		r;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (ft_free(&buf, rest, 0));
		buf[r] = '\0';
		if (*rest == NULL)
			*rest = ft_strdup("");
		*tmp = ft_strdup(*rest);
		ft_free(rest, 0, 0);
		*rest = ft_strjoin(*tmp, buf);
		ft_free(tmp, 0, 0);
		if (has_newline(buf))
			break ;
	}
	ft_free(&buf, 0, 0);
}

char	*get_before_newline(const char *s)
{
	char	*rest;
	int		i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * (i + 1));
	if (!rest)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		rest[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		rest[i] = s[i];
		i++;
	}
	rest[i] = '\0';
	return (rest);
}

char	*get_after_newline(const char *s)
{
	char	*rest;
	int		i;
	int		j;

	j = 0;
	while (s[j])
	{
		j++;
	}
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] && s[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * (j - i + 1));
	if (!rest)
		return (NULL);
	j = 0;
	while (s[i + j])
	{
		rest[j] = s[i + j];
		j++;
	}
	rest[j] = '\0';
	return (rest);
}
