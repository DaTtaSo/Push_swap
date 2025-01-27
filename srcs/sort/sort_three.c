/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbedouan <nbedouan@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:06:07 by nbedouan          #+#    #+#             */
/*   Updated: 2025/01/22 20:37:33 by nbedouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//void	sort_three(t_stack **stack)
//{
//	int	first;
//	int	second;
//	int	third;
//
//	first = (*stack)->value;
//	second = (*stack)->next->value;
//	third = (*stack)->next->next->value;
//	if (first > second && second > third)
//	{
//		sa(stack);
//		rra(stack);
//	}
//	else if (first > second && second < third && first > third)
//		ra(stack);
//	else if (first < second && second > third && first < third)
//	{
//		sa(stack);
//		ra(stack);
//	}
//	else if (first > second && second < third && first < third)
//		sa(stack);
//	else if (first < second && second > third && first > third)
//		rra(stack);
//}

//void	sort_three(t_stack **stack_a)
//{
//	int	one;
//	int	two;
//	int	three;
//
//	one = (*stack_a)->value;
//	two = (*stack_a)->next->value;
//	three = (*stack_a)->prev->value;
//	if ((one < two) && (two > three) && (one < three))
//	{
//		rra(stack_a);
//		sa(stack_a);
//	}
//	else if ((one < two) && (two > three) && (one > three))
//		rra(stack_a);
//	else if ((one > two) && (two < three) && (one > three))
//		ra(stack_a);
//	else if ((one > two) && (two > three))
//	{
//		sa(stack_a);
//		rra(stack_a);
//	}
//	else
//		sa(stack_a);
//}

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}
