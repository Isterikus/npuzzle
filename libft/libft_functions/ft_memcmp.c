/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:40:02 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 14:38:40 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*d1;
	char	*d2;

	i = 0;
	d1 = (char *)s1;
	d2 = (char *)s2;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (d1[i] == d2[i])
			i++;
		else
			return ((unsigned char)d1[i] - (unsigned char)d2[i]);
	}
	return (0);
}
