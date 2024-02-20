/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:23:09 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/15 16:49:57 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	return ;
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	return ;
}

void	swap_ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	return ;
}
