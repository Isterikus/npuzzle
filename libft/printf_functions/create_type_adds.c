/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_type_adds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:07:20 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/11 13:47:23 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			flags(const char *type, int i, t_printf **elem, int flag)
{
	int		j;

	j = 0;
	if (type[i] == '-' || type[i] == '+' ||\
		type[i] == ' ' || type[i] == '#' || type[i] == '0')
	{
		while (type[i + j] == '-' || type[i + j] == '+' ||\
		type[i + j] == ' ' || type[i + j] == '#' || type[i + j] == '0')
			j++;
		if (flag == 0)
			(*elem)->flags = ft_strsub((char *)type, i, j);
		else
			(*elem)->flags = ft_strjoin((*elem)->flags,\
				ft_strsub((char *)type, i, j));
		i += j;
	}
	return (i);
}

int			int_w(const char *type, int i, t_printf **elem, va_list *ap)
{
	if (type[i] == '*')
	{
		(*elem)->width = va_arg(*ap, int);
		if ((*elem)->width < 0)
		{
			(*elem)->flags = ft_strjoin((*elem)->flags, "-");
			(*elem)->width = -(*elem)->width;
		}
		i++;
	}
	if (type[i] == '-' || (type[i] > 47 && type[i] < 58))
	{
		(*elem)->width = ft_atoi(type + i);
		while (type[i] > 47 && type[i] < 58)
			i++;
	}
	if (type[i] == '*')
	{
		(*elem)->width = va_arg(*ap, int);
		i++;
	}
	return (i);
}

int			int_a(const char *type, int i, t_printf **elem, va_list *ap)
{
	while (type[i] == '.')
		i++;
	if (type[i] == '*')
	{
		(*elem)->accuracy = va_arg(*ap, int);
		i++;
	}
	if (type[i] == '-' || (type[i] > 47 && type[i] < 58))
	{
		(*elem)->accuracy = ft_atoi(type + i);
		while (type[i] > 47 && type[i] < 58)
			i++;
	}
	if (type[i] == '*')
	{
		(*elem)->accuracy = va_arg(*ap, int);
		i++;
	}
	return (i);
}

int			help_modificators(const char *type, int i, t_printf **elem)
{
	if (type[i] == 'h')
	{
		if (type[i + 1] == 'h')
		{
			i++;
			(*elem)->modificator = 'H';
		}
		else
			(*elem)->modificator = 'h';
		i++;
	}
	if (type[i] == 'l')
	{
		if (type[i + 1] == 'l')
		{
			i++;
			(*elem)->modificator = 'L';
		}
		else
			(*elem)->modificator = 'l';
		i++;
	}
	return (i);
}

int			modificators(const char *type, int i, t_printf **elem)
{
	i = help_modificators(type, i, elem);
	if (type[i] == 'L')
	{
		i++;
		(*elem)->modificator = 'Z';
	}
	if (type[i] == 'j')
	{
		i++;
		(*elem)->modificator = 'j';
	}
	if (type[i] == 'z')
	{
		i++;
		(*elem)->modificator = 'z';
	}
	while (type[i] == 'h' || type[i] == 'l' || type[i] == 'L'
			|| type[i] == 'j' || type[i] == 'z')
		i++;
	return (i);
}
