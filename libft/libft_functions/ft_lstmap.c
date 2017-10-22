/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:58:41 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:35:39 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*cr;

	ret = NULL;
	if (lst)
		ret = f(lst);
	if (ret == NULL)
		return (NULL);
	cr = ret;
	while (lst->next)
	{
		lst = lst->next;
		cr->next = f(lst);
		if (cr->next == NULL)
			return (NULL);
		cr = cr->next;
	}
	return (ret);
}
