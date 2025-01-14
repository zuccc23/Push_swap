/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:34:12 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/14 10:27:42 by dahmane          ###   ########.fr       */
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
}
void	sort_2(s_list **stack)
{
	s_list	*second;

	second = (*stack)->next;
	if ((*stack)->data > second->data)
		swap(&(*stack));
}

void	find_target_b(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp_a;
	s_list	*temp_b;
	s_list	*target_temp;

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
				// printf("test");
			}
		}
		temp_b = temp_b->next;
	}
	temp_b = *stack_b;
	if (temp_a->target == NULL)
		temp_a->target = max_node(temp_b);
}

void	assign_target_b(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp_a;
	s_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_a != NULL)
	{
		find_target_b(&temp_a, &temp_b);
		temp_a = temp_a->next;
	}
}