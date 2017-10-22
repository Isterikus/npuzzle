/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:13:44 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:31:50 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	if (i == size)
		return (i + ft_strlen(src));
	size = size - i - 1;
	while (src[j] && j < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
