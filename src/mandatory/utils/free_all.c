/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:30:19 by lannur-s          #+#    #+#             */
/*   Updated: 2024/02/15 21:30:19 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_list **a_stack, t_list **b_stack, char ***args)
{
	int	i;

	if (a_stack != NULL)
		ft_lstclear(a_stack, free);
	if (b_stack != NULL)
		ft_lstclear(b_stack, free);
	if (*args)
	{
		i = 0;
		while (args[0][i])
		{
			free(args[0][i]);
			i++;
		}
		free(*args);
	}
}
