/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 12:25:57 by canguyen          #+#    #+#             */
/*   Updated: 2024/12/06 16:15:38 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_start(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	return (start);
}

static int	get_end(int start, char const *s1, char const *set)
{
	int	end;

	end = ft_strlen((char *)s1) - 1;
	while (end >= start && s1[end] && ft_strchr(set, s1[end]))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = get_start(s1, set);
	end = get_end(start, s1, set);
	if (set == NULL)
		strtrim = ft_strdup((char *)s1);
	if (end - start == 0)
		strtrim = malloc(sizeof * strtrim);
	else
		strtrim = malloc(sizeof * strtrim * (end - start + 2));
	if (strtrim == NULL)
		return (NULL);
	while (start <= end)
		strtrim[i++] = s1[start++];
	strtrim[i] = '\0';
	return (strtrim);
}
