/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:08:31 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/18 18:21:40 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
{
	int	n1;
	int	n2;

	while (list && list->next)
	{
		n1 = ((t_content *)list->content)->index;
		n2 = ((t_content *)list->next->content)->index;
		if (n1 > n2)
			return (0);
		list = list->next;
	}
	return (1);
}

int	find_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
