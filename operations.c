/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:28:15 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/29 11:45:45 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **give, t_stack **receive)
{
	t_stack	*temp;

	if (!*give)
		return ;
	if ((*give)->next == NULL)
	{
		(*give)->next = *receive;
		(*receive)->prev = *give;
		*receive = *give;
		ft_printf("pb\n");
		return ;
	}
	else
	{
		temp = (*give)->next;
		(*give)->next = *receive;
		if (*receive != NULL)
			(*receive)->prev = *give;
		*receive = *give;
		*give = temp;
		(*give)->prev = NULL;
	}
	ft_printf("pb\n");
}

void	swap(t_stack **list)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (!*list)
		return ;
	if (!(*list)->next)
		return ;
	temp_a = *list;
	temp_b = *list;
	temp_b = temp_b->next;
	temp_a->next = temp_b->next;
	temp_a->prev = temp_b;
	temp_b->next = temp_a;
	temp_b->prev = NULL;
	*list = temp_b;
	ft_printf("sa\n");
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	ft_printf("ra\n");
}

void	rotate_down(t_stack **stack)
{
	t_stack	*last;
	t_stack	*b4last;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	b4last = ft_lst_before_last(*stack);
	b4last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	(*stack)->prev = NULL;
	ft_printf("rra\n");
}
