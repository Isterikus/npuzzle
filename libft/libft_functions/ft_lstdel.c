/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:04:48 by dkovalen          #+#    #+#             */
/*   Updated: 2016/12/04 13:31:19 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp;

	while (*alst)
	{
		temp = *alst;
		*alst = (*alst)->next;
		del(temp->content, temp->content_size);
		free(temp);
	}
}
