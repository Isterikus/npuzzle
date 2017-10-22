/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:53:53 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:48:46 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (s1 && s2)
		while (s1[i] || s2[i])
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	return (1);
}
