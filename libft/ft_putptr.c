/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:26:59 by canguyen          #+#    #+#             */
/*   Updated: 2025/03/08 14:27:03 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long long adr)
{
	char	*hexa;
	int		len;
	int		tmp;

	len = 0;
	hexa = "0123456789abcdef";
	if (adr == 0)
	{
		return (ft_putstr("(nil)"));
	}
	if (adr >= 16)
	{
		tmp = ft_putptr(adr / 16);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	tmp = ft_putchar(hexa[adr % 16]);
	if (tmp == -1)
		return (-1);
	return (len + 1);
}
