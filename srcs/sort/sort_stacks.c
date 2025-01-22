/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:03:05 by nbedouan          #+#    #+#             */
/*   Updated: 2025/01/22 18:03:10 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int size;

	size = stack_size(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else if (size <= 100)
		chunk_sort(stack_a, stack_b, 5);
	else
		radix_sort(stack_a, stack_b);
}
