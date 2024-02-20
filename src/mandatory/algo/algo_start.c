/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:40:04 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/20 09:30:36 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_sort(t_list **a_stack, t_list **b_stack)
{
	insert_a_to_b(a_stack, b_stack);
	sort_three(a_stack, ((t_content *)(*a_stack)->content)->index,
		((t_content *)(*a_stack)->next->content)->index,
		((t_content *)(*a_stack)->next->next->content)->index);
	if (insert_b_to_a(a_stack, b_stack) == 1)
		return (1);
	return (0);
}

int	perform_sort(t_list **a_stack, t_list **b_stack)
{
	int	stack_size;

	if (is_sorted(*a_stack) == 1)
		return (0);
	stack_size = ft_lstsize(*a_stack);
	if (stack_size == 2)
		sort_two(*a_stack);
	if (stack_size >= 3)
	{
		if (stack_size == 3)
			sort_three(a_stack, ((t_content *)(*a_stack)->content)->index,
				((t_content *)(*a_stack)->next->content)->index,
				((t_content *)(*a_stack)->next->next->content)->index);
		else
		{
			if (run_sort(a_stack, b_stack) == 1)
				return (1);
		}
	}
	return (0);
}
