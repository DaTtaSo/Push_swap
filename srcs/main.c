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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
	{
//		free(&stack_a);
		return (0);
	}
	sort_stacks(&stack_a, &stack_b);
//	free_stack(&stack_a);
	return (0);
}