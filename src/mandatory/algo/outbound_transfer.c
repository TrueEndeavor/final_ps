/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outbound_transfer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:54:22 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/19 18:50:34 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* calculate distance_of_highest_from_top above median */
int	distance_of_highest_from_top(t_list *list, int median)
{
	int		highest;
	int		len;

	highest = 0;
	len = ft_lstsize(list);
	while (list && ((t_content *)list->content)->index > median)
	{
		highest++;
		list = list->next;
	}
	if (highest >= len)
		highest = -1;
	return (highest);
}

/* calculate distance_of_lowest_from_bottom below median */
int	distance_of_lowest_from_bottom(t_list *list, int median)
{
	int	lowest;

	lowest = 1;
	while (list)
	{
		if (((t_content *)list->content)->index <= median)
			lowest = 0;
		lowest++;
		list = list->next;
	}
	return (lowest);
}

void	smart_rotate(t_list **list, int highest, int lowest)
{
	if (highest <= lowest)
	{
		while (highest > 0)
		{
			rotate_a(list);
			highest--;
		}
	}
	else
	{
		while (lowest)
		{
			reverse_rotate_a(list);
			lowest--;
		}
	}
}

/* Push elements to stack B based on their position relative to the median */
void	insert_a_to_b(t_list **a_stack, t_list **b_stack)
{
	int		highest;
	int		lowest;
	int		median;

	median = ft_lstsize(*a_stack) / 2;
	highest = distance_of_highest_from_top(*a_stack, median);
	while (highest > -1 && ft_lstsize(*a_stack) > 3)
	{
		lowest = distance_of_lowest_from_bottom(*a_stack, median);
		smart_rotate(a_stack, highest, lowest);
		push_b(a_stack, b_stack);
		highest = distance_of_highest_from_top(*a_stack, median);
	}
	while (ft_lstsize(*a_stack) > 3)
		push_b(a_stack, b_stack);
}
