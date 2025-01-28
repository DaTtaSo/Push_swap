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

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*new;
	long		num;
	int			i;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			error_exit(&stack_a, NULL);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_exit(&stack_a, NULL);
		if (check_duplicate(stack_a, (int)num))
			error_exit(&stack_a, NULL);
		new = create_node((int)num);
		if (!new)
		{
			free_stack(&stack_a);
			return (NULL);
		}
		push_back(&stack_a, new);
		i++;
	}
	return (stack_a);
}
