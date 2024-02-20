/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:23:09 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/15 16:47:15 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_list **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	return ;
}

void	reverse_rotate_b(t_list **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	return ;
}

void	reverse_rotate_both(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
	return ;
}
