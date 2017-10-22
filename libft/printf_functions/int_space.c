/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:20:40 by dkovalen          #+#    #+#             */
/*   Updated: 2017/01/25 15:43:24 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		print_space(char **str, t_printf *elem, int wid, char c)
{
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(*str);
	if (!(elem->accuracy == 0 && (*str)[0] == '0'))
		wid = wid - len;
	if ((*str)[0] == '-' && c == '0')
	{
		ft_putchar('-');
		(*str)++;
		if (elem->accuracy > 0)
			wid++;
	}
	while (i < wid)
	{
		ft_putchar(c);
		i++;
	}
	return (i);
}

int		acc(t_printf *elem, char **str, int d)
{
	int		slow;

	slow = 0;
	if (count_plus(d, elem) != 0 && ft_strchr(AN_SYS, elem->type) == NULL)
		slow = count_plus(d, elem) - 1;
	else if (ft_strchr(AN_SYS, elem->type) != NULL && elem->accuracy != 0)
	{
		slow = count_plus(d, elem);
		elem->accuracy += slow;
		if (ft_strchr(elem->flags, '#') != NULL && (elem->type == 'o'
			|| elem->type == 'O'))
			elem->accuracy--;
	}
	if (elem->accuracy > 0)
		return (print_space(str, elem, elem->accuracy - slow, '0'));
	return (0);
}

void	help_int_width(t_printf *elem, char *str, int d, int len)
{
	int		slow;
	int		srav;

	slow = count_plus(d, elem);
	if (ft_strchr(elem->flags, '0') != NULL && elem->accuracy < 0)
	{
		print_plus(d, elem);
		print_space(&str, elem, elem->width - slow, '0');
		ft_putstr(str);
	}
	else
	{
		if (elem->accuracy != -12345 && elem->accuracy > len)
			srav = elem->accuracy - len;
		else
			srav = 0;
		if (elem->width > elem->accuracy)
			print_space(&str, elem, elem->width - slow - srav, ' ');
		print_plus(d, elem);
		srav = acc(elem, &str, d);
		if (!(elem->accuracy == 0 && d == 0))
			ft_putstr(str);
	}
}

int		int_width(t_printf *elem, char *str, int d)
{
	int		slow;
	int		srav;
	int		len;

	slow = count_plus(d, elem);
	len = (int)ft_strlen(str);
	if (str[0] == '-')
		len--;
	if (ft_strchr(elem->flags, '-') != NULL)
	{
		print_plus(d, elem);
		srav = acc(elem, &str, d);
		if (!(elem->accuracy == 0 && d == 0))
			ft_putstr(str);
		print_space(&str, elem, elem->width - slow - srav, ' ');
	}
	else
		help_int_width(elem, str, d, len);
	if (elem->accuracy == 0 && d == 0)
		return (elem->width + slow);
	if (str[0] == '-')
		return (find_biggest(++len + slow, elem->width, ++elem->accuracy));
	return (find_biggest(len + slow, elem->width, elem->accuracy));
}

void	modific(long long int *d, t_printf *elem, va_list *ap)
{
	if (elem->modificator == 'h')
	{
		*d = va_arg(*ap, int);
		*d = (short int)*d;
	}
	else if (elem->modificator == 'H')
	{
		*d = va_arg(*ap, long long int);
		*d = (char)*d;
	}
	else if (elem->modificator == 'l')
		*d = va_arg(*ap, long int);
	else if (elem->modificator == 'L')
		*d = va_arg(*ap, long long int);
	else if (elem->modificator == 'j')
		*d = va_arg(*ap, intmax_t);
	else if (elem->modificator == 'z')
		*d = va_arg(*ap, size_t);
}
