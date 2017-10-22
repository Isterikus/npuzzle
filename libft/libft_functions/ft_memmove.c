/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:03:06 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:31:28 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (s < d)
	{
		i = len - 1;
		while (len > 0)
		{
			d[i] = s[i];
			i--;
			len--;
		}
	}
	else
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	return (d);
}
