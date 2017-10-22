/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:19:13 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:44:25 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*rez;

	i = -1;
	rez = NULL;
	while (s[++i])
		if (s[i] == c)
			rez = (char *)(s + i);
	if (c == '\0')
		return ((char *)(s + i));
	return (rez);
}
