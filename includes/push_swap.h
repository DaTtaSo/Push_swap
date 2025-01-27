/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 19:02:59 by nbedouan          #+#    #+#             */
/*   Updated: 2025/01/21 20:37:58 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// operations
void	swap(t_stack **stack);
void	ss(t_stack **stack_b, t_stack **stack_a);
void	sb(t_stack **stack_b);
void	sa(t_stack **stack_a);
void	rotate(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	reverse_rotate(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	push(t_stack **dest, t_stack **src);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

// Sorting functions
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	radix_algorithm(t_stack **stack_a, t_stack **stack_b, int max_bits);
void	sort_stacks(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	sort_up_to_nine(t_stack **stack_a, t_stack **stack_b);
int		find_smallest(t_stack *stack);

// stack management
t_stack	*create_node(int value);
void	push_front(t_stack **stack, t_stack *new);
t_stack	*pop_front(t_stack **stack);
int		stack_size(t_stack *stack);

//parsing
t_stack	*parse_arguments(int argc, char **argv);
int		is_valid_number(char *str);
int		ft_atol(const char *str);
int		check_duplicate(t_stack *stack, int value);

//error management
void	error_exit(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **stack);

#endif
