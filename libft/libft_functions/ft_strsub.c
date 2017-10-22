/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:43:02 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 14:14:30 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cr;

	i = 0;
	cr = (char *)malloc(sizeof(char) * (len + 1));
	if (!cr || !s)
		return (NULL);
	while (i < len)
	{
		cr[i] = s[start + i];
		i++;
	}
	cr[i] = '\0';
	return (cr);
}
