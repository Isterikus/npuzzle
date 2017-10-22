/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:20:18 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:31:34 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int		i;

	i = -1;
	if (s)
		while (s[++i])
			ft_putchar_fd(s[i], fd);
	ft_putchar_fd('\n', fd);
}
