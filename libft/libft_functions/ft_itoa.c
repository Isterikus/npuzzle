/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:16:28 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/05 21:14:23 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long long int n)
{
	int		i;

	i = 0;
	if (n <= 0)
	{
		n = -n;
		i++;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long long int n)
{
	int			i;
	char		*str;

	i = ft_len(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = 48;
	while (n != 0)
	{
		str[i--] = n % 10 + 48;
		n /= 10;
	}
	return (str);
}
