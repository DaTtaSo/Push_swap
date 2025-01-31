/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:53:28 by nbedouan          #+#    #+#             */
/*   Updated: 2025/01/27 03:15:42 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	radix_algorithm(t_stack **stack_a, t_stack **stack_b, int max_bits)
{
	int	i;
	int	j;
	int	size;

	size = stack_size(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size && is_sorted(*stack_a) == 0)
		{
			if (((*stack_a)->final_index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
}
