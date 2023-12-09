/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:54:39 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/09 21:35:08 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_icheck(char c, va_list ap)
{
	int				count;
	unsigned long	p;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		count += ft_putnbr2(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_hexaconv(va_arg(ap, unsigned int), c);
	else if (c == 'p')
	{
		p = (unsigned long)va_arg(ap, void *);
		count += ft_hexapointer(p, 1);
	}
	else if (c != '\0')
		write(1, &c, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (write (1, "", 0) == -1)
		return (-1);
	i = 0;
	count = 0;
	va_start(ap,str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[++i] == '\0')
				break ;
			count += ft_icheck(str[i], ap);
		}
		else
		{
			write (1, &str[i], 1);
			count++;
		}
		i++;
	}
	return (va_end (ap), count);
}
