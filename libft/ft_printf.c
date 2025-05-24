/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:23:13 by canguyen          #+#    #+#             */
/*   Updated: 2024/12/14 11:43:56 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;
	int		tmp;

	if (!s || *s == '\0')
		return (0);
	len = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
			tmp = do_format(s, args, ++i);
		else
			tmp = ft_putchar(s[i]);
		if (tmp == -1)
			return (-1);
		len += tmp;
		i++;
	}
	va_end(args);
	return (len);
}

int	do_format(const char *s, va_list args, int i)
{
	int					tmp;
	unsigned long long	adr;

	tmp = 0;
	if (s[i] && s[i] == 'c')
		tmp = ft_putchar(va_arg(args, int));
	else if (s[i] && s[i] == 's')
		tmp = ft_putstr(va_arg(args, char *));
	else if (s[i] && s[i] == 'p')
	{
		adr = va_arg(args, unsigned long long);
		tmp = handle_pointer_null(adr);
	}
	else if (s[i] && (s[i] == 'd' || s[i] == 'i'))
		tmp = ft_putnbr(va_arg(args, int));
	else if (s[i] && s[i] == 'u')
		tmp = ft_putunbr(va_arg(args, unsigned int));
	else if (s[i] && (s[i] == 'x' || s[i] == 'X'))
		tmp = ft_putx(va_arg(args, unsigned int), s[i]);
	else if (s[i] && s[i] == '%')
		tmp = ft_putchar('%');
	if (tmp == -1)
		return (-1);
	return (tmp);
}

int	handle_pointer_null(unsigned long long adr)
{
	if (adr == 0)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_putptr(adr));
}
