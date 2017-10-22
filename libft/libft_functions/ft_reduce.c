/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:50:24 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 14:10:56 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_op0(char op, t_list *beg)
{
	int		ret;

	ret = (int)beg->content;
	if (op == '-')
		while (beg->next)
		{
			beg = beg->next;
			ret -= (int)beg->content;
		}
	else if (op == '+')
		while (beg->next)
		{
			beg = beg->next;
			ret += (int)beg->content;
		}
	return (ret);
}

static int	ft_op1(char op, t_list *beg)
{
	int		ret;

	ret = (int)beg->content;
	if (op == '*')
		while (beg->next)
		{
			beg = beg->next;
			ret *= (int)beg->content;
		}
	else if (op == '/')
		while (beg->next)
		{
			beg = beg->next;
			ret /= (int)beg->content;
		}
	return (ret);
}

int			ft_reduce(char op, t_list *beg)
{
	if (op == '-' || op == '+')
		return (ft_op0(op, beg));
	else if (op == '*' || op == '/')
		return (ft_op1(op, beg));
	else
		return (0);
}
