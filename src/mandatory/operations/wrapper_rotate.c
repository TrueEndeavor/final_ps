/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:23:09 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/15 16:46:39 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	return ;
}

void	rotate_b(t_list **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	return ;
}

void	rotate_both(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	return ;
}
