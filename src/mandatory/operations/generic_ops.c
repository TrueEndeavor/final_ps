/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:23:09 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/19 17:08:34 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*temp;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
}

void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (!(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	if (!(*lst) || !(*lst)->next)
		return ;
	temp = *lst;
	last = ft_lstlast(*lst);
	*lst = (*lst)->next;
	last->next = temp;
	temp->next = NULL;
}

void	reverse_rotate(t_list **lst)
{
	t_list	*temp;
	t_list	*last;

	if (!*(lst) || !(*lst)->next)
		return ;
	last = ft_lstlast(*lst);
	temp = *lst;
	while (temp->next != last)
		temp = temp->next;
	temp->next = NULL;
	last->next = *lst;
	*lst = last;
}
