/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:43:23 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:32:03 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		while (little[j] != '\0' && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		else
			j = 0;
		i++;
	}
	return (NULL);
}
