/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:34:12 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/28 15:16:33 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	t_stack	*second;
	t_stack	*third;

	second = (*stack)->next;
	third = second->next;
	if ((*stack)->data > second->data && (*stack)->data > third->data)
		rotate(&(*stack));
	if (second->data > (*stack)->data && second->data > third->data)
		rotate_down(&(*stack));
	second = (*stack)->next;
	third = second->next;
	if (second->data < (*stack)->data)
		swap(&(*stack));
	second = (*stack)->next;
	third = second->next;
	third->prev = second;
	second->prev = *stack;
}

void	sort_2(t_stack **stack)
{
	t_stack	*second;

	second = (*stack)->next;
	if ((*stack)->data > second->data)
		swap(&(*stack));
}

void	sort_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_length(*stack_a) == 4)
		push(&(*stack_a), &(*stack_b));
	if (stack_length(*stack_a) > 4)
	{
		push(&(*stack_a), &(*stack_b));
		push(&(*stack_a), &(*stack_b));
		assign_all(&(*stack_a), &(*stack_b));
	}
	while (stack_length(*stack_a) > 3)
	{
		push_cheapest_to_b(&(*stack_a), &(*stack_b));
	}
	sort_3(&(*stack_a));
}

void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	assign_all2(&(*stack_a), &(*stack_b));
	while ((*stack_b)->data != (*stack_a)->data)
	{
		push_cheapest_to_a(&(*stack_a), &(*stack_b));
	}
}

void	sort_final(t_stack **stack)
{
	t_stack	*temp;

	index_assign(&(*stack), &(*stack));
	median_assign(&(*stack), &(*stack));
	temp = max_node(*stack);
	if (temp->index != stack_length(*stack))
	{
		if (temp->above_median == 1)
		{
			while (temp->index != stack_length(*stack))
			{
				rotate(&(*stack));
				index_assign(&(*stack), &(*stack));
			}
			return ;
		}
		if (temp->above_median == 0)
		{
			while (temp->index != stack_length(*stack))
			{
				rotate_down(&(*stack));
				index_assign(&(*stack), &(*stack));
			}
		}
	}
}
