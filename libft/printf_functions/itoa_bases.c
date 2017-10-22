/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:43:02 by dkovalen          #+#    #+#             */
/*   Updated: 2017/01/25 15:37:53 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_itoa_base(long long int value, int base, int flag)
{
	char					*rez;
	unsigned long long int	srav;
	int						i;

	i = ft_count(value, base);
	rez = ft_strnew(i--);
	if (value < 0 && base == 10)
		rez[0] = '-';
	if (value < 0)
		srav = -value;
	else
		srav = value;
	if (srav == 0)
		rez[0] = '0';
	while (srav > 0)
	{
		if (srav % base > 9 && flag == 0)
			rez[i--] = srav % base + 55;
		else if (srav % base > 9 && flag == 1)
			rez[i--] = srav % base + 87;
		else
			rez[i--] = srav % base + 48;
		srav = srav / base;
	}
	return (rez);
}

char	*ft_itoa_base_unsigned(unsigned long long int value, int base, int flag)
{
	char	*rez;
	int		i;

	i = ft_count_unsigned(value, base);
	rez = (char *)malloc(sizeof(char) * (i + 1));
	rez[i--] = '\0';
	if (value == 0)
		rez[0] = '0';
	while (value > 0)
	{
		if (value % base > 9 && flag == 0)
			rez[i--] = value % base + 55;
		else if (value % base > 9 && flag == 1)
			rez[i--] = value % base + 87;
		else
			rez[i--] = value % base + 48;
		value = value / base;
	}
	return (rez);
}

char	*ft_itoa_base_test(intmax_t value, int base, int flag)
{
	char					*rez;
	unsigned long long int	test;
	int						i;

	i = ft_count_test(value, base);
	rez = (char *)malloc(sizeof(char) * (i + 1));
	rez[i--] = '\0';
	if (value < 0)
		test = ULLONG_MAX + value + 1;
	else
		test = value;
	if (test == 0)
		rez[0] = '0';
	while (test > 0)
	{
		if (test % base > 9 && flag == 0)
			rez[i--] = test % base + 55;
		else if (test % base > 9 && flag == 1)
			rez[i--] = test % base + 87;
		else
			rez[i--] = test % base + 48;
		test = test / base;
	}
	return (rez);
}
