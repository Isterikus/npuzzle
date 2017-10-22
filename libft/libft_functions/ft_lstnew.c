/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:36:20 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:31:22 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (content == NULL)
	{
		elem->content = (void *)NULL;
		elem->content_size = 0;
	}
	else
	{
		elem->content = (t_list *)malloc(content_size);
		if (!elem->content)
			return (NULL);
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
