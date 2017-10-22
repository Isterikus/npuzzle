/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 22:05:12 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:31:59 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*lol;
	size_t	i;

	i = 0;
	lol = (char *)malloc(sizeof(char) * (size + 1));
	if (!lol)
		return (NULL);
	while (i <= size)
		lol[i++] = '\0';
	return (lol);
}
