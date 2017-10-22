/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_dot_small.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:26:59 by dkovalen          #+#    #+#             */
/*   Updated: 2017/01/25 15:42:11 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_10pow(int d)
{
	int		i;
	int		ret;

	ret = 1;
	i = 0;
	while (i < d)
	{
		ret = ret * 10;
		i++;
	}
	return (ret);
}

int		ft_intlen(long int d, int flag)
{
	int			ret;

	if (d < 0)
		d = -d;
	ret = 1;
	if (flag == 1)
		ret--;
	while (d > 0)
	{
		d = d / 10;
		if (flag == 0)
			ret = ret * 10;
		else
			ret++;
	}
	if (flag == 0)
		ret = ret / 10;
	return (ret);
}

int		count_dig(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (str[i++] == '.')
			return (i - 1);
	return (i);
}

int		print_dob(char *str, t_printf *elem, long double d)
{
	if (elem->width != 0)
		return (int_width(elem, str, d));
	else
	{
		print_plus(d, elem);
		ft_putstr(str);
	}
	return (ft_strlen(str) + count_plus(d, elem));
}

int		print_double(t_printf *elem, va_list *ap)
{
	long double	d;
	char		*str;

	if (elem->modificator == 'Z')
		d = va_arg(*ap, long double);
	else
		d = va_arg(*ap, double);
	if (elem->accuracy == -12345)
		elem->accuracy = 6;
	str = ft_get_double(d, elem);
	return (print_dob(str, elem, d));
}
