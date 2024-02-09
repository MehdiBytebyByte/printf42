/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:35:09 by mboughra          #+#    #+#             */
/*   Updated: 2023/12/08 17:41:10 by mboughra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putnbr(long n);
int	ft_putnbr2(long n);
int	ft_putstr(char *s);
int	ft_hexaconv(unsigned int a, char c);
int	ft_hexapointer(unsigned long a);

#endif
