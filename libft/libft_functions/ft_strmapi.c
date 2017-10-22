/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:31:44 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 14:13:19 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
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
			cr[i] = f(i, s[i]);
	}
	return (cr);
}
