/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:10:11 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/20 08:29:49 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a_stack;
	t_list	*b_stack;
	char	**args;

	a_stack = NULL;
	b_stack = NULL;
	args = NULL;
	if (ac == 1)
		return (0);
	if (parse_input(ac, av, &args, &a_stack) == 1)
	{
		ft_printf("Error\n");
		free_all(&a_stack, &b_stack, &args);
		return (1);
	}
	if (perform_sort(&a_stack, &b_stack) == 1)
	{
		ft_printf("Error\n");
		free_all(&a_stack, &b_stack, &args);
		return (1);
	}
	free_all(&a_stack, &b_stack, &args);
	return (0);
}
