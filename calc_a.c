/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:22:43 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/19 00:22:24 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_a(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp_a;
	s_list	*temp_b;
	s_list	*target_temp;
	// printf("---%d\n", (*stack_b)->data);
	temp_a = *stack_a;
	temp_b = *stack_b;
	target_temp = NULL;
	while (temp_a != NULL)
	{
		if (temp_a->data < temp_b->data)
		{
			if (target_temp == NULL || temp_a->data < target_temp->data)
			{
				temp_b->target = temp_a;
				target_temp = temp_a;
			}
		}
		temp_a = temp_a->next;
	}
	temp_a = *stack_a;
	if (temp_b->target == NULL)
		temp_b->target = min_node(temp_a);
}

void	assign_target_a(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp_a;
	s_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_b != NULL)
	{
		find_targetv2(temp_a, &temp_b);
		temp_b = temp_b->next;
	}
}

void	assign_all2(s_list **stack_a, s_list **stack_b)
{
	assign_target_a(&(*stack_a), &(*stack_b));
	index_assign(&(*stack_a), &(*stack_b));
	median_assign(&(*stack_a), &(*stack_b));
	cost_of_push(&(*stack_b), &(*stack_a));
	find_cheapest(&(*stack_b));
}

void	push_cheapest_to_a(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp;

	// assign_all2(&(*stack_a), &(*stack_b));
	
	move_b3(&(*stack_b), *stack_a);
	move_a3(*stack_b, &(*stack_a));
	push(&(*stack_b), &(*stack_a));
	assign_all2(&(*stack_a), &(*stack_b));
}

void	move_a2(s_list **stack_a, s_list *stack_b)
{
	s_list	*give;
	s_list	*receive;

	give = stack_b;
	receive = *stack_a;
	while (give->cheapest != 1)
		give = give->next;
	if (give->target->above_median == 1)
	{
		while (give->target->index != 1)
		{
			rotate(&receive);
			individual_index(&receive);
		}
	}
	if (give->target->above_median == 0)
	{
		while (give->target->index != 1)
		{
			rotate_down(&receive);
			individual_index(&receive);
		}
	}
	*stack_a = receive;
}

void	move_b2(s_list *stack_a, s_list **stack_b)
{
	s_list	*give;
	s_list	*receive;

	give = stack_a;
	receive = *stack_b;
	while (give->cheapest != 1)
		give = give->next;
	if (give->above_median == 1)
	{
		while (give->index != 1)
		{
			rotate(&(*stack_b));
			individual_index(&(*stack_b));
		}
	}
	if (give->above_median == 0)
	{
		while (give->index != 1)
		{
			rotate_down(&(*stack_b));
			individual_index(&(*stack_b));
		}
	}
	*stack_b = receive;
}

void	move_a3(s_list *givee, s_list **receive)
{
	s_list	*a_temp;
	s_list	*b_temp;

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

void	move_b3(s_list **give, s_list *receive)
{
	s_list	*a_temp;

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