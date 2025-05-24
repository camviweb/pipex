/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:40:49 by canguyen          #+#    #+#             */
/*   Updated: 2025/03/08 14:40:54 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putx(unsigned int n, char c)
{
	char	*hexa;
	int		len;
	int		tmp;

	len = 0;
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	if (n >= 16)
	{
		tmp = ft_putx(n / 16, c);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = ft_putchar(hexa[n % 16]);
	if (tmp == -1)
		return (-1);
	return (len + 1);
}
