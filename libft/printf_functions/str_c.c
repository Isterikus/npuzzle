/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:11:32 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/11 13:28:28 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	first_str(char *str, t_printf *elem, char c, int acc)
{
	int		i;

	i = 0;
	if (ft_strchr(SINGLE, elem->type) != NULL && str[0] == '\0')
		ft_putchar(str[0]);
	if (elem->accuracy != -12345 && elem->type != 'p')
	{
		i = 0;
		while (i < elem->accuracy && str[i])
			ft_putchar(str[i++]);
	}
	else
		ft_putstr(str);
	i = 0;
	while (i < elem->width - acc)
	{
		i++;
		ft_putchar(c);
	}
}

void	first_c(char *str, t_printf *elem, char c, int acc)
{
	int		i;

	i = 0;
	while (i < elem->width - acc)
	{
		i++;
		ft_putchar(c);
	}
	if (ft_strchr(SINGLE, elem->type) != NULL)
		ft_putchar(str[0]);
	else if (elem->accuracy != -12345 && elem->type != 'p')
	{
		i = 0;
		while (i < elem->accuracy && str[i])
			ft_putchar(str[i++]);
	}
	else
		ft_putstr(str);
}

void	create_spaces(char *str, t_printf *elem, char c, int flag)
{
	int		i;
	int		acc;

	i = 0;
	if (elem->accuracy != -12345 && elem->accuracy < (int)ft_strlen(str)
		&& elem->type != 'p')
		acc = elem->accuracy;
	else
		acc = ft_strlen(str);
	if (ft_strchr(SINGLE, elem->type) != NULL)
		acc = 1;
	if (flag == 1)
		first_str(str, elem, c, acc);
	else
		first_c(str, elem, c, acc);
}

int		print_string(t_printf *elem, va_list *ap)
{
	char	*str;
	int		i;

	i = -1;
	str = va_arg(*ap, char *);
	(str == NULL) ? str = ft_strdup(NL) : 0;
	if (elem->width != 0)
	{
		if (ft_strchr(elem->flags, '-') != NULL)
			create_spaces(str, elem, ' ', 1);
		else if (ft_strchr(elem->flags, '0') != NULL)
			create_spaces(str, elem, '0', 0);
		else
			create_spaces(str, elem, ' ', 0);
		if ((int)ft_strlen(str) < elem->accuracy || elem->accuracy < 0)
			return (find_biggest(ft_strlen(str), elem->width, 0));
		else
			return (find_biggest(0, elem->width, elem->accuracy));
	}
	else if (elem->accuracy >= 0)
		while (++i < elem->accuracy && str[i])
			ft_putchar(str[i]);
	else
		ft_putstr(str);
	return ((i == -1) ? ft_strlen(str) : i);
}

int		print_char(t_printf *elem, va_list *ap, int flag)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (flag == 0)
		str[0] = va_arg(*ap, unsigned int);
	else if (elem->type == '%')
		str[0] = '%';
	else
		str[0] = elem->type;
	str[1] = '\0';
	if (elem->width != 0)
	{
		if (ft_strchr(elem->flags, '-') != NULL)
			create_spaces(str, elem, ' ', 1);
		else if (ft_strchr(elem->flags, '0') != NULL)
			create_spaces(str, elem, '0', 0);
		else
			create_spaces(str, elem, ' ', 0);
		return (elem->width);
	}
	else
		ft_putchar(str[0]);
	free(str);
	return (1);
}
