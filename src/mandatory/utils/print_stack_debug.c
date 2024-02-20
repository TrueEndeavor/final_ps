/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack_debug.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:22:33 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/19 09:33:28 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_debug(t_list *a_stack, t_list *b_stack)
{
	t_list	*temp;

	ft_printf("stack a : \n");
	temp = a_stack;
	while (temp)
	{
		ft_printf("%d ", *(int *)(temp->content));
		temp = temp->next;
	}
	ft_printf("\nstack b : \n");
	temp = b_stack;
	while (temp)
	{
		ft_printf("%d ", *(int *)(temp->content));
		temp = temp->next;
	}
	ft_printf("\n");
}
