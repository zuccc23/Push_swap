/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:34:12 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/16 15:53:38 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(s_list **stack)
{
	s_list	*second;
	s_list	*third;

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
void	sort_2(s_list **stack)
{
	s_list	*second;

	second = (*stack)->next;
	if ((*stack)->data > second->data)
		swap(&(*stack));
}

void	push_cheapest_to_b(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp;

	move_b(*stack_a, &(*stack_b));
	move_a(&(*stack_a), *stack_b);
	push(&(*stack_a), &(*stack_b));
	assign_all(&(*stack_a), &(*stack_b));
}

void	move_b(s_list *stack_a, s_list **stack_b)
{
	s_list	*a_temp;
	s_list	*b_temp;

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

void	move_a(s_list **stack_a, s_list *stack_b)
{
	s_list	*a_temp;

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