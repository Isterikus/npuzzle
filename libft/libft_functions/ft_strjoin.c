/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:47:59 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/13 10:21:03 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*con;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	con = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!con)
		return (NULL);
	while (s1[++i])
		con[i] = s1[i];
	while (s2[j])
		con[i++] = s2[j++];
	con[i] = '\0';
	return (con);
}
