/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_plus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:19:11 by dkovalen          #+#    #+#             */
/*   Updated: 2017/01/25 15:41:54 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		print_hash(int d, t_printf *elem)
{
	if (elem->type == 'x' && d != 0)
	{
		ft_putstr("0x");
		return (2);
	}
	else if (elem->type == 'X' && d != 0)
	{
		ft_putstr("0X");
		return (2);
	}
	else if ((elem->type == 'o' || elem->type == 'O'))
	{
		if (elem->accuracy == -12345 && d == 0)
			return (0);
		ft_putchar('0');
		return (1);
	}
	return (0);
}

int		print_plus(int d, t_printf *elem)
{
	if (d >= 0 && ft_strchr(AN_SYS, elem->type) == NULL)
	{
		if (ft_strchr(elem->flags, '+') != NULL)
		{
			ft_putchar('+');
			return (1);
		}
		else if (ft_strchr(elem->flags, ' ') != NULL)
		{
			ft_putchar(' ');
			return (1);
		}
	}
	if (ft_strchr(elem->flags, '#') != NULL)
		return (print_hash(d, elem));
	return (0);
}

int		count_plus(int d, t_printf *elem)
{
	int		i;

	i = 0;
	if (ft_strchr(elem->flags, '#') != NULL)
	{
		if ((elem->type == 'x' || elem->type == 'X') && d != 0)
			return (2);
		else if ((elem->type == 'o' || elem->type == 'O'))
		{
			if (elem->accuracy == -12345 && d == 0)
				return (0);
			return (1);
		}
	}
	if (d >= 0 && (ft_strchr(elem->flags, '+') ||
		ft_strchr(elem->flags, ' ')) && ft_strchr(AN_SYS, elem->type) == NULL)
		return (1);
	return (0);
}

int		find_biggest(int len, int wid, int acc)
{
	if (wid > acc)
	{
		if (wid > len)
			return (wid);
		else
			return (len);
	}
	else
	{
		if (acc > len)
			return (acc);
		else
			return (len);
	}
}
