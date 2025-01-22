/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:34:12 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/22 19:19:18 by dahmane          ###   ########.fr       */
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

void	push_cheapest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	move_b(*stack_a, &(*stack_b));
	move_a(&(*stack_a), *stack_b);
	push(&(*stack_a), &(*stack_b));
	assign_all(&(*stack_a), &(*stack_b));
}

void	move_b(t_stack *stack_a, t_stack **stack_b)
{
	t_stack	*a_temp;
	t_stack	*b_temp;

	a_temp = stack_a;
	b_temp = *stack_b;
	while (a_temp->cheapest != 1)
		a_temp = a_temp->next;
	if (a_temp->target->above_median == 1)
	{
		while (a_temp->target->index != 1)
		{
			rotate(&b_temp);
			individual_index(&b_temp);
		}
	}
	if (a_temp->target->above_median == 0)
	{
		while (a_temp->target->index != 1)
		{
			rotate_down(&b_temp);
			individual_index(&b_temp);
		}
	}
	*stack_b = b_temp;
}

void	move_a(t_stack **stack_a, t_stack *stack_b)
{
	t_stack	*a_temp;

	a_temp = *stack_a;
	while (a_temp->cheapest != 1)
		a_temp = a_temp->next;
	if (a_temp->above_median == 1)
	{
		while (a_temp->index != 1)
		{
			rotate(&(*stack_a));
			individual_index(&(*stack_a));
		}
	}
	if (a_temp->above_median == 0)
	{
		while (a_temp->index != 1)
		{
			rotate_down(&(*stack_a));
			individual_index(&(*stack_a));
		}
	}
}