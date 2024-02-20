/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:10:34 by lannur-s          #+#    #+#             */
/*   Updated: 2023/11/07 11:10:34 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(int n, t_list **a_stack)
{
	t_list	*item;

	item = *a_stack;
	while (item)
	{
		if (n == ((t_content *)item->content)->value)
			return (1);
		item = item->next;
	}
	return (0);
}

int	validate_input(int ac, char **av, t_list **a_stack)
{
	int			i;
	t_content	*content;
	t_list		*next;

	i = 0;
	while (i < ac)
	{
		if ((ac > 1 && av[i][0] == '\0') || is_int(av[i]) == 1)
			return (1);
		content = malloc(sizeof(t_content));
		if (!content)
			return (1);
		content->value = ft_atoi(av[i]);
		if (check_duplicate(content->value, a_stack) == 1)
		{
			free(content);
			return (1);
		}
		next = ft_lstnew(content);
		if (!next)
			return (1);
		ft_lstadd_back(a_stack, next);
		i++;
	}
	return (0);
}

void	assign_indices_in_ascending_order(t_list *a_stack)
{
	int		i;
	int		min;
	int		stack_size;
	t_list	*tmp;

	i = 0;
	initialize_indices(a_stack);
	stack_size = ft_lstsize(a_stack);
	while (i < stack_size)
	{
		tmp = a_stack;
		min = 2147483647;
		while (tmp)
		{
			if (((t_content *)tmp->content)->index == -1
				&& ((t_content *)tmp->content)->value < min)
				min = ((t_content *)tmp->content)->value;
			tmp = tmp->next;
		}
		tmp = a_stack;
		while (((t_content *)tmp->content)->value != min)
			tmp = tmp->next;
		((t_content *)tmp->content)->index = i;
		i++;
	}
}

int	parse_input(int ac, char **av, char ***args, t_list **a_stack)
{
	int		i;

	*a_stack = NULL;
	if (!av)
		return (-1);
	if (ac == 2)
		*args = ft_split(av[1], ' ');
	else
	{
		*args = malloc(ac * sizeof(char *));
		i = 0;
		while (i < ac - 1)
		{
			args[0][i] = ft_strdup(av[i + 1]);
			if (!args[0][i])
				return (1);
			i++;
		}
		args[0][i] = NULL;
	}
	if (validate_input(count_array_elements(*args), *args, a_stack) == 1)
		return (1);
	assign_indices_in_ascending_order(*a_stack);
	return (0);
}
