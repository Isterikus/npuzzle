/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_dot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:44:41 by dkovalen          #+#    #+#             */
/*   Updated: 2017/01/25 15:40:58 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_get_double(long double d, t_printf *elem)
{
	long long int	i;
	char			*str;
	char			*dot;
	int				j;

	str = ft_itoa_base(d, 10, 0);
	if (d < 0)
		d = -d;
	i = (long long int)d;
	if ((elem->type == 'g' || elem->type == 'G') && ft_strlen(str) == 6)
		return (str);
	str = ft_strjoin(str, ".");
	d = d - i;
	i = (int)((double)d * (ft_10pow(elem->accuracy) * 10));
	if (i % 10 >= 5)
		i += 10;
	i = i / 10;
	j = ft_intlen((int)i, 1);
	if (j == 0)
		j++;
	while (j++ < 6 && elem->type != 'g' && elem->type != 'G')
		str = ft_strjoin(str, "0");
	dot = ft_itoa_base(i, 10, 0);
	str = ft_strjoin(str, dot);
	return (str);
}

char	*ft_get_double_e(long double d, t_printf *elem)
{
	char		*str;
	long int	i;
	int			j;
	char		*dot;

	d = d / ft_intlen(d, 0);
	str = ft_itoa_base((int)d, 10, 0);
	if (d < 0)
		d = -d;
	i = (long int)d;
	d = d - i;
	i = d * (ft_10pow(elem->accuracy) * 10);
	if (i % 10 >= 5)
		i += 10;
	i = i / 10;
	str = ft_strjoin(str, ".");
	j = ft_intlen((int)i, 1);
	if (j == 0 || elem->type == 'g' || elem->type == 'G')
		j++;
	while (j++ < 6)
		str = ft_strjoin(str, "0");
	dot = ft_itoa_base(i, 10, 0);
	str = ft_strjoin(str, dot);
	return (str);
}

int		print_e(t_printf *elem, long double d, char *str, int ten)
{
	if (elem->type == 'e' || elem->type == 'g')
	{
		if (ten > 9)
			str = ft_strjoin(str, "e+");
		else
			str = ft_strjoin(str, "e+0");
	}
	else
	{
		if (ten > 9)
			str = ft_strjoin(str, "E+");
		else
			str = ft_strjoin(str, "E+0");
	}
	str = ft_strjoin(str, ft_itoa_base(ten - 1, 10, 0));
	if (elem->width != 0)
		return (int_width(elem, str, d));
	else
	{
		print_plus(d, elem);
		ft_putstr(str);
	}
	return (ft_strlen(str) + count_plus(d, elem));
}

int		print_double_e(t_printf *elem, va_list *ap)
{
	long double	d;
	int			ten;
	char		*str;

	if (elem->modificator == 'Z')
		d = va_arg(*ap, long double);
	else
		d = va_arg(*ap, double);
	if (elem->accuracy == -12345)
		elem->accuracy = 6;
	str = ft_get_double_e(d, elem);
	ten = ft_intlen(d, 1);
	return (print_e(elem, d, str, ten));
}

int		print_double_short(t_printf *elem, va_list *ap)
{
	long double	d;
	int			ten;
	char		*str1;
	char		*str2;

	if (elem->modificator == 'Z')
		d = va_arg(*ap, long double);
	else
		d = va_arg(*ap, double);
	if (elem->accuracy == -12345)
		elem->accuracy = 5;
	str1 = ft_get_double(d, elem);
	str2 = ft_get_double_e(d, elem);
	ten = ft_intlen(d, 1);
	if (count_dig(str1) < 7)
	{
		str1[7] = '\0';
		return (print_dob(str1, elem, d));
	}
	else
		return (print_e(elem, d, str2, ten));
}
