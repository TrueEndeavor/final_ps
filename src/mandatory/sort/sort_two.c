/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:02:23 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/18 18:24:26 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list *stack)
{
	if (((t_content *)stack->content)->index
		> ((t_content *)stack->next->content)->index)
		ft_printf("sa\n");
}
