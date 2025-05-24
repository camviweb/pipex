/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:01:41 by canguyen          #+#    #+#             */
/*   Updated: 2024/12/09 18:27:48 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	firstoccu;
	int		check_little;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	firstoccu = 0;
	while (big[i] && i < len)
	{
		check_little = 0;
		firstoccu = i;
		while (big[i + check_little] == little[check_little] && \
				little[check_little] != '\0' && (i + check_little) < len)
		{
			check_little++;
		}
		if (check_little == ft_strlen((char *)little))
			return (&((char *)big)[firstoccu]);
		i++;
	}
	return (NULL);
}
