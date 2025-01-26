/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imput_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:16:57 by nbedouan          #+#    #+#             */
/*   Updated: 2025/01/26 19:49:06 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack *parse_arguments(int argc, char **argv)
{
	t_stack *stack_a;
	long int num;
	int i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			error_exit(&stack_a, NULL);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_exit(&stack_a, NULL);
		if (has_duplicate(stack_a, (int)num))
			error_exit(&stack_a, NULL);
		push_front(&stack_a, create_node((int)num));
		i++;
	}
	return (stack_a);
}