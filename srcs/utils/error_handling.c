/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:48:50 by nbedouan          #+#    #+#             */
/*   Updated: 2025/01/22 20:49:07 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	error_exit(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	t_stack	*next;

	if (stack_a && *stack_a)
	{
		current = *stack_a;
		while (current)
		{
			next = current->next;
			free(current);
			current = next;
		}
	}
	ft_printf("%s\n", "Error : invalid input\n");
	exit(EXIT_FAILURE);
}
