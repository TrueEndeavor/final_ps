/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:06:32 by lannur-s          #+#    #+#             */
/*   Updated: 2023/05/18 12:42:48 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp1;
	t_list	*temp2;

	temp2 = *lst;
	while (temp2)
	{
		temp1 = temp2->next;
		ft_lstdelone(temp2, del);
		temp2 = temp1;
	}
	*lst = NULL;
}
