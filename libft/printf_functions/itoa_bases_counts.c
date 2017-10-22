/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bases_counts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:15:48 by dkovalen          #+#    #+#             */
/*   Updated: 2017/01/25 15:45:40 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_count(long long int value, int base)
{
	int						i;
	unsigned long long int	srav;

	i = 0;
	if (value < 0 && base == 10)
		i++;
	if (value < 0)
		srav = -value;
	else
		srav = value;
	if (srav == 0)
		i++;
	while (srav > 0)
	{
		srav = srav / base;
		i++;
	}
	return (i);
}

int		ft_count_unsigned(unsigned long long int value, int base)
{
	int		i;

	i = 0;
	if (value == 0)
		i++;
	while (value > 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

int		ft_count_test(intmax_t value, int base)
{
	int						i;
	unsigned long long int	test;

	i = 0;
	if (value < 0)
		test = ULLONG_MAX + value + 1;
	else
		test = value;
	if (test == 0)
		i++;
	while (test > 0)
	{
		test = test / base;
		i++;
	}
	return (i);
}

void	ft_putnbr_unsigned(unsigned long long int d)
{
	if (d > 9)
	{
		ft_putnbr(d / 10);
		ft_putnbr(d % 10);
	}
	else
		ft_putchar(d + 48);
}
