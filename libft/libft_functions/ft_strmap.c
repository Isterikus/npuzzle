/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:30:49 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:43:30 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*cr;

	i = 0;
	cr = NULL;
	if (s)
	{
		while (s[i])
			i++;
		cr = (char *)malloc(sizeof(char) * (i + 1));
		if (!cr)
			return (NULL);
		cr[i] = '\0';
		while (--i >= 0)
			cr[i] = f(s[i]);
	}
	return (cr);
}
