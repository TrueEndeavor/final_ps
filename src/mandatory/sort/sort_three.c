/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:54:22 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/18 18:24:10 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack, int n0, int n1, int n2)
{
	if (n0 < n1)
	{
		if (n1 > n2)
		{
			reverse_rotate_a(stack);
			if (n0 < n2)
				swap_a(stack);
		}
	}
	else
	{
		if (n1 < n2)
		{
			if (n0 < n2)
				swap_a(stack);
			else
				rotate_a(stack);
		}
		else
		{
			swap_a(stack);
			reverse_rotate_a(stack);
		}
	}
}
