/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 13:58:42 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/22 17:56:12 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*chain;

	current = *lst;
	if (!*lst)
		return ;
	while (current != NULL)
	{
		chain = current->next;
		(*del)(current->content);
		free(current);
		current = chain;
	}
	*lst = NULL;
}
