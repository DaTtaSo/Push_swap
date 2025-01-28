/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 00:35:14 by nbedouan          #+#    #+#             */
/*   Updated: 2025/01/27 00:35:49 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_smallest(t_stack *stack)
{
	int	smallest;

	smallest = stack->value;
	while (stack)
	{
		if (stack->value < smallest)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

void	sort_up_to_nine(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;

	while (stack_size(*stack_a) > 3)
	{
		smallest = find_smallest(*stack_a);
		while ((*stack_a)->value != smallest)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
