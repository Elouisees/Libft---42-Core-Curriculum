/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 15:29:51 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/29 11:47:58 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_head(t_list **head, t_list *new_node)
{
	t_list	*temp;

	temp = *head;
	if (!*head)
		*head = new_node;
	else
	{
		temp = ft_lstlast(*head);
		temp->next = new_node;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	size_t	i;

	head = NULL;
	new_node = NULL;
	i = ft_lstsize(lst);
	while (i)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (!new_node)
		{
			ft_lstdelone(new_node, del);
			return (head);
		}
		check_head(&head, new_node);
		lst = lst->next;
		i--;
	}
	return (head);
}
