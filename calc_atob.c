/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_atob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:59:16 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/28 15:05:27 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	t_stack	*target_temp;

	temp_a = *stack_a;
	temp_b = *stack_b;
	target_temp = NULL;
	while (temp_b != NULL)
	{
		if (temp_a->data > temp_b->data)
		{
			if (target_temp == NULL || temp_b->data > target_temp->data)
			{
				temp_a->target = temp_b;
				target_temp = temp_b;
			}
		}
		temp_b = temp_b->next;
	}
	temp_b = *stack_b;
	if (target_temp == NULL)
		temp_a->target = max_node(temp_b);
}

void	assign_target_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a != NULL)
	{
		find_target_b(&temp_a, &temp_b);
		temp_a = temp_a->next;
	}
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
			rotate_b(&b_temp);
			individual_index(&b_temp);
		}
	}
	if (a_temp->target->above_median == 0)
	{
		while (a_temp->target->index != 1)
		{
			rotate_down_b(&b_temp);
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
