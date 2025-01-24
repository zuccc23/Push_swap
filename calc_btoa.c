/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:10:45 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/24 14:22:32 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_targetv2(t_stack *stack_a, t_stack **stack_b)
{
	t_stack	*target;
	t_stack	*a_temp;
	t_stack	*b_temp;

	a_temp = stack_a;
	b_temp = *stack_b;
	target = NULL;
	while (a_temp != NULL)
	{
		if (a_temp->data > b_temp->data)
		{
			if (target == NULL || target->data > a_temp->data)
				target = a_temp;
		}
		a_temp = a_temp->next;
	}
	if (target == NULL)
		b_temp->target = min_node(stack_a);
	else
		b_temp->target = target;
}

void	assign_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_b != NULL)
	{
		find_targetv2(temp_a, &temp_b);
		temp_b = temp_b->next;
	}
}

void	push_cheapest_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	move_b3(&(*stack_b), *stack_a);
	move_a3(*stack_b, &(*stack_a));
	push(&(*stack_b), &(*stack_a));
	assign_all2(&(*stack_a), &(*stack_b));
}

void	move_a3(t_stack *givee, t_stack **receive)
{
	t_stack	*a_temp;
	t_stack	*b_temp;

	a_temp = givee;
	b_temp = *receive;
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
	*receive = b_temp;
}

void	move_b3(t_stack **give, t_stack *receive)
{
	t_stack	*a_temp;

	a_temp = *give;
	while (a_temp->cheapest != 1)
		a_temp = a_temp->next;
	if (a_temp->above_median == 1)
	{
		while (a_temp->index != 1)
		{
			rotate(&(*give));
			individual_index(&(*give));
		}
	}
	if (a_temp->above_median == 0)
	{
		while (a_temp->index != 1)
		{
			rotate_down(&(*give));
			individual_index(&(*give));
		}
	}
}
