/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:31:43 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 14:13:50 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		if (little[j] == '\0')
			return ((char *)(big + i - j + 1));
		i++;
	}
	return (NULL);
}
