/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:26:28 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/16 15:49:01 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

s_list	*max_node(s_list *stack)
{
	s_list	*max;
	s_list	*temp;

	if (!stack || !stack->next)
		return (NULL);
	max = stack;
	temp = max->next;
	while (temp != NULL)
	{
		if (max->data < temp->data)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

s_list	*min_node(s_list *stack)
{
	s_list	*min;
	s_list	*temp;

	if (!stack || !stack->next)
		return (NULL);
	min = stack;
	temp = min->next;
	while (temp != NULL)
	{
		if (min->data > temp->data)
			min = temp;
		temp = temp->next;
	}
	return (min);
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

void	index_assign(s_list **stack_a, s_list **stack_b)
{
	s_list	*a_temp;
	s_list	*b_temp;
	int		i;

	i = 1;
	a_temp = *stack_a;
	b_temp = *stack_b;
	while (a_temp != NULL)
	{
		a_temp->index = i;
		a_temp = a_temp->next;
		i++;
	}
	i = 1;
	while (b_temp != NULL)
	{
		b_temp->index = i;
		b_temp = b_temp->next;
		i++;
	}
}
void	individual_index(s_list **stack)
{
	s_list	*temp;
	int		i;

	i = 1;
	temp = *stack;
	while (temp != NULL)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

void	median_calc(s_list **stack)
{
	s_list	*a_temp;
	int		median;

	if (!*stack)
		return;
	a_temp = *stack;

	median = stack_length(a_temp) / 2;
	if ((stack_length(a_temp) % 2) != 0)
		median ++;
	while (a_temp != NULL)
	{
		if (a_temp->index <= median)
			a_temp->above_median = 1;
		else
			a_temp->above_median = 0;
		a_temp = a_temp->next;
	}
}
void	median_assign(s_list **stack_a, s_list **stack_b)
{
	median_calc(&(*stack_a));
	median_calc(&(*stack_b));
}

void	individual_cost(s_list **stack)
{
	s_list	*temp;
	int		i;

	temp = *stack;
	i = 1;
	while (temp->above_median != 0)
	{
		temp->cost = temp->index - 1;
		temp = temp->next;
	}
	temp = ft_lstlast(*stack);
	while (temp->above_median != 1)
	{
		temp->cost = i;
		i++;
		temp = temp->prev;
	}
}

void	cost_of_push(s_list **give, s_list **receive)
{
	s_list	*temp;
	
	individual_cost(&(*give));
	individual_cost(&(*receive));
	temp = *give;
	while (temp != NULL)
	{
		temp->cost = (temp->cost) + (temp->target->cost);
		temp = temp->next;
	}
}

void	find_cheapest(s_list **stack)
{
	s_list	*temp;
	s_list	*cheapest;

	temp = *stack;
	while (temp != NULL)
	{
		temp->cheapest = 0;
		temp = temp->next;
	}
	temp = *stack;
	cheapest = temp;
	while (temp != NULL)
	{
		if (temp->cost < cheapest->cost)
			cheapest = temp;
		temp = temp->next;
	}
	cheapest->cheapest = 1;
}

void	assign_all(s_list **stack_a, s_list **stack_b)
{
	assign_target_b(&(*stack_a), &(*stack_b));
	index_assign(&(*stack_a), &(*stack_b));
	median_assign(&(*stack_a), &(*stack_b));
	cost_of_push(&(*stack_a), &(*stack_b));
	find_cheapest(&(*stack_a));
}