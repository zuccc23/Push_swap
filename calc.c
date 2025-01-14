/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:26:28 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/14 12:03:57 by dahmane          ###   ########.fr       */
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
void	median_calc(s_list **stack)
{
	s_list	*a_temp;
	int		median;

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