/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:34 by lannur-s          #+#    #+#             */
/*   Updated: 2024/01/11 15:11:34 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char *s)
{
	char	*max;

	max = "2147483647";
	if (!s)
		return (1);
	while (ft_isspace(*s))
		s++;
	if (*s == '+' && *(s + 1) != '\0')
		s++;
	else if (*s == '-' && *(s + 1) != '\0')
	{
		max = "2147483648";
		s++;
	}
	while (*s == '0')
		s ++;
	if (ft_strlen(s) > 10 || (ft_strlen(s) == 10 && ft_strncmp(s, max, 10) > 0))
		return (1);
	while (*s)
	{
		if (ft_isdigit(*s) == 0)
			return (1);
		s++;
	}
	return (0);
}

int	count_array_elements(char **args)
{
	int	i;

	i = 0;
	while (args && args[i])
		i++;
	return (i);
}

void	initialize_indices(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp)
	{
		((t_content *)temp->content)->index = -1;
		temp = temp->next;
	}
}
