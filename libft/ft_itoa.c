/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:28:28 by canguyen          #+#    #+#             */
/*   Updated: 2024/12/11 14:21:53 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static	char	*ft_start(int n)
{
	char	*new;

	new = malloc(sizeof * new * (get_len(n)));
	if (new == NULL)
		return (NULL);
	return (new);
}

char	*ft_itoa(int n)
{
	char	*new;
	int		ilen;
	int		copyn;

	copyn = n;
	ilen = get_len(n) - 2;
	new = ft_start(n);
	if (!new)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		new[0] = '0';
	if (n < 0)
	{
		new[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		new[ilen--] = n % 10 + '0';
		n = n / 10;
	}
	new[get_len(copyn) - 1] = '\0';
	return (new);
}
