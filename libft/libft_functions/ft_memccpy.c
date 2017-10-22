/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:20:59 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 14:09:50 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dst;

	i = 0;
	src = (unsigned char *)s;
	dst = (unsigned char *)d;
	while (i < n)
	{
		dst[i] = src[i];
		if (dst[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
