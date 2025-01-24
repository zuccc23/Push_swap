/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:26:28 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/24 14:20:32 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_assign(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a_temp;
	t_stack	*b_temp;
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

void	individual_index(t_stack **stack)
{
	t_stack	*temp;
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

void	median_calc(t_stack **stack)
{
	t_stack	*a_temp;
	int		median;

	if (!*stack)
		return ;
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

void	median_assign(t_stack **stack_a, t_stack **stack_b)
{
	median_calc(&(*stack_a));
	median_calc(&(*stack_b));
}

void	find_cheapest(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*cheapest;

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
