/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:22:43 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/16 17:00:36 by dahmane          ###   ########.fr       */
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
		find_target_a(&temp_a, &temp_b);
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

	assign_all2(&(*stack_a), &(*stack_b));
	move_b2(&(*stack_a), &(*stack_b));
	move_a2(&(*stack_a), *stack_b);
	push(&(*stack_b), &(*stack_a));
	// assign_all2(&(*stack_a), &(*stack_b));
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
		// printf("%d\n", give->data);
		while (give->target->index != 1)
		{
			// printf("test");
			rotate(&receive);
			index_assign(&give, &receive);
			// printf("%d\n", give->target->data);
		}
	}
	if (give->target->above_median == 0)
	{
		while (give->target->index != 1)
		{
			rotate_down(&receive);
			index_assign(&give, &receive);
		}
	}
	*stack_a = receive;
}

void	move_b2(s_list **stack_a, s_list **stack_b)
{
	s_list	*give;
	s_list	*receive;

	give = *stack_a;
	receive = *stack_b;
	while (give->cheapest != 1)
		give = give->next;
	if (give->above_median == 1)
	{
		while (give->index != 1)
		{
			rotate(&(*stack_b));
			index_assign(&(*stack_a), &(*stack_b));
		}
	}
	if (give->above_median == 0)
	{
		while (give->index != 1)
		{
			rotate_down(&(*stack_b));
			index_assign(&(*stack_a), &(*stack_b));
		}
	}
}