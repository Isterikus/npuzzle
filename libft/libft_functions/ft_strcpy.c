/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 10:39:18 by dkovalen          #+#    #+#             */
/*   Updated: 2017/01/11 20:34:13 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
