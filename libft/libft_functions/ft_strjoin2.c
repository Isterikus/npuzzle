/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:22:11 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/13 16:29:24 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin2(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*con;

	i = 0;
	j = 0;
	if (!s1)
		con = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	else
		con = (char *)malloc(sizeof(char) * (ft_strlen(s1)\
			+ ft_strlen(s2) + 1));
	if (!con)
		return (NULL);
	while (s1 && s1[i])
	{
		con[i] = s1[i];
		i++;
	}
	while (s2[j])
		con[i++] = s2[j++];
	con[i] = '\0';
	if (s1 != NULL)
		free((void *)s1);
	return (con);
}
