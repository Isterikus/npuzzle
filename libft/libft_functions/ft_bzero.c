/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:16:00 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:33:53 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*b;

	i = -1;
	b = (unsigned char *)s;
	while (++i < n)
		b[i] = (unsigned char)(NULL);
}
