/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:10:44 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/06 15:10:19 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*tr;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s) - 1;
	while (s[i] && (s[i] == 9 || s[i] == 10 || s[i] == 32))
		i++;
	while (s[j] == 9 || s[j] == 10 || s[j] == 32)
		j--;
	if (i > j)
		return (ft_strnew(0));
	tr = (char *)malloc(sizeof(char) * (j - i + 2));
	if (tr == NULL)
		return (NULL);
	while (i <= j)
		tr[k++] = s[i++];
	tr[k] = '\0';
	return (tr);
}
