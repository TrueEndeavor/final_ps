/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lannur-s <lannur-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:19:04 by lannur-s          #+#    #+#             */
/*   Updated: 2023/10/18 18:46:51 by lannur-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* *****************************   INCLUDES   ******************************* */
/* malloc(), free(), exit() */
# include <stdlib.h>

# include <unistd.h>

/* Libft functions */
# include "libft.h"

/* *****************************   STRUCTURES   *******************************/

typedef struct s_content
{
	int	value;
	int	index;
}	t_content;

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	score;
}	t_moves;

/* *************************   PARSE FUNCTIONS   ****************************/
int		parse_input(int ac, char **av, char ***args, t_list **a_stack);
int		perform_sort(t_list **a_stack, t_list **b_stack);
int		count_array_elements(char **args);
int		is_int(char *s);
void	initialize_indices(t_list *list);

void	free_all(t_list **a_stack, t_list **b_stack, char ***args);

int		is_sorted(t_list *stack);
int		find_min(int a, int b);

void	sort_two(t_list *stack);
void	sort_three(t_list **stack, int n0, int n1, int n2);

void	swap(t_list **stack);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_ss(t_list **stack_a, t_list **stack_b);

void	push(t_list **src, t_list **dest);
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_b, t_list **stack_a);

void	rotate(t_list **stack);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_both(t_list **stack_a, t_list **stack_b);

void	reverse_rotate(t_list **stack);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_both(t_list **stack_a, t_list **stack_b);

void	insert_a_to_b(t_list **a_stack, t_list **b_stack);
int		insert_b_to_a(t_list **a_stack, t_list **b_stack);

t_moves	*calculate_cost(int index, t_list *a_stack, t_list *b_stack, int i);

void	print_stack_debug(t_list *a_stack, t_list *b_stack);

#endif
