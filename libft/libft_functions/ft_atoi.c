/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:58:51 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/16 12:00:54 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *str)
{
	int			i;
	long int	num;
	int			min;

	i = 0;
	num = 0;
	min = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		i++;
		min = -1;
	}
	while (str[i] > 47 && str[i] < 58)
		num = num * 10 + str[i++] - 48;
	return (num * min);
}
