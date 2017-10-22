/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:03:41 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:49:04 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cp;

	i = ft_strlen(s1);
	cp = (char *)malloc(sizeof(char) * (i + 1));
	if (!cp)
		return (NULL);
	i = -1;
	while (s1[++i])
		cp[i] = s1[i];
	cp[i] = '\0';
	return (cp);
}
