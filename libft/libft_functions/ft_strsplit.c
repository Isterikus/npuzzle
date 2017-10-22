/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:39:36 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 14:30:29 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_str_find_next(const char *str, char c, int skip)
{
	if (skip)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

static int			ft_str_count_splits(const char *str, char seps)
{
	int		i;

	i = 0;
	while (*str != '\0')
	{
		str = ft_str_find_next(str, seps, 1);
		if (*str != '\0')
		{
			i++;
			str = ft_str_find_next(str, seps, 0);
		}
	}
	return (i);
}

static char			**ft_tabledel(char **str, int len)
{
	int		i;

	i = 0;
	while (i < len)
		free(str[i++]);
	free(str);
	return (NULL);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**str;
	int			i;
	const char	*next;

	if (s == NULL)
		return (NULL);
	str = (char**)malloc(sizeof(char*) * (ft_str_count_splits(s, c) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		s = ft_str_find_next(s, c, 1);
		if (*s != '\0')
		{
			next = ft_str_find_next(s, c, 0);
			str[i] = ft_strsub((char *)s, 0, next - s);
			if (str[i] == NULL)
				return (ft_tabledel(str, i));
			i++;
			s = next;
		}
	}
	str[i] = 0;
	return (str);
}
