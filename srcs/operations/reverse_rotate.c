/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:40:04 by nbedouan          #+#    #+#             */
/*   Updated: 2025/01/22 18:04:37 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rra\n", 4);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*second_last;

	if (!stack || !(*stack)->next)
		return ;
	temp = *stack;
	second_last = NULL;
	while (temp->next) {
		second_last = temp;
		temp = temp->next;
	}
	second_last->next = NULL;
	temp->next = *stack;
	*stack = temp;
}
