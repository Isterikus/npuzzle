/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:49:47 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/11 13:47:36 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			abs(int d)
{
	if (d >= 0)
		return (d);
	else
		return (-d);
}

void		fill_type(t_printf **elem, int *i)
{
	*elem = (t_printf *)malloc(sizeof(t_printf));
	(*i)++;
	(*elem)->flags = "\0";
	(*elem)->width = 0;
	(*elem)->accuracy = -12345;
	(*elem)->modificator = 0;
	(*elem)->type = 0;
}

void		free_elem(t_printf **elem, char **test)
{
	free(*elem);
	*elem = NULL;
	free(*test);
	*test = NULL;
}

t_printf	*create_type(const char *type, int *i, va_list *ap)
{
	t_printf	*elem;

	fill_type(&elem, i);
	*i = flags(type, *i, &elem, 0);
	*i = int_w(type, *i, &elem, ap);
	if (type[*i] == '.')
	{
		*i = int_a(type, *i + 1, &elem, ap);
		if (type[*i] == '.' || elem->accuracy == -12345)
		{
			while (type[*i] == '.')
				(*i)++;
			elem->accuracy = 0;
		}
	}
	*i = modificators(type, *i, &elem);
	if (ft_strchr(FLAGS, type[*i]) != NULL)
		*i = flags(type, *i, &elem, 1);
	if (ft_strchr(TYPES, type[*i]) == NULL || type[*i] == '\0')
		return (NULL);
	elem->type = type[(*i)++];
	if (elem->type == 'D' || elem->type == 'O')
		elem->modificator = 'l';
	return (elem);
}
