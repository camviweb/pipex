/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:26:47 by canguyen          #+#    #+#             */
/*   Updated: 2025/03/08 14:26:49 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	int	len;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len = ft_putnbr(-n);
		if (len == -1)
			return (-1);
		return (len + 1);
	}
	len = 0;
	if (n > 9)
	{
		len = ft_putnbr(n / 10);
		if (len == -1)
			return (-1);
	}
	if (ft_putchar(n % 10 + '0') == -1)
		return (-1);
	return (len + 1);
}
