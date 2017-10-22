/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_chars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:09:28 by dkovalen          #+#    #+#             */
/*   Updated: 2017/01/25 15:47:20 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_putwchar(wchar_t c)
{
	char	*str;

	str = ft_encode(c);
	ft_putstr(str);
	return (1);
}

int		ft_putwchars(wchar_t *str)
{
	int		i;

	i = 0;
	while (str[i])
		ft_putwchar(str[i++]);
	return (i);
}

int		first_str_wch(wchar_t *str, t_printf *elem, char c, int acc)
{
	int		ret;
	int		i;

	ret = 0;
	if (ft_strchr(SINGLE, elem->type) != NULL && str[0] == '\0')
		ret += ft_putwchar(str[0]);
	if (elem->accuracy != -12345)
	{
		i = 0;
		while (i < elem->accuracy && str[i])
			ret += ft_putwchar(str[i++]);
	}
	else
		ret += ft_putwchars(str);
	i = 0;
	while (i < elem->width - acc)
	{
		i++;
		ft_putchar(c);
	}
	return (ret + i);
}

int		first_c_wch(wchar_t *str, t_printf *elem, char c, int acc)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (i < elem->width - acc)
	{
		i++;
		ft_putchar(c);
	}
	if (ft_strchr(SINGLE, elem->type) != NULL)
		ret += ft_putwchar(str[0]);
	else if (elem->accuracy != -12345 && elem->type != 'p')
	{
		i = 0;
		while (i < elem->accuracy && str[i])
			ret += ft_putwchar(str[i++]);
	}
	else
		ret += ft_putwchars(str);
	return (ret + i);
}

int		create_spaces_wch(wchar_t *str, t_printf *elem)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (elem->width != 0)
	{
		if (ft_strchr(elem->flags, '-') != NULL)
			return (first_str_wch(str, elem, ' ', 1));
		else if (ft_strchr(elem->flags, '0') != NULL)
			return (first_c_wch(str, elem, '0', 1));
		else
			return (first_c_wch(str, elem, ' ', 0));
	}
	else if (elem->accuracy != -12345)
	{
		while (i < elem->accuracy && str[i])
			ret += ft_putwchar(str[i++]);
	}
	else
		ret += ft_putwchars(str);
	return (ret);
}
