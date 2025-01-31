/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:41:59 by nbedouan          #+#    #+#             */
/*   Updated: 2025/01/27 11:42:06 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static void	fill_final_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*control;
	int		i;

	current = stack;
	i = stack_size(stack) - 1;
	while (current)
	{
		control = stack;
		while (control)
		{
			if (current->value < control->value)
				(current->final_index)++;
			control = control->next;
		}
		current->final_index = i - current->final_index;
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	stack_b = NULL;
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		return (1);
	fill_final_index(stack_a);
	if (is_sorted(stack_a) == 1)
	{
		free_stack(&stack_a);
		return (0);
	}
	sort_stacks(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
