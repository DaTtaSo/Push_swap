/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:09:31 by nbedouan          #+#    #+#             */
/*   Updated: 2025/01/22 18:09:31 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_bits(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		count++;
		n >>= 1;
	}
	return (count);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		max_bits;
	t_stack	*current;

	current = *stack_a;
	max_bits = 0;
	while (current)
	{
		if (current->value > max_bits)
			max_bits = current->value;
		current = current->next;
	}
	max_bits = count_bits(max_bits);
	radix_algorithm(stack_a, stack_b, max_bits);
}
