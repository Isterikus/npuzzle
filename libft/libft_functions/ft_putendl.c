/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:39:19 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:31:33 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	int		i;

	i = -1;
	if (s)
		while (s[++i])
			ft_putchar(s[i]);
	ft_putchar('\n');
}
