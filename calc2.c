/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:06:33 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/24 14:21:01 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_node(t_stack *stack)
{
	t_stack	*max;
	t_stack	*temp;

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

t_stack	*min_node(t_stack *stack)
{
	t_stack	*min;
	t_stack	*temp;

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

void	individual_cost(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	if (stack_length(temp) <= 2)
	{
		temp->cost = 0;
		if (temp->next != NULL)
			temp->next->cost = 1;
		return ;
	}
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

void	cost_of_push(t_stack **give, t_stack **receive)
{
	t_stack	*temp;

	individual_cost(&(*give));
	individual_cost(&(*receive));
	temp = *give;
	while (temp != NULL)
	{
		temp->cost = (temp->cost) + (temp->target->cost);
		temp = temp->next;
	}
}
