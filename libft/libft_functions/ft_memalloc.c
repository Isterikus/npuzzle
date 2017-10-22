/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:36:47 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:34:37 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*lol;
	size_t	i;

	i = 0;
	lol = (char *)malloc(sizeof(char) * size);
	if (!lol)
		return (NULL);
	while (i < size)
		lol[i++] = '\0';
	return (lol);
}
