/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:36:34 by tle               #+#    #+#             */
/*   Updated: 2021/04/01 15:35:36 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*to_free;
	t_list	*next_node;

	if (*lst)
	{
		to_free = *lst;
		while (to_free)
		{
			next_node = to_free;
			del(to_free->content);
			free(to_free);
			to_free = next_node->next;
		}
		*lst = NULL;
	}
}
