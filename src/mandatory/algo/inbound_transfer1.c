/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inbound_transfer1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:54:22 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/20 10:03:40 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*find_optimal_rotation_sequence(t_list **a_stack, t_list **b_stack)
{
	t_moves	*moves_so_far;
	t_moves	*seq;
	t_list	*current_element;
	int		i;

	i = 0;
	moves_so_far = NULL;
	current_element = *b_stack;
	while (current_element)
	{
		seq = calculate_cost(((t_content *)current_element->content)->index, \
			*a_stack, *b_stack, i);
		if (!seq)
			return (NULL);
		if (!moves_so_far || moves_so_far->score > seq->score)
		{
			free(moves_so_far);
			moves_so_far = seq;
		}
		else
			free(seq);
		i++;
		current_element = current_element->next;
	}
	return (moves_so_far);
}

void	do_rotations(t_moves **moves, t_list **a_stack, t_list **b_stack)
{
	while ((*moves)->rr || (*moves)->ra || (*moves)->rb)
	{
		if ((*moves)->rr)
		{
			rotate_both(a_stack, b_stack);
			(*moves)->rr--;
		}
		if ((*moves)->ra)
		{
			rotate_a(a_stack);
			(*moves)->ra--;
		}
		if ((*moves)->rb)
		{
			rotate_b(b_stack);
			(*moves)->rb--;
		}
	}
}

void	do_rvrs_rotations(t_moves **moves, t_list **a_stack, t_list **b_stack)
{
	while ((*moves)->rrr || (*moves)->rra || (*moves)->rrb)
	{
		if ((*moves)->rrr)
		{
			reverse_rotate_both(a_stack, b_stack);
			(*moves)->rrr--;
		}
		else if ((*moves)->rra)
		{
			reverse_rotate_a(a_stack);
			(*moves)->rra--;
		}
		else if ((*moves)->rrb)
		{
			reverse_rotate_b(b_stack);
			(*moves)->rrb--;
		}
	}
}

char	*ft_last_rotate(t_list *list)
{
	t_list	*temp;
	int		min;
	int		i;
	int		imin;

	i = 0;
	min = ((t_content *)list->content)->index;
	temp = list;
	while (temp)
	{
		if (((t_content *)temp->content)->index < min)
		{
			min = ((t_content *)temp->content)->index;
			imin = i;
		}
		temp = temp->next;
		i++;
	}
	if (imin <= ft_lstsize(list) - imin)
		return ("ra");
	else
		return ("rra");
}

int	insert_b_to_a(t_list **a_stack, t_list **b_stack)
{
	t_moves	*moves;
	char	*last_r;

	while (*b_stack)
	{
		moves = find_optimal_rotation_sequence(a_stack, b_stack);
		if (!moves)
			return (1);
		do_rotations(&moves, a_stack, b_stack);
		do_rvrs_rotations(&moves, a_stack, b_stack);
		push_a(b_stack, a_stack);
		free(moves);
	}
	last_r = ft_last_rotate(*a_stack);
	while (is_sorted(*a_stack) == 0)
	{
		if (ft_strcmp(last_r, "ra") == 0)
			rotate_a(a_stack);
		if (ft_strcmp(last_r, "rra") == 0)
			reverse_rotate_a(a_stack);
	}
	return (0);
}
