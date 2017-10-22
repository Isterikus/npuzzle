/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:41:41 by dkovalen          #+#    #+#             */
/*   Updated: 2017/02/08 14:28:24 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		print_int(t_printf *elem, va_list *ap)
{
	long long int	d;
	char			*str;

	if (elem->modificator != 0)
		modific(&d, elem, ap);
	else
		d = va_arg(*ap, int);
	str = ft_itoa_base(d, 10, 0);
	if (elem->width != 0 || elem->accuracy != -12345)
		return (int_width(elem, str, d));
	else
	{
		print_plus(d, elem);
		ft_putstr(str);
	}
	d = ft_strlen(str);
	free(str);
	return (d + count_plus(d, elem));
}

char	*get_another_sys(t_printf *elem, unsigned long long int d)
{
	char	*str;

	str = NULL;
	if (elem->type == 'o' || elem->type == 'O')
		str = ft_itoa_base_unsigned(d, 8, 0);
	else if (elem->type == 'x')
	{
		if (elem->modificator == 'j')
			str = ft_itoa_base_test(d, 16, 1);
		else
			str = ft_itoa_base_unsigned(d, 16, 1);
	}
	else if (elem->type == 'X')
	{
		if (elem->modificator == 'j')
			str = ft_itoa_base_test(d, 16, 0);
		else
			str = ft_itoa_base_unsigned(d, 16, 0);
	}
	else if (elem->type == 'b')
		str = ft_itoa_base_unsigned(d, 2, 0);
	return (str);
}

int		print_another_system(t_printf *elem, va_list *ap)
{
	unsigned long long int	d;
	char					*str;

	if (elem->modificator != 0)
		modific_unsigned(&d, elem, ap);
	else
		d = va_arg(*ap, unsigned int);
	str = get_another_sys(elem, d);
	if (elem->width != 0 || elem->accuracy != -12345)
		return (int_width(elem, str, d));
	else
	{
		print_plus(d, elem);
		ft_putstr(str);
	}
	return (ft_strlen(str) + count_plus(d, elem));
}

void	modific_unsigned(unsigned long long int *d, t_printf *elem, va_list *ap)
{
	if (elem->modificator == 'h')
	{
		*d = va_arg(*ap, unsigned int);
		*d = (unsigned short int)*d;
	}
	else if (elem->modificator == 'H')
	{
		*d = va_arg(*ap, unsigned int);
		*d = (unsigned char)*d;
	}
	else if (elem->modificator == 'l')
		*d = va_arg(*ap, unsigned long int);
	else if (elem->modificator == 'L')
		*d = va_arg(*ap, unsigned long long int);
	else if (elem->modificator == 'j')
		*d = va_arg(*ap, uintmax_t);
	else if (elem->modificator == 'z')
		*d = va_arg(*ap, unsigned long long int);
}

int		print_int_unsigned(t_printf *elem, va_list *ap)
{
	unsigned long long int	d;
	char					*str;

	if (elem->type == 'U')
		d = va_arg(*ap, uintmax_t);
	else if (elem->modificator != 0)
		modific_unsigned(&d, elem, ap);
	else
		d = va_arg(*ap, unsigned int);
	str = ft_itoa_base_test(d, 10, 0);
	if (elem->width != 0 || elem->accuracy != -12345)
		return (int_width(elem, str, d));
	else
		ft_putstr(str);
	return (ft_strlen(str));
}
