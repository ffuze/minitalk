/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ints (copy).c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adegl-in <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:43:53 by adegl-in          #+#    #+#             */
/*   Updated: 2025/02/10 14:21:26 by adegl-in         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_d_i(int n)
{
	long	lnum;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		n = 147483648;
		count = 2;
	}
	if (n < 0)
	{
		count += ft_printf_c('-');
		lnum = (long)(-n);
	}
	else
		lnum = (long)n;
	if (lnum == 0)
		return (count + ft_printf_c('0'));
	if (lnum >= 10)
		count += ft_printf_d_i(lnum / 10);
	count += ft_printf_c((lnum % 10) + '0');
	return (count);
}

int	ft_printf_u(unsigned int n)
{
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_printf_u(n / 10);
	count += ft_printf_c((n % 10) + '0');
	return (count);
}
